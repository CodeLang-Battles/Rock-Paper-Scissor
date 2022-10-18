/*
This source file is part of the Project <Rock-Paper-Scissor>
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"


Player *Player_newPlayer() {
	Player *p = (Player*) malloc( sizeof(Player) );
	p->idx = 0;
	p->size = PLAYER_SIZE;
	p->moves = (char**) malloc( p->size * sizeof(char*) );

	return p;
}


Player *Player_addPlay( Player *p, char play[] ) {
	// null pointer test, allways a good practice
	if( !p ){
		fprintf( stderr, "ERROR: Null point sent to function <Player_addPlay>\n" );
		return NULL;
	}
	// check if array has free space to the new play, if not the array is increased
	if( p->idx == p->size ){
		p->size += PLAYER_SIZE;
		p->moves = (char **) realloc( p->moves, p->size * sizeof(char *) );
	}
	// save the play
	p->moves[p->idx] = strdup(play);
	p->idx += 1;

	return p;
}


char Player_getPlay( Player *p, int idx ) {
	// null pointer test, allways a good practice
        if( !p ){
                fprintf( stderr, "ERROR: Null point sent to function <Player_getPlay>\n" );
                return -1;
        }
	// check if idx is a valid index
	if( idx<0 || idx > p->idx ){
		fprintf( stderr, "ERROR: Invalid value of argument idx in function <Player:getPlay>" );
		return -1;
	}
	return *(p->moves[idx]);
}


int Player_getDim( Player *p ){
        // null pointer test, allways a good practice
        if( !p ){
                fprintf( stderr, "ERROR: Null point sent to function <Player_getDim>\n" );
                return -1;
        }
	return p->idx;
}


int Player_deletePlayer( Player *p ){
        // null pointer test, allways a good practice
        if( !p ){
                fprintf( stderr, "ERROR: Null point sent to function <Player_deletePlayer>\n" );
                return -1;
        }
	int i;
	for( i=0; i<p->idx; i++ ){
		free( p->moves[i] );
	}
	free( p );
	return 0;
}
