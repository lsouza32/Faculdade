#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *v , int inicio, int meio, int fim){
    int *temp;
    int p1, p2, tamanho, i ,j ,k;

    tamanho = fim-inicio+1;
    p1= inicio;
    p2= meio+1;
    temp= (int*) malloc(tamanho*sizeof(int));

    if(temp != NULL){
        for (i = 0; i < tamanho; i++){
            if ((p1<= meio) && (p2<= fim)){
                if (v[p1] < v[p2]){
                    temp[i]= v[p1++];
                } else{
                    temp[i]= v[p2++];
                }
            } else{
                if (p1<= meio){
                    temp[i]= v[p1++];
                } else{
                    temp[i]= v[p2++];
                }
            }
        }
        k=inicio;
        for (j= 0; j<tamanho; j++){
            v[k] = temp [j];
            k++;
        }
    }
    free(temp);
}

void mergeSort(int *v, int inicio, int fim){
    int meio;
    if (inicio< fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio,meio,fim);
    }
}

int main() {

    int vetor [10] = {7,4,1,0,8,5,2,9,6,3};

    mergeSort(vetor,0, 9 );

    for (int i = 0; i < 10; i++) {
        printf("%d", vetor[i]);
    }

    return 0;
}
