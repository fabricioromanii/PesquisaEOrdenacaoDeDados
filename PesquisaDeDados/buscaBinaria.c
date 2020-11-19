#include <stdio.h>
#include <stdlib.h>

void main()
{   
    int n = 50;
    int inicio = 0;
    int fim = n-1;
    int vetor[n], i;

    while(inicio <= (inicio + fim)/2){
        if(vetor[(inicio + fim)/2]){
            return (inicio + fim)/2;
        }else{
            fim=((inicio + fim)/2) - 1;
            }
        
    }




    for (i = 0; i < 10; i++)
    {
        vetor[i] = i * 3;
        printf("Posicao %d : %d\n", i, vetor[i]);
    }

    //lendo valores e passando para um vetor
    for (i = 0; i < 10; i++)
    {
        printf("Digite um numero para adicionar ao vetor.");
        scanf("%d\n", &vetor[i]);
        printf("Posicao %d : %d\n", i, vetor[i]);
    }

}