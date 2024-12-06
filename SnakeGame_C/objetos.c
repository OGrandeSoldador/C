//
// Created by marco on 02/12/2024.
//
#include "objetos.h"
#include "stdbool.h"
#include <stdio.h>
#include "map.h"
#include "player.h"
#include <stdlib.h>



OBJECTS createItem(int x, int y) {
    OBJECTS item;

    item.type = ITEM;       // Define o tipo como ITEM
    item.cord.x = x;          // Coordenada X do item
    item.cord.y = y;          // Coordenada Y do item
    item.isSolid = 0;       // Não é sólido, pode ser coletado
    item.points = 1;       // Valor dos pontos ao coletar (ajuste como quiser)
    item.symbol = 'I';      // Caractere que representa o item no mapa

    return item;
}

void checkCollision(PLAYER* player, MAP* map, bool* gameover) {
    // Verifica o tipo de objeto na posição onde o jogador está
     ObjectType Wall = map->mapmemory[player->posY][player->posX];
     ObjectType Item = map->mapmemory[player->posY][player->posX];
     ObjectType Snake = map->mapmemory[player->posY][player->posX];
    // Se o jogador colidir com uma parede ou inimigo, o jogo acaba
    if (Wall == WALL) {
        *gameover = true;  // Define que o jogo acabou
        printf("\ncolidiu com um objeto perigoso! Fim de jogo.\n");
    }
    if (Item == ITEM)
    {
        spawnitem(map,*player);
        player->snake.bodylen++;
    }
    if (Snake == player->symbol)
    {
        *gameover = true;
        printf("\nSe comeu! Fim de jogo.\n");
    }


}

Position findvalidposition(MAP* map)
{
    Position pos = {};
    int valid = 0;

    while (valid == 0) {
        pos.x = rand() % map->columnslen;  // Posição aleatória X
        pos.y = rand() % map->lineslen;    // Posição aleatória Y

        // Verifica se a posição está vazia
        if (map->mapmemory[pos.x][pos.y] == EMPTY) {
            valid = 1;
        }
    }
    return pos;
}

void spawnitem(MAP* map,PLAYER player)
{
    Position pos = findvalidposition(map);

    // Cria o item com as propriedades configuradas
    OBJECTS item = createItem(pos.x, pos.y);

    // Coloca o símbolo do item no mapa
    map->mapmemory[item.cord.x][item.cord.y] = item.symbol;
}

