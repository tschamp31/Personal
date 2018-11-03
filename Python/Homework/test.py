# Work with Python 3.6
import random
import asyncio
import aiohttp
import json

from discord import Game
from discord.ext.commands import Bot

BOT_PREFIX = ("?", "!")
TOKEN = "'*****'"  # Get at discordapp.com/developers/applications/me
client = Bot(command_prefix=BOT_PREFIX)

extensions = ['TwitterCog','TestCog']

@client.command()
async def load(extension):
    try:
        client.load_extension(extension)
        print('Loaded {}'.format(extension))
        await client.say('Loaded {}'.format(extension))
    except Exception as error:
        exc = '{}: {}'.format(type(error).__name__, error)
        print('Failed to load extension {}\n{}'.format(extension, exc))
        await client.say('Failed to load extension {}\n{}'.format(extension, exc))

@client.command()
async def unload(extension):
    try:
        client.unload_extension(extension)
        print('Unloaded {}'.format(extension))
        await client.say('Unloaded {}'.format(extension))
    except Exception as error:
        print('{} cannot be unloaded. [{}]'.format(extension, error))
        await client.say('{} cannot be unloaded. [{}]'.format(extension, error))

@client.command()
async def reload(extension):
    try:
        client.unload_extension(extension)
        print('Unloaded {}'.format(extension))
        await client.say('Unloaded {}'.format(extension))
        client.load_extension(extension)
        print('Loaded {}'.format(extension))
        await client.say('Loaded {}'.format(extension))
    except Exception as error:
        print('{} cannot be unloaded. [{}]'.format(extension, error))
        await client.say('{} cannot be unloaded. [{}]'.format(extension, error))     
        exc = '{}: {}'.format(type(error).__name__, error)
        print('Failed to load extension {}\n{}'.format(extension, exc))
        await client.say('Failed to load extension {}\n{}'.format(extension, exc))

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

if __name__ == '__main__':
    for extension in extensions:
        try:
            client.load_extension(extension)
            print('Loaded {}'.format(extension))
        except Exception as error:
            exc = '{}: {}'.format(type(error).__name__, error)
            print('Failed to load extension {}\n{}'.format(extension, exc))


async def list_servers():
    await client.wait_until_ready()
    while not client.is_closed:
        print("Current servers:")
        for server in client.servers:
            print(server.name)
        await asyncio.sleep(30)

client.loop.create_task(list_servers())
client.run(TOKEN)

