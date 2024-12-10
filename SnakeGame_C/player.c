#include "conio.h"
#include "map.h"
#include "player.h"
#include "objetos.h"
#include <stdlib.h>
#include <stdio.h>
#include "stdbool.h"

void inversearray(int *arr, int size)
{
    {
        int i = 1, j = size - 1;
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
}

int countemptyspace(MAP filecur)
{
    int count = 0;
        for (int i = 0; i < filecur.columnslen; i++){
            for (int j = 0; j < filecur.lineslen; j++){
                if (filecur.mapmemory[i][j] == EMPTY){
                    count++;
                }
            }
        }
    return count;
}

void allocateSnakeBody(PLAYER *player, int maxSize) {
    player->snake.bodyX = (int *)malloc(maxSize * sizeof(int));
    player->snake.bodyY = (int *)malloc(maxSize * sizeof(int));
    player->snake.maxbodylen = maxSize;
}

void freeSnakeBody(PLAYER *player) {
    free(player->snake.bodyX);
    free(player->snake.bodyY);
}

char inputmove(void)
{
    char keypress = c_getch();
    return keypress;
}

bool movePlayer(PLAYER* player,char keypress,MAP mapsize)
{
    switch (keypress)
    {
        case 'w':
            if (player->posY > 0)
                player->posY--;
                storeSnakeBody(player);
                player->snake.bodyY[0]--;
            break;
        case 'a':
            if (player->posX > 0)
                player->posX--;
                storeSnakeBody(player);
                player->snake.bodyX[0]--;
            break;
        case 's':
            if (player->posY < mapsize.columnslen - 1)
                player->posY++;
                storeSnakeBody(player);
                player->snake.bodyY[0]++;
            break;
        case 'd':
            if (player->posX < mapsize.lineslen - 1)
                player->posX++;
                storeSnakeBody(player);
                player->snake.bodyX[0]++;

            break;
        default:
            break;
    }
    return true;
}

void findplayerlocation(MAP* filecur,PLAYER* playerinf)
{
    for (int i = 0; i < filecur->columnslen; i++)
    {
        for (int j = 0; j < filecur->lineslen; j++)
        {
            if (filecur->mapmemory[i][j] == playerinf->symbol)
            {
                playerinf->posX = j;
                playerinf->posY = i;
                playerinf->snake.bodyX[0] = playerinf->posX;
                playerinf->snake.bodyY[0] = playerinf->posY;
            }
            if (filecur->mapmemory[i][j] == 'o')
            {
                playerinf->snake.bodyX[playerinf->snake.bodylen] = j;
                playerinf->snake.bodyY[playerinf->snake.bodylen] = i;
                playerinf->snake.bodylen++;
            }
        }
    }
    if(playerinf->snake.bodyX[1] < playerinf->snake.bodyX[0])
    {
        inversearray(playerinf->snake.bodyX,playerinf->snake.bodylen);
    }
    if(playerinf->snake.bodyY[1] < playerinf->snake.bodyY[0])
    {
        inversearray(playerinf->snake.bodyY,playerinf->snake.bodylen);
    }
}

void updateplayermatrix(PLAYER player,MAP* map)
{
    map->mapmemory[player.posY][player.posX] = '0';
    map->mapmemory[player.snake.bodyY[1]][player.snake.bodyX[1]] = '0';
}

void storeSnakeBody(PLAYER *player) {
    for (int i = player->snake.bodylen; i > 0; i--) {
        player->snake.bodyX[i] = player->snake.bodyX[i - 1];
        player->snake.bodyY[i] = player->snake.bodyY[i - 1];
    }
}

void updatesnakebodymatrix(PLAYER* player,MAP* map){

    for (int i = player->snake.bodylen - 1 ; i > 1; i--)
    {
        map->mapmemory[player->snake.bodyY[i]][player->snake.bodyX[i]] = '*';

    }
}

void printcordsnake(PLAYER player)
{
    printf("b = %d\n",player.snake.bodylen);
    for (int i = 0; i <= player.snake.bodylen - 1;i++)
    {
        printf("x[%d]= %d\t",i,player.snake.bodyX[i]);
        printf("y[%d] = %d\n",i,player.snake.bodyY[i]);

    }
}

void deletelastpositionbody(PLAYER player,MAP* map)
{
    int lastpositionX = player.snake.bodyX[player.snake.bodylen - 1];
    int lastpositionY = player.snake.bodyY[player.snake.bodylen - 1];

    map->mapmemory[lastpositionY][lastpositionX] = EMPTY;
}

void keepmoveforward(PLAYER* player,MAP* map)
{
    if(player->snake.bodyX[1] < player->snake.bodyX[0])
    {
        player->posX++;
        storeSnakeBody(player);
        player->snake.bodyX[0]++;
    }
    if(player->snake.bodyX[1] > player->snake.bodyX[0])
    {
        player->posX--;
        storeSnakeBody(player);
        player->snake.bodyX[0]--;
    }
    if(player->snake.bodyY[1] > player->snake.bodyY[0])
    {
        player->posY--;
        storeSnakeBody(player);
        player->snake.bodyY[0]--;
    }
    if(player->snake.bodyY[1] < player->snake.bodyY[0])
    {
        player->posY++;
        storeSnakeBody(player);
        player->snake.bodyY[0]++;
    }
}