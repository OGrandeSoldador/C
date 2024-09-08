#include <stdio.h>

int main()
{
    int *p,i;
    p = malloc(10*sizeof(int));
    if (p == NULL)
    {
        printf("Espaço insuficiente");
        exit(1);
    }
    else
    {
        printf("Primeiros 10 numeros.\n");
        for (i = 0; i<10; i++)
        {
            p[i] = i + 10;
            printf(" %d-%d\n", i, p[i] );
        }
    }

    p = realloc(p, 20*sizeof(int));

    for (i = 10; i<20; i++)
    {
        p[i]= i + 20;
        printf(" %d-%d\n", i, p[i] );
    }

    free(p);

        return 0;

}
