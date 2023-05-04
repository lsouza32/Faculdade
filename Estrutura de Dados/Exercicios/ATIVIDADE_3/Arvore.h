//
// Created by root on 15/10/2019.
//

#ifndef UNTITLED_ARVORE_H
#define UNTITLED_ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char *chave;
} Objeto;

typedef struct NoArvore *PtrArvore;

typedef struct NoArvore {
    Objeto elemento;
    PtrArvore esquerda;
    PtrArvore direita;
} NoArvore;

int numeroNosArvore(PtrArvore *arvore);
int alturaArvore(PtrArvore *arvore);
void iniciaArvore(PtrArvore *arvore){
    *arvore=NULL;
};
bool estaVazia(PtrArvore *arvore){
    return (*arvore==NULL);
};
bool insereItem(PtrArvore *arvore, Objeto x){

    if ((*arvore)==NULL){
        (*arvore)= (PtrArvore)malloc(sizeof(NoArvore));
        (*arvore)->elemento=x;
        (*arvore)->direita=(*arvore)->esquerda=NULL;
        (*arvore)->elemento=x;
        return (true);
    }
    if ((*arvore)->elemento.chave == x.chave){
        return (false);
    }
    if ((*arvore)->elemento.chave > x.chave){
        return (insereItem(&(*arvore)->esquerda, x));
    }
    else{
        return (insereItem(&(*arvore)->direita, x));
    }
};
void destroiArvore(PtrArvore *arvore);
void preOrdem(PtrArvore *arvore){
    if (*arvore== NULL){
        return;
    }
    else{
        printf("%s  ", (*arvore)->elemento.chave);
        preOrdem(&(*arvore)->esquerda);
        preOrdem(&(*arvore)->direita);
    }
};
void posOrdem(PtrArvore *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        posOrdem(&(*arvore)->esquerda);
        posOrdem(&(*arvore)->direita);
        printf("%d  ", (*arvore)->elemento.chave);
    }
};
void EmOrdem(PtrArvore *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        EmOrdem(&(*arvore)->esquerda);
        printf("%d  ", (*arvore)->elemento.chave);
        EmOrdem(&(*arvore)->direita);
    }

};

bool procuraItem(PtrArvore *arvore, int key, Objeto *ret){
    if ((*arvore)==NULL){
        return (false);
    }
    if ((*arvore)->elemento.chave == key){
        return (true);
    }
    if (key < (*arvore)->elemento.chave){
        return procuraItem(&(*arvore)->esquerda, key, ret);
    }
    else{
        return procuraItem(&(*arvore)->direita, key, ret);
    }
}

PtrArvore getMinAux(PtrArvore *arvore){
    //-------------------------------------------USADO NA REMOCAO-------------------------------------------------------
    PtrArvore ret;
    if ((*arvore)->esquerda == NULL){
        ret = (*arvore);
        (*arvore) = (*arvore)->direita;
        return (ret);
    }
    return (getMinAux(&(*arvore)->esquerda));
}

PtrArvore getMaxAux(PtrArvore *arvore){
    //-------------------------------------------USADO NA REMOCAO-------------------------------------------------------
    PtrArvore ret;
    if ((*arvore)->direita == NULL){
        ret = (*arvore);
        (*arvore) = (*arvore)->esquerda;
        return (ret);
    }
    return (getMaxAux(&(*arvore)->direita));
}

bool removeItem(PtrArvore *arvore, Objeto key){
    if ((*arvore)==NULL){
        printf("ARVORE ESTA VAZIA!!");
        return false;
    }
    //-----------------------------------EXISTE O ELEMENTO A REMOVER/ ATT PONTEIROS ------------------------------------
    if ((*arvore)->elemento.chave == key.chave) {
        PtrArvore temp;
        temp=(PtrArvore)malloc(sizeof(NoArvore));
        //--------------------------------------------- 1 caso (sub-arvore esq nula/ folha)-----------------------------
        if ((*arvore)->esquerda == NULL) {
            (*arvore) = (*arvore)->direita;
        }
            //----------------------------------------- 2 caso (direita nula/ folha) -----------------------------------
        else if ((*arvore)->direita == NULL) {
            (*arvore) = (*arvore)->esquerda;
        }
            //---------------------------------------------- 3 caso (raiz)----------------------------------------------
        else {
            temp = getMaxAux(&(*arvore)->esquerda);
            (*arvore)->elemento = temp->elemento;
        }
        free(temp);
        return true;
    }
    if ((*arvore)->elemento.chave > key.chave){
        return (removeItem(&(*arvore)->esquerda,key));
    } else{
        return (removeItem(&(*arvore)->direita, key));
    }
}

#endif //UNTITLED_ARVORE_H
