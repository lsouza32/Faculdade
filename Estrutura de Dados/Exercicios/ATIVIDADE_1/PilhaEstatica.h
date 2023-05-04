//
// Created by lucas on 14/09/19.
//

#ifndef UNTITLED5_PILHAESTATICA_H
#define UNTITLED5_PILHAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 100


typedef struct {
    int chave;

} ObjetoE;

typedef struct {
    ObjetoE array[MAXTAM];
    int topo;
} pilhaEstatica;

void iniciaPilhaE(pilhaEstatica *pilha){
    pilha->topo=0;
};

bool estaVaziaE(pilhaEstatica *pilha){
    if (pilha->topo==0){
        return true;
    }
    else{
        return false;
    }
};
bool estaCheiaE(pilhaEstatica *pilha){
    if (pilha->topo==MAXTAM){
        return true;
    }
    else{
        return false;
    }
} ;

void empilhaE( ObjetoE item, pilhaEstatica *pilha){
    if (estaCheiaE(pilha)==false){
        pilha->array[pilha->topo]=item;
        pilha->topo = pilha->topo+1;

    }
    else{
        printf("A PILHA JA ESTA CHEIA");
    }
};

ObjetoE desempilhaE(pilhaEstatica *pilha){
    if (estaVaziaE(pilha)==false){

        ObjetoE item= pilha->array[pilha->topo-1];
        pilha->topo = pilha->topo-1;
        return (item);
    }
    else{
        printf("A PILHA JA ESTA VAZIA");
    }
};
int tamanhoPilhaE(pilhaEstatica *pilha){
    return (pilha->topo);
};

void imprimePilhaE(pilhaEstatica *pilha){
    for (int i = 0; i <pilha->topo ; i++) {
        printf("%d", pilha->array[i].chave);
    }
};

#endif //UNTITLED5_PILHAESTATICA_H
