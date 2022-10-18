#!/usr/bin/env python3
# NAME:			Rock-Paper-Scissor-Plays-Generator
# DEVELOPED BY: 	Tiago Almeida
# DATE:		    	11/10/2022
# VERSION:   		0
# LAST MODIFIED: 	11/10/2022
# Python 3.10.6


import random       # importing the random module


# array with the possible letters for the plays (R-Rock; P-Paper; S-Scissor)
possibleLetters = "RPS"
print("Rock-Paper-Scissor-Plays-Generator")
print("Generates letters for the Rock-Paper-Scissor game")

# ask how many letters the user wants to generate
quantity = ""           # intialization
while(  not quantity.isdigit() or int(quantity) <= 0):
	quantity = input("Please insert the number of letters you want to generate: ")

quantity = int(quantity)

# open file to write the output
with open("output.txt", "w") as outputFile:
	# generate random numbers which will correspond to the position of the letters of the array <possibleLetters>
	nPossibleLetters = len( possibleLetters ) - 1
	for i in range(quantity):
		randomInt = random.randint( 0, nPossibleLetters )     # generate a random number between 0 and 2 (length of <possibleLetters> - 1)
		outputFile.write( possibleLetters[randomInt] + "\n")                             # prints the letter to the output. If you want the letters in a file copy the output or redirect the output to a file when calling the program

print("Program ended successfully")
