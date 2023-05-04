#ifndef UNTITLED_TIPOI_H
#define UNTITLED_TIPOI_H

#include "Registradores.h"

void funcoesTipoI(int opCode_int, FILE *entrada) {
    printf("COMANDO DE FUNCAO TIPO I\n");

    char rs[6];
    fgets(rs, 6, entrada);
    int rs_int = atoi(rs);

    char rt[6];
    fgets(rt, 6, entrada);
    int rt_int = atoi(rt);

    char endereco[17];
    fgets(endereco,17,entrada);
    int endereco_int= atoi(endereco);

    printf("\n");
    if(opCode_int==1000){     //ADDI=001000
        printf("ADDI\n");
        tabelaRegistradores[convertToDec(rt_int)][0]= tabelaRegistradores[convertToDec(rs_int)][0] + convertToDec(endereco_int);
        printf("REGISTRADORES UTILIZADOS: %s + %i = %s\n", nomeRegistrador(rs_int), convertToDec(endereco_int),nomeRegistrador(rt_int));
        printf("RESULTADO: %i + %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],convertToDec(endereco_int),tabelaRegistradores[convertToDec(rt_int)][0]);
    }
    else if(opCode_int==1001){        //ADDIU=001001
        printf("ADDIU\n");
        tabelaRegistradores[convertToDec(rt_int)][0]= tabelaRegistradores[convertToDec(rs_int)][0] + convertToDec(endereco_int);
        printf("REGISTRADORES UTILIZADOS: %s + %i = %s\n", nomeRegistrador(rs_int), convertToDec(endereco_int),nomeRegistrador(rt_int));
        printf("RESULTADO: %i + %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],convertToDec(endereco_int),tabelaRegistradores[convertToDec(rt_int)][0]);
    }
    else{
        printf("ERRO NA ENTRADA!!\nNAO FOI POSSIVEL IDENTIFICAR A OPERACAO!\n");
    }


}

#endif //UNTITLED_TIPOI_H
