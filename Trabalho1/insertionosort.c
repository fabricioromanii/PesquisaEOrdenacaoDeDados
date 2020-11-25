#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionsort(int vet[], int n) 
{ 
    int i, c, j; 
    for (i = 1; i < n; i++) { 
        c = vet[i]; 
        j = i - 1; 
        while (j >= 0 && vet[j] > c) { 
            vet[j + 1] = vet[j]; 
            j = j - 1; 
        } 
        vet[j + 1] = c; 
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

    insertionsort(vet,n);

    printf("Valore ordenados ");
    for(int q=0;q<5;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}