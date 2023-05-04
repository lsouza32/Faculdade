//analisador sintático preditivo descendente recursivo ALL(*)
package analisadorsintatico;

//importa do projeto anteriror
import analisadorlexico.Lex;
import analisadorlexico.TipoToken;
import analisadorlexico.Token;

import java.util.ArrayList;
import java.util.List;


public class AnalisadorSintatico {
    private final static int tam_buffer=20; //tamanho do buffer
    List<Token> buffer_token; //lista de buffers
    Lex lex; //chama o     boolean fim_leitura = false;// controle da leituralex
    boolean fim_leitura = false;// controle da leitura
    
    public AnalisadorSintatico(Lex lex){
        this.lex=lex;// inicializa o lex no construtor
        buffer_token= new ArrayList<>(); // lista simples arraylist
        read_token();// faz a primeira leitura de um token
    }
    
    private void read_token(){// busca no lexico um token para preencher o buffer
        if(buffer_token.size()>0){
            buffer_token.remove(0);
        }
        while(buffer_token.size() < tam_buffer && !fim_leitura){// chama o proximo token enquanto nao encher o buffer e nao for o fim do arquivo
            Token proximo= lex.proximoToken();
            buffer_token.add(proximo);
            if(proximo.tipo == TipoToken.EOF){// achou final do arquivo
                fim_leitura=true;
            }
        }
        System.out.println("Lido: "+ lookahead(1));//printa o token lido
    }
    
    Token lookahead(int cont){//olha cont simboloas a frente 
        if(buffer_token.isEmpty()){//tratamento de erro se for vazio retornaa nulo
            return null;
        }
        if(cont-1 >= buffer_token.size()){//retona o o ultimo token ... tratamento de erro
            return buffer_token.get(buffer_token.size() -1);
        }
        return buffer_token.get(cont -1);
    }
    
    void match(TipoToken tipo){// verifica se é o token esperado
        if(lookahead(1).tipo == tipo){
            System.out.println("Match: "+lookahead(1));
            read_token();// avança a leitura
        }else{// se não for erro
            erro_sintaxe(tipo.toString());
        }
    }
    
    void erro_sintaxe(String... aux){// printa o erro e diz o que deveria ter lido
        String msg_erro="Erro sintatico: esperando um dos seguintes (";// mostra o que era esperado
        for(int i=0; i<aux.length;i++){
            msg_erro+= aux[i];
            if(i<aux.length-1){
                msg_erro+=",";
            }
        }
        msg_erro+="), mas foi encontrado"+lookahead(1);//mostra o que foi encontrado no lugar
        throw new RuntimeException(msg_erro);
    }
    
//Programa → ':' 'DEC' ListaDeclaracoes ':' 'PROG' ListaComandos;
    public void programa(){//simula a estrutura sintatica do programa 
        match(TipoToken.Delim);//primeiro identifica o delimitadro
        match(TipoToken.PCDec);// ent~ao a declaração
        lista_declaracoes();//lista a declaração
        match(TipoToken.Delim);
        match(TipoToken.PCProg);
        lista_comandos();        
    }
 
//ListaDeclaracoes → Declaracao ListaDeclaracoes | Declaracao;
    public void lista_declaracoes(){
        //look ahead(4) pois tomando a variavel como exemplo primeiro lemos um simbolo depois o :
        //int ou real ou seja temos 3 simbolos
        // e queremos olhar o proximo depois do terceiro
        if(lookahead(4).tipo== TipoToken.Delim){
            declaracao();            
        }else if(lookahead(4).tipo==TipoToken.Var){            
            declaracao();            
            lista_declaracoes();
        }
        else{
            erro_sintaxe(TipoToken.Delim.toString(),TipoToken.Var.toString());
        }        
    }

//Declaracao → VARIAVEL ':' TipoVar;
    public void declaracao(){// verifica se a variavel realmen é var e se o delimitar esta correto
        match(TipoToken.Var);
        match(TipoToken.Delim);
        tipo_variavel();// apos a declaração devemos ter uma variavel        
    }

//TipoVar → 'INT' | 'REAL';
    public void tipo_variavel(){
        if(lookahead(1).tipo == TipoToken.PCInt){// se o proximo token forint
            match(TipoToken.PCInt);// ahcamaos um int 
        }else if(lookahead(1).tipo==TipoToken.PCReal){//se o proximo for real 
            match(TipoToken.PCReal);//mach real
        }else{//se nao erro, era espererado um num int ou real
            erro_sintaxe("Inteiro","Real");
        }        
    }

//ExpressaoAritmetica → ExpressaoAritmetica '+' TermoAritmetico | ExpressaoAritmetica '-' TermoAritmetico | TermoAritmetico;
    public void expressao_aritmetica(){
         termo_aritmetico();
         expressao_aritmetica2();
    }
    public void expressao_aritmetica2(){
        //o look ahead deve ser apenas o operador + ou o operador -
        if(lookahead(1).tipo == TipoToken.OpAritSoma || lookahead(1).tipo== TipoToken.OpAritSub){
            expressao_aritmetica2_subregra();
            expressao_aritmetica2();//pode ser uma cadeia de somas e subtraçoes
        }else{
            //vazio
        }
    }
    public void expressao_aritmetica2_subregra(){
        if(lookahead(1).tipo == TipoToken.OpAritSoma){// encontra +
            match(TipoToken.OpAritSoma);
            termo_aritmetico();
        }
        else if(lookahead(1).tipo == TipoToken.OpAritSub){//encontra - 
            match(TipoToken.OpAritSub);
            termo_aritmetico();
        }else{//se nõ esva esperando + ou - e não foi encontrado
            erro_sintaxe("+","-");
        }
        
    }
    
//TermoAritmetico → TermoAritmetico '*' FatorAritmetico | TermoAritmetico '/' FatorAritmetico | FatorAritmetico;
    //re petimos a logica acima para +  e -  agora pra operações de * e /
    public void termo_aritmetico(){
        fator_aritmetico();
        termo_aritmetico2();
    }
    public void termo_aritmetico2(){
        if(lookahead(1).tipo == TipoToken.OpAritMult || lookahead(1).tipo==TipoToken.OpAritDiv){
            termo_aritmetico2_subregra();
            termo_aritmetico2();
        }else{
            //vazio
        }
    }
    public void termo_aritmetico2_subregra(){
        if(lookahead(1).tipo == TipoToken.OpAritMult){
            match(TipoToken.OpAritMult);
            fator_aritmetico();
        }else if(lookahead(1).tipo == TipoToken.OpAritDiv){
            match(TipoToken.OpAritDiv);
            fator_aritmetico();
        }else{
            erro_sintaxe("*","/");
        }
    }
//FatorAritmetico → NUMINT | VARIAVEL | '(' ExpressaoAritmetica ')'
    public void fator_aritmetico(){
        // temos que ver qual é se num int, num real, var, abre ou fecha parenteses 
        if(lookahead(1).tipo == TipoToken.NumInt){
            match(TipoToken.NumInt);
        }else if(lookahead(1).tipo == TipoToken.NumReal){
            match(TipoToken.NumReal);
        }else if(lookahead(1).tipo == TipoToken.Var){
            match(TipoToken.Var);
        }else if(lookahead(1).tipo== TipoToken.AbrePar){
            match(TipoToken.AbrePar);
            expressao_aritmetica();
            match(TipoToken.FechaPar);
        }else {// se não for nem um destes-> erro 
            erro_sintaxe("NumInt","NumReal","Variavel","(");
        }
    }
//ExpressaoRelacional → ExpressaoRelacional OperadorBooleano TermoRelacional | TermoRelacional;
    public void expressao_relacional(){
        termo_relacional();
        expressao_relacional2();
    }
    public void expressao_relacional2(){
        if(lookahead(1).tipo == TipoToken.OpBoolE || lookahead(1).tipo==TipoToken.OpBoolOu){
            operador_boolean();
            termo_relacional();
            expressao_relacional2();
        }else{
            //vazio
        }
    }
//TermoRelacional → ExpressaoAritmetica OP_REL ExpressaoAritmetica | '(' ExpressaoRelacional ')';
    public void termo_relacional(){
        //se o primeiro toke for numero, variavel ou abre parenteses podemos esta iniciando uma expressao
        if(lookahead(1).tipo == TipoToken.NumInt|| lookahead(1).tipo == TipoToken.NumReal ||
                lookahead(1).tipo == TipoToken.Var|| lookahead(1).tipo == TipoToken.AbrePar){
            expressao_aritmetica();
            op_relacional();
            expressao_aritmetica();
            
        //abre parentese esta nos dois casos 
        }else if(lookahead(1).tipo == TipoToken.AbrePar){
            match(TipoToken.AbrePar);
            expressao_relacional();
            match(TipoToken.FechaPar);
        }else{// se não erro esperava numero, var ou abre par
            erro_sintaxe("NumInt", "NumReal","Var","(");
        }
    }
    public void op_relacional(){
        //checa os operadores relaciopnas
        if(lookahead(1).tipo == TipoToken.OpRelDif){
            match(TipoToken.OpRelDif);
        }else if(lookahead(1).tipo == TipoToken.OpRelIgual){
            match(TipoToken.OpRelIgual);
        }else if (lookahead(1).tipo == TipoToken.OpRelMaior){
            match(TipoToken.OpRelMaior);
        }else if (lookahead(1).tipo == TipoToken.OpRelMaiorIgual){
            match(TipoToken.OpRelMaiorIgual);
        }else if (lookahead(1).tipo == TipoToken.OpRelMenor){
            match(TipoToken.OpRelMenor);
        }else if (lookahead(1).tipo == TipoToken.OpRelMenorIgual){
            match(TipoToken.OpRelMenorIgual);
        }else{
            erro_sintaxe("!=","==",">",">=", "<","<=");
           // erro_sintaxe
        }
    }
    
//OperadorBooleano → 'E' | 'OU';
    public void operador_boolean(){//check operadores booleanos
        if(lookahead(1).tipo == TipoToken.OpBoolE){
            match(TipoToken.OpBoolE);
        }else if(lookahead(1).tipo == TipoToken.OpBoolOu){
            match(TipoToken.OpBoolOu);
        }else{
            erro_sintaxe("E","OU");
        }
    }
//ListaComandos → Comando ListaComandos | Comando;
    public void lista_comandos(){
        comando();
        lista_comandos_subregra();
        
    }
    void lista_comandos_subregra() {
        // checa as possibilidades de inicio de comando
        if (lookahead(1).tipo == TipoToken.Atrib ||
        lookahead(1).tipo == TipoToken.PCLer ||
        lookahead(1).tipo == TipoToken.PCImprimir ||
        lookahead(1).tipo == TipoToken.PCSe ||
        lookahead(1).tipo == TipoToken.PCEnqto ||
        lookahead(1).tipo == TipoToken.PCIni) {            
            lista_comandos();// lista ao final
        } else {
           //vazio, acabou a lista de comandos...
        }
    }

//Comando → ComandoAtribuicao | ComandoEntrada | ComandoSaida | ComandoCondicao | ComandoRepeticao | SubAlgoritmo;
    void comando() {// verifica se é comnado 
        if (lookahead(1).tipo == TipoToken.Var) {
            comando_atribuicao();                         
        } else if (lookahead(1).tipo == TipoToken.PCLer) {
            comando_entrada();
        } else if (lookahead(1).tipo == TipoToken.PCImprimir) {
            comando_saida();
        } else if (lookahead(1).tipo == TipoToken.PCSe) {
            comando_condicao();
        } else if (lookahead(1).tipo == TipoToken.PCEnqto) {
            comando_repeticao();
        } else if (lookahead(1).tipo == TipoToken.PCIni) {
            sub_algoritmo();
        } else {
            erro_sintaxe("ATRIBUIR","LER","IMPRIMIR","SE","ENQUANTO","INICIO");
        }
    }
//ComandoAtribuicao → VARIAVEL ':=' ExpressaoAritmetica;
    void comando_atribuicao() {//Metodo usado para encontrar uma atribuicao
        match(TipoToken.Var);
        match(TipoToken.Atrib);      
        expressao_aritmetica();        
    }
//ComandoEntrada → 'LER' VARIAVEL;
    void comando_entrada() {//metodo usado para encontrar um comando de entrada
        match(TipoToken.PCLer);
        match(TipoToken.Var);
    }
//ComandoSaida → 'IMPRIMIR'  (VARIAVEL | CADEIA);
    void comando_saida() {//metodo usado para encontrar um comando de saida
        match(TipoToken.PCImprimir);
        comando_saida_subregra();
    }
    void comando_saida_subregra() {
        if (lookahead(1).tipo == TipoToken.Var) {
            match(TipoToken.Var);
        } else if (lookahead(1).tipo == TipoToken.Cadeia) {
            match(TipoToken.Cadeia);
        } else {
            erro_sintaxe(TipoToken.Var.toString(),TipoToken.Cadeia.toString());
        }
    }
//ComandoCondicao → 'SE' ExpressaoRelacional 'ENTAO' Comando | 'SE' ExpressaoRelacional 'ENTAO' Comando 'SENAO' Comando;
    void comando_condicao() {
        match(TipoToken.PCSe);
        expressao_relacional();
        match(TipoToken.PCEntao);
        comando();
        comando_condicao_subregra();
    }

    void comando_condicao_subregra() {
        if (lookahead(1).tipo == TipoToken.PCSenao) {
            match(TipoToken.PCSenao);
            comando();
        } else {
            // vazio
        }
    }
//ComandoRepeticao → 'ENQUANTO' ExpressaoRelacional Comando;
    void comando_repeticao() {//verifica repetição
        match(TipoToken.PCEnqto);
        expressao_relacional();
        comando();
    }
//SubAlgoritmo → 'INI' ListaComandos 'FIM';
     void sub_algoritmo() {
        match(TipoToken.PCIni);       
        while(lookahead(1).tipo!=TipoToken.PCFim){//lista comandos até chegar no pcFim
            lista_comandos();
        } 
        match(TipoToken.PCFim);
    }     
}
