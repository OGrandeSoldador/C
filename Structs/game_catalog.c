//
// Created by marco on 31/08/2024.
//

#include <stdio.h>
#include "string.h"

typedef struct
{
    int day;
    int month;
    int year;
} data;

typedef struct

{
    char nome[30];
    char plataforma[30];
    data releasedata;
    float notaAva;
    int temjogo;
} Game;


void setcatalogo(Game* jogos, int capacidade)
{
    for (int i = 0; i < capacidade; i++)
    {
        strcpy(jogos[i].nome, "");
        strcpy(jogos[i].plataforma, "");
        jogos[i].releasedata.day = 0;
        jogos[i].releasedata.month = 0;
        jogos[i].releasedata.year = 0;
        jogos[i].notaAva = 0;
        jogos[i].temjogo = 0;
    }
}

Game addGame(const char* nome, const char* plataforma, int day, int month, int ano, float nota)
{
    Game game;
    strcpy(game.nome, nome);
    strcpy(game.plataforma, plataforma);
    game.releasedata.year = ano;
    game.releasedata.month = month;
    game.releasedata.day = day;
    game.notaAva = nota;
    game.temjogo = 1;

    return game;
}

void addcatalogo(Game* vetorjogos, int tamanhovetor, Game addgame, int* posicao)
{
    int cont = 0;
    for (int i = 0; i < tamanhovetor; i++)
    {
        if (vetorjogos[i].temjogo != 1)
        {
            vetorjogos[i] = addgame;
            i = tamanhovetor;
        }
        else
        {
            cont++;
        }
    }
    if (cont == tamanhovetor)
    {
        vetorjogos[*posicao] = addgame;
        *posicao = *posicao + 1;
    }
}

void printdata(int day, int month, int year)
{
    int formatint = 0;

    printf("Data de lançamento: ");

    if (day < 10)
    {
        printf("%d", formatint);
    }

    printf("%d/", day);

    if (month < 10)
    {
        printf("%d", formatint);
    }

    printf("%d/%d\n", month, year);
}

void imprimejogo(Game* jogo)
{
    printf("Nome: %s\n", jogo->nome);
    printf("Plataforma: %s\n", jogo->plataforma);
    printdata(jogo->releasedata.day, jogo->releasedata.month, jogo->releasedata.year);
    printf("Nota: %.1f\n", jogo->notaAva);
    printf("-------------------------------------\n");
}

void buscaPlataforma(Game* jogos, int tamanhovetor)
{
    char plataforma[30];
    printf("\nBusque jogos pela plataforma\n>: ");
    scanf("%s", plataforma);
    printf("-------------------------------------\n");

    int cond = 0;
    while (cond == 0)
    {
        for (int i = 0; i < tamanhovetor; i++)
        {
            if (strcmp(jogos[i].plataforma, plataforma) == 0)
            {
                imprimejogo(&jogos[i]);
                cond = 1;
            }
        }
        if (cond != 1)
        {
            printf("Não encontrada, tente denovo\n");
            printf("\nBusque jogos pela plataforma\n>: ");
            scanf("%s", plataforma);
            printf("-------------------------------------\n");
        }
    }
}

void imprimetodosjogos(Game* jogos, int tamanhovetor)
{
    for (int i = 0; i < tamanhovetor; i++)
    {
        if (jogos[i].releasedata.year != 0)
        {
            imprimejogo(&jogos[i]);
        }
        else
        {
            printf("Sem Jogo adicionado na posição: %d\n", i + 1);
            printf("-------------------------------------\n");
        }
    }
}

void delete_game(Game* jogos, int tamanhovetor)
{
    char confirmation[1] = {"s"};

    printf("Deseja deletar algum jogo?\n");
    printf("s ou n? ");

    int end2 = 0;
    int end = 0;

    while (end == 0)
    {
        scanf("%s", confirmation);

        if ((strcmp(confirmation, "n") != 0) && (strcmp(confirmation, "s") != 0))
        {
            printf("\nTecla invalida!\n\n");
            printf("Deseja deletar algum jogo?\n");
            printf("s ou n? ");
        }

        if (strcmp(confirmation, "s") == 0)
        {
            char name[30];
            printf("Digite o nome do jogo, para deletar: ");
            scanf(" %[^\n]", name);

            while (end2 == 0)
            {
                for (int i = 0; i < tamanhovetor; i++)
                {
                    if (strcmp(jogos[i].nome, name) == 0)
                    {
                        setcatalogo(&jogos[i], 1);
                        printf("\n");
                        printf("Jogo: %s foi removido. \n", name);
                        printf("\nDeseja deletar outro jogo?\n");
                        printf("s ou n? ");
                    }
                    end2 = 1;
                }
                if (end2 == 0)
                {
                    printf("\nDigite jogo valido!\n\n");
                    printf("Digite o nome do jogo, para deletar: ");
                    scanf(" %[^\n]", name);
                }
            }
        }
        if (strcmp(confirmation, "n") == 0)
        {
            end = 1;
        }
    }
    printf("\n");
}

void update_game()
{

}

int main(void)
{
    Game jogos[5];

    int posi = 0;
    int* PosicaodeSubistituicao = &posi;
    int capacidade_total = sizeof(jogos) / sizeof(jogos[0]);

    setcatalogo(jogos, capacidade_total);

    addcatalogo(jogos, capacidade_total, addGame("Valorant", "Pc", 10, 03, 2017, 8), PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("Doom", "Pc", 31, 25, 2017, 8), PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("Crash Bandicoot", "Playstation", 1, 4, 2017, 8),
                PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("Resident Evil", "Playstation", 23, 8, 2017, 8),
                PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("Mario kart", "Nintendo", 2, 2, 1998, 8), PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("123", "Playstation", 32, 04, 2017, 8), PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("345", "Playstation", 04, 05, 2017, 8), PosicaodeSubistituicao);
    addcatalogo(jogos, capacidade_total, addGame("678", "Playstation", 1, 12, 2017, 8), PosicaodeSubistituicao);

    imprimetodosjogos(jogos, capacidade_total);
    delete_game(jogos, capacidade_total);
    imprimetodosjogos(jogos, capacidade_total);

    return 0;
}
