#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  int TamVet;

  printf("Digite o tamanho de vetor: \n");
  scanf("%d", &TamVet);

  int bubble_vetor[TamVet];
  int OrdemVet;
  int ValorDecre = TamVet;

  printf("Escolha um numero: 1-aleatorio // 2-crescente // 3-decrescente \n");
  scanf("%d", &OrdemVet);

  if (OrdemVet == 1)
  {
    printf("ORGANIZACAO BUBBLE DA LISTA COM NUMEROS ALEATÓRIOS DE %d itens\n", TamVet);
    for (int s = 0; s < TamVet; s++)
    {
      bubble_vetor[s] = rand() % 10000;
    }
  }
  else if (OrdemVet == 2)
  {
    printf("ORGANIZACAO BUBBLE DA LISTA COM NUMEROS CRESCENTES DE %d itens\n", TamVet);
    for (int s = 0; s < TamVet; s++)
    {
      bubble_vetor[s] = s;
    }
  }
  else if (OrdemVet == 3)
  {
    printf("ORGANIZACAO BUBBLE DA LISTA COM NUMEROS DECRESCENTES DE %d itens\n", TamVet);
    for (int s = 0; s < TamVet; s++)
    {
      bubble_vetor[s] = ValorDecre;
      ValorDecre--;
    }
  }

  clock_t t;
  int comparacoes = 0;
  int trocas = 0;
  t = clock();
  for (int i = TamVet; i > 1; i--)
  {
    int flag = 0;

    for (int j = 1; j < i; j++)
    {
      comparacoes++;
      if (bubble_vetor[j - 1] > bubble_vetor[j])
      {
        int a = bubble_vetor[j];
        trocas++;
        bubble_vetor[j] = bubble_vetor[j - 1];
        bubble_vetor[j - 1] = a;
        flag = 1;
      }
    }
    if (flag == 0)
    {
      break;
    }
  }

  t = clock() - t;
  for (int o = 0; o < TamVet; o++)
  {
    printf("%d ", bubble_vetor[o]);
  }
  printf("\n");
  if (OrdemVet == 1)
  {
    printf("ORGANIZACAO BUBBLE DA LISTA COM NUMEROS ALEATÓRIO DE %d itens\n", TamVet);
  }
  else if (OrdemVet == 2)
  {
    printf("ORGANIZACAO BUBBLE DA LISTA COM NUMEROS CRESCENTES DE %d itens\n", TamVet);
  }
  else if (OrdemVet == 3)
  {
    printf("ORGANIZACAO BUBBLE DA LISTA COM NUMEROS DECRESCENTES DE %d itens\n", TamVet);
  }
  printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
  printf("Comparacoes %d \n", comparacoes);
  printf("Trocas %d\n", trocas);
  return 0;
}
