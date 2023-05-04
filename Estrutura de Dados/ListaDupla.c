#include <stdio.h>
#include "Lista.h"

int main() {

    Objeto y;
    Lista x;
    iniciaLista(&x);

    y.chave = 1;
    inserir(&x,y);
    y.chave=2;
    inserir(&x,y);
    y.chave=3;
    inserir(&x,y);
    y.chave=4;
    inserir(&x,y);
    y.chave=5;
    inserir(&x,y);
    imprimirLista(&x);
    imprimirReverso(&x);


//    removeElemento(&x,10, &y);
//    imprimirLista(&x);
//
//    removeElemento(&x,98,&y);
//    imprimirLista(&x);
//
//    removeElemento(&x, 15, &y);
//    imprimirLista(&x);



    return 0;
}