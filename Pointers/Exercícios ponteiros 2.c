//
// Created by marcos on 23/08/2024.
//

#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char nome[8];
    int idade;
    float altura;
};

int main(void)
{
   struct Pessoa p;

   strcpy(p.nome, "Marcos");
   p.idade = 24;
   p.altura = 1.77;

   printf("Endereço nome: %p\n", (void*)&p.nome);
   printf("Endereço idade: %p\n", (void*)&p.idade);
   printf("Endereço altura: %p\n", (void*)&p.altura);

   return 0;
}
