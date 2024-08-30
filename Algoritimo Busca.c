//
// Created by marco on 29/08/2024.
//

#include <stdio.h>

// Função que busca a chave no array e retorna o índice onde ela foi encontrada
// Se a chave não for encontrada, retorna 2
int buscar(int chave, int n, int *a)
{
    // Verifica se o número de elementos no array é maior que 0
    if (n > 0)
    {
        // Loop através do array, do índice 0 até n-1
        for (int i = 0; i <= n - 1; i++)
        {
            // Se o valor do elemento atual do array for igual à chave, retorna o índice
            if (a[i] == chave)
            {
                return i;
            }
        }
    }
    // Se a chave não for encontrada, retorna 2
    return 2;
}

int main(void)
{
    // Declara um array de inteiros com 7 elementos
    int a[7] = {1, 2, 4, 10, 3, 6, 7};

    // Calcula o número de elementos no array dividindo o tamanho total do array pelo tamanho de um elemento
    int n = sizeof(a) / sizeof(a[0]);

    // Chama a função buscar para encontrar a chave 8 no array
    int resultado = buscar(8, n, a);

    // Verifica se a função retornou um índice válido (diferente de 2)
    if (resultado != 2) {
        // Se a chave foi encontrada, imprime o índice onde ela foi encontrada
        printf("Chave encontrada no índice: %d\n", resultado);
    } else {
        // Se a chave não foi encontrada, imprime uma mensagem indicando isso
        printf("Chave não encontrada\n");
    }
    return 0;
}