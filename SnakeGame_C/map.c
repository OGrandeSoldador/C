#include <stdio.h>
#include <stdlib.h>
#include "map.h"

#include "conio.h"

int readsizemap(MAP* filecur)
{
    FILE* file = fopen(filecur->filelocal, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    int colcur = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        filecur->sizemap++;
        if (ch == '\n')
        {
            filecur->columnslen++;
            if (colcur > filecur->lineslen)
            {
                filecur->lineslen = colcur;
            }
            colcur = 0;
        }
        else
        {
            colcur++;
        }
    }
    fclose(file);
    return 0;
}

void allocmap(MAP* filecur)
{
    filecur->mapmemory = (char**)malloc(filecur->columnslen * sizeof(char*));
    if (filecur->mapmemory == NULL) {
        perror("Erro ao alocar memória");
        return;
    }

    for (int i = 0; i < filecur->columnslen; i++) {
        filecur->mapmemory[i] = (char*)malloc(filecur->lineslen * sizeof(char));
        if (filecur->mapmemory[i] == NULL) {
            perror("Erro ao alocar memória para linha");
            return;
        }
    }
}

int fillMatrix(MAP* filecur)
{
    FILE* file = fopen(filecur->filelocal, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i =0;i < filecur->columnslen;i++)
    {
        for (int j = 0;j <filecur->lineslen;j++)
        {
            char ch = fgetc(file);
            if (ch == '\n')
            {
                ch = fgetc(file);
            }
            filecur->mapmemory[i][j] = ch;
        }
    }
    fclose(file);
    return 0;
}

void freematrix(MAP* filecur) {
    for (int i = 0; i < filecur->columnslen; i++) {
        free(filecur->mapmemory[i]);
    }
    free(filecur->mapmemory);
}

void printMap(MAP* filecur)
{
    // Itera pelas linhas do mapa
    for (int i = 0; i < filecur->columnslen; i++) {
        for (int j = 0; j < filecur->lineslen; j++) {
            // Move o cursor para a posição correta antes de imprimir
            c_gotoxy( j + 6, i + 5);

            // Configura as cores com base no caractere atual
            switch (filecur->mapmemory[i][j]) {
            case 'X': // Paredes
                c_textbackground(WHITE);
                c_textcolor(WHITE);
                break;
            case 'Q': // Escaço vazio
                c_textbackground(DARKGRAY);
                c_textcolor(DARKGRAY);
                break;
            case '*': // Jogador
                c_textbackground(GREEN);
                c_textcolor(GREEN);
                break;
            case 'I': //ITEM
                c_textbackground(RED);
                c_textcolor(RED);
                break;
            case 'o': //TESTE CORPO
                c_textbackground(GREEN);
                c_textcolor(GREEN);
                break;
            default:
                c_textbackground(BLACK);
                c_textcolor(WHITE);
                break;
            case '.':
                c_textbackground(GREEN);
                c_textcolor(WHITE);
                break;
            }
            // Imprime o caractere do mapa
            putchar(filecur->mapmemory[i][j]);
        }
    }
    // Reseta as cores para o padrão
    c_textbackground(BLACK);
    c_textcolor(WHITE);
    // Move o cursor para fora do mapa
    c_gotoxy(filecur->lineslen + 6, filecur->columnslen + 5);
}


