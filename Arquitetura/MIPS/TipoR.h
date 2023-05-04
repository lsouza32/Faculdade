#ifndef UNTITLED_TIPOR_H
#define UNTITLED_TIPOR_H

#include "Registradores.h"

void funcoesTipoR(int opCode_int, FILE *entrada){
    printf("COMANDO DE FUNCAO TIPO R\n\n");

    char rs[6];
    fgets(rs,6,entrada);
    int rs_int = atoi(rs);

    char rt[6];
    fgets(rt,6,entrada);
    int rt_int = atoi(rt);

    char rd[6];
    fgets(rd,6,entrada);
    int rd_int = atoi(rd);

    char shamt[6];
    fgets(shamt,6,entrada);
    int shamt_int = atoi(shamt);

    char funct[7];
    fgets(funct,7,entrada);
    int funct_int = atoi(funct);
    printf("funct:%i\n",funct_int);

    // POR CONTA DA TRANSFORMACAO DE STRING PARA INT ALGUMAS FUNCOES FORAM REMOVIDAS O ZERO DE SUAS PRIMEIRAS CASAS EX: 0010 -> 10

    if (funct_int==100000) {    // ADD
        printf("ADD\n");
        tabelaRegistradores[convertToDec(rd_int)][0]=tabelaRegistradores[convertToDec(rs_int)][0] + tabelaRegistradores[convertToDec(rt_int)][0];
        printf("REGISTRADORES UTILIZADOS: %s + %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i + %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==100010){     //SUB
        printf("SUB\n");
        tabelaRegistradores[convertToDec(rd_int)][0]=tabelaRegistradores[convertToDec(rs_int)][0] - tabelaRegistradores[convertToDec(rt_int)][0];
        printf("REGISTRADORES UTILIZADOS: %s - %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i - %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==11000){     //MULT= 011000       --------VER COM O PROF
        printf("MULTI\n");
        printf("REGISTRADORES UTILIZADOS: %s x %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        // Concatenar rd e shamt
    }
    else if(funct_int==11010){     //DIV= 011010        --------VER COM O PROF
        printf("DIV\n");
        printf("REGISTRADORES UTILIZADOS: %s / %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        // Concatenar rd e shamt
    }
    else if(funct_int==100100){     //PORTA AND
        printf("PORTA AND\n");
        if(tabelaRegistradores[convertToDec(rs_int)][0] == tabelaRegistradores[convertToDec(rt_int)][0]){
            tabelaRegistradores[convertToDec(rd_int)][0]=1;
        }
        else{
            tabelaRegistradores[convertToDec(rd_int)][0]=0;
        }
        printf("REGISTRADORES UTILIZADOS: %s AND %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i AND %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==100101){     //PORTA OR
        printf("PORTA OR\n");
        if(tabelaRegistradores[convertToDec(rs_int)][0] == 1 || tabelaRegistradores[convertToDec(rt_int)][0] == 1){
            tabelaRegistradores[convertToDec(rd_int)][0]=1;
        }
        else{
            tabelaRegistradores[convertToDec(rd_int)][0]=0;
        }
        printf("REGISTRADORES UTILIZADOS: %s OR %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i OR %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==100110){     //PORTA XOR
        printf("PORTA XOR\n");
        if(tabelaRegistradores[convertToDec(rs_int)][0] == tabelaRegistradores[convertToDec(rt_int)][0]){
            tabelaRegistradores[convertToDec(rd_int)][0]= 0;
        }
        else{
            tabelaRegistradores[convertToDec(rd_int)][0]= 1;
        }
        printf("REGISTRADORES UTILIZADOS: %s XOR %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i XOR %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==100111){     //PORTA NOR
        printf("PORTA NOR\n");
        if(tabelaRegistradores[convertToDec(rs_int)][0] == 0 && tabelaRegistradores[convertToDec(rt_int)][0] == 0){
            tabelaRegistradores[convertToDec(rd_int)][0]=1;
        }
        else{
            tabelaRegistradores[convertToDec(rd_int)][0]=0;
        }
        printf("REGISTRADORES UTILIZADOS: %s NOR %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i NOR %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==	101010){        //SLT
        printf("SLT\n");
        if(tabelaRegistradores[convertToDec(rs_int)][0] < tabelaRegistradores[convertToDec(rt_int)][0]){
            tabelaRegistradores[convertToDec(rd_int)][0]=1;
        }
        else{
            tabelaRegistradores[convertToDec(rd_int)][0]=0;
        }
        printf("REGISTRADORES UTILIZADOS: %s < %s = %s\n", nomeRegistrador(rs_int), nomeRegistrador(rt_int), nomeRegistrador(rd_int));
        printf("RESULTADO: %i < %i = %i\n", tabelaRegistradores[convertToDec(rs_int)][0],tabelaRegistradores[convertToDec(rt_int)][0],tabelaRegistradores[convertToDec(rd_int)][0]);
    }
    else if(funct_int==000000){     //SLL           --------VER COM O PROF
        printf("SLL\n");

    }
    else if(funct_int==10){       //SRL =000010      --------VER COM O PROF
        printf("SRL\n");

    }
    else if(funct_int==11){       //SRA =000011         --------VER COM O PROF
        printf("SRA\n");

    }
    else{
        printf("ERRO NA ENTRADA!!\nNAO FOI POSSIVEL IDENTIFICAR A OPERACAO!\n");
    }






}

#endif //UNTITLED_TIPOR_H
