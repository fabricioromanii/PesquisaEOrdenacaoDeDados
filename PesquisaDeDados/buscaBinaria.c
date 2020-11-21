#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int A[], int n, int chave)
{
  int inicio, fim, meio;
  inicio = 0;
  fim = n-1;
  while (inicio <= fim)
  {
    meio = (inicio+fim)/2;

    if (chave == A[meio])
    {
      return meio;
    }
    if (chave < A[meio])
    {
      fim = meio-1;
    }
    else
    {
      inicio = meio+1;
    }
  }
  return -1;
}