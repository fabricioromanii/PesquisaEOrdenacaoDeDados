#include "quick.c" 

int main(){

    Lista *lista;
    int size = 5;

    printf("\nFabricio Romani - Pesquisa e Ordenacao de Dados\n");
    printf("Ciencia da Computacao - UFFS\n\n");

    lista = criaLista(size);

    ItemLista *aux;

    printf("\n\nLista desordenada:  ");
    for (aux = lista -> head; aux != NULL; aux = aux -> prox)  printf("%d ", aux -> valor -> val);

    quickSort(lista -> head, lista -> tail);

    printf("\nLista ordenada:  ");
    for (aux = lista -> head; aux != NULL; aux = aux -> prox)  printf("%d ", aux -> valor -> val); 

    printf("\n\n");

    return 0;

}