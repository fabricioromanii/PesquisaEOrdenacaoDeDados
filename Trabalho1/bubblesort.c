#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bubblesort(int vet[], int n){
    int flag=0;
    for(int i = n-1; i>=1; i--){
        flag=0;
        for(int j = 0; j<=i-1; j++){
            if(vet[j]>vet[j+1]){
                int troca = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = troca;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void main(){
    int vet[5] = {10,9,7,19,5};
    int n=5;
    
    printf("Valore desordenados ");
    for(int q=0;q<5;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    bubblesort(vet, n);

    printf("Valore ordenados ");
    for(int q;q<5;q++){
        printf("%d ",vet[q]);
    }
    printf("\n");
    }
