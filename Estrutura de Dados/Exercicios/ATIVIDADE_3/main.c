#include <stdio.h>
#include <string.h>
#include "Arvore.h"
#include "LIsta.h"

int main() {
    PtrArvore x;
    iniciaArvore(&x);
    Objeto y;


    Lista z;
    iniciaLista(&z);
    ObjetoLista m;



    FILE *entrada=NULL;
    entrada= fopen("/home/todos/alunos/ap/a2104563/Downloads/entrada2.txt", "r");
    if (entrada==NULL){
        printf("ERRO AO ABRIR ARQUIVO!!");
        return 1;
    }

    char texto[50];
    const char virgula[4]= ", >";
    char *token;
    int page=0;

    fscanf(entrada,"<termos:%s",texto);
    token= strtok(texto,virgula);

    while (token != NULL){
        //printf("%s \n", token);
        y.chave= token;
        insereItem(&x,y);

        m.chave= token;
        inserir(&z,m);


        token= strtok(NULL,virgula);

    }

    preOrdem(&x);
    printf("\n");

    imprimirLista(&z);

    //-------------- PRECISA DE FILA PARA IMPRIMIR OS NO (IMPRESAO EM NÓ)-----------------------------------------------





    fclose(entrada);

    return 0;
}
