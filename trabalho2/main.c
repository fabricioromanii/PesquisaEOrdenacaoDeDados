#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mergesort.c"
#include "quicksort.c"
#include "heapsort.c"
#include "geravet.c"

void main(){
    int n;
    int num = 1000;
    clock_t start,end;
    double difTempo;
    int metodo;
    int tipovet;

    printf("Qual método de ordenção usar?\n1 - Mergesort\n2 - Quicksort\n3 - Heapsort\n");
    scanf("%d", &metodo);
    printf("\n");
    printf("Ok, agora escolha o tamanho do vetor a ser usado?\n");
    scanf("%d", &n);
    printf("\n");
    int vet[n];
    printf("Escolha agora o tipo de vetor.\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    printf("\n");
    scanf("%d", &tipovet);
    printf("\n");
    escolheTipoVet (tipovet, vet, n, num);

    //print(vet, n, 0);

    start = clock();
    
    sort (metodo, vet, n);
    
    end = clock();

    //print(vet, n, 1);

    difTempo = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\nTempo(s): %lf\n",difTempo);
    printf("Tempo(ms): %lf\n",difTempo*1000);
}