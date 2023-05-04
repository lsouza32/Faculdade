#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"
#include "PilhaEstatica.h"
#include <string.h>

//---------------------- O PROGRAMA CONVERTE SOMENTE UM UNICO NUMERO NO ARQUIVO --------------------------------

int main(){

    FILE *entrada = NULL;
    FILE *saida = NULL;
    char tipo;
    int bin[100];
    int i=0;

    entrada= fopen("entrada.txt", "r");
    saida = fopen("saida.txt", "w");

    if (entrada==NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
    }
    if (saida==NULL){
        printf("ERRO AO CRIAR AQUIVO DE SAIDA");
    }

    tipo= fgetc(entrada);
//----------------------------------------PILHA DINAMICA------------------------------------------------------------
    if (tipo == 'd') {

        PilhaDinamica pd;
        ObjetoD x;
        iniciaPilhaD(&pd);

        while (feof(entrada) == 0) {
            int numero;
            fscanf(entrada, "%d\n", &numero);

            while (numero != 0) {
                if (numero % 2 == 0) {
                    bin[i]=0;
                    i++;
                    numero = numero / 2;
                }
                if (numero % 2 != 0 && numero != 1) {
                    bin[i]=1;
                    i++;
                    numero = numero / 2;
                }
                if (numero == 1) {
                    bin[i]=1;
                    i++;
                    numero = 0;
                }
            }
            if (numero == 0) {
                bin[i]=0;
                i++;
            }
            for (int j = 0; j <i ; j++) {
                x.chave = bin[j];
                empilhaD(x,&pd);
            }
            while (estaVaziaD(&pd) == false) {

                int numero2 = desempilhaD(&pd);
                printf("desempinhado: %d \n", numero2);
                fprintf(saida, "%d", numero2);
            }
        }
        imprimePilhaD(&pd);
    }
//-------------------------------------------------PILHA ESTATICA--------------------------------------------------
    if (tipo== 'e'){

        pilhaEstatica pe;
        ObjetoE y;
        iniciaPilhaE(&pe);

        while (feof(entrada) == 0) {
            int numero;
            fscanf(entrada, "%d\n", &numero);

            while (numero != 0) {
                if (numero % 2 == 0) {
                    bin[i]=0;
                    i++;
                    numero = numero / 2;
                }
                if (numero % 2 != 0 && numero != 1) {
                    bin[i]=1;
                    i++;
                    numero = numero / 2;
                }
                if (numero == 1) {
                    bin[i]=1;
                    i++;
                    numero = 0;
                }
            }
            if (numero == 0) {
                bin[i]=0;
                i++;
            }
            for (int j = 0; j <i ; j++) {
                y.chave = bin[j];
                empilhaE(y,&pe);
            }
            while (estaVaziaE(&pe) == false) {
                ObjetoE numero2 = desempilhaE(&pe);
                printf("desempinhado: %d \n", numero2);
                fprintf(saida, "%d", numero2);
            }
        }
        imprimePilhaE(&pe);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}