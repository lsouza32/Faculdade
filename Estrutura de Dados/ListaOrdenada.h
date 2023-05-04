// Created by a2104563 on 17/09/19.
//

#ifndef UNTITLED_LISTAORDENADA_H
#define UNTITLED_LISTAORDENADA_H

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

    if ((estaVazia(list)==true) || (x.chave<list->inicio->obj.chave)){
        novo->proximo = list->inicio;
        list->inicio= novo;
    }
    else{
        PtrNoLista aux;
        aux = list->inicio;
        while (aux->proximo != NULL && x.chave> aux->obj.chave) {
            aux = aux->proximo;
        }
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
        for (aux = list->inicio; aux != NULL; aux = aux->proximo) {
            printf("%d\n", aux->obj.chave);
        }
        printf("\n");
    }
};
void destruirLista(Lista *list){

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
                printf("ELEMENTO %d REMOVIDO \n", (*item).chave);
                list->tamanho--;
            }
        }
    }
    else{
        printf("NAO EXISTE ELEMENTO NA LISTA!!\n");
    }

};

/*Objeto primeiro(Lista *list){
    Objeto aux= list->inicio->obj;
    return(aux);
};
Objeto ultimo(Lista *list);
*/
void removeElemento(Lista *list, int x, Objeto *item){
    if (estaVazia(list)==true || x< list->inicio->obj.chave){
        printf("NAO EXISTE ELEMENTO NA LISTA!!\n");
    }
    else{
        if (x==list->inicio->obj.chave){
            printf("REMOVENDO O PRIMEIRO ELEMENTO... \n");
            removePrimeiro(list, item);
            //printf("ELEMENTO %d REMOVIDO \n", (*item).chave);
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


#endif //UNTITLED_LISTAORDENADA_H