// IMPLEMENTACAO AUTOMATO COM PILHA DUPLO BALANCEAMENTO (a^n b^n | n>=1)
/*Link com a explicacao parte 1 e 2
 * https://drive.google.com/drive/folders/1Ruwy9SiRYI_zESOSD0K22TIcjz3bMSrk?usp=sharing
 * */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXTAM 100  // tamanho da pilha

typedef struct {
    char chave;
} ObjetoE;

typedef struct {
    ObjetoE array[MAXTAM];
    int topo;
    int aux;        //variavel auxiliar
} pilhaEstatica;

void iniciaPilhaE(pilhaEstatica *pilha){
    pilha->topo=0;
    pilha->aux=1;
};

bool estaVaziaE(pilhaEstatica *pilha){
    if (pilha->topo==0){
        return true;
    }
    else{
        return false;
    }
};
bool estaCheiaE(pilhaEstatica *pilha){
    if (pilha->topo==MAXTAM){
        return true;
    }
    else{
        return false;
    }
} ;

void empilhaE( ObjetoE item, pilhaEstatica *pilha){
    if (estaCheiaE(pilha)==false){
        pilha->array[pilha->topo]=item;
        pilha->topo = pilha->topo+1;
    }
    else{
        printf("A PILHA JA ESTA CHEIA");
    }
};

ObjetoE desempilhaE(pilhaEstatica *pilha){
    if (estaVaziaE(pilha)==false){
        ObjetoE item= pilha->array[pilha->topo-1];
        pilha->topo = pilha->topo-1;
        return (item);
    }
    else{
        printf("A PILHA JA ESTA VAZIA\n");
        pilha->aux--;   // caso o automato tente desempilhar com a pilha vazia aux = 0 e o programa rejeita a entrada
    }
}
char topoPilhaE(pilhaEstatica *pilha){
    if(estaVaziaE(pilha)){
        printf("Pilha vazia\n");
    }
    else{
        printf("Topo da pilha: %c\n",pilha->array[pilha->topo-1].chave);
        return (pilha->array[pilha->topo-1].chave);
    }
};
/*
void imprimePilhaE(pilhaEstatica *pilha){
    for (int i = 0; i <pilha->topo ; i++) {
        printf("%c\n", pilha->array[i].chave);
    }
};*/

int main() {
    pilhaEstatica pe;   // pe -> Pilha Estatica
    ObjetoE y;          // objeto para a key
    iniciaPilhaE(&pe);  // inicia a pilha

    char entrada[200];  // simbolos de entrada

    int estado=0;       //estados

    printf("Digite a sua entrada: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada,"\n")]='\0';

    printf("Caminhos:\n");

    for (int i = 0; i <= strlen(entrada); i++) {

        printf("Estado Q%i\n",estado);  // imprime estado atual
        topoPilhaE(&pe);  // imprime o topo atual

        if(estado==0 && entrada[i]=='0'){ // estado inicial recebe 0
            y.chave='$';        //empilha $
            empilhaE(y,&pe);    //empilha
            estado=1;           //pula para o estado 1
        }
        else if(estado==1 && entrada[i]=='0'){ // estado 1 recebe 0
            y.chave='0';        //empilha 0
            empilhaE(y,&pe);    //empilha
            estado=1;           //loop
        }
        else if(estado==1 && entrada[i]=='1'){ // estado 1 entrada 1
            desempilhaE(&pe);   // desempilha
            estado=2;           //vai para o proximo estado
        }
        else if(estado==2 && entrada[i]=='1'){    // estado 2 entrada 1
            desempilhaE(&pe);   //desempilha
            estado = 2;           // loop
        }
        printf("\n");
    }

    if((estado==2) && estaVaziaE(&pe) && pe.aux==1){    // estado final + pilha vazia + aux(aux==1 significa que NAO tentou desempilhar enquanto a pilha estava vazia)
        printf("ACEITO!");
    }
    else{
        printf("REJEITADO!");
    }

    return 0;
}
