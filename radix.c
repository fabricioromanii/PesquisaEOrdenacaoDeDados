#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void radixsort(int *vetor, int n) {
	int i, expo = 1, xx, vetux[n], temp[n];

	for(i = 0; i < n; i++) {
		if(vetor[i] > xx) {
			xx = vetor[i];
		}
	}

	while((xx/expo) > 0) {
		for (i = 0; i < n; i++) {
			vetux[i] = 0;
		}
		for(i = 0; i < n; i++) {
			vetux[(vetor[i] / expo) % 10]++;
		}
		for(i = 1; i < n; i++) {
			vetux[i] += vetux[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			temp[--vetux[(vetor[i] / expo) % 10]] = vetor[i];
		}
		for(i = 0; i < n; i++) {
			vetor[i] = temp[i];
		}
		expo *= 10;
	}
}

void escolheTipoDoVetor (int TipoDoVetor, int *vetor, int n) {
    if (TipoDoVetor == 1) {
        for (int i = 0; i < n; i++) {
            vetor[i] = i+1;
        }
    }
    if (TipoDoVetor == 2) {
        int j = n;
        for (int i = 0; i < n; i++) {
            vetor[i] = j;
            j--;
        }
    }
    if (TipoDoVetor == 3){
        int i;
        for (i = 0; i < n; i++){
            vetor[i] = rand() % n;
        }
    }
}

int main() {
    clock_t start,end;
    double MeuTime;
    int ipo, n, i, metodo, TipoDoVetor;
   
    printf("TAMANHO DO VETOR\n");
    scanf("%d", &n);
    int vetor[n];
        
    printf("\nORDEM DO VETOR\n|1 - Crescente| |2 - Decrescente| |3 - Aleatorio| \n");
    scanf("%d", &TipoDoVetor);
    escolheTipoDoVetor (TipoDoVetor, vetor, n);

    printf("\nDESORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
        printf("%d ", vetor[ipo]);
    }

    start = clock();
    radixsort(vetor,n);
    end = clock();

    printf("\nORDENADO\n");
    for (ipo = 0; ipo < n; ipo++){
        printf("%d ", vetor[ipo]);
    }

    MeuTime = ((double)end - start)/CLOCKS_PER_SEC;

    printf("\n(tempo em segundos): %lf\n",MeuTime);
    printf("(tempo em milisegundos): %lf\n",MeuTime*1000);

    return(0);
}