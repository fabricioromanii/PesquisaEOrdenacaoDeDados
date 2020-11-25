#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionsort(int vet[],int n){
    for(int i=0; i<n-1;i++){
        int min_idx = i; 
        for (int j = i+1; j < n; j++){
          if (vet[j] < vet[min_idx]){
            min_idx = j;
            }
        }
        printf("%d",min_idx);
        int aux = vet[i];
        vet[i] = vet[min_idx];
        vet[min_idx] = aux;
    }
}


void main(){
    int vet[5] = {3,27,6,4,5};
    int n=5;

    printf("Valore desordenados ");
    for(int q=0;q<5;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    selectionsort(vet,n);

    printf("Valore ordenados ");
    for(int q=0;q<5;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}