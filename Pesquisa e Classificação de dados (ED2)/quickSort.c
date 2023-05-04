#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int particiona(int *v, int inicio, int fim){
    int troca;
    int cont = inicio;

    for (int i = inicio+1; i <= fim ; i++) {
        if (v[i]< v[inicio]){
            cont++;
            troca= v[i];
            v[i]= v[cont];
            v[cont]= troca;
        }
    }
    troca = v[inicio];
    v[inicio]= v[cont];
    v[cont]= troca;

    return cont;
}

void quickSort(int *v, int inicio, int fim){
    int pivo;

    if (inicio < fim){
        pivo = particiona(v, inicio,fim);
        quickSort(v, inicio,pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

int main() {

    int vetor [10] = {7,4,1,0,8,5,2,9,6,3};

    quickSort(vetor, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d", vetor[i]);
    }

    return 0;
}
