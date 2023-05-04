#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main() {

    char tipo;

    FILE *entrada=NULL;
    entrada= fopen("entrada2.txt","r");
    if (entrada==NULL){
        printf("ERRO NA ENTRADA");
    }

    tipo= fgetc(entrada);
    printf("tipo:%c\n", tipo);

    Objeto y;
    Lista x;
    iniciaLista(&x);
    int numeros;

//--------------------------------------- ORDEM CRESCENTE --------------------------

    if (tipo=='c'){

        while (feof(entrada)==0){

            fscanf(entrada, "%d,", &numeros);
            y.chave= numeros;
            inserir(&x,y);
        }
        imprimirLista(&x);
    }
//--------------------------------------- ORDEM DECRESCENTE -------------------------

    if (tipo=='d') {
        while (feof(entrada) == 0) {
            fscanf(entrada, "%d,", &numeros);
            y.chave = numeros;
            inserir(&x, y);
        }
        imprimirReverso(&x);
    }
//--------------------------------------- ARQUIVO COM ERRO ---------------------------
    else{
        FILE *saida=NULL;
        saida= fopen("saida.txt", "w");
        fprintf(entrada,"ERRO!");
        fclose(saida);
    }

    fclose(entrada);

    
    return 0;
}
