#include <stdio.h>

void insertionSort(int *v, int tam){
    int atual;
    int j;
    for(int i= 1; i< tam; i++){
        atual = v[i];
        for(j= i; (j>0) && (atual <v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = atual;
    }
}

int main() {

    int vetor [10] = {7,4,1,0,8,5,2,9,6,3};

    insertionSort(vetor, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d", vetor[i]);
    }

    return 0;
}
