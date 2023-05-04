//
// Created by lucas on 14/09/19.
//

#ifndef UNTITLED5_PILHADINAMICA_H
#define UNTITLED5_PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} ObjetoD;

typedef struct NoPilha *PtrNoPilha;

typedef struct NoPilha{
    ObjetoD obj;
    PtrNoPilha proximo;
} NoPilha;

typedef struct {
    PtrNoPilha topo;
    int tamanho;
} PilhaDinamica;

void iniciaPilhaD(PilhaDinamica *p){
    p->topo=NULL;
    p->topo=0;
    p->tamanho=0;
};
bool estaVaziaD(PilhaDinamica *p){
    if(p->topo==NULL){
        return true;
    }
    else{
        return false;
    }

};
void empilhaD(ObjetoD obj, PilhaDinamica *p){
    PtrNoPilha aux;
    aux = (PtrNoPilha)malloc(sizeof(NoPilha));
    aux->obj= obj;
    aux->proximo=p->topo;
    p->topo= aux;
    p->tamanho++;
};

int desempilhaD(PilhaDinamica *p){
    if (estaVaziaD(p)==false){
        PtrNoPilha aux;
        aux = p->topo;
        p->topo=p->topo->proximo;
        int numero = aux->obj.chave;
        free(aux);
        return(numero);

    }
    else{
        return (printf("Ja ta vazia! \n"));
    }
};
int tamanhoPilhaD(PilhaDinamica *p){
    printf("Tamanho: %d \n", p->tamanho);
};
ObjetoD topoD(PilhaDinamica *p, ObjetoD *obj){
    *obj = p->topo->obj;
    return *obj;
};
void imprimePilhaD(PilhaDinamica *p){
    if (estaVaziaD(p)==false) {
        PtrNoPilha aux;
        printf("PILHA: {");
        while (aux != NULL) {
            printf(" %d ", aux->obj.chave);
            aux = aux->proximo;
        }
        printf("} \n");
    }

    else{
        printf("PILHA VAZIA! \n");
    }
};

#endif //UNTITLED5_PILHADINAMICA_H
