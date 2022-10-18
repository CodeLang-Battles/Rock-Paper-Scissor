/*
NAME:			Rock-Paper-Scissor
DEVELOPED BY: 	Tiago Almeida
DATE:			05/10/2022
VERSION:	   	0.0
LAST MODIFIED: 	18/10/2022
C language
*/


#include <stdio.h>
#include <string.h>
#include "player.h"


#define FILE1 "player1.txt"
#define FILE2 "player2.txt"
#define BUF_SIZE 2
#define POSSIBLE_PLAYS 3




int readFile( Player *player, char *filename ){
	// open file
	FILE *file = fopen(filename, "r");
        if( file == NULL ){
                fprintf(stderr, "ERROR: CANNOT OPEN FILE %s\n", filename);
                return -1;
        }
        
	// read data from file
	char buffer[BUF_SIZE], play[BUF_SIZE];
	int nRead = 0, i = 0;
	while( ( nRead = fread( buffer, sizeof(char), BUF_SIZE, file ) ) > 0 ){		// read from file to a buffer
		
		for( i=0; i<nRead; i++ ){
			if( buffer[i] == '\n' || buffer[i] == EOF ) continue;		// ignore this chars
			else{						// create an auxiliary string save the play
				play[0] = buffer[i];			// the first element is the letter corresponding to the play
				play[1] = '\0';				// the second is a null character to indicate the endo of the string
				player = Player_addPlay( player, play );		// Call the function to add the play to the struct Player
			}
		}
	}
	
	// close the file
	fclose( file );
	return 0;
}



int main() {
	// initialization of some variables
	Player *player1_moves = Player_newPlayer();	// array to save player 1 plays
	Player *player2_moves = Player_newPlayer();	// array to save player 1 plays
	char rules[] = "SPRSPR";	// string to help find the winner (S - Scissor; P - Paper; R - Rock)
					// Scissor beats Paper; Paper beats Rock; Rock beats Scissor
	int player1_wins = 0;		// counter
	int player2_wins = 0;		// counter
	int draws = 0;			// counter

	// open files with the plays
	if( readFile( player1_moves, FILE1 ) < 0 ){
		fprintf(stderr, "ERROR: Error in function <readFile>\n");
		return -1;
	}
	if( readFile( player2_moves, FILE2 ) < 0 ){
                fprintf(stderr, "ERROR: Error in function <readFile>\n");
                return -1;
        }

	// check if the number of plays for both players are the same
	if( Player_getDim( player1_moves ) != Player_getDim( player2_moves ) ){
	    fprintf(stderr, "ERROR: Player 1 and Player 2 have a different number of moves!\n");
	    return -1;
	}

	// calculations to find the winner
		// the string <rules> is used to calculate the winner
	int length = Player_getDim( player1_moves );
	int i;
	for( i=0; i<length; i++ ){
		char *sub_rules = strchr( rules, Player_getPlay( player1_moves, i ) );		// create a substring starting with the letter of player 1 play. This is needed to find the corresponding letter of player 2 play after player 1 letter
		char *p2_move = strchr( sub_rules, Player_getPlay( player2_moves, i ) );	// find the letter corresponding to the player 2 play after the letter of player 1
		int result = p2_move - sub_rules;						// subtraction of the letter indexes, the result is used to find the winner:
		switch( result ){
			case 0:
				draws += 1;		// res = 0 - the letter of both players is the same, so it's a draw
				break;
			case 1:
				player1_wins += 1;	// res = 1 - player 1 wins because of the order of the string (one letter beats the subsquent letter)
				break;
			case 2:
				player2_wins += 1;	// res = 2 - player 2 wins because one letter is beaten by the second subsquent letter which is equal to the letter immediatly preceding
				break;
			default:
				fprintf( stderr, "ERROR: Move not allowed" );
				return -1;
		}
	}

	// show the result
	printf( "Player1 wins: %d\n", player1_wins );
	printf( "Player2 wins: %d\n", player2_wins );
	printf( "Draws: %d\n", draws );

	return 0;
}

