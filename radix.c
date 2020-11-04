/*
RADIX SORT

Ordena baseado nos digitos do numero, e nao mais no numero inteiro;
Nao realiza comparações. Se utilixa do tecnica do Counting Sort;
Counting sort se baseia em contagem;

A chave é decoposta e tratada por partes;
A chave é analisada do digito amis relevante para o menos, ou do menos para o mais;

Criado para ordenar cartoes perfurados;

Radix pode ser usado para string, numeros, etc...

O counting sort seleciona o maior elemento do vetor a ser ordenado;
com base nesse numero, crio um outro vetor com o tamanho desse maior elemento;
zero todo esse vetor;
vou usar om for para ler cada um das minhas posicoes do primeiro vetor
VOu acessar a posicao do vetor auxiliar que tenha aquela mesma posicao do outro vetor;
vou pegar na posicao do 0 do primeiro vetor, o elemento que esta la, e ir para a posicao que for = a esse numero;
o valor do vetor é o indice no outro vetor

agora vou andar em cima do outro vetor; vou imprimindo os valores no numero de vezes que é seu indice

vet     1|2|4
vetaux  0|0|0|0 --maior numero do vet é meu tamanho;

Agora vou pegar os valores do vet, e ver aquele mesmo valor no meu indice;

vetaux 1|1|0|1| -- quando meu numero em vet for 1, vou botar 1 no meu indice 1
                --quando meu numero em vet for 2 vou por 1 no indice 2
|1|2|4|         --Agora vou pegar um vetor multiplicando o indice pelo seu valor
                

tenho que verificar o numero de digitos tambem;

vou fazer a mesma coisa considerando apenas o ultimo digito, depois considero apenas o primeiro;

vet 8|2|9|1|3
vetaux|0|0|0|0|0|0|0|0 - 9 é o numero maior, 9 posicoes

vetaux |0|0|0|0|0|0|0|1|0 - posicao 8 = 1
vetaux |0|1|0|0|0|0|0|1|0 - posicao 2 = 2
vetaux |0|1|0|0|0|0|0|1|1 - posicao 9 = 1
vetaux |1|1|1|0|0|0|0|1|1 - posicao 1 = 1
vetaux |1|1|1|0|0|0|0|1|1 - posicao 3 = 1

agora vai ser o indice vezes o valor
vetaux = 1|2|3|8|9

vet = 45|34|21|02|90
vetaux = 0|0|0|0|0|0|0|0|0| - maior numero  é 9(considerando um digito por vez)= tamanho;

complexidade linear independente da ordenacao da entrada;
estavel;

CONSIDERANDO O ULTIMO NUMERO
vet = 45|34|21|02|90
vet aux = 0|0|0|0|1|0|0|0|0 -- posicao 5 = 1
vet aux = 0|0|0|1|1|0|0|0|0 -- posicao 4 = 1
vet aux = 1|0|0|1|1|0|0|0|0 -- posicao 1 = 1
vet aux = 1|1|0|1|1|0|0|0|0 -- posicao 2 = 1
vet aux = 1|1|0|1|1|0|0|0|0 -- posicao 0 = 1
vet aux = 90|21|02|34|45

CONSIDERANDO O PRIMEIRO NUMERO

....

*/
