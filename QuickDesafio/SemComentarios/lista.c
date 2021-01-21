#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int val;
} Valor;

struct ItemLista {
    Valor *valor;
    int posicao;
    struct ItemLista *prev;
    struct ItemLista *prox;
};
typedef struct ItemLista ItemLista;

typedef struct {
    ItemLista *head;
    ItemLista *tail;
} Lista;

Lista *criaLista(int size){
    
    Lista *lista = (Lista *) malloc( sizeof (Lista));
    ItemLista *first =  (ItemLista *) malloc( sizeof (ItemLista));

    first -> prev = NULL;
    first -> prox = NULL;
    first -> valor = (Valor *) malloc( sizeof (Valor));
    lista -> head = first;
 
    int PrimeiroValor, valor2;
    printf("Digite um numero para adicionar a lista: ");
    scanf("%d", &PrimeiroValor);

    first -> valor -> val = PrimeiroValor;
    first -> posicao = 0;

    ItemLista *elemento = first;  
    ItemLista *aux;

    int i = size-1;

    while(i > 0){

        aux = ( ItemLista *) malloc( sizeof (ItemLista));
        aux -> valor = (Valor *) malloc( sizeof (Valor));

        printf("Digite um numero para adicionar a lista: ");
        scanf("%d", &valor2);

        aux -> valor -> val = valor2;
        aux -> posicao = elemento -> posicao + 1;
        aux -> prev = elemento; 
        aux -> prox = NULL;
        elemento -> prox = aux; 
        elemento = aux;
        i--;
 
    }

    lista -> tail = aux;
    
    return lista;

}