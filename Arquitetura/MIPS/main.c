#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TipoI.h"
#include "TipoJ.h"
#include "TipoR.h"
#include "Registradores.h"


int main() {

    //tabelaRegistradores[9][0]=2;      // -> $t1
    //tabelaRegistradores[10][0]=3;     // -> %t2

    FILE *entrada = NULL;
    entrada= fopen("entrada.txt", "r");
    if(entrada==NULL){
        printf("\nERRO AO ABRIR ARQUIVO DE ENTRADA!!!\n");
        return 1;
    }

    char opcode[7];
    fgets(opcode,7,entrada);    // captura opcode

    printf("opcode:%s\n",opcode);
    int intOpcode = atoi(opcode);   // tranforma em int para facilitar as comparacoes

    if(intOpcode==000000){
        funcoesTipoR(intOpcode,entrada);
    }
    else if(intOpcode == 1000 || intOpcode == 1001){
        funcoesTipoI(intOpcode,entrada);
    }
    else if(intOpcode == 3){
        funcoesTipoJ(intOpcode,entrada);
    }
    else{
        printf("ERRO NA ENTRADA!!\n NAO FOI POSSIVEL IDENTIFICAR O FORMATO DE INSTRUCOES!");
    }


    return 0;
}
