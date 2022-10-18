/*
This header file is part of the Project <Rock-Paper-Scissor>
*/

#ifndef PLAYER_H_
#define PLAYER_H_


// Constants
#define PLAYER_SIZE 1000


// structs
typedef struct {
        char** moves;
        int idx;
        int size;
} Player;


// declaration of functions
Player *Player_newPlayer();

Player *Player_addPlay( Player *p, char play[] );

char Player_getPlay( Player *p, int idx );

int Player_getDim( Player *p );

int Player_deletePlayer( Player *p );




#endif /* PLAYER_H_ */
