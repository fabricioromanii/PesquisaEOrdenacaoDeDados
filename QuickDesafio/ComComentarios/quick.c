#include "lista.c" 

void swap( ItemLista *a, ItemLista *b ){

    ItemLista *proximaA, *anteriorA;
    
    int posicaoA;

    if (a == b){       // isso aqui deixa o quick estavel, nao troca o valor se for =
        return;
    }

    Valor *aux = a -> valor;
    a -> valor = b -> valor;
    b -> valor = aux;

}


void quickSort( ItemLista *inicio, ItemLista *fim){

    if (inicio -> posicao < fim -> posicao){                                    //começamos com duas chaves olhando para o inicio; Meu pivo sera a ultima posicao

        ItemLista *a = inicio;                                                  //vou comecar a comparar os meus elementos do inicio da lista, mas sem fazer swap ainda
        ItemLista *b = inicio;
        ItemLista *PivoAtual = fim;                                             //aponta para meu pivo
                                    
        for(b; b != fim; b = b -> prox){                                        //enquanto meu i nao chegar ao fim, i -> prox

            if(b -> valor -> val <= PivoAtual -> valor -> val){                 //se o valor que eu estou comparando no inicio for maior que o meu pivo, ele ignora e passaa para frente pra testar o proximo
                swap(a,b);                                                      //se eu encontrar um valor menor que o pivo, eu vou trocar de lugar com o meu k e o i. o k vai avançando pra frente
                a = a -> prox;                                                  //entre as minhas chaves k e i eu terei os numeros maiores que o pivo; antes de i eu terei os menores que o pivo.
            }

        } 

        if(a -> valor -> val > PivoAtual -> valor -> val) swap(a, PivoAtual);            //Isso aqui é pra fazer meu pivo ir pra posicao correta,
                                                                                         //vou passar novamente as duas sublistas pelo quick sort ; A lista a direita do pivo e a esquerda
        ItemLista *PivoNovo = a;                                                         //Meu pivo agora vai ser o item da lista que ja esta ordenado
                                                                                         //vou passar como parametro o prev do item ordenado e o prox
        if(PivoNovo -> prev != NULL) quickSort(inicio, PivoNovo -> prev);                //Aqui seria como se fosse a lista do inicio ate o item ordenado
        
        if(PivoNovo -> prox != NULL) quickSort(PivoNovo -> prox, fim);                   //Aqui seria como se fosse a sublista a do item ordenado ate o final
            
    }

}