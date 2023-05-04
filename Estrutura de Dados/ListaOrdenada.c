#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"

int main() {

    Objeto y;
    Lista x;
    iniciaLista(&x);
    int c;

    y.chave = 98;
    inserir(&x,y);
    y.chave=15;
    inserir(&x,y);
    y.chave=10;
    inserir(&x,y);
    imprimirLista(&x);


    removeElemento(&x,10, &y);
    imprimirLista(&x);

    removeElemento(&x,98,&y);
    imprimirLista(&x);

    removeElemento(&x, 15, &y);
    imprimirLista(&x);




    return 0;
}