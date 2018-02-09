# \/ #Assignment Three Part One# \/ #

import math
import random

number = random.randint(1,20) #Creates the random integar
numAttempts = 3 #sets attempt times

name = input("What is your name? ") #Name Input
print ("Hello", name,", want to play a game? Im thinking of a number 1-20 guess it.") #Begins the game

while numAttempts > 0: #Runs the game 3 rounds
	numAttempts = numAttempts - 1 #Subtracts each attempt
	guess = int(input("What is your guess? ")) #Takes in the guess
	if guess > number: #Checks to see if the number is higher than the guess
		print ("You've have guessed too high try again. ")
	elif guess < number: #Checks to see if the number is lower than the guess
		print ("You've have guessed too low try again. ")
	elif guess == number: #Checks to see if the number is the guess
		print ("You've have guessed correctly congrats!")
		break #ends game
else: #If the 3 attempts end up being wrong then it reads this
	print ("You've ran out of guesses better luck next time.")  
	print ("The answer was", number,".") #tells the correct answer






# \/ #Assignment Three Part Two# \/ #







def decider(Player1, PlayerR): #Decides who wins the round
	if (Player1 == 'S' or Player1 == 's') and (PlayerR == 'P' or PlayerR == 'p'): #Each if statement here checks what letter 
		return 1                                                                  #is the input for each player then
	elif (Player1 == 'R' or Player1 == 'r') and (PlayerR == 'S' or PlayerR == 's'):#runs it so that there is logic to the inputs
		return 1                                                                   #also allows the input to be upper or lowercase
	elif (Player1 == 'P' or Player1 == 'p') and (PlayerR == 'R' or PlayerR == 'r'):# 1 = player 1
		return 1                                                                   # 2 = Player 2
	elif (Player1 == 'S' or Player1 == 's') and (PlayerR == 'R' or PlayerR == 'r'):# 0 = Neither
		return 2                                                                   #Return system is used for the points
	elif (Player1 == 'R' or Player1 == 'r') and (PlayerR == 'P' or PlayerR == 'p'):#It returns the given digit there
		return 2
	elif (Player1 == 'P' or Player1 == 'p') and (PlayerR == 'S' or PlayerR == 's'):
		return 2
	else:
		return 0

def Player2(): #Simulates the chosing of player 2 (NPC)
	choice = random.randint(1,3) #Choses 1-3
	if choice == 3:   #If statements check to see the random value then sees which letter is assigned to the number
		Player2 = 'S'
	elif choice == 2:
		Player2 = 'P'
	elif choice == 1:
		Player2 = 'R'
	return (Player2) #Returns player 2's choice.

print("Welcome to Rock, Paper, Scissors. The 5 Round version.")	#Introduces the game.
rounds = 5 #sets rounds
P1S = 0 #sets scores
P2S = 0 # ^
while rounds > 0: #Starts the rounds cycle to run until 5 rounds.
	PlayerR = Player2() #Assigns the output to have a variable. Reasoning behind this is that if you were to plug 
	                    #Player2() straight into the places PlayerR is. Itd create errors in the boolean functions and it would also run the function over again
	Player1 = input("Player 1: Please choose R, P, or S: ") #Takes player 1 input
	print("Player 2: Chose:", PlayerR) #Prints player 2's play
	results = decider(Player1, PlayerR) #Runs the function decier

	if results == 1:           #evaluates the return to see who won
		print("Player 1 Won!")
		P1S = P1S + 1           #tallies the points
	elif results == 2:
		print("Player 2 Won!")
		P2S = P2S + 1
	elif results == 0:
		print("It was a tie!")

	rounds = rounds - 1 #Ends the round
	print("Points")         #Reads the tallied points
	print("Player 1: ",P1S)
	print("Player 2: ",P2S)

if P1S > P2S:                                #Reads out who wins based on the points
	print("Congrats Player 1! You won!")
elif P1S < P2S:
	print("Congrats Player 2! You won!")
elif P1S == P2S:
	print("It was a tie.")