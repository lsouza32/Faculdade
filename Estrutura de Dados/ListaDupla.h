//
// Created by lucas on 29/09/19.
//

#ifndef UNTITLED6_LISTA_H
#define UNTITLED6_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct  {
    int chave;
} Objeto;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Objeto obj;
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int tamanho;
} Lista;

void iniciaLista(Lista *list){
    list->inicio=NULL;
    list->tamanho = 0;
};
bool estaVazia(Lista *list) {
    if (list->inicio == NULL) {
        return true;
    } else {
        return false;
    }
}
void inserir(Lista *list, Objeto x){

    PtrNoLista novo;
    novo=(PtrNoLista)malloc(sizeof(NoLista));
    novo->obj=x;
    PtrNoLista aux;

    if (estaVazia(list)==true){
        novo->proximo = list->inicio;
        novo->anterior = list->inicio;
        list->inicio= novo;
    }
    if (list->tamanho ==1){
        novo->anterior=list->inicio;
        novo->proximo=list->inicio->proximo;
        list->inicio->proximo=novo;
    }
    if (list->tamanho >1){
        aux = list->inicio;
        while (aux->proximo != NULL && x.chave> aux->obj.chave) {
            aux = aux->proximo;
        }
        novo->anterior= aux;
        novo->proximo= aux->proximo;
        aux->proximo= novo;
    }
    list->tamanho++;

};
void imprimirLista(Lista *list){
    if (estaVazia(list)==true){
        printf("LISTA VAZIA!!");
    }
    else {
        PtrNoLista aux;
        printf("{");
        for (aux = list->inicio; aux != NULL; aux = aux->proximo) {
            printf("%d ", aux->obj.chave);
        }
        printf("}\n");
    }
};

void imprimirReverso(Lista *list){
    if (estaVazia(list)==true){
        printf("LISTA VAZIA!!");
    }
    else{
        PtrNoLista aux = list->inicio;

        while(aux->proximo != NULL){
            aux=aux->proximo;
        }
        printf("{");
        while (aux->anterior != NULL){
            printf("%d ", aux->obj.chave);
            aux=aux->anterior;
        }
        printf("%d",aux->obj.chave);
        printf("}\n");
    }
};

bool pesquisar(Lista *list, int x){
    if (estaVazia(list)== true){
        return false;
    }
    PtrNoLista aux;
    aux= list->inicio;
    while (aux!=NULL && x > aux->obj.chave){
        aux= aux->proximo;
    }
    if (aux==NULL || aux->obj.chave > x){
        return false;
    }
    else {
        return true;
    }
};
int tamanhoLista(Lista *list){
    return (list->tamanho);
};

int removePrimeiro(Lista *list, Objeto *item){
    PtrNoLista aux;
    aux= list->inicio;
    list->inicio = list->inicio->proximo;
    int x = aux;
    free(aux);
    list->tamanho--;
    return(x);

};
void removeUltimo(Lista *list, Objeto *item){
    if(estaVazia(list)==false){
        if (tamanhoLista(list)==1){
            removePrimeiro(list, item);
        }
        else{
            PtrNoLista aux;
            aux = list->inicio;
            for (aux = list->inicio; aux->proximo->proximo != NULL; aux= aux->proximo) {
                PtrNoLista remove= aux->proximo;
                *item= remove->obj;
                aux->proximo = NULL;
                free(remove);
                list->tamanho--;
            }
        }
    }
    else{
        printf("NAO EXISTE ELEMENTO NA LISTA!!\n");
    }

};

void removeElemento(Lista *list, int x, Objeto *item){
    if (estaVazia(list)==true || x< list->inicio->obj.chave){
        printf("NAO EXISTE ELEMENTO NA LISTA!!\n");
    }
    else{
        if (x==list->inicio->obj.chave){
            printf("REMOVENDO O PRIMEIRO ELEMENTO... \n");
            removePrimeiro(list, item);

        }
        else {
            PtrNoLista aux = list->inicio;
            while ((aux->proximo != NULL) && (x > aux->proximo->obj.chave)) {
                aux = aux->proximo;
            }
            if ((aux->proximo==NULL)||(x<aux->proximo->obj.chave)){
                printf("NAO EXISTE ELEMENTO NA LISTA!!\n");
            }
            else{
                PtrNoLista remove = aux->proximo;
                aux->proximo= aux->proximo->proximo;
                list->tamanho--;
                free(remove);
                printf("REMOVENTO ELEMENTO...\n");
            }
        }
    }
};

bool destruirLista(Lista *list){
    PtrNoLista aux;
    PtrNoLista aux2;
    if(estaVazia(list)== true){
        return false;
    }
    else{
        aux2= list->inicio;
        while (aux2 !=NULL) {
            aux = aux2;
            aux2= aux2->proximo;
            free(aux);
            list->tamanho--;
        }
        printf("LISTA DESTRUIDA");
    }
};


#endif //UNTITLED6_LISTA_H
