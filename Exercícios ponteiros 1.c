#include <stdio.h>


int main(void)
{
    int *ptr;
    int number = 10;

    ptr = &number;

    printf("Valor do number %d\n", number);
    printf("valor via ponteiro %d\n", *ptr);

    *ptr = 20;

    printf("Novo valor de number %d\n", number);

    return 0;
}


