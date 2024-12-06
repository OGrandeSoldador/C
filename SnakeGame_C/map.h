#ifndef MAP_H
#define MAP_H

typedef struct{
    char** mapmemory;
    char filelocal[100];
    char emptyspace;
    int sizemap;
    int columnslen;
    int lineslen;
}MAP;

int readsizemap(MAP* filecur);
void allocmap(MAP* filecur);
int fillMatrix(MAP* filecur);
void freematrix(MAP* filecur);
void printMap(MAP* filecur);




#endif //MAP_H
