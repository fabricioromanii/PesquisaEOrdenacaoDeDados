/*
Simular a maneira que as pessoas ordenam cartas de baralho;
Começa pelo segundo elemento da lista desordenada e compara com o primeiro, se for menor troca essas posições;
Na segunda interação, pega o [2] e compara com o [1], se [2]<[1] então troca os elementos;
Se for menor, agora o elemento que antes era [2] agora está em [1], ai ele é comparado com o [0] e segue a mesma lógica anterios;
A idéia é partir de um elemento e ir inserindo outros já em parte ordenada;
Inserção direta;
Basicamente, pega os números a direita como se tivesse selecionando cartas, ai compara com as "cartas" que você ja tem,
da direita para a esquerda e ai é encontrado a sua posição;
Método eficiente para listas quase ordenadas;
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int TamVet;

    printf("Digite o tamanho de vetor: \n");
    scanf("%d", &TamVet);

    int insertion_vetor[TamVet];
    int OrdemVet;
    int ValorDecre = TamVet;

    printf("Escolha um numero: 1-aleatorio // 2-crescente // 3-decrescente \n");
    scanf("%d", &OrdemVet);

    if (OrdemVet == 1)
    {
        printf("ORGANIZACAO DA LISTA COM NUMEROS ALEATÓRIA DE %d itens\n", TamVet);
        for (int s = 0; s < TamVet; s++)
        {
            insertion_vetor[s] = rand() % 10000;
        }
    }
    else if (OrdemVet == 2)
    {
        printf("ORGANIZACAO DA LISTA COM NUMEROS CRESCENTES DE %d itens\n", TamVet);
        for (int s = 0; s < TamVet; s++)
        {
            insertion_vetor[s] = s;
        }
    }
    else if (OrdemVet == 3)
    {
        printf("ORGANIZACAO DA LISTA COM NUMEROS DECRESCENTES DE %d itens\n", TamVet);
        for (int s = 0; s < TamVet; s++)
        {
            insertion_vetor[s] = ValorDecre;
            ValorDecre--;
        }
    }

    clock_t t;
    int comparacoes = 0;
    int trocas = 0;
    t = clock();

    int i, j, x;
    for (i = 1; i < TamVet; i++)
    {
        int pivo = insertion_vetor[i];
        int j = i - 1;
        comparacoes++;
        while (j >= 0 && insertion_vetor[j] > pivo)
        {
            insertion_vetor[j + 1] = insertion_vetor[j];
            j--;
            trocas++;
        }
        insertion_vetor[j + 1] = pivo;
    }
    t = clock() - t;
    for (int o = 0; o < TamVet; o++)
    {
        printf("%d ", insertion_vetor[o]);
    }
    printf("\n");

    if (OrdemVet == 1)
    {
        printf("ORGANIZACAO INSERTION DA LISTA COM NUMEROS ALEATÓRIA DE %d itens\n", TamVet);
    }
    else if (OrdemVet == 2)
    {
        printf("ORGANIZACAO INSERTION DA LISTA COM NUMEROS CRESCENTES DE %d itens\n", TamVet);
    }
    else if (OrdemVet == 3)
    {
        printf("ORGANIZACAO INSERTION DA LISTA COM NUMEROS DECRESCENTES DE %d itens\n", TamVet);
    }
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    printf("Comparacoes %d \n", comparacoes);
    printf("Trocas %d\n", trocas);
    return 0;
}
