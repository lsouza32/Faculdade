#include <stdio.h>
#include "Arvore.h"

int main() {
    PtrArvore x;
    iniciaArvore(&x);
    Objeto y;

    y.chave = 5;
    insereItem(&x, y);
    y.chave = 1;
    insereItem(&x, y);
    y.chave=2;
    insereItem(&x, y);
    y.chave=3;
    insereItem(&x, y);
    y.chave=7;
    insereItem(&x, y);
    y.chave=15;
    insereItem(&x, y);
    y.chave=9;
    insereItem(&x, y);
    y.chave=8;
    insereItem(&x, y);
    y.chave=14;
    insereItem(&x, y);

    y.chave=2;
    removeItem(&x,y);
    preOrdem(&x);
    printf("\n");

    y.chave=8;
    removeItem(&x,y);
    preOrdem(&x);
    printf("\n");

    y.chave=15;
    removeItem(&x,y);
    preOrdem(&x);
    printf("\n");

    y.chave=5;
    removeItem(&x,y);
    preOrdem(&x);
    printf("\n");


    return 0;
}
