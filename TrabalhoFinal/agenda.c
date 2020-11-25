#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

struct MREC {
     char name[30];
     Date  birth; 
     char email[40];
     char phone[15];
	struct MREC *next;
	struct MREC *prev;
};
typedef struct MREC Contact;

int menu()
{
    int op=0;
    
     printf("Escolha uma opcao:\n");
     printf("|1| Inserir contato\n|2| Deletar contato\n|3| Listar todos os contatos\n|4| Pesquisar contato\n|5| Atualizar contato\n");
     scanf("%d",&op);
    
    return op;
}
void insContact()
{
     printf("INSERIR CONTATO\n");
     return;
}
void delContact ()
{
     printf("DELETAR CONTATO\n");
     return;
}
void listContacts ()
{
     printf("LISTAR CONTATOS\n");
     return;
}
void queryContact ()
{
     printf("PESQUISAR CONTATO\n");
     return;
}
void upContact ()
{
     printf("ATUALIZAR CONTATO\n");
     return;
}
int main()
{
    int op=0;
    Contact MContact;

     FILE *agenda;
     agenda = fopen("Agenda.txt","a");

     op=menu();
     printf("OPCAO %d: ",op);
     switch(op)
     {
          case 1 : insContact();break;
          case 2 : delContact();break;
          case 3 : listContacts();break;
          case 4 : queryContact();break;
          case 5 : upContact();break;
     }
     
    fclose(agenda);
    return 0;
}
