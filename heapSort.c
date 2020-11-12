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
#include <time.h>
#include <math.h>

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void criaheap (int *vet, int n, int i) {
    int aux;
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < n && vet[esquerda] > vet[maior]) {
        maior = esquerda;
    }

    if (direita < n && vet[direita] > vet[maior]) {
        maior = direita;
    }

    if (maior != i) {
        swap (&vet[i], &vet[maior]);
        criaheap(vet, n, maior);
    }
}

void heapsort (int *vet, int n) {
    int k;
    int aux;
    for (k = (n/2 - 1); k >= 0; k--) {
        criaheap (vet, n, k);
    }

    for (k = n-1; k >= 0; k--) {
        swap(&vet[0], &vet[k]);
        criaheap(vet, k, 0);
    }
}

void escolheTipoDoVetor (int TipoDoVetor, int *vet, int n) {
    if (TipoDoVetor == 1) {
        for (int i = 0; i < n; i++) {
            vet[i] = i+1;
        }
    }
    if (TipoDoVetor == 2) {
        int j = n;
        for (int i = 0; i < n; i++) {
            vet[i] = j;
            j--;
        }
    }
    if (TipoDoVetor == 3){
        int i;
        for (i = 0; i < n; i++){
            vet[i] = rand() % n;
        }
    }
}

 void main(){
    int n;
    int num = 1000;
    clock_t start,end;
    double MeuTime;
    int metodo;
    int TipoDoVetor;
    int ipo;

    printf("TAMANHO\n");
    scanf("%d", &n);
    int vet[n];
    printf("\nORDEM DO VETOR\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    printf("\n");
    scanf("%d", &TipoDoVetor);
    printf("\n");
    escolheTipoDoVetor (TipoDoVetor, vet, n);

    start = clock();

    printf("\nDESORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    }    

    heapsort (vet, n);
    
    end = clock();

    printf("\nORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    }

    MeuTime = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\n(segundos): %lf\n",MeuTime);
    printf("(milisegundos): %lf\n",MeuTime*1000);
}