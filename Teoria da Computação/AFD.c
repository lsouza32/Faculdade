// IMPLEMENTACAO AFD
#include <stdio.h>
#include <string.h>

int main() {
    char entrada[200];
    int estado=0; // estado inicial

    printf("Digite a entrada: ");
    fgets(entrada, sizeof(entrada),stdin);
    entrada[strcspn(entrada,"\n")]='\0';

    int cont = strlen(entrada); // quantidade de simbolos de entrada
    int i =0; // auxiliar para percorrer a string

    printf("Caminhos:");
    printf("\nEstado N0");
    while (cont >0){ // rodar o laco ate acabar os simbolos de entrada

        if(estado ==0 && entrada[i]== '1'){ // esta no estado N0 e recebe entrada 1
            estado =0; // transicao de estado
        }
        else if(estado == 0 && entrada[i]== '0'){// esta no estado N0 e recebe entrada 0
            estado=1;// transicao de estado
        }
        else if(estado == 1 && entrada[i]== '1'){// esta no estado N1 e recebe entrada 1
            estado=2;// transicao de estado
        }
        else if(estado == 1 && entrada[i]== '0'){// esta no estado N1 e recebe entrada 0
            estado=3;// transicao de estado
        }
        else if(estado == 2 && entrada[i]== '1'){// esta no estado N2 e recebe entrada 1
            estado=1;// transicao de estado
        }
        else if(estado == 2 && entrada[i]== '0'){// esta no estado N2 e recebe entrada 0
            estado=1;// transicao de estado
        }
        else if(estado == 3 && entrada[i]== '1'){// esta no estado N3 e recebe entrada 1
            estado=3;// transicao de estado
        }
        else if(estado == 3 && entrada[i]== '0'){// esta no estado N3 e recebe entrada 0
            estado=3;// transicao de estado
        }
        printf("\nEstado N%i",estado);
        i++; // incrementa contador auxiliar
        cont--; //decrementa o contador de simbolos
    }

    if(estado==2 || estado==3){ // estados de aceitacao
        printf("\nAceito");
    } else{
        printf("\nRejeitado");
    }

    return 0;
}
