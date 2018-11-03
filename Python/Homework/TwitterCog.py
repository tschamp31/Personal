import tweepy
import asyncio
from tweepy import OAuthHandler
from tweepy import Stream
from tweepy.streaming import StreamListener

import discord
from discord.ext import commands

class TwitterCog():

    def __init__(self, bot, api):
        self.bot = bot
        self.api = api

    class TwitterListen(tweepy.StreamListener):

        def __init__(self, bot, api):
            self.bot = bot
            self.api = api

        def on_connect( self ):
            print("Connection established!!")
            return True

        def on_disconnect( self, notice ):
            print("Connection lost!! : ", notice)

        def on_status(self, status):
            if status.in_reply_to_status_id is not None:
                #message = '{} posted {}'.format(status.in_reply_to_screen_name, status.text)
                sending = output(self.bot, self.api)
                task = self.bot.loop.create_task(sending.messagesender(status))
                #self.bot.loop.run_until_complete(task)
                #self.messagesender(message)
                #print(message)
                
            else:
                #message = 'Posted {}'.format(status.text)
                sending = output(self.bot, self.api)
                task = self.bot.loop.create_task(sending.messagesender(status))
                #self.bot.loop.run_until_complete(task)
                #self.messagesender(message)
                #print(message)

        def on_error(self, status):
            if status_code == 420:
                #returning False in on_data disconnects the stream
                return False
            print(status) 

        # @commands.command()
        # async def tweet(text):
        #     api.update_status(status=text)

    def stream(self):
        twitterListener = TwitterCog.TwitterListen(self.bot, self.api)
        twitterStream = Stream(auth = self.api.auth, listener=twitterListener)
        twitterStream.filter(follow=['1030330030155390978'], async = True)


class output():

    def __init__(self, bot, api):
        self.bot = bot
        self.api = api

    async def messagesender(self, status):
        status.tweet_web_url = f'https://twitter.com/i/web/status/{status.id}'
        #status.tweet_url = f'https://twitter.com/{tweet.author.screen_name}/status/{tweet.id}'
        await self.bot.send_message(discord.Object(id='436538608321691670'), f'@{status.author.name}' + " tweeted this at " + f'{status.created_at}' + ":")
        await self.bot.send_message(discord.Object(id='436538608321691670'), status.tweet_web_url)
        embed = discord.Embed(color=0x00ff00, title=status.author.name)
        embed.set_author(name=f'@{status.author.name}')
        embed.set_thumbnail(url=status.author.profile_image_url_https)
        embed.add_field(value=status.text, inline=False)
        await self.bot.send_message(discord.Object(id='436538608321691670'), embed=embed)
        

def setup(bot):
    consumer_key = 'rwlqF29bMcv24HNwOM6xbykcs'
    consumer_secret = 'ZbXiKjpasIGpWY6Jv7z7ULDoE7j25S0WCuzvh1cpI5xCXUCo7N'
    access_token = '1030330030155390978-jRimP6RXJByoG93paVyIZD0nxxsbX6'
    access_secret = 'b3b51NH0ag6ZYqqfa2089IDC4ViUEApB6Od4tEh2o0qX0'

    auth = OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_token, access_secret)

    api = tweepy.API(auth)
    cog = TwitterCog(bot, api)

    bot.loop = asyncio.get_event_loop()
    bot.loop.create_task(cog.stream())
    bot.add_cog(cog)



    #Figure out how to stop the twitter API from autoclosing the connect/socket to the bot. :) 