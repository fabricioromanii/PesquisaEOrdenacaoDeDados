/*
HEAP SORT;
ele vai selecionando os elementos em uma ordem desejada em uma arvore heap binaria; 2 fases: construir um heap maximo atravez da reorganizacao dos elementos do vet inicial;
2- repetidamente remover o maior elemento e posiciona0lo ao final da parte nao ordenada do vetor, garantindo que a propriedade de ser um valor maximo ou minimo continue valida para o restante dos elementos;

Semelhante as arvores;
Em um arvore binaria cada nó pode ter nenhum, 1 ou 2 filhos;
Arvore binaria cheia todo nó possui 0 ou 2 filhos;
se é cheoia o numero de nos é calculada por 2^h -1
a altura da arvore é dada por log²*(nos-1);

arvore binaria completa é cheia ate o penultimo nivel; o ultimo nivel pode estar incompleto, mas toos devem estar mais a esquerda possivel.
altura proxima dela é O(log n);

heap binario é como uma arvore binaria completa

Para mim descobrir a posicao do pai é so fazer n/2 -1;

heap minimo a raiz é sempre menor que seus filhos; o menor valor se encontra na raiz;

heap maximo: o pai é sempre maior que os filhos, raiz tem o maior valor;

interações: criar um novo no folha no ultimo nivel, na posicao mais a esquerda possivel;
verificar se a estrutura satisfaz a relacao de ordem parcial(minimo ou maximo); se compara com o elemento pai;

complexidade da insercao é O(log n);

remocao: substituir o no raiz pelo no que esta no ultimo nivel mais a esquerda possivel;
se a ordem do heap for prejudicava, realiza o processo de afuncar o elemento que esta na raiz e o troca com seu filho de maior valor ou menor;
complexidade da remocao log n;


a busca sempre é feita pelo elemento da raiz

*/