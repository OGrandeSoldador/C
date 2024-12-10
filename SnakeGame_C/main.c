#include <stdio.h>
#include "conio.h"
#include "map.h"
#include "player.h"
#include "objetos.h"
#include "stdbool.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int readsizemap(MAP* filecur);
void allocmap(MAP* filecur);
int fillMatrix(MAP* filecur);
void freematrix(MAP* filecur);
void findplayerlocation(MAP* filecur,PLAYER* playerinf);
void printMap(MAP* filecur);
char inputmove(void);
bool movePlayer(PLAYER* player,char keypress,MAP mapsize);
void updateplayermatrix(PLAYER player,MAP* map);

void checkCollision(PLAYER* player, MAP* map, bool* gameover);

int countemptyspace(MAP filecur);
void allocateSnakeBody(PLAYER *player, int maxSize);
void storeSnakeBody(PLAYER *player) ;
void freeSnakeBody(PLAYER *player);

OBJECTS createItem(int x, int y);
Position findvalidposition(MAP* map);
void spawnitem(MAP* map,PLAYER player);
void updatesnakebodymatrix(PLAYER* player,MAP* map);

void printcordsnake(PLAYER player);

void deletelastpositionbody(PLAYER player,MAP* map);

void keepmoveforward(PLAYER* player,MAP* map);

int main(void)
{
  c_clrscr();

  srand(time(NULL));
  char ch = 0;
  bool gameover = false;
  MAP mainmap = {NULL,"SnakeGameMap.txt",EMPTY ,0, 0, 0,};
  PLAYER player = {0,0 ,0,1,0,0,PLAYER_CHAR};


  readsizemap(&mainmap);
  allocmap(&mainmap);
  fillMatrix(&mainmap);
  allocateSnakeBody(&player,countemptyspace(mainmap));
  findplayerlocation(&mainmap,&player);
  spawnitem(&mainmap,player);
  updateplayermatrix(player,&mainmap);


  while (ch != 'q' && gameover == false)
  {
    printMap(&mainmap);
    ch = inputmove();
    //deletelastpositionbody(player,&mainmap);
    movePlayer(&player,ch,mainmap);
    //printcordsnake(player);
    checkCollision(&player,&mainmap,&gameover);
    updateplayermatrix(player,&mainmap);
    updatesnakebodymatrix(&player,&mainmap);
    usleep(100000);

    while (c_kbhit() == 0 && gameover == false)
    {
      printMap(&mainmap);
      updateplayermatrix(player,&mainmap);
      //deletelastpositionbody(player,&mainmap);
      keepmoveforward(&player,&mainmap);
      //printcordsnake(player);
      checkCollision(&player,&mainmap,&gameover);
      updateplayermatrix(player,&mainmap);
      updatesnakebodymatrix(&player,&mainmap);
      usleep(70000);
    }
  }

  c_gotoxy(0,40);
  printf("Game Over\n");

  freeSnakeBody(&player);
  freematrix(&mainmap);
  return 0;
}
