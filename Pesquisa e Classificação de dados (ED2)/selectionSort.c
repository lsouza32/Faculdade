#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *V, int n){
    int menor, aux, i, j = 0;
    int fim, indice;
    
    fim= n;
    
    for(i=0; i<fim; i++){
        menor= i;
        for(j=i; j<fim; j++){
            if(V[menor]>V[j]){
                menor =j;
            }
        }
        
        if(i != menor){
            aux = V[i];
            V[i]= V[menor];
            V[menor]= aux;
        }
    }
}
  

int main(){
    
    int vetor [10] = {7,4,1,0,8,5,2,9,6,3};
    
    selectionSort(vetor,10);
    
    for (size_t i= 0;i<10; i++){
        printf("%i", vetor[i]);
    }

  return 0;
}
