#include "lista.c" 

void swap( ItemLista *a, ItemLista *b ){

    ItemLista *proximaA, *anteriorA;
    
    int posicaoA;

    if (a == b){
        return;
    }

    Valor *aux = a -> valor;
    a -> valor = b -> valor;
    b -> valor = aux;

}


void quickSort( ItemLista *inicio, ItemLista *fim){

    if (inicio -> posicao < fim -> posicao){

        ItemLista *a = inicio;            
        ItemLista *b = inicio;
        ItemLista *PivoAtual = fim;
                                    
        for(b; b != fim; b = b -> prox){

            if(b -> valor -> val <= PivoAtual -> valor -> val){
                swap(a,b);
                a = a -> prox;
            }

        } 

        if(a -> valor -> val > PivoAtual -> valor -> val) swap(a, PivoAtual);
        
        ItemLista *PivoNovo = a;

        if(PivoNovo -> prev != NULL) quickSort(inicio, PivoNovo -> prev);
        
        if(PivoNovo -> prox != NULL) quickSort(PivoNovo -> prox, fim);
            
    }

}