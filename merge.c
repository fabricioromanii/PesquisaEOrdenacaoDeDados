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

void mergeSort(int *v, int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        //se o inicio < fim entao calcula o meio;
        meio = floor((inicio + fim) / 2);
        //Funcao mergeSort;
        mergeSort(v, inicio, meio);
        //chama novamente o merge sort para o inicio ate o meio, e depois para meio ate o fim;
        mergeSort(v, meio + 1, fim);
        //Funcao merge;
        merge(v, inicio, meio, fim);
    }
}

void merge(int *v, int inicio, int meio, int fim)
//combinar os dados de forma ordenada;
//vou comparar as pocicoes p1 e p2, e combinar elas em um vetor maior (ordenado);
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    //defino o tamanho com base no inicio e no fim;
    p1 = inicio;
    p2 = meio + 1;
    //p1 e p2 sao os inicios dos dois vetores;
    temp = (int *)malloc(tamanho * sizeof(int));
    //vou combinar os dois outros vetores em um terceiro (temp);
    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                //verificar quem da posicao p1 e p2 é o menor elemento;
                //o menor passa a ser o prim posicao do vetor temp;
                if (v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
                //aqui é quando chega no final de algum deles;
                //se um dos vetores acabar, nao precisa ficar copiando e comparando, ai é so copiar oq sobrou;
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        //esse ultimo for copia do auxiliar pro original;
        //pega os dados do vetor temp e joga no v de forma ordenada;
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}
