#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ItemLista
{
    int valor;
    struct ItemLista *next;
};
typedef struct ItemLista ItemLista;

int main()
{

    ItemLista *head = NULL;
    ItemLista *aux = NULL;
    int tail;

    for (int i = 0; i < 10; i++)
    {
        aux = (ItemLista *)malloc(sizeof(ItemLista));
        aux->valor = i;
        aux->next = NULL;

        if (head == NULL)
        { //ItemLista vazia
            head = aux;
        }
        else
        { //faz encademento
            aux->next = head;
            head = aux;
        }
    }
    for (aux = head; aux != NULL; aux = aux->next)
    {
        printf("%d\n", aux->valor);
    }
    for (aux = head; aux->next != NULL; aux = aux->next)
    {
        tail = aux;
    }

    return 0;
}