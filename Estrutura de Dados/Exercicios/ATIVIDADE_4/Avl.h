#ifndef ATVAVL_AVL_H
#define ATVAVL_AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Objeto;

typedef struct NoArvoreAVL *PtrArvoreAVL;

typedef struct NoArvoreAVL {
    Objeto elemento;
    PtrArvoreAVL esquerda;
    PtrArvoreAVL direita;
    int altura;
} NoArvoreAVL;

void iniciaArvoreAVL(PtrArvoreAVL *arvore){
    *arvore=NULL;
}
bool estaVaziaArvoreAVL(PtrArvoreAVL *arvore){
    return ((*arvore)==NULL);
}
void preOrdem(PtrArvoreAVL *arvore){
    if (*arvore== NULL){
        return;
    }
    else{
        printf("%d  ", (*arvore)->elemento.chave);
        preOrdem(&(*arvore)->esquerda);
        preOrdem(&(*arvore)->direita);
    }
}
void posOrdem(PtrArvoreAVL *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        posOrdem(&(*arvore)->esquerda);
        posOrdem(&(*arvore)->direita);
        printf("%d  ", (*arvore)->elemento.chave);
    }
}
void EmOrdem(PtrArvoreAVL *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        EmOrdem(&(*arvore)->esquerda);
        printf("%d  ", (*arvore)->elemento.chave);
        EmOrdem(&(*arvore)->direita);
    }
}
int alturaArvoreAVL(PtrArvoreAVL *arvore){
    if((*arvore) == NULL){
        return 0;
    }else{
        int D, E;
        E = alturaArvoreAVL(&(*arvore)->esquerda);
        D = alturaArvoreAVL(&(*arvore)->direita);
        if(E > D){
            return (E+1);
        }else{
            return (D+1);
        }
    }
}
int atualizaAlturaArvoreAVL(PtrArvoreAVL *arvore){
    if((*arvore)== NULL){
        return false;
    }else{
        (*arvore)->altura = alturaArvoreAVL(arvore);
        atualizaAlturaArvoreAVL(&(*arvore)->direita);
        atualizaAlturaArvoreAVL(&(*arvore)->esquerda);
        return true;
    }
}
void RSimpDir(PtrArvoreAVL *arvore){
    PtrArvoreAVL u;
    u = (*arvore)->esquerda;
    (*arvore)->esquerda = u->direita;
    u->direita = (*arvore);
    atualizaAlturaArvoreAVL(&u);
    atualizaAlturaArvoreAVL(arvore);
    (*arvore) = u;
}
void RSimpEsq(PtrArvoreAVL *arvore){
    PtrArvoreAVL u;
    u=(*arvore)->direita;
    (*arvore)->direita=u->esquerda;
    u->esquerda= (*arvore);
    atualizaAlturaArvoreAVL(&u);
    atualizaAlturaArvoreAVL(arvore);
    (*arvore)= u;
}
void RDuplaEsq(PtrArvoreAVL *arvore){
    PtrArvoreAVL v;
    PtrArvoreAVL u;
    u = (*arvore)->direita;
    v = u->esquerda;
    (*arvore)->direita = v->esquerda;
    u->esquerda = v->direita;
    v->direita = u;
    v->esquerda = (*arvore);
    atualizaAlturaArvoreAVL(&u);
    atualizaAlturaArvoreAVL(&v);
    atualizaAlturaArvoreAVL(arvore);
    (*arvore)= v;
}
void RDuplaDir(PtrArvoreAVL *arvore) {
    PtrArvoreAVL u;
    PtrArvoreAVL v;
    u = (*arvore)->esquerda;
    v = u->direita;
    u->direita = v->esquerda;
    (*arvore)->esquerda = v->direita;
    v->direita = (*arvore);
    v->esquerda = u;
    atualizaAlturaArvoreAVL(&u);
    atualizaAlturaArvoreAVL(&v);
    atualizaAlturaArvoreAVL(arvore);
    (*arvore) = v;
}
void aplicarRotacoes(PtrArvoreAVL *arvore){
    int hdir, hesq, bf;
    hdir= alturaArvoreAVL(&(*arvore)->direita);
    hesq= alturaArvoreAVL(&(*arvore)->esquerda);
    bf = hdir - hesq;

    if (bf == 2){
        if (alturaArvoreAVL(&(*arvore)->direita->esquerda) > (alturaArvoreAVL(&(*arvore)->direita->direita))){
            printf("ROTAÇÃO DUPLA P/ ESQUERDA...\n");
            RDuplaEsq(&(*arvore));
            }
        else{
            printf("ROTAÇÃO SIMPLES P/ ESQUERDA...\n");
            RSimpEsq(&(*arvore));
        }
    }
    if (bf == -2){
        if (alturaArvoreAVL(&(*arvore)->esquerda->esquerda) >= (alturaArvoreAVL(&(*arvore)->esquerda->direita))){
            printf("ROTAÇÃO SIMPLES P/ DIREITA...\n");
            RSimpDir(&(*arvore));
        }
        else{
            printf("ROTAÇÃO DUPLA P/ DIREITA...\n");
            RDuplaDir(&(*arvore));
            }
        }
}
bool inserirArvoreAVL(PtrArvoreAVL *arvore, Objeto x){
    bool aux=0;
    printf("Inserindo: %d\n", x.chave);
    if ((*arvore)==NULL){
        (*arvore)= (PtrArvoreAVL)malloc(sizeof(NoArvoreAVL));
        (*arvore)->elemento=x;
        (*arvore)->direita=(*arvore)->esquerda=NULL;
        (*arvore)->elemento=x;
        (*arvore)->altura=0;
        return (true);
    }
    else if ((*arvore)->elemento.chave == x.chave){
        return (false);
    }
    else if ((*arvore)->elemento.chave > x.chave){
        aux= inserirArvoreAVL(&(*arvore)->esquerda, x);
    }
    else if((*arvore)->elemento.chave < x.chave){
        aux= inserirArvoreAVL(&(*arvore)->direita, x);
    }
    if (aux == false) return (false);

    int hdir, hesq, bf;
    hdir= alturaArvoreAVL(&(*arvore)->direita);
    hesq= alturaArvoreAVL(&(*arvore)->esquerda);
    bf = hdir - hesq;
    if ((bf == -2) || (bf ==2)){
        printf("APLICANDO ROTAÇÃO\n");
        aplicarRotacoes(&(*arvore));
    }
    (*arvore)->altura= atualizaAlturaArvoreAVL(&(*arvore));
    return (true);
}
PtrArvoreAVL getMaxAux(PtrArvoreAVL *arvore){
    PtrArvoreAVL ret;
    if ((*arvore)->direita == NULL){
        ret = (*arvore);
        (*arvore) = (*arvore)->esquerda;
        return (ret);
    }
    return (getMaxAux(&(*arvore)->direita));
}
PtrArvoreAVL getMinAux(PtrArvoreAVL *arvore){
    PtrArvoreAVL ret;
    if ((*arvore)->esquerda == NULL){
        ret = (*arvore);
        (*arvore) = (*arvore)->direita;
        return (ret);
    }
    return (getMinAux(&(*arvore)->esquerda));
}
bool remover(PtrArvoreAVL *arvore, Objeto x) {
    bool aux;
    PtrArvoreAVL temp;
    if ((*arvore) == NULL){
        return false;
    }
    if ((*arvore)->elemento.chave == x.chave){
        temp = (*arvore);
        if ((*arvore)->direita == NULL && (*arvore)->esquerda == NULL){
            (*arvore) = NULL;
        }
        else if ((*arvore)->esquerda == NULL){
            (*arvore) = (*arvore)->direita;
        }
        else if ((*arvore)->direita == NULL){
            (*arvore) = (*arvore)->esquerda;
        }
        else {
            (*arvore) = getMaxAux(&(*arvore)->esquerda);
            (*arvore)->direita = temp->direita;
        }
        printf("Removendo: %d\n", temp->elemento.chave);
        free(temp);
        return true;
    }
    if ((*arvore)->elemento.chave > x.chave){
        aux = remover(&(*arvore)->esquerda, x);
        }
    else{
        aux = remover(&(*arvore)->direita, x);
        }
    if (aux) {
        aplicarRotacoes(&(*arvore));
        atualizaAlturaArvoreAVL(&(*arvore));
        return true;
    }
    else{
        return false;
    }
}
void ImprimirTopo(PtrArvoreAVL *arvore, int cont, FILE *saida){

    if((*arvore) == NULL){
        return;
    }
    else{
        if(cont == 1){
            int bf = 0;
            int hd= alturaArvoreAVL(&(*arvore)->direita);
            int he= alturaArvoreAVL(&(*arvore)->esquerda);
            bf = hd-he;
            printf("%d (%d),",(*arvore)->elemento.chave,bf);
            fprintf(saida,"%d (%d),",(*arvore)->elemento.chave,bf);
        }
        else{
            ImprimirTopo(&(*arvore)->esquerda, cont - 1,saida);
            ImprimirTopo(&(*arvore)->direita, cont - 1,saida);
        }
    }
}
void imprimeArvoreAVLNivel(PtrArvoreAVL *arvore, FILE *saida){
    for(int i=1;i<= alturaArvoreAVL(&(*arvore));++i){
        ImprimirTopo(&(*arvore), i,saida);
        printf("\n");
        fprintf(saida,"\n");
    }
}


#endif //ATVAVL_AVL_H
