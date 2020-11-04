#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*merge sort 
separar para unir
primeiro separa a lista em dados menores
e depois de seaprados uni-los ordenadamente

[4, 7, 2, 6, 4, 1, 8, 3]
divide a lista ao meio

fica:
[4, 7, 2, 6]
[4, 1, 8, 3]

divide ao meio novamente
[4,7]
[2,6]
[4,1]//[1,4]
[8,3]//[3,8]

faz chamadas recursivas do mesmo algoritimo
passando por todas as sublistas

divide de novo
cada lista fica com um elemento
[4]
[7]
[2]
[6]
[4]
[1]
[8]
[3]
agora vem o passo merge de fato

se tenta juntar as sublistas em uma nova lista, que esteja ordenadamente

inicia a comparação de um com um
facilitando a ordenação
o menor é o da fila da direita

//new

dividir e conquistar
divide um vetor de 10 elementos 
deixando em 10 subconjuntos de 1 elemento
coombina 2 subconjuntos de dorma a obter um conjunto maior e ordenado
se repete até que exista somente um conjunto
*/

void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1=inicio;//primeiro vetor
    p2=meio+1;//segundo vetor
    temp= (int *)malloc(tamanho*sizeof(int));//novo vetor  
    if (temp != NULL){
        for (i=0; i<tamanho; i ++){
            if(!fim1 && !fim2){
                if(v[p1]< v[p2]){
                    temp[i]=v[p2++];
                }else{
                    temp[i]=v[p2++];
                }
                if(p1>meio)fim1=1;//VETOR
                if(p2>fim)fim2=1;//ACABOU?
            }else{
                if(!fim1){
                    temp[i]=v[p1++];//copiar o que sobrar
                }
                else{//copiar o que sobrar
                    temp[i]=v[p2++];//copiar o que sobrar
                }
            }
        }
        for (j=0, k=inicio; j<tamanho; j++, k++){//copiar do auxiliar para o original
            v[k]=temp[j];//pega os dados do vetor temp e joga no vetor v
        }
    }
    free (temp);
}
void mergesort(int *v, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2);//divide o vetor no meio
        mergesort(v,inicio,meio);//chma a primeira metade do vetor
        mergesort(v, meio+1,fim);//chama a segunda metade do vetor(meio+ 1 ate fim)
        merge(v, 0, meio, 100);//combina duas metades de forma ordenada
    }
}
int main (void) {
    int ipo;
    int TamanhoVetor=100;
    int v[TamanhoVetor];
    int indice=0;

    printf("\nEste eh meu vetor inicial\n");

    for(int s = TamanhoVetor; s >= 0; s--){
      v[indice] = s;
      indice++;
    }

    for (ipo = 0; ipo < 100; ipo++){
      printf("%d ", v[ipo]);
    }

    printf("\nEste eh o vetor ja ordenado com o merge sort\n");

    mergesort(v,100,0);

    for (ipo = 0; ipo < 100; ipo++){
      printf("%d ", v[ipo]);
    }

    return 0;
}