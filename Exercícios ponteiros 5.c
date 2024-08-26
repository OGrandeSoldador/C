//
// Created by marco on 25/08/2024.
//
//Passagem de Arrays para Funções:
//Escreva uma função que receba um array e seu tamanho,
//e use um ponteiro para modificar os elementos do array dentro da função.

#include <stdio.h>


int printArray(int *arr,int size)
{

    for(int i=0;i<10;i++)
    {
        printf("positions: %d\n", num[i]);
    }

    printf("\n");

    return 0;
}

int main(void)
{
    int a[];
    int sizeofarray = 0;
    scanf("Tamanho do array: %d", sizeofarray);
    printArray(a);

    return 0;
}
