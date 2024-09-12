//
// Created by marco on 07/09/2024.
//

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
    char gamename[30];
    struct Game *next;

}Game;

void aloc_memo(*list, size_list)
{
    for (int i = 0; i < size_list; i++)
    {
        size_list[i] = malloc(sizeof(Game))
    }
}
int main(void)
{
    Game linked_List[3];
    size_list = (sizeof(linked_list) / sizeof(linked_list[0]));


    return 0;
}
