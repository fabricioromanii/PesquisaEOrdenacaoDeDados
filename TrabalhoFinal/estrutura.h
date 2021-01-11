#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

struct Contact {
    char name[30];
    Date  birth; 
    char email[40];
    char phone[15];
	struct Contact *next;
};

typedef struct Contact Contact;


int menu(void);
void opcao(Contact *lista, int op);
int vazia(Contact *lista);
void salvarLista(Contact *lista);
void formataname(char name[]);
void insContact(Contact *lista);
void listContacts(Contact *lista);
void delContact(char name[] ,Contact *lista);
void queryContact(char name[],Contact *lista);
void upContact(char name[],Contact *lista);
