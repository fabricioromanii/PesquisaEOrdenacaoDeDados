/*
ARVORES BINARIAS DE BUSCA (BST); 

sao projetadas para um acesso rapido a informação;
é um conjunto de registros onde cada registro é denominado de nó e satisfaz as condições:
1 - cada no possui dois elementos filhos;
-o elemento a esquerda é menor ou igual que o valor do nó e a direita é maior ao valor do nó;

int value apenas ilustra um tipo de dado simples, mas pode ser de qualuqer tipo char, double,.....;

Primeiro nó é a raiz;
Folhas sao elementos que seus filhos apontam para null;
os outros nodos nao tem definicao exata, sao chamados de nodos internos;

Para buscar, vamos comparando o nosso K(num procurado) com os nodos e dai se for menor vamos pra esquerda, se for maior vamos pra direita.
Quando vamos pra esq ou dir ja eliminamos todo o outro lado;

A altura de uma arvore é dada pela distancia da raiz ate a ultima folha;
A altura de um nó é dada pela distancia dele ate a ultima folha;
A profundidade de um nodo é a distancia dele ate a raiz; 
No caso da ultima folha, a altura dessa arvore e a profundidade desse nó sera o mesmo;

3 formas de percorrer a arvore:
Pré-order: visita a raiz, percorre a esquerda, percorre a direita;
In-order: percorre a esquerda, visita a raiz, percorre a direita;
Pós-order: percorre a esquerda, percorre a direita, visita a raiz; 

Para arvores balanceadas, a complex é log n;
para arvores desbalanceadas a complex pode chegar a ;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    typedef struct node{
        int value;
        struct node *left, *right;
    } Node;

    Node *buscaChave(Node *root, int key){

        if (root == NULL || root->value == key){
            return root;}

        if (key > root->value){
            return buscaChave(root->right, key);}
        else{
        return buscaChave(root->left, key);}
    }
    return 0;
}