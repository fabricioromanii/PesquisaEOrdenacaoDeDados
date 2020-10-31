/*
HEAP SORT;

Semelhante as arvores;
Em um arvore binaria cada nó pode ter nenhum, 1 ou 2 filhos;
Arvore binaria cheia todo nó possui 0 ou 2 filhos;
se é cheoia o numero de nos é calculada por 2^h -1
a altura da arvore é dada por log²*(nos-1);

arvore binaria completa é cheia ate o penultimo nivel; o ultimo nivel pode estar incompleto, mas toos devem estar mais a esquerda possivel.
altura proxima dela é O(log n);

heap binario é como uma arvore binaria completa

Para mim descobrir a posicao do pai é so fazer n/2 -1;

heap minimo a raiz é sempre menor que seus filhos; o menor valor se encontra na raiz;

heap maximo: o pai é sempre maior que os filhos, raiz tem o maior valor;

interações: criar um novo no folha no ultimo nivel, na posicao mais a esquerda possivel;
verificar se a estrutura satisfaz a relacao de ordem parcial(minimo ou maximo); se compara com o elemento pai;

complexidade da insercao é O(log n);

remocao: substituir o no raiz pelo no que esta no ultimo nivel mais a esquerda possivel;
se a ordem do heap for prejudicava, realiza o processo de afuncar o elemento que esta na raiz e o troca com seu filho de maior valor ou menor;
complexidade da remocao log n;

a busca sempre é feita pelo elemento da raiz


HEAP SORT

A ideia para ordenar um vetor A[1,2,...  ,n] usando um heap é:

-contruir um heap maximo;
-Trocar a raiz com um elemento da ultima posição do vetor;
-Diminuir o tamanho do heap em 1;
-Rearranjar o heap maximo, caso necessario;
-Repetir os tres passos n-1 vezes;

1) primeiro voce troca o ultimo elemento com o primeiro;
2) depois, compara o que agora é o primeiro elemento com seus filhos, se for maior vai trocar;
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
}

void heapSort(int *vet, int N)
{
    int i, aux;

    for (i = (N - 1) / 2; i >= 0; i--)
    {
        //criar heap a partir dos dados
        criaHeap(vet, i, N - 1);
    }

    for (i = N - 1; i <= 1; i--)
    {
        //reconstruir o heap
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}