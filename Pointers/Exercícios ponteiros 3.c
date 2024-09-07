//
// Created by marco on 23/08/2024.
//

#include <stdio.h>


int swap(int *a, int*b)
{
    int temp = *b;
    *b = *a;
    *a = temp;

    return 0;
}

int main(void)
{
    int numero = 5;
    int numero1 = 10;

    printf("primeiro numero %d\n", numero);
    printf("segundo numero %d\n\n", numero1);

    swap(&numero,&numero1 );

    printf("primeiro numero %d\n", numero);
    printf("segundo numero %d\n", numero1);

    return 0;

}