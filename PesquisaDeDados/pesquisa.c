/*
a busca nos dados depende de como eles estao estruturados (vetor, lista, arvore), se estao ordenados e se ha elementos duplicados;

BUSCA LINEAR - pega o vetor apartir da 1º pos e depois ir comparando com o elemento procurado;

BUSCA BINARIA: num vetor ordenado usamos uma estrategia mais sofisticada, a bisca binaria;
Divisao e conquista, a cada passo analisa o elemento do meio do vetor;

*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    //BUSCA LINEAR;
    int i, vetor[10];

    for (i = 0; i < 10; i++)
    {
        vetor[i] = i * 3;
        printf("Posicao %d : %d\n", i, vetor[i]);
    }

    //lendo valores e passando para um vetor
    for (i = 0; i < 10; i++)
    {
        printf("Digite um numero para adicionar ao vetor.");
        scanf("%d\n", &vetor[i]);
        printf("Posicao %d : %d\n", i, vetor[i]);
    }
}