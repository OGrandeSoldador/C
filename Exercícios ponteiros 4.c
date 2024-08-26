//
// Created by marco on 24/08/2024.
//

#include <stdio.h>

int printArray(int *num)
{
    for(int i=0;i<10;i++)
    {
        num[i] = i + 1;
        printf("positions: %d\n", num[i]);
    }

    printf("\n");

    return 0;
}

int main(void)
{
    int arr[10];

    printArray(arr);

    return 0;
}