//
// Created by a2104563 on 10/09/19.
//

#ifndef UNTITLED1_FILADINAMICA_H
#define UNTITLED1_FILADINAMICA_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int chave;
    /* outros componentes */
} Objeto;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
    Objeto obj;
    PtrNoFila proximo;
} NoFila;

typedef struct {
    PtrNoFila inicio;
    PtrNoFila fim;
    int tamanho;
} FilaDinamica;

void iniciaFila(FilaDinamica *fila){
    fila->inicio=NULL;
    fila->fim=NULL;
    fila->tamanho=0;
};



int estaVazia(FilaDinamica *fila){
    return (fila->tamanho == 0);
};


void enfileira(Objeto x, FilaDinamica *fila){

    PtrNoFila aux;
    aux= (PtrNoFila)malloc(sizeof(NoFila));
    aux->obj=x;

    if (estaVazia(fila)) {
        fila->inicio = fila->fim= aux;
        aux->proximo=NULL;

    }
    else{
        aux->proximo=NULL;
        fila->fim->proximo=aux;
        fila->fim= fila->fim->proximo;
    }
    fila->tamanho++;
};

Objeto desenfileira(FilaDinamica *fila){

    if (!estaVazia(fila)){
        PtrNoFila aux;
        aux = fila->inicio;
        fila->inicio= fila->inicio->proximo;
        Objeto ret = aux->obj;
        free(aux);
        fila->tamanho--;
        return (ret);
    }
    else{
        printf("JA ESTA VAZIA \n");
    }

};

void tamanhoFila(FilaDinamica *fila){
    printf("tamanho: %d \n",fila->tamanho);
};

void imprimeFila(FilaDinamica *fila){

    if (!estaVazia(fila)){

        PtrNoFila aux;
        aux = fila->inicio;
        printf("{");

        while(aux != NULL){
            printf(" %d ", aux->obj.chave);
            aux = aux->proximo;

        }
        printf("} \n");



    } else{
        printf("A FILA ESTA VAZIA \n");
    }


};

#endif //UNTITLED1_FILADINAMICA_H
