#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = pai*2 + 1;
    while (filho <= fim){
        if (filho < fim) {
            if ((v[filho]) < (v[filho + 1])) {
                filho++;
            }
        }
        if (aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = pai*2 + 1;
        } else{
            filho = fim + 1;
        }
    }
    v[pai] = aux;
}

void  heapSort( int *v, int tam){
    int i, aux;

    for (int i = (tam-1)/2; i >=0 ; i--) {
        criaHeap(v, i, tam-1);
    }
    for (int i = tam-1 ; i >= 1 ; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i-1);
    }
}

int main() {

    int vetor [10] = {7,4,1,0,8,5,2,9,6,3};

    heapSort(vetor, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d", vetor[i]);
    }

    return 0;
}
