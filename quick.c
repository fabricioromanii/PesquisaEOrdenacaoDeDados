/*
O quicksort adota a estratégia de divisão e conquista.
A estratégia consiste em rearranjar as chaves de modo que as chaves "menores" precedam as chaves "maiores".
Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores
recursivamente até que a lista completa se encontre ordenada.

Ordenação por intercalação; 
-Map reduce (pesquisar);
Escolhe um elemento especial chamado de pivô; Com base nele, posiciono todos os elementos menores uqe ele a esquerda e todos os maiores a direita;
A partir dai fazemos uma chamada recursiva pra selecionar o pivo e dividir as listas novamente em maiores e menores;
O pivo pode ser o primeiro elemento, o ultimo, o do meio ou algum aleatório; 
Os estudos apontam que o pivo ser um elemento aleatório é melhor. 
Na disciplina vamos usar o ultimo elemento como pivo pq é mais didatico;
2º passo: separa o vetor em duas partes, esquerda com os menores que o pivo e a direita os maiores;
na 2ª interação, o pivo ja esta no lugar certo, pois seus numeros maiores e menores ja estao separados;
o merge divide a lista por 2, o quick o define o pivo na posição correta e chama apenas os vetores que estao do seu lado e repete a operação;

Melhor caso: N log N;
Pior caso (raro): N²;
estavel, nao altera a ordem de dados iguais;
A maneira como escolhe o pivo é o que afeta o desempenho;

Implementação: quickSort + particionamento;

34,65,1,2,8,9,3 // escolhe o pivo (3);
1,2,65,3,8,9,34 //o pivo vai para o lugar (k-1);
1,2,3,65,8,9,34
1,2|3|65,8,9,34 //1 chamada recursiva;
1,2|3|65,8,9,34 //faz o quick sort na parte a esquerda;
1,2,3|8,9,65,34 //comeca o quick na parte a direita;
1,2,3|8,9,65,34 //chegou no pivo, agora troca o k com o pivo;
1,2,3|8,9,34,65 //terminou o quick da parte a direita;
1,2,3,8,9,34,65 //lista ordenada;

|pivo|
$ListaOrdenada

54, 4, 6, 21, |4| // escolhe o pivo (4);
54, 4, 6, 21, |4| //começa as comparções;
54, 4, 6, 21, |4| //o numero k continua como 54, entao troca-se com o pivo;
|4| 4, 6, 21,  54  
$4, 4, 6, 21, |54| //agora, funciona como se so tivessemos uma lista de numeros maiores que o pivo inicial, entao se pega o ultimo item dessa lista e usa como pivo;
$4, 4, 6, 21,  $54   //
$4, 4, 6,|21|, $54
$4, 4, 6, $21, $54
$4, 4,|6|,$21, $54
$4,$4,$6, $21, $54

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int particionando (int *vet, int inicio, int fim) {
    int pivo = vet[inicio];
    int aux, esq, dir;
    esq = inicio + 1;
    dir = fim;
    while(esq <= dir){
        if(vet[esq] <= pivo){
            esq++;
        }
        else if (vet[dir] > pivo){
            dir--;
        }
        else if(esq <= dir){
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
            esq++;
            dir--;
        }
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

void quicksort (int *vet, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particionando (vet, inicio, fim);
        quicksort(vet, inicio, pivo-1);
        quicksort(vet, pivo+1, fim);

    }
}

void escolheTipoDoVetor (int TipoDoVetor, int *vet, int n) {
    if (TipoDoVetor == 1) {
        for (int i = 0; i < n; i++) {
            vet[i] = i+1;
        }
    }
    if (TipoDoVetor == 2) {
        int j = n;
        for (int i = 0; i < n; i++) {
            vet[i] = j;
            j--;
        }
    }
    if (TipoDoVetor == 3){
        int i;
        for (i = 0; i < n; i++){
            vet[i] = rand() % n;
        }
    }
}

void main(){
    int n;
    clock_t start,end;
    double MeuTime;
    int metodo;
    int TipoDoVetor;
    int ipo;

    printf("TAMANHO\n");
    scanf("%d", &n);
    int vet[n];
    printf("\nORDEM DO VETOR\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    printf("\n");
    scanf("%d", &TipoDoVetor);
    printf("\n");
    escolheTipoDoVetor(TipoDoVetor, vet, n);

    printf("\nDESORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    } 

    start = clock();
    
    quicksort(vet, 0, n-1);

    end = clock();

    printf("\nORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
      printf("%d ", vet[ipo]);
    }

    MeuTime = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\n(segundos): %lf\n",MeuTime);
    printf("(milisegundos): %lf\n",MeuTime*1000); 
}