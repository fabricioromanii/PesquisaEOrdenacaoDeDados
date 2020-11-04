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