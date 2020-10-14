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

int particiona(int *v, int inicio, int final)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio]; //pivo é minha posição de inicio nesse caso;

    while (esq < dir)
    {
        //enquanto a esq<dir eu ando com esq ate encontrar um elemento menor que pivo;
        while (v[esq] <= pivo)
            esq++;
        //recua posicao da direita;
        while (v[dir] > pivo)
            dir--;
        //se esquerda for menor que direita entao troca os dois de lugar;
        if (esq < dir)
        {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
        printf("%d\n", pivo);
    }
    //paro o processo quando a esquerda nao for mais menor que a direita;
    v[inicio] = v[dir]; //inicio recebe o valor aonde a direita parou;
    v[dir] = pivo;      //a posicao da direita se torna o valor do pivo;
    return dir;         //aonde parei com a direita é o ponto aonde todos antes sao menores e todos apos sao maiores;
}

void quickSort(int *v, int inicio, int fim)
//passo um vetor, o inicio e o fim dele;
{
    int pivo;
    if (fim > inicio)
    {
        //Se fim>inicio calculo o pivo usando uma função particiona;
        pivo = particiona(v, inicio, fim);
        //tendo o pivo, para os elementos antes do pivo e os elementos sequentes;
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}

int main()
{
    int v[10] = {1, 2, 34, 55, 777, 544, 55, 23, 2, 5};
    quickSort(v, 0, 9);
    return 0;
}