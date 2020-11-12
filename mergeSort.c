/*
um dos metodos mais usados;

Pega duas coisas e junta elas, duas listas ordenadas formam uma só;

Merge = juntar/misturar/intercalar;

Metodos que usam estratégias mais sofisticadas e eficientes;

Algoritimo do tipo divisao e conquisa; trabalha em decompor o problema 
em instancias cada vez menores do mesmo tipo de problema, resolve elas 
(em geral, recursivamente), e por fim combinar as soluções parciais para 
obter a solução do problema como um todo;

Ideia geral é dividir o vetor em duas partes;
depois disso ordena recursivamente cada parte, 
e depois intercala elas formando um novo segmento ordenado;

as duas listas finais que se se comparam ja sao ordenadas, porque passaram por varias comparações;

quando é lista com n elementos impar, o elemento do meio fica na primeira parte e a segunda é definida apartir de meio+1;

comparações n log n (melhor e pior caso)
estavel; 
recursivo;

Este algoritmo necessita de memoria auxiliar, nao é um algoritmo in place;

4,2,1,6,8,5,7,3
4,2,1,6|8,5,7,3
4,2|1,6|8,5|7,3
2,4|1,6|
se compara a [0] de cada vetor e leva ao vetor ordenado
1,2|4,6|
1,2,4,6|8,5|7,3
1,2,4,6|5,8|3,7
1,2,4,6|3,5,7,8
se compara a [0] de cada vetor e leva ao vetor ordenado
1,2,3,4,5,6,7,8

30,21,43,3,9,82,15
21,30|4,43|9,82|15
3,21,30,43|9,15,82
3,9,15,21,30,43,82
*/
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