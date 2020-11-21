#include <stdio.h> 
#define EXIT 10

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
    while (op!=EXIT)
    {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
    }
    return op;
}

void insContact()
{
     return;
}

void delContact ()
{
     return;
}

void listContacts ()
{
     return;
}

void queryContact ()
{
     return;
}

void upContact ()
{
     return;
}

int main()
{
    int op=0;
    Contact MContact;

    while (op!=EXIT)
    {
          op=menu();
          switch(op)
          {
              case 1 : insContact();
              case 2 : delContact();
              case 3 : upContact();
              case 4 : queryContact();
              case 5 : listContacts();
          }
    }
    return 0;
}
