//
// Created by marco on 02/12/2024.
//

#ifndef OBJETOS_H
#define OBJETOS_H

#include "objetos.h"
#include "stdbool.h"
#include "map.h"
#include "player.h"

typedef struct {
    int x;
    int y;
} Position;

typedef enum  {
    EMPTY = 'Q',   // Espaço vazio
    WALL = 'X',    // Parede
    ITEM = 'I',    // Item coletável
    ENEMY = 3,    // Inimigo
}ObjectType;

typedef struct {
    ObjectType type; // Tipo de objeto
    int isSolid;          // Define se pode ser atravessado (0 ou 1)
    int points;           // Pontos ao coletar (apenas para ITEM)
    Position cord;
    char symbol;          // Caractere para exibir no mapa
}OBJECTS;

void checkCollision(PLAYER* player, MAP* map, bool* gameover);

OBJECTS createItem(int x, int y);

Position findvalidposition(MAP* map);

void spawnitem(MAP* map,PLAYER player);

void growSnake(PLAYER *player);

#endif //OBJETOS_H

