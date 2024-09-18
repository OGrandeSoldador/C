#include <stdio.h>

int main(void)
{
    struct Caracteristicas
    {
        char nome[20];
        float vida;
        int mana;
    };

    struct Caracteristicas personagem;

    scanf("%s", personagem.nome);
    printf("Nome :%s\n", personagem.nome);
    personagem.vida = 20;
    printf("Vida :%.0f\n", personagem.vida);
    personagem.mana = 10;
    printf("Mana :%d\n", personagem.mana);

    return 0;
}
