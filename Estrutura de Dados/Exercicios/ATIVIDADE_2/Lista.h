//
// Created by a2104563 on 01/10/19.
//

#define UNTITLED_LISTA_H
#define UNTITLED_LISTA_H

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
bool inserir(Lista *list, Objeto x){

    PtrNoLista novo;
    novo=(PtrNoLista)malloc(sizeof(NoLista));
    novo->obj=x;
    PtrNoLista aux;

    if ((estaVazia(list)) || (x.chave < list->inicio->obj.chave)){
        novo->anterior = NULL;
        novo->proximo = list->inicio;
        list->inicio = novo;
    }
    else {
        aux = list->inicio;
        while (aux->proximo != NULL && x.chave> aux->proximo->obj.chave) {
            aux = aux->proximo;
        }
        novo->proximo= aux->proximo;
        if (aux->proximo!=NULL) {
            aux->proximo->anterior = novo;

        }
        novo->anterior= aux;
        aux->proximo = novo;
    }
    list->tamanho++;
    return (true);
};

void imprimirLista(Lista *list){
    FILE *saida=NULL;
    saida=fopen("saida.txt", "w");
    if (saida==NULL) printf("ERRO NA SAIDA");

    if (estaVazia(list)==true){
        printf("LISTA VAZIA!!");
    }
    else {
        PtrNoLista aux;

        fprintf(saida,"TAMANHO: %d \n", list->tamanho);
        printf("{");
        for (aux = list->inicio; aux != NULL; aux = aux->proximo) {
            printf("%d ", aux->obj.chave);
            fprintf(saida,"%d,", aux->obj.chave);
        }
        printf("}\n");
    }
    fclose(saida);
};

void imprimirReverso(Lista *list){
    FILE *saida=NULL;
    saida=fopen("saida.txt", "w");
    if (saida==NULL) printf("ERRO NA SAIDA");

    if (estaVazia(list)==true){
        printf("LISTA VAZIA!!");
    }
    else{
        PtrNoLista aux = list->inicio;

        while(aux->proximo != NULL){
            aux=aux->proximo;
        }
        fprintf(saida,"TAMANHO: %d \n", list->tamanho);
        printf("{");
        while (aux->anterior != NULL){
            printf("%d ", aux->obj.chave);
            fprintf(saida,"%d,", aux->obj.chave);
            aux=aux->anterior;
        }
        printf("%d",aux->obj.chave);
        fprintf(saida,"%d,", aux->obj.chave);
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

bool removePrimeiro(Lista *list, Objeto *item){
    if (estaVazia(list)==false) {
        PtrNoLista aux;
        aux = list->inicio;
        list->inicio = list->inicio->proximo;
        free(aux);
        list->tamanho--;
        return (true);
    } else{
        return (false);
    }

};
bool removeUltimo(Lista *list, Objeto *item){
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
        return (true);
    }
    else{
        printf("NAO EXISTE ELEMENTO NA LISTA!!\n");
        return (false);
    }

};

bool removeElemento(Lista *list, int x, Objeto *item){
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
    return (true);
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


#endif //UNTITLED_LISTA_H
