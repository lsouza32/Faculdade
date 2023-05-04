/* ---------------------- REDEFINIR A VARIAVEL PATH NOS CASE (COLOCAR O CAMINHO DOS ARQUIVOS) ------------------------- */
/* --------- ARQUIVO ESTOQUE.TXT DEVE MANTER O PADRAO->  Nome_Produto'espaco'Quantidade'espaco'UnidadeDeMedida ------ */
/* AS FUNCOES DE ADD AO ESTOQUE E FABRICAR PRODUTO NAO RODAM MAIS DE UMA VEZ POR EXECUCAO DE CODIGO, MAS RODA PERFEITAMENTE NESSA UNICA VEZ */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Estoque{
    char nome_produto[40];
    float quantidade_produto;
    char unidade_medida[3];
}EstoqueProd;

typedef struct Receita{
    char nome_produto[40];
    float quantidade_produto;
    char unidade_medida[3];
}ReceitaProd;

void VerReceita(char *path){
    FILE *arqReceita;
    arqReceita= fopen(path,"r");
    if (arqReceita == NULL){
        printf("ERRO NA LEITURA DO ARQUIVO DE RECEITA\n");
        exit(1);
    }

    printf("\nReceita\n");
    
    char str[60];
    while (feof(arqReceita)==0){ // Percorre o arquivo ate o final
        fgets(str,60, arqReceita); // ARMAZENA A LINHA DO ARQUIVO
        
        printf("%s",str);     // MOSTRA NA TELA
    }
    printf("\n\n");
    fclose(arqReceita);
}

void Estoque(char *path, EstoqueProd *Estoque_Prod){
    FILE *arqEstoque;
    arqEstoque=fopen(path,"r");
    if (arqEstoque== NULL){
        printf("ERRO NA LEITURA DO ARQUIVO ESTOQUE\n");
        exit(1);
    }

    int cont_prod=0;
    int k=0;
    while (feof(arqEstoque)==0){    //Percorre o arquivo ate o final para adicionar os dados a struct Estoque

        // Como o nome do produto possui underline entre as palavras conseguimos pegar como uma unica string unsado fscanf
        fscanf(arqEstoque,"%s %f %s\n", Estoque_Prod[k].nome_produto, &Estoque_Prod[k].quantidade_produto, Estoque_Prod[k].unidade_medida); // Recupera itens do estoque
        k++;    //Proximo Produto
        cont_prod++; // Contador de produto
        Estoque_Prod= realloc(Estoque_Prod,50*sizeof(EstoqueProd)); // REALOCA STRUCT
    }

    int quantidade_add=0;
    printf("Digite a quantidade de produtos que deseja adicionar no estoque: \n");
    scanf("%i", &quantidade_add);   //recebe a quantidade a ser cadastrada
    setbuf(stdin,NULL);

    char nome_tmp[40]; // String temporaria para armazenar nome do produto

    for (int i = 0; i < quantidade_add; i++) {  // Roda a quantidade que vai ser add
        printf("Digite o nome do produto %i: \n",i+1);
        fgets(nome_tmp,40,stdin);   //recebe nome
        nome_tmp[strcspn(nome_tmp,"\n")]='\0';  // Remove \n
        setbuf(stdin,NULL); //limpa buffer

        for (int j = 0; j < strlen(nome_tmp); j++) {    //Percorre toda a string nome_tmp
            if (nome_tmp[j]==' '){//Substituir espaco por underline para o nome formar uma unica string para formar um padrao a ser lido pelo fscanf
                nome_tmp[j]='_';
            }
        }

        int verificador_nome=0;
        for (int j = 0; j < cont_prod+1; j++) { // Percorrer a struct de produtos
            if(strcmp(nome_tmp,Estoque_Prod[j].nome_produto)==0){   //Compara os nomes para verificar se esse produto ja existe no estoque
                // PRODUTO JA EXISTE SO ATUALIZAMOS A QUANTIDADE

                float aux_qt=0;
                printf("Digite a quantidade que deseja dar entrada: \n");
                scanf("%f", &aux_qt);
                setbuf(stdin,NULL);

                Estoque_Prod[j].quantidade_produto= Estoque_Prod[j].quantidade_produto+aux_qt; // SOMA A QUANTIDADE NO ESTOQUE COM A NOVA

                printf("\nQuantidade do produto atualizada!!\n\n");

                verificador_nome=0; // Reset verificardor
                break; //forcar parada
            }
            else{
                verificador_nome=1; // Verificador =1 -> Significa q o produto nao existe no estoque entao tera que ser cadastrado
            }
        }
        if (verificador_nome==1){   // Produto nao existe no estoque
            Estoque_Prod= realloc(Estoque_Prod,50*sizeof(EstoqueProd)); // REALOCA STRUCT

            strncpy(Estoque_Prod[cont_prod].nome_produto,nome_tmp,40);  // Copia o nome da string temporaria para a struct

            printf("Digite a Unidade de Medida do produto %i (SOMENTE L OU KG): \n",i+1); // ADD UND DE MEDIDA
            fgets(Estoque_Prod[cont_prod].unidade_medida,3,stdin);
            Estoque_Prod[cont_prod].unidade_medida[strcspn(Estoque_Prod[cont_prod].unidade_medida, "\n")]='\0'; //REMOVE \N
            setbuf(stdin,NULL); // LIMPA BUFFER

            printf("Digite a quantidade do Produto %i: \n",i+1); //ADD QUANTIDADE
            scanf("%f", &Estoque_Prod[cont_prod].quantidade_produto);
            setbuf(stdin,NULL);

            cont_prod++;    // Novo produto adicionado

            printf("\nProduto adiconado ao estoque!!\n\n");
        }
    }
    fclose(arqEstoque);

    FILE *arqTmp;
    arqTmp= fopen(path,"w+");   // CRIA NOVO ARQUIVO E APAGA O ANTERIOR PARA ATUALIZAR O ESTOQUE

    for (int i = 0; i < cont_prod; i++) {   // ESCREVE NO NOVO ARQ
        fprintf(arqTmp,"%s %.3f %s\n",Estoque_Prod[i].nome_produto, Estoque_Prod[i].quantidade_produto, Estoque_Prod[i].unidade_medida);
        // Escreve a struct no arquivo
        // 3 casas decimais para ter melhor precisao
    }

    fclose(arqTmp);
    free(Estoque_Prod);
}

void FabricarProduto(char *path_estoque,char *path_receita, EstoqueProd *Estoque_Prod, ReceitaProd *Receita_Prod){
    //----------------------ADD ESTOQUE STRUCT----------------
    FILE *arqEstoque;
    arqEstoque=fopen(path_estoque,"r");
    if (arqEstoque== NULL){
        printf("ERRO NA LEITURA DO ARQUIVO ESTOQUE\n");
        exit(1);
    }

    int cont_ProdE=0;
    int k=0;
    while (feof(arqEstoque)==0){    //Percorre o arquivo ate o final para adicionar os dados a struct Estoque

        // Como o nome do produto possui underline entre as palavras conseguimos pegar como uma unica string unsado fscanf
        fscanf(arqEstoque,"%s %f %s\n", Estoque_Prod[k].nome_produto, &Estoque_Prod[k].quantidade_produto, Estoque_Prod[k].unidade_medida); // Recupera itens do estoque
        k++;    //Proximo Produto
        cont_ProdE++; // cont produto estoque
        Estoque_Prod= realloc(Estoque_Prod,50*sizeof(EstoqueProd)); // REALOCA STRUCT
    }
    fclose(arqEstoque);

    //-------------------ADD RECEITA STRUCT---------------
    FILE *arqReceita;
    arqReceita=fopen(path_receita,"r");
    if (arqReceita== NULL){
        printf("ERRO NA LEITURA DO ARQUIVO RECEITA\n");
        exit(1);
    }

    int cont_ProdR=0;
    k=0;
    while (feof(arqReceita)==0){    //Percorre o arquivo ate o final para adicionar os dados a struct Estoque

        // Como o nome do produto possui underline entre as palavras conseguimos pegar como uma unica string usado fscanf
        fscanf(arqReceita,"%s %f %s\n", Receita_Prod[k].nome_produto, &Receita_Prod[k].quantidade_produto, Receita_Prod[k].unidade_medida); // Le dados da receita
        k++;    //Proximo Produto
        cont_ProdR++; //  cont produto receita
        Receita_Prod= realloc(Receita_Prod,50*sizeof(ReceitaProd)); // REALOCA STRUCT
    }
    fclose(arqReceita);

    //---------------- Verifica se tem quantidade necessaria -------

    int verificador=0;
    for (int i = 0; i < cont_ProdR; i++) {  //Percorrer produtos da receita
        for (int j = 0; j < cont_ProdE; j++) {  // Percorrer produtos do estoque
            // verifica se temos a quantidade minima de cada produto de acordo com a receita
            if (strcmp(Receita_Prod[i].nome_produto,Estoque_Prod[j].nome_produto)==0){  //Procura o nome do produto
                if(Estoque_Prod[j].quantidade_produto >= Receita_Prod[i].quantidade_produto){   // Verifica quantidade
                    verificador++; // Incrementa sempre que o estoque possui a quantidade necessaria
                }
                else{   //Informa qual produto falta
                    printf("\n\n!!! QUANTIDADE DE %s INSUFICIENTE!!!\n\n", Receita_Prod[i].nome_produto);
                }
            }
        }
    }
    if (verificador== cont_ProdR){ //TODOS PRODUTOS NECESSARIOS = TODOS PRODUTOS DA RECEITA ENTAO REPRODUZ A RECEITA
        printf("Voce possui a quantidade necessaria para reproduzir a receita!!\n");

        for (int i = 0; i < cont_ProdR; i++) {  // Percorrer produtos da receita
            for (int j = 0; j < cont_ProdE; j++) {  // Percorrer produtos do estoque
                if ((strcmp(Receita_Prod[i].nome_produto,Estoque_Prod[j].nome_produto)==0)){    // Procura o nome do produto
                    Estoque_Prod[j].quantidade_produto= Estoque_Prod[j].quantidade_produto - Receita_Prod[i].quantidade_produto; // Remove a quantidade do estoque
                }
            }
        }
        printf("A receita foi reproduzida e os itens necessarios foram removidos do estoque!\n");
    }

    FILE *arqTmp;
    arqTmp= fopen(path_estoque,"w+");   // CRIA NOVO ARQUIVO de estoque E APAGA O ANTERIOR PARA ATT O ESTOQUE

    for (int i = 0; i < cont_ProdE; i++) {   // ESCREVE NO NOVO ARQ
        fprintf(arqTmp,"%s %.3f %s\n",Estoque_Prod[i].nome_produto, Estoque_Prod[i].quantidade_produto, Estoque_Prod[i].unidade_medida);
        // Escreve a struct no arquivo
    }

    fclose(arqTmp);
    free(Estoque_Prod); //Limpa struct
    free(Receita_Prod);

};

void VerificarTipo(char *tipo){
    char *nome_marca="YpEQ";
    char tipos_amaciantes[4][15]={"Carinho","Delicado","Aconchego","Ternura"};
    char tipos_detergentes[7][15]={"clear","clear_care","coco","limao","maca","neutro","capim_limao"};

    int menu=0;

    if(tipo=="Amaciante"){ // MENU PARA AMACIANTE
        printf("\nQual cor de corante foi utilizado?\n");
        printf("1- Amarelo\n");
        printf("2- Branco\n");
        printf("3- Azul\n");
        printf("4- Rosa\n");
        scanf("%i", &menu);
        setbuf(stdin,NULL);

        if (menu>=1 && menu<=4){    //VERIFICA SE A OPCAO DIGITADA E VALIDA, SEMPRE ENTRE 1 E 4
            printf("\n\nTipo Produzido:\n");
            printf("Amaciante %s %s\n",nome_marca,tipos_amaciantes[menu-1]);
            //USAMOS A OPCAO DESEJADA COMO INDICE PARA SELECIONAR O TIPO DO PRODUTO
            // UTILIZA O INDICE MENU-1 POIS O MENU COMECA EM 1 E O INDICE EM 0
        }
        else{
            printf("\nOPCAO INVALIDA!\n");
        }
    };

    if(tipo=="Detergente"){
        printf("\nQual cor de corante foi utilizado?\n");
        printf("1- Transparente\n");
        printf("2- Rosa\n");
        printf("3- Branco-coco\n");
        printf("4- Verde\n");
        printf("5- Vermelho\n");
        printf("6- Amarelo\n");
        printf("7- Verde-claro\n");
        scanf("%i", &menu);
        setbuf(stdin,NULL);

        if (menu>=1 && menu<=7){   //VERIFICA SE A OPCAO DIGITADA E VALIDA, SEMPRE ENTRE 1 E 7
            printf("\n\nTipo Produzido:\n");
            printf("Detergente %s %s\n",nome_marca,tipos_detergentes[menu-1]);
            //USAMOS A OPCAO DESEJADA COMO INDICE PARA SELECIONAR O TIPO DO PRODUTO
            // UTILIZA O INDICE MENU-1 POIS O MENU COMECA EM 1 E O INDICE EM 0
        }
        else{
            printf("\nOPCAO INVALIDA!\n");
        }
    };
}

int media(int quantidade, int aux_media){
    if (quantidade<1){ // Neste caso nao e mais possivel fazer divisoes, retorna o valor de quantas divisoes foram feitas
        //LEMBRANDO QUE NAO E POSSIVEL PRODUZIR FRACOES DE PRODUTOS
        return aux_media;
    }
    else{
        aux_media++;
        return media(quantidade-30, aux_media); // Recursao para calcular divisao por subtracao sucessiva
    }
};

int main() {
    int menu1=0;
    int menu2=0;
    int menu3=0;
    int quantidade_mes=0;
    int prod_diaria=0;
    int aux_media=0;
    char *path_estoque;
    char *path_receita;
    char *tipo;

    EstoqueProd *Estoque_Prod=NULL;
    Estoque_Prod= (EstoqueProd*)malloc(sizeof(EstoqueProd));    // Alocacao dinamica Estoque

    ReceitaProd *Receita_Prod= NULL;
    Receita_Prod= (ReceitaProd*)malloc(sizeof(ReceitaProd));    // Alocacao dinamica Receita

    printf("Hello, Engenheiro Quimico! Seja bem vindo a fabrica de amaciante e detergente YpEQ!\n");

    do {
        printf("\n======= Menu principal =======\n\n");
        printf("Escolha o que deseja fabricar:\n");
        printf("1-Amaciante.\n");
        printf("2-Detergente.\n");
        printf("3-Calcular media de producao diaria\n");
        printf("4-Sair do programa.\n");

        scanf("%i", &menu1);
        setbuf(stdin,NULL);

        switch (menu1) {

            case 1: // Menu Principal -> Amanciante
                path_estoque="Estoque.txt"; // Define caminho do Arquivo DE estoque
                path_receita="Receita_Amaciante.txt"; // Define caminho do Arquivo DE estoque

                printf("\n======= Seja bem vindo ao setor de amaciante! =======\n");

                do {
                    printf("\nEscolha a opcao desejada.\n");
                    printf("1-Ver receita.\n");
                    printf("2-Adicionar insumos no estoque.\n");
                    printf("3-Fabricar produto.\n");
                    printf("4-Tipo do amaciante produzido.\n");
                    printf("5-Voltar ao menu principal!\n");

                    scanf("%i", &menu2);
                    setbuf(stdin,NULL);

                    switch (menu2) { // Menu Secundario (Setor Amaciante)
                        case 1: // Ver receita
                            VerReceita(path_receita);
                            break;

                        case 2: // Add estoque
                            Estoque(path_estoque, Estoque_Prod);
                            break;
                        case 3: // Fabricar Produtos
                            FabricarProduto(path_estoque,path_receita, Estoque_Prod, Receita_Prod);
                            break;
                        case 4: // Tipo do amaciante
                            tipo="Amaciante";
                            VerificarTipo(tipo);
                            break;

                    }

                } while (menu2 !=5);// menu amaciante -> EXIT
            break; // FIM CASE 1 -> MENU PRINCIPAL


            case 2: // Menu Principal -> Detergente
                path_estoque="Estoque.txt"; // Define caminho do Arquivo DE estoque
                path_receita="Receita_Detergente.txt"; // Define caminho do Arquivo DE estoque

                printf("\n======= Seja bem vindo ao setor de detergente! =======\n");

                do {
                    printf("\nEscolha a opcao desejada.\n");
                    printf("1-Ver receita.\n");
                    printf("2-Adicionar insumos no estoque.\n");
                    printf("3-Fabricar produto.\n");
                    printf("4-Tipo do detergente produzido.\n");
                    printf("5-Voltar ao menu principal!\n");

                    scanf("%i", &menu3);
                    setbuf(stdin,NULL);

                    switch (menu3) {
                        case 1:
                            VerReceita(path_receita);
                            break;
                        case 2:
                            Estoque(path_estoque, Estoque_Prod);
                            break;
                        case 3:
                            FabricarProduto(path_estoque,path_receita, Estoque_Prod, Receita_Prod);
                            break;
                        case 4:
                            tipo="Detergente";
                            VerificarTipo(tipo);
                            break;
                    }

                }while (menu3 != 5);// menu detergente -> EXIT

            break; // FIM CASE 2 -> MENU PRINCIPAL

            case 3:
                printf("Quantos produtos deseja fazer em 1 mes?\n");
                scanf("%i", &quantidade_mes);
                setbuf(stdin,NULL);
                prod_diaria=media(quantidade_mes, aux_media);
                printf("Sua producao diaria sera de: %i produtos ao dia.\n", prod_diaria);

                break; // FIM CASE 3 -> MENU PRINCIPAL

        }   // SWITCH MEU PRINCIPAL

    }while (menu1 != 4); // Menu Principal -> EXIT

    return 0;

}
