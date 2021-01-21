/*

O quicksort adota a estratégia de divisão e conquista.
A estratégia consiste em rearranjar as chaves de modo que as chaves "menores" precedam as chaves "maiores".
Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores recursivamente até que a lista completa se encontre ordenada.

Melhor caso: N log N;
Pior caso (raro): N²;
Estavel, nao altera a ordem de dados iguais;
A maneira como escolhe o pivo é o que afeta o desempenho;

|X| = pivo
$ = ListaOrdenada

54, 4, 6, 21, |4|     escolhe o pivo (4);
54, 4, 6, 21, |4|     começa as comparções;
54, 4, 6, 21, |4|     o numero k continua como 54, entao troca-se com o pivo;
|4| 4, 6, 21,  54  
$4, 4, 6, 21, |54|    agora, funciona como se so tivessemos uma lista de numeros maiores que o pivo inicial, entao se pega o ultimo item dessa lista e usa como pivo;
$4, 4, 6, 21,  $54  
$4, 4, 6,|21|, $54
$4, 4, 6, $21, $54
$4, 4,|6|,$21, $54
$4,$4,$6, $21, $54

*/

#include "quick.c" 

int main(){

    Lista *lista;
    int size = 5;

    printf("\nFabricio Romani - Pesquisa e Ordenacao de Dados\n");
    printf("Ciencia da Computacao - UFFS\n\n");

    lista = criaLista(size);     //mando criar o vetor com tamanho 5

    ItemLista *aux;

    printf("\n\nLista desordenada:  ");
    for (aux = lista -> head; aux != NULL; aux = aux -> prox)  printf("%d ", aux -> valor -> val);    //funcao 'printLista()'

    quickSort(lista -> head, lista -> tail);

    printf("\nLista ordenada:  ");
    for (aux = lista -> head; aux != NULL; aux = aux -> prox)  printf("%d ", aux -> valor -> val);    //funcao 'printLista()'    

    printf("\n\n");

    return 0;

}