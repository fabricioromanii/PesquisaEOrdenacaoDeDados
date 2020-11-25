void geraVetorCrescente (int *vet , int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = i+1;
    }
}

void geraVetorDecrescente (int *vet , int n) {
    int j = n;
    for (int i = 0; i < n; i++) {
        vet[i] = j;
        j--;
    }
}

void geraVetorAleatorio (int *vet, int n, int num) {
    int i;
    for (i = 0; i < n; i++){
        vet[i] = rand() % num;
        
    }
}

void escolheTipoVet (int tipovet, int *vet, int n, int num) {
    if (tipovet == 1) {
            geraVetorCrescente(vet, n);
        }
        else if (tipovet == 2) {
            geraVetorDecrescente(vet, n);
        }
        else if (tipovet == 3){
            geraVetorAleatorio(vet, n, num);
        }
}

void sort (int metodo, int *vet, int n) {
    if (metodo == 1) {        
        mergesort(vet, 0, n-1);  
    }
    else if (metodo == 2) {
        quicksort(vet, 0, n-1);
    }
    else if (metodo == 3) {
        heapsort (vet, n);
    }
}

void print (int *vet, int n, int mod) {
    if (mod == 0) {
        printf("\nValore desordenados ");
        for(int q=0;q<n;q++){
            printf("%d ",vet[q]);
        }
    } else {
        printf("\nValore ordenados ");
        for(int q=0;q<n;q++){
            printf("%d ",vet[q]);
        }
        printf("\n");
    }
 }
