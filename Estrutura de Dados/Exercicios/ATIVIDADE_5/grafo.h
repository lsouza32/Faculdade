#ifndef UNTITLED_GRAFO_H
#define UNTITLED_GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Objeto;

typedef struct NoVertice *Ptrvertice;

typedef struct NoVertice {
    Objeto elemento;
    Ptrvertice adj; //fazer por matriz ou fila
    int tempoD;
    int tempoF;
    char cor;
    char *pai;
} NoVertice;

void iniciaGrafo(Ptrvertice *vertice){
    (*vertice)=NULL;
}
void inserir(Ptrvertice *vertice, Objeto x, Objeto y){
    (*vertice)= (Ptrvertice)malloc(sizeof(NoVertice));
    (*vertice)->elemento=x;
    (*vertice)->adj->elemento=y; //fazer por matriz ou fila
};
void BuscaLargura(Ptrvertice *grafo, Ptrvertice *vertice){

}


#endif //UNTITLED_GRAFO_H
