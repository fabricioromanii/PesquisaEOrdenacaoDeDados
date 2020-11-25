#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubble_sort(int *vet, int n){
    long int comparacoes = 0, trocas = 0;
    int troca, flag;
    for(int i = n-1; i>=1; i--){
        flag = 0;
        for(int j = 0; j<=i-1; j++){
             comparacoes+=1;
            if (vet[j] > vet[j+1]){  
                troca = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = troca;
                flag = 1;
                trocas+=1;
            }
           
        }
        if (flag == 0){
                break;
        }
        
    }
    printf("Comparacoes: %ld\n", comparacoes);
    printf("Trocas: %ld\n", trocas);
}

int insertionsort(int *v, int n) { 
    int i, c, j;
    long int comparacoes = 0, trocas = 0; 
    for (int i = 0; i < n; i++){
        int c = v[i];
        int j = i - 1;

        while(j >= 0 ){
            comparacoes++;
            if(v[j] > c){
                v[j + 1] = v[j];
                j--;
                trocas++;
            } else {
                break;
            }
        }
        v[j + 1] = c;
    }
    
    printf("Comparacoes: %ld\n", comparacoes);
    printf("Trocas: %ld\n", trocas);
}
void selectionsort(int *v, int n){
 int menor;
    long int trocas=0, comp=0;

 for(int i = 0; i<=n-2; i++){
        menor = i;
        for(int j = i+1; j <= n-1; j++){
   comp+=1;
            if(v[menor] > v[j]){
                menor = j;
   }
  } 
  if (menor != i){
   int troca = v[i];
   v[i] = v[menor];
   v[menor] = troca; 
   trocas+=1;
  }
}
printf("Comparacoes: %ld\n", comp);
printf("Trocas: %ld\n", trocas);

}
void geraVetorCrescente (int *vet , int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = i+1;
    }
}
void geraVetorDecrescente (int *vet , int n) {
    int j = n;
    for (int i = 0; i < n; i++) {
        vet[i] = j;
        j--;
    }
}

void geraVetorAleatorio (int *vet, int n, int num) {
    int i;
    for (i = 0; i < n; i++){
        vet[i] = rand() % num;
        
    }

    
}
void escolheTipoVet (int tipovet, int *vet, int n, int num) {
    if (tipovet == 1) {
            geraVetorCrescente(vet, n);
        }
        else if (tipovet == 2) {
            geraVetorDecrescente(vet, n);
        }
        else if (tipovet == 3){
            geraVetorAleatorio(vet, n, num);
        }
}



void main(){
    int n;
    int num = 1000000;
    clock_t start,end;
    double difTempo;
    int metodo;
    int tipovet;

    printf("Qual método de ordenção usar?\n1 - BubbleSort\n2 - InsertionSort\n3 - SelectionSort\n");
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

    if (metodo == 1) {
        
        start = clock();
        bubble_sort(vet, n);  
    }
    else if (metodo == 2) {
    
        start = clock();
        insertionsort(vet, n);
    }
    else if (metodo == 3) {
        
        start = clock();
        selectionsort (vet, n);
    }
    
    end = clock();

    printf("\nValore ordenados ");
   /* for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");*/

    difTempo = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\nTempo(s): %lf\n",difTempo);
    printf("Tempo(ms) %lf\n",difTempo*1000);
}