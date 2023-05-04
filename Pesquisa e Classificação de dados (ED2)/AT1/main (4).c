/** Tarefa desenvolvida pela dupla :
Nome: LUCAS SANTOS SOUZA
Nome: LEONARDO TEODORO
*/
/**
 * Tudo feito corretamente porem nao conseguimos utilizar a busca binaria, e algumas funcoes prontas estavam
 * dando bug, por conta disso algumas funcoes fizemos a mao
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LIMPAR(char *s){   //Funcao para limpar espacos vazios da string, fazendo um registro de tamanho variavel, para evitar perde de memoria!
    int  i,k=0;
    for(i=0;s[i];i++){
        s[i]=s[i+k];
        if(s[i]==' '&&s[i+1]==' '){ //Condicao para limpar apenas espacos vazios, e nao tirar todos os espacos!
            k++;
            i--;
        }
    }
}
void limpar_number(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

typedef struct cadastro {   //Struct Cadastro
    int RRN;
    char ID[4];
    char nome[25];
    char rua[25];
    char cidade[20];
    char UF[2];
    char IP[5];

}cad;

typedef struct cadastroOrdenado {
    int RRN;
    char nome[25];
    char cidade[20];
}CadOrder;

int compararNome (const void *a, const void *b) {   // Usado Para o Qsort
    return strcmp (((CadOrder *)a)->nome,((CadOrder *)b)->nome);
}

//------------------------------ INDICE PRIMARIO -> COMBINACAO DE UF+ID------------------------------------------------
void CriarIndicePrimario(cad *Pessoas){
    FILE *arqIP;
    arqIP= fopen("IndicePrimario.txt", "w+"); // Cria Novo arquivo

    int cont=0; // Contador
    while (cont<10){ //While para percorer a Struct de cadastro de 10 em 10
        int k=0;

        for(int i = 0; i <= 5; i++){ //concatena UF + ID = INDICE PRIMARIO
            if(i < 2){ // Pega o UF e coloca nas primeiras posicoes
                Pessoas[cont].IP[i] = Pessoas[cont].UF[i];
            }
            else{ // Pega o ID e coloca nas posicoes restantes
              Pessoas[cont].IP[i]= Pessoas[cont].ID[k];
              k++;
            }
        }

        fwrite(Pessoas[cont].IP, sizeof(char), strlen(Pessoas[cont].IP) , arqIP); // Escreve INDICE PRIMARIO NO ARQ
        fprintf(arqIP,"|%d\n",Pessoas[cont].RRN); // ESCREVE RRN NO ARQ
        cont++;
    }
    cont =0;
    fclose(arqIP);

};

//------------------------------ INDICES SECUNDARIOS ------------------------------------------------------------------
void CriarIndiceSecundario(cad *Pessoas){
    FILE *arqIS_Cidade;
    FILE *arqIS_Nome;
    arqIS_Cidade= fopen("IndiceSecundario_Cidade.txt", "w+"); //CRIA ARQ_CIDADE
    arqIS_Nome= fopen("IndiceSecundario_Nome.txt", "w+");    // CRIA ARQ_NOME

    int i = 0;
    while(i < 10){// While para escrever nos arqs o cadatro armazenado na struct Cadastro de 10 em 10
        //----------------------------  Cidade fracamente ligado -------------------------------------------------------
        fwrite(Pessoas[i].cidade, sizeof(char),strlen(Pessoas[i].cidade), arqIS_Cidade); // Escreve a cidade
        fprintf(arqIS_Cidade,"|");  // escreve delimitador
        fwrite(Pessoas[i].IP, sizeof(char),strlen(Pessoas[i].IP), arqIS_Cidade);    // Escreve o indice primario
        fprintf(arqIS_Cidade, "\n");
        // ---------------------------- Nome Fortemente ligado ---------------------------------------------------------
        fwrite(Pessoas[i].nome, sizeof(char),strlen(Pessoas[i].nome), arqIS_Nome);  //Escreve o nome
        fprintf(arqIS_Nome,"\t");
        fprintf(arqIS_Nome,"%d\n",Pessoas[i].RRN);  //Escreve RRN

        i++;
    }
    fclose(arqIS_Cidade);
    fclose(arqIS_Nome);
};

void ListarTodos(CadOrder *Order){
    FILE *arqCad;
    arqCad= fopen("C://Users/Lucas/Documents/Clion/Pc_Indexacao/cadastro.txt", "r");

    qsort(Order, 500, sizeof(CadOrder), compararNome); // Ordena os Nomes Por ordem alfabetica

    int k=0;
    char str1[76];
    char c;
    int count=0;

    while (k<500) { //While para percorrer a struct CadOrder
        fseek(arqCad,0,SEEK_SET);//define o ponteiro do arquivo para seu incio
        while (feof(arqCad) == 0) { // While para percorrer arq
            c = fgetc(arqCad);
            if (c=='\n'){ // Contadore de linha iniciando em 0
                count++;
            }
            if (count== Order[k].RRN){ // Quando a linha for = RRN pega a linha do arq e mostra na tela
                fgets(str1,76,arqCad);
                printf("%s\n", str1);
                break;
            }
        }
        count=0;
        k++;
    }
    fclose(arqCad);
};

int PesquisaNome(CadOrder *Order){
    char nome_busca[25];
    int RRN_busca;

    printf("Digite o nome COMPLETO:");  //somente nome completo

    fgets(nome_busca,strlen(nome_busca),stdin);
    nome_busca[strcspn(nome_busca,"\n")]='\0';

    int k=0;
    char str1[76];
    char c;
    int count=0;

    FILE *arqCad = fopen("C://Users/Lucas/Documents/Clion/Pc_Indexacao/cadastro.txt", "r");

    while (k< 500){ //While para percorrer struct CadOrder
        if(strcmp(nome_busca,Order[k].nome)==0){    //Compara os nomes
            RRN_busca= Order[k].RRN;    //Salva RRN do nome de busca
            while (feof(arqCad) == 0) { //Percorre arq
                c = fgetc(arqCad);
                if (c=='\n'){   // Contador de linhas
                    count++;
                }
                if (count== RRN_busca){ // Quando linha = RRN mostra o registro na tela
                    fgets(str1,76,arqCad);
                    printf("%s\n", str1);
                    break;
                }
            }
        }
        k++;
    }

    fclose(arqCad);
};

void PesquisaCidade(CadOrder *Order){
    char cidade_busca[25];
    int RRN_busca;

    printf("Digite a cidade:");
    fgets(cidade_busca,strlen(cidade_busca),stdin);
    cidade_busca[strcspn(cidade_busca,"\n")]='\0';

    int k=0;
    char str1[76];
    char c;
    int count=0;
    FILE *arqCad = fopen("C://Users/Lucas/Documents/Clion/Pc_Indexacao/cadastro.txt", "r");

    while (k< 500){ //Percorre a struct CadOrder
        if(strncmp(cidade_busca,Order[k].cidade, strlen(Order[k].cidade))==0){  // Compara as cidades
            RRN_busca= Order[k].RRN;    // Salva RRN DA CIDADE

            while (feof(arqCad) == 0) { //Percorre arq
                c = fgetc(arqCad);
                if (c=='\n'){   //Conta linhas
                    count++;
                }
                if (count== RRN_busca){ // Se linha = RRN printa os registros na tela
                    fgets(str1,76,arqCad);
                    printf("%s\n", str1);
                    break;
                }
            }
        }
        k++;
    }
    fclose(arqCad);
};


int main() {

//----------------------------------- ABRIR O ARQ DE CADASTRO ----------------------------------------------------------
    FILE *arqread;
    arqread= fopen("C://Users/Lucas/Documents/Clion/Pc_Indexacao/cadastro.txt", "r");
    if (arqread == NULL ){
        printf("ERRO AO ABRIR ARQUIVO DE CADASTROS! \n");
        exit(1);
    }
//------------------------------------ ADICIONAR CADASTROS A RAM -------------------------------------------------------
    CadOrder Order[500];

    cad Pessoas[10];
    int indice=0;
    int cont = 0;

    while (feof(arqread) == 0) { //Percorre o arquivo
        while (cont < 10){// Pega os cadastros de 10 em 10

            fgets(Pessoas[cont].ID,4, arqread); //Pega o ID
            fgets(Pessoas[cont].nome,26, arqread); //Pega o nome
            LIMPAR(Pessoas[cont].nome);
            fgets(Pessoas[cont].rua,26, arqread); //Pega a rua e numero
            LIMPAR(Pessoas[cont].rua);
            fgets(Pessoas[cont].cidade,21, arqread); //Pega a cidade
            LIMPAR(Pessoas[cont].cidade);
            fgets(Pessoas[cont].UF,4, arqread); //Pega a UF
            Pessoas[cont].UF[strcspn(Pessoas[cont].UF, "\n")]='\0'; //REMOVER \n
            LIMPAR(Pessoas[cont].UF);
            Pessoas[cont].RRN= indice; // Cria indice(RRN)

            strncpy(Order[indice].nome, Pessoas[cont].nome, 26); // Copia nome para struct de ordenacao
            Order[indice].RRN= Pessoas[cont].RRN;   //envia RRN para struct de ordenacao
            strncpy(Order[indice].cidade, Pessoas[cont].cidade,20); // Copia cidade para struct de ordenacao

            indice++;
            cont++;
        }

        CriarIndicePrimario(Pessoas);   //FUNCAO PARA CRIAR INDICES DOS CADASTROS
        CriarIndiceSecundario(Pessoas); //FUNCAO PARA CRIAR INDICES DOS CADASTROS

        cont = 0;   //Reset cont
        free(Pessoas);  //Limpa Struct
    }
    fclose(arqread);


    //------------------------------------- OPCOES DO MENU -------------------------------------------------------------
    int menu;

    do{
        printf("======== Amigos do Apolonio =======");
        printf("\n1 - Listar todos os dados dos amigos ");
        printf("\n2 - Pesquisar por nome");
        printf("\n3 - Pesquisar por cidade");
        printf("\n4 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%i", &menu);
        limpar_number();    // As vezes nao limpava o buffer

        if (menu != 1 && menu != 2 && menu != 3 && menu != 4 ){
            printf("\n\nOPCAO INVALIDA\n\n");
        }

        switch(menu){
            case 1:
                ListarTodos(Order);

                break;
            case 2:
                PesquisaNome(Order);
                break;
            case 3:
                PesquisaCidade(Order);
                break;
            case 4:
                break;
        }
    }while(menu != 4);

    return 0;
}
