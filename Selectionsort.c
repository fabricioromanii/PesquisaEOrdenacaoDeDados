/*
É "selecionado (selection)" na lista desordenada o menor elemento e troca ele com o [0] dessa mesma lista;
A lista ordenada fica a esquerda; elementos a esquerda são todos menores ou iguais aos da direita;
Complexidade: quadrática em todos os casos;
Não é sensível a ordenação inicial;
Espaço: constante; 
Realiza menos trocas que o bubble sort;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

    int TamVet;

    printf("Digite o tamanho de vetor: \n");
    scanf("%d", &TamVet);

    int selec_vet[TamVet];
    int OrdemVet;
    int ValorDecre = TamVet;

    printf("Escolha um numero: 1-aleatorio // 2-crescente // 3-decrescente \n");
    scanf("%d", &OrdemVet);

    if (OrdemVet == 1)
    {
        printf("ORGANIZACAO SELECTION DA LISTA COM NUMEROS ALEATÓRIOS DE %d itens\n", TamVet);
        for (int s = 0; s < TamVet; s++)
        {
            selec_vet[s] = rand() % 10000;
        }
    }
    else if (OrdemVet == 2)
    {
        printf("ORGANIZACAO SELECTION DA LISTA COM NUMEROS CRESCENTES DE %d itens\n", TamVet);
        for (int s = 0; s < TamVet; s++)
        {
            selec_vet[s] = s;
        }
    }
    else if (OrdemVet == 3)
    {
        printf("ORGANIZACAO SELECTION DA LISTA COM NUMEROS DECRESCENTES DE %d itens\n", TamVet);
        for (int s = 0; s < TamVet; s++)
        {
            selec_vet[s] = ValorDecre;
            ValorDecre--;
        }
    }

    int comparacoes = 0;
    int trocas = 0;

    clock_t t;
    int menor_do_menor = selec_vet[0];
    t = clock();

    for (int i = 0; i < TamVet; i++)
    {
        int menor = selec_vet[i];
        int posmenor = i;
        for (int j = i; j < TamVet; j++)
        {
            comparacoes++;
            if (selec_vet[j] < menor)
            {
                menor = selec_vet[j];
                posmenor = j;
                trocas++;
            }
        }
        int a = selec_vet[i];
        selec_vet[i] = menor;
        selec_vet[posmenor] = a;
    }

    t = clock() - t;
    for (int o = 0; o < TamVet; o++)
    {
        printf("%d ", selec_vet[o]);
    }
    printf("\n");
    if (OrdemVet == 1)
    {
        printf("ORGANIZACAO SELECTION DA LISTA COM NUMEROS ALEATÓRIOS DE %d itens\n", TamVet);
    }
    else if (OrdemVet == 2)
    {
        printf("ORGANIZACAO SELECTION DA LISTA COM NUMEROS CRESCENTES DE %d itens\n", TamVet);
    }
    else if (OrdemVet == 3)
    {
        printf("ORGANIZACAO SELECTION DA LISTA COM NUMEROS DECRESCENTES DE %d itens\n", TamVet);
    }
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    printf("Comparacoes %d \n", comparacoes);
    printf("Trocas %d\n", trocas);
    return 0;
}
