#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_CHAR '*'
#include <stdbool.h>

typedef struct{
    int *bodyX,*bodyY;
    int maxbodylen;
    int bodylen;
}BODYSNAKE;

typedef struct {
    BODYSNAKE snake;
    int posX;
    int posY;
    char symbol;
}PLAYER;


void findplayerlocation(MAP* filecur,PLAYER* playerinf);
char inputmove(void);
bool movePlayer(PLAYER* player,char keypress,MAP mapsize);
void updateplayermatrix(PLAYER player,MAP* map);

void allocateSnakeBody(PLAYER *player, int maxSize);
void storeSnakeBody(PLAYER *player) ;
void freeSnakeBody(PLAYER *player);
int countemptyspace(MAP filecur);
void updatesnakebodymatrix(PLAYER* player,MAP* map);

void printcordsnake(PLAYER player);

void deletelastpositionbody(PLAYER player,MAP* map);

void keepmovefoward(PLAYER* player,MAP* map);


#endif //PLAYER_H
