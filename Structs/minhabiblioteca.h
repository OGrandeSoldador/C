//
// Created by marco on 07/09/2024.
//

#ifndef FUNCOES_H
#define FUNCOES_H

void printdata(int day,int month,int year)
{
    int formatint = 0;

    printf("Data de lançamento: ");

    if (day < 10)
    {
        printf("%d",formatint);
    }

    printf("%d/",day);

    if  (month < 10)
    {
        printf("%d",formatint);
    }

    printf("%d/%d\n",month,year);

}

int pointer()
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

#endif //FUNCOES_H
