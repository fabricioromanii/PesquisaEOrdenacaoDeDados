#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int particionando (int *vet, int inicio, int fim) {
    int pivo = vet[inicio];
    int aux, esq, dir;
    esq = inicio + 1;
    dir = fim;
    while(esq <= dir){
        if(vet[esq] <= pivo){
            esq++;
        }
        else if (vet[dir] > pivo){
            dir--;
        }
        else if(esq <= dir){
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
            esq++;
            dir--;
        }
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

void quicksort (int *vet, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particionando (vet, inicio, fim);
        quicksort(vet, inicio, pivo-1);
        quicksort(vet, pivo+1, fim);

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
    escolheTipoDoVetor(TipoDoVetor, vet, n);

    printf("\nDESORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    } 

    start = clock();
    
    quicksort(vet, 0, n-1);

    end = clock();

    printf("\nORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    }

    MeuTime = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\n(segundos): %lf\n",MeuTime);
    printf("(milisegundos): %lf\n",MeuTime*1000); 
}