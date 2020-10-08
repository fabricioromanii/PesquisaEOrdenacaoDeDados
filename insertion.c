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
