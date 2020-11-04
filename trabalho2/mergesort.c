#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void intercalando (int *vet, int inicio, int meio, int fim) {
    int tam = fim - inicio + 1;
    int i = inicio;
    int j = meio + 1;
    int *aux;
    aux = (int *) malloc(tam*sizeof(int));
    int k = 0;

    while(i<=meio && j<=fim){  
        if(vet[i] < vet[j]){
            aux[k] = vet[i];
            i++;
        }
        else{
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    while(i<=meio){
        aux[k] = vet[i];
        k++;
        i++;

    }
    while(j<=fim){
        aux[k] = vet[j];
        k++;
        j++;

    }
       
    for (k = inicio; k<=fim; k++) {
        vet[k] = aux[k-inicio];

    }  
    free(aux);
}

void mergesort (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio =floor(((inicio + fim)/2));
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, fim);
        intercalando(vet, inicio, meio, fim);
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

    printf("\n");
    printf("TAMANHO\n");
    scanf("%d", &n);
    int vet[n];
    printf("\nORDEM DO VETOR\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    printf("\n");
    scanf("%d", &TipoDoVetor);
    printf("\n");
    escolheTipoDoVetor (TipoDoVetor, vet, n);

    printf("\nDESORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
        printf("%d ", vet[ipo]);
    }

    start = clock();
    
    mergesort(vet, 0, n-1);  
    
    end = clock();
    
    printf("\nORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    }

    MeuTime = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\n(segundos): %lf\n",MeuTime);
    printf("(milisegundos): %lf\n",MeuTime*1000);
}