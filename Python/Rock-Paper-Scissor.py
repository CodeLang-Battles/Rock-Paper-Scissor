#!/usr/bin/env python3
# NAME:			Rock-Paper-Scissor
# DEVELOPED BY: 	Tiago Almeida
# DATE:			05/10/2022
# VERSION:   		0.0
# LAST MODIFIED: 	05/10/2022
# Python 3.10.6


# initialization of some variables
player1_moves = []	# list to save player 1 plays
player2_moves = []	# list to save player 1 plays
rules = "SPRSPR"	# string to help find the winner (S - Scissor; P - Paper; R - Rock)
			# Scissor beats Paper; Paper beats Rock; Rock beats Scissor
player1_wins = 0	# counter
player2_wins = 0	# counter
draws = 0		# counter


# open files with the plays
with open("player1.txt", "r") as file1:
    for line in file1:
        player1_moves.append(line[0])

with open("player2.txt", "r") as file2:
    for line in file2:
        player2_moves.append(line[0])


# check if the number of plays for both players are the same
if(len(player1_moves) != len(player2_moves)):
    print("ERROR: Player 1 and Player 2 have a different number of moves!")
    exit()

# calculations to find the winner
							# the string <rules> is used to calculate the winner
for i in range(len(player1_moves)):
    p1_move = rules.find(player1_moves[i])		# find the letter corresponding to the player 1 play
    sub_rules = rules[p1_move:p1_move+3]		# create a substring starting with the letter of player 1 play. This is needed to find the corresponding letter of player 2 play after player 1 letter
    p1_move = 0						# auxiliary variable to help with the calculations
    p2_move = sub_rules.find(player2_moves[i])		# find the letter corresponding to the player 2 play after the letter of player 1
    result = p2_move - p1_move				# subtraction of the letter indexes, the result is used to find the winner:
    if (result == 0): draws += 1			#	res = 0 - the letter of both players is the same, so it's a draw
    elif (result == 1): player1_wins += 1		#	res = 1 - player 1 wins because of the order of the string (one letter beats the subsquent letter)
    elif (result == 2): player2_wins += 1		#	res = 2 - player 2 wins because one letter is beaten by the second subsquent letter which is equal to the letter immediatly preceding
    else:
        print("ERROR: Move not allowed!!")
        exit()


# show the result
print(f"Player1 wins: {player1_wins}")
print(f"Player2 wins: {player2_wins}")
print(f"Draws: {draws}")

