#include "estrutura.h"

int menu(void){
	int op;
	printf("\nEscolha a opcao:\n\n");
	printf("0 - Sair e salvar\n");
	printf("1 - Inserir contato\n");
	printf("2 - Deletar contato\n");
	printf("3 - listar contatos\n");
	printf("4 - Consultar um contato pelo name\n");
    printf("5 - Atualizar os campos de um contato\n\n");
	printf("Sua opcao: "); scanf("%d", &op);
	return op;
}


void opcao(Contact *lista, int op){
	char name[30];
	switch(op){
		case 0:
            printf("\nObrigado por usar nossa agenda!\n");
            salvarLista(lista);
            if(!vazia(lista)){
                Contact *ProximoContato,*ContatoAtual;
                ContatoAtual = lista->next;
                while(ContatoAtual != NULL){
                    ProximoContato = ContatoAtual->next;
                    free(ContatoAtual);
                    ContatoAtual = ProximoContato;
                }
	        }
            lista->next = NULL;
			break;
		case 1:
            printf("\n---------------------------------------\n");
            printf("INSERIR CONTATO\n");
            printf("---------------------------------------\n");
			insContact(lista);
			break;
		case 2:
            printf("\n---------------------------------------\n");
            printf("DELETAR CONTATO\n");
            printf("---------------------------------------\n");
			printf("Insira o name do contato a ser deletado: ");
            setbuf(stdin,NULL);
            scanf("%s",name);
            delContact(name,lista);
			break;
        case 3: 
            printf("\n---------------------------------------\n");
            printf("LISTAR CONTATOS\n");
            printf("---------------------------------------\n");
            listContacts(lista);
            break;
        case 4:
        	printf("---------------------------------------\n");
            printf("CONSULTAR CONTATO PELO NOME\n");
        	printf("---------------------------------------\n");
            printf("Digite o nome do contato a ser buscado: ");
            scanf("%s",name);
        	queryContact(name,lista);
        	break;
        case 5:
            printf("---------------------------------------\n");
            printf("ATUALIZAR OS CAMPOS DE UM CONTATO\n");
            printf("---------------------------------------\n");
            printf("Digite o nome do contato que voce deseja editar: ");
            scanf("%s", name);
            upContact(name ,lista);
            break;
		default:
			printf("\nComando invalido\n");
	}
}


void listContacts (Contact *lista){
    FILE *arq = fopen("agenda.txt","r"); //se nao existir, vai ser criado, nunca sera nulo;
    int i = 0;
    char Linha[100];
    char *result;
    printf("\n---------------------------------------\n");
    if(arq == NULL){
        printf("Arquivo NULL");
    }
    while (!feof(arq))
    {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
	  printf("%s",Linha);
      i++;
    }
    if(i<=1){
        printf("NAO HA CONTATOS\n");
    }
    printf("---------------------------------------\n");
    fclose(arq);
}


void queryContact(char name[], Contact *lista){
    formataname(name);
    Contact *minhaLista = lista;
    char novo[30];
    char *save;
    int cont = 1;

    while(minhaLista != NULL){
        save = strstr(minhaLista->name,name);
        if(save == NULL){
            minhaLista = minhaLista->next;
        }else{
            printf("\n---------------------------------------\n");
            printf("Nome: %s - Data de aniversario: %d/%d/%d - Email: %s - Telefone: %s\n", minhaLista->name, minhaLista->birth, minhaLista->email, minhaLista->phone);
            printf("---------------------------------------\n");
            cont= 0;
            return;
        }
    }
    if (cont ==1)  {
        printf("%s nao encontrado!\n",name);
    }
}


void upContact(char name[],Contact *lista){

    formataname(name);

    Contact *minhalista = lista;
    int opcaoAlterar;

    if(vazia(lista)==1){
        printf("Sua agenda esta vazia!");
    }else{
        while(minhalista){

            char *aux;
            aux = strstr(minhalista->name,name);
            char novoNome[30];
            char novoEmail[40];
            char novoPhone[15];
            int novoDia, novoMes, novoAno;

            if(aux != NULL){
                printf("O que voce deseja alterar?\n 1-Nome / 2-Aniversario / 3-Email / 4-Telefone\nSua opcao: ");
                scanf("%d", &opcaoAlterar);
                switch(opcaoAlterar){
                    case(1):
                        printf("Digite o novo nome: ");
                        scanf("%s", &novoNome);
                        formataname(novoNome);
                        snprintf(minhalista->name, sizeof(minhalista->name), "%s", novoNome);
                        break;
                    case(2):
                        printf("Digite a nova data de aniversario: ");
                        scanf("%d %d %d", &novoDia, &novoMes, &novoAno);
                        minhalista->birth.day = novoDia;
                        minhalista->birth.month = novoMes;
                        minhalista->birth.year = novoAno;
                        break;
                    case(3):
                        printf("Digite o novo email: ");
                        scanf("%s", &novoEmail);
                        snprintf(minhalista->email, sizeof(minhalista->email), "%s", novoEmail);
                        break;
                    case(4):
                        printf("Digite o novo telefone: ");
                        scanf("%s", &novoPhone);
                        snprintf(minhalista->phone, sizeof(minhalista->phone), "%s", novoPhone);
                        break;
                    default:break;
                }
            }
            minhalista = minhalista->next;
        }
    }    
}


int vazia(Contact *lista){
	if(lista->next == NULL)
		return 1;
	else
		return 0;
}


void insContact(Contact *lista){
    Contact *novo=(Contact *) malloc(sizeof(Contact));
    int i = 0;
    
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
 
    printf("\nNome: "); 
    scanf(" %s",novo->name); //pede e armazena o nome
    formataname(novo->name);
    printf("Data de aniversario (formato dia mes ano - 22 02 2001): "); //pede a data de aniversario
    scanf("%d %d %d", &novo->birth.day, &novo->birth.month, &novo->birth.year);//armazena a data de aniversario
    printf("Email: ");
    scanf("%s", novo->email);//pede e armazena o email
    printf("Telefone: ");
    scanf("%s",novo->phone);//pede e armazena o phoneefone

    novo->next = NULL;   // um novo contato é criado
    
	if(vazia(lista)){ // se a lista esta vazia, ele adiciona direto o "novo";
		lista->next = novo;
    }else{
		Contact *auxiliar = lista->next; //Contact *auxiliar recebe o proximo da lista
		Contact *ant = lista; //

        int cont = 0;
        Contact *aux;
        aux = lista->next;
        while(aux != NULL){
            cont++;
            aux = aux->next;
        }

        if(cont == 1){    // no caso de ter um Contact,
			if(strcmp(auxiliar->name,novo->name) > 0){ //verifica a ordem alfabetica
                novo->next = auxiliar;
				ant->next = novo;
				return;
			}
			auxiliar->next = novo;
			return;
		}
        
		do{ // caso tenha mais de um Contact insere o novo ja ordenado
			if(strcmp(auxiliar->name,novo->name) > 0){
				novo->next = auxiliar;
				ant->next = novo;
				return;
			}
			ant = ant->next;
			auxiliar = auxiliar->next;
		}while( auxiliar->next != NULL  ||  novo->next != NULL);

        if(strcmp(auxiliar->name,novo->name) > 0){
            ant->next = novo;
            novo->next = auxiliar;
            return;
        }
		auxiliar->next = novo; //insere novo Contact caso ele esteja na ultima posicao
	}
}


void salvarLista(Contact *lista){
    FILE *arq = fopen("agenda.txt","w"); //se nao existir, vai ser criado, nunca sera nulo;
    Contact *auxiliar;
    auxiliar = lista->next;
    Contact c;

    if(arq == NULL){
        printf("Arquivo NULL!");
        exit(1);
    }
    
    while(auxiliar != NULL){
        strcpy(c.name,auxiliar->name);
        c.birth = auxiliar->birth;
        strcpy(c.email,auxiliar->email);
        strcpy(c.phone,auxiliar->phone);
        fprintf(arq,"Nome: %s - Data de aniversario: %d/%d/%d - Email: %s - Telefone: %s\n", c.name, c.birth, c.email, c.phone);
        auxiliar = auxiliar-> next;
    }
    fclose(arq);
}


void delContact(char *name, Contact *lista){
    Contact *minhaLista = lista;
    Contact *minhaListaNext = lista->next;
    formataname(name);

    if (minhaLista->next == NULL){
        printf("Lista vazia!");
    }
    
    while(minhaListaNext != NULL && strcmp(minhaListaNext->name,name) != 0){
        minhaLista = minhaListaNext;
        minhaListaNext = minhaListaNext->next;
    }
    if(strcmp (name, minhaListaNext->name) == 0){
        minhaLista->next = minhaListaNext->next;
        printf("%s foi excluido!",name);
    }else{
        printf("%s nao foi encontrado!",name);
    }
}


void formataname(char name[]){
    int i = 0;
    while(i < strlen(name)){// Formatar o name ex: JoAo -> Joao, paula-> Paula
		name[i] = tolower(name[i]);
		if(i == 0 || name[i-1] == ' '){
			name[i] = toupper(name[i]);
		}
		i++;
	}
}