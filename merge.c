/*
um dos metodos mais usados;

Pega duas coisas e junta elas, duas listas ordenadas formam uma só;

Merge = juntar/misturar/intercalar;

Metodos que usam estratégias mais sofisticadas e eficientes;

Algoritimo do tipo divisao e conquisa; trabalha em decompor o problema 
em instancias cada vez menores do mesmo tipo de problema, resolve elas 
(em geral, recursivamente), e por fim combinar as soluções parciais para 
obter a solução do problema como um todo;

Ideia geral é dividir o vetor em duas partes;
depois disso ordena recursivamente cada parte, 
e depois intercala elas formando um novo segmento ordenado;

as duas listas finais que se se comparam ja sao ordenadas, porque passaram por varias comparações;

quando é lista com n elementos impar, o elemento do meio fica na primeira parte e a segunda é definida apartir de meio+1;

comparações n log n

Este algoritmo necessita de memoria auxiliar, nao é um algoritmo in place;

4,2,1,6,8,5,7,3
4,2,1,6|8,5,7,3
4,2|1,6|8,5|7,3
2,4|1,6|
se compara a [0] de cada vetor e leva ao vetor ordenado
1,2|4,6|
1,2,4,6|8,5|7,3
1,2,4,6|5,8|3,7
1,2,4,6|3,5,7,8
se compara a [0] de cada vetor e leva ao vetor ordenado
1,2,3,4,5,6,7,8


30,21,43,3,9,82,15
21,30|4,43|9,82|15
3,21,30,43|9,15,82
3,9,15,21,30,43,82

*/
#include <stdio.h>
#include <stdlib.h>
