#include <stdio.h>
#include "FIlaDInamica.h"

int main() {

    FilaDinamica fila;
    iniciaFila(&fila);
    Objeto x;

    x.chave=15;
    enfileira(x,&fila);
    x.chave=10;
    enfileira(x, &fila);
    x.chave=98;
    enfileira(x,&fila);
    imprimeFila(&fila);
    tamanhoFila(&fila);
    desenfileira(&fila);
    imprimeFila(&fila);
    tamanhoFila(&fila);

    return 0;
}
