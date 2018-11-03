# Work with Python 3.6
import random
import asyncio
import aiohttp
import json
import multiprocessing

from discord import Game
from discord.ext.commands import Bot

import tweepy
from tweepy import OAuthHandler
from tweepy import Stream
from tweepy.streaming import StreamListener

BOT_PREFIX = ("?", "!")
TOKEN = "NDc5ODc3MTE4MDIxNTk5MjM0.DlftuQ.C-XeUAsHG8KFt0b0MjlrpBNP1mg"  # Get at discordapp.com/developers/applications/me

client = Bot(command_prefix=BOT_PREFIX)

class twitterlistener(tweepy.StreamListener):

    def __init___(self):

        consumer_key = 'rwlqF29bMcv24HNwOM6xbykcs'
        consumer_secret = 'ZbXiKjpasIGpWY6Jv7z7ULDoE7j25S0WCuzvh1cpI5xCXUCo7N'
        access_token = '1030330030155390978-jRimP6RXJByoG93paVyIZD0nxxsbX6'
        access_secret = 'b3b51NH0ag6ZYqqfa2089IDC4ViUEApB6Od4tEh2o0qX0'

        auth = OAuthHandler(consumer_key, consumer_secret)
        auth.set_access_token(access_token, access_secret)
        api = tweepy.API(auth)
        self.__stream = Stream(auth = api.auth, listener=self)
        self.__stream.filter(follow=['1030330030155390978'], async=True)

    def on_connect( self ):
        print("Connection established!!")

    def on_disconnect( self, notice ):
        print("Connection lost!! : ", notice)


    def on_status(self, status, api):
        print("x")
        #if status.in_reply_to_status_id is not None:
        #    message = 'test.'.format(status.in_reply_to_screen_name, status.text)
        #    print(status.text)
            
        #else:
        #    message = 'test.'.format(status.text)
        #    print(status.text)


        #client.send_message(client.get("436538608321691670"), message.encode('utf-8'))

    def on_error(self, status):
        print(status)
        

@client.command()
async def what():
    await client.say("I am the creation of Dope, I will be updated over the weekend.")

@client.command(name='8ball',
                description="Answers a yes/no question.",
                brief="Answers from the beyond.",
                aliases=['eight_ball', 'eightball', '8-ball'],
                pass_context=True)
async def eight_ball(context):
    possible_responses = [
        'That is a resounding no',
        'It is not looking likely',
        'Too hard to tell',
        'It is quite possible',
        'Definitely',
    ]
    await client.say(random.choice(possible_responses) + ", " + context.message.author.mention)

@client.command()
async def tweet(text):
    api.update_status(status=text)

@client.command()
async def test():
    await client.say("test")

@client.command()
async def square(number):
    squared_value = int(number) * int(number)
    await client.say(str(number) + " squared is " + str(squared_value))

@client.command()
async def bitcoin():
    url = 'https://api.coindesk.com/v1/bpi/currentprice/BTC.json'
    async with aiohttp.ClientSession() as session:  # Async HTTP request
        raw_response = await session.get(url)
        response = await raw_response.text()
        response = json.loads(response)
        await client.say("Bitcoin price is: $" + response['bpi']['USD']['rate'])


async def list_servers():
    await client.wait_until_ready()
    while not client.is_closed:
        print("Current servers:")
        for server in client.servers:
            print(server.name)
        listener = twitterlistener()
        await asyncio.sleep(600)

client.loop.create_task(list_servers())
client.run(TOKEN)

