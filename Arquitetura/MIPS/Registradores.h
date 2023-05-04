#ifndef UNTITLED_REGISTRADORES_H
#define UNTITLED_REGISTRADORES_H

int zero;
int at;
int v0;int v1;
int a0;int a1;int a2;int a3;
int t0;int t1;int t2;int t3;int t4;int t5;int t6;int t7;int t8;int t9;
int s0;int s1;int s2;int s3;int s4;int s5;int s6;int s7;
int k0;int k1;
int *gp;
int *sp;
int *fp;
int *ra;

int **teste;

int tabelaRegistradores[32][1];     // convertendo a instrucao do registrador em binario para decimal temos o indice do registrador

char *nomeRegistrador(int Regist){      //FUNCAO PARA RETORNAR OS NOMES DOS REGISTRADORES UTILIZADOS
    if(Regist==00000){return "$zero";}
    else if(Regist==1){return "$at";}
    else if(Regist==10){return "$v0";}
    else if(Regist==11){return "$v1";}
    else if(Regist==100){return "$a0";}
    else if(Regist==101){return "$a1";}
    else if(Regist==110){return "$a2";}
    else if(Regist==111){return "$a3";}
    else if(Regist==1000){return "$t0";}
    else if(Regist==1001){return "$t1";}
    else if(Regist==1010){return "$t2";}
    else if(Regist==1011){return "$t3";}
    else if(Regist==1100){return "$t4";}
    else if(Regist==1101){return "$t5";}
    else if(Regist==1110){return "$t6";}
    else if(Regist==1111){return "$t7";}
    else if(Regist==10000){return "$s0";}
    else if(Regist==10001){return "$s1";}
    else if(Regist==10010){return "$s2";}
    else if(Regist==10011){return "$s3";}
    else if(Regist==10100){return "$s4";}
    else if(Regist==10101){return "$s5";}
    else if(Regist==10110){return "$s6";}
    else if(Regist==10111){return "$s7";}
    else if(Regist==11000){return "$t8";}
    else if(Regist==11001){return "$t9";}
    else if(Regist==11010){return "$k0";}
    else if(Regist==11011){return "$k1";}
    else if(Regist==11100){return "$gp";}
    else if(Regist==11101){return "$sp";}
    else if(Regist==11110){return "$fp";}
    else if(Regist==11111){return "$ra";}
    else{
        return "ERRO NA ENTRADA!!\nNAO FOI POSSSIVEL IDENTIFICAR O REGISTRADOR";
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int convertToDec(int valor) {       // Converter binario para decimal
    int sobra, novoValor = 0;
    for (int j = 0; j < 6; j++) {
        sobra = valor - ((valor / 10)*10);
        valor = valor / 10;
        novoValor += sobra * pow(2,j);
    }
    return novoValor;
}


#endif //UNTITLED_REGISTRADORES_H
