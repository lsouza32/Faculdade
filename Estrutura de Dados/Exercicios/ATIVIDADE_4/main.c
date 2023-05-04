#include <stdio.h>
#include <string.h>
#include "Avl.h"

int main() {
    FILE *entrada= NULL;
    entrada = fopen("entrada.txt", "r");
    if (entrada== NULL){
        printf("ERRO AO ABRIR ARQUIVO DE ENTRADA");
        return 1;
    }
    FILE *saida=NULL;
    saida= fopen("saida.txt","w");

    PtrArvoreAVL x;
    iniciaArvoreAVL(&x);
    Objeto y;

    char linha1[1000];
    char linha2[1000];

    fgets(linha1, sizeof(linha1), entrada);
    fgets(linha2, sizeof(linha2), entrada);

    char *token=NULL;
    token = strtok(linha1, ",");
    int num_inserir=0;
//------------------------------------------------------INSERIR---------------------------------------------------------
    while (token != NULL){
        num_inserir= atoi(token);
        y.chave= num_inserir;
        inserirArvoreAVL(&x,y);
        token= strtok(NULL,",");
    }
    fprintf(saida,"[*]antes\n");
    imprimeArvoreAVLNivel(&x, saida);
    preOrdem(&x);
    printf("\n");

//-------------------------------------------------------REMOVER--------------------------------------------------------
    int num_remover=0;
    char *token2=NULL;
    token2 = strtok(linha2, ",");

    while (token2 !=NULL){
        num_remover= atoi(token2);
        y.chave= num_remover;
        remover(&x,y);
        token2=strtok(NULL,",");
    }
    preOrdem(&x);
    printf("\n");
    printf("\n");
    printf("\n");

    fprintf(saida,"\n[*]depois\n");
    imprimeArvoreAVLNivel(&x,saida);

    fclose(entrada);
    fclose(saida);


    return 0;
}