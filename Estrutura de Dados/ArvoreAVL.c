#include <stdio.h>
#include "ArvoreAVL.h"

int main() {
    PtrArvoreAVL x;
    iniciaArvoreAVL(&x);
    Objeto y;

    y.chave = 5;
    inserirArvoreAVL(&x, y);
    y.chave = 1;
    inserirArvoreAVL(&x, y);
    y.chave=2;
    inserirArvoreAVL(&x, y);
    y.chave=3;
    inserirArvoreAVL(&x, y);
    y.chave=7;
    inserirArvoreAVL(&x, y);
    y.chave=15;
    inserirArvoreAVL(&x, y);
    y.chave=9;
    inserirArvoreAVL(&x, y);
    y.chave=8;
    inserirArvoreAVL(&x, y);
    y.chave=14;
    inserirArvoreAVL(&x, y);


    preOrdem(&x);
    printf("\n");


    return 0;
}
