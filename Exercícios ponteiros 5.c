//
// Created by marco on 25/08/2024.
//
//Passagem de Arrays para Funções:
//Escreva uma função que receba um array e seu tamanho,
//e use um ponteiro para modificar os elementos do array dentro da função.

#include <stdio.h>
#include <stdlib.h>


void printArray(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i] = i + 1;
        printf("positions: %d\n", arr[i]);
    }

    printf("\n");

}

int main(void)
{
    int sizeofarray;
    printf("tamanho do array: ");
    scanf("%d", &sizeofarray);

    int *a = malloc(sizeofarray * sizeof(int));

    if (a == NULL)
    {
        printf("Erro de alocação");
        return 1;
    }

    printArray(a,sizeofarray);

    free(a);

    return 0;
}
