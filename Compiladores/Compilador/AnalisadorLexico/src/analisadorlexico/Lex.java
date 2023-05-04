package analisadorlexico;

public class Lex {
    LeitorArquivo myfile;
    
    public Lex(String arquivo){        
        myfile = new LeitorArquivo(arquivo);
    }

    private Token Parenteses(){// reconhecer os parenteses
        int caractere_lido=myfile.lerProximoCaractere();
        char c= (char)caractere_lido;
        if(c == '('){
                return new Token(TipoToken.AbrePar, "(");
        }else if(c == ')'){
            return new Token(TipoToken.FechaPar, ")");
        }else{
            return null;
        }
    }
    private Token operadorAritmetico(){  //identificador de OP Aritmetico      
        int caractere_lido=myfile.lerProximoCaractere();
        char c= (char)caractere_lido;
        if(c == '*'){
            return new Token(TipoToken.OpAritMult, "OpArtMult");
        }else if(c == '/'){
            return new Token(TipoToken.OpAritDiv, "OpArtDiv");
        }else if(c == '+'){
            return new Token(TipoToken.OpAritSoma, "OpArtSoma");
        }else if(c == '-'){
            return new Token(TipoToken.OpAritSub, "OpArtSub");
        }else {
            return null;
        }        
    }
    
    private Token delemitadorAtrib(){// reconhecer os delimitadores
       int caractere_lido=myfile.lerProximoCaractere();
       char c= (char)caractere_lido;
       if(c == ':'){
            c = (char)myfile.lerProximoCaractere();
            if(c == '='){
                return new Token(TipoToken.Atrib, ":=");
            }else{
                myfile.retroceder();// já que nao e um delimitador de 2 digitos,, volta um byte para seguir lendo o arquivo
                return new Token(TipoToken.Delim, ":");
                }
            }
       else{
           return null;
       }
    }

    
    private Token operadorRelacional(){// identifica os operadores relacionais
        int caractere_lido=myfile.lerProximoCaractere();
        char c= (char)caractere_lido;
        
        if(c == '<'){
            c = (char) myfile.lerProximoCaractere();
            if(c == '='){
                return new Token(TipoToken.OpRelMenorIgual, "<=");
            }else{
                myfile.retroceder();// já que nao e um op relacional de 2 digitos, volta um byte para seguir lendo o arquivo
                return new Token(TipoToken.OpRelMenor, "<");
            }   
        }else if(c == '>'){
            c = (char) myfile.lerProximoCaractere();
            if(c == '='){
                return new Token(TipoToken.OpRelMaiorIgual, ">=");
            }else{
                myfile.retroceder();
                return new Token(TipoToken.OpRelMaior, ">");
            }
        }else if(c == '='){
            c = (char) myfile.lerProximoCaractere();
            if(c == '='){
                return new Token(TipoToken.OpRelIgual, "==");
            }
        }else if(c == '!'){
            c = (char) myfile.lerProximoCaractere();
            if(c == '='){
                return new Token(TipoToken.OpRelDif, "!=");
            }                
        }else{
            return null;
        }
        return null;
    }
    
    private Token variavel(){// reconhecer as variaveis
        int estado = 1;
        while(true){
            char c = (char) myfile.lerProximoCaractere();
            if(estado == 1){
                if(Character.isLetter(c)){
                    estado = 2;
                }else{
                    return null;
                }
            }else if(estado == 2){
                if(! Character.isLetterOrDigit(c)){
                    myfile.retroceder();                    
                    return new Token(TipoToken.Var,myfile.getLexema());
                }
            }
        }
    }
    
    
    private Token numeros() {//reconhece inteiros e reais
        int estado = 1; //maquina de estados
        while (true) {
            char c = (char) myfile.lerProximoCaractere();
            if (estado == 1) {
                if (Character.isDigit(c)) {// verifica se e um digito
                    estado = 2;// digito passa pro proximo estado
                } else {
                    return null;
                }
            } else if (estado == 2) {// reconheceu um numero
                if (c == '.') {// verifica se possui um ponto(num real)
                    c = (char) myfile.lerProximoCaractere();
                    if (Character.isDigit(c)) {
                        estado = 3;// encontrou um numero seguindo de um ponto e outro numero, passa pro estado 3
                    } else {
                        return null;
                    }
                } else if (!Character.isDigit(c)) {// naop encontrou numero depois do ponto, logo e um inteiro
                    myfile.retroceder();
                    return new Token(TipoToken.NumInt, myfile.getLexema());
                }
            } else if (estado == 3) {
                if (!Character.isDigit(c)) {// chegou no estado 3 e nao possui mais digitos, entra como num real
                    myfile.retroceder();
                    return new Token(TipoToken.NumReal, myfile.getLexema());
                }
            }
        }
    }
     
     private Token palavrasChave(){// identifica palavras chaves
         while(true){
             char c = (char) myfile.lerProximoCaractere();

             if(! Character.isLetter(c)){
                 myfile.retroceder();
                 String lex = myfile.getLexema();

                 if(lex.equals("DEC")){
                     return new Token(TipoToken.PCDec, lex);
                 }else if (lex.equals("E")){
                     return new Token(TipoToken.OpBoolE, lex);
                 }else if (lex.equals("OU")){
                     return new Token(TipoToken.OpBoolOu, lex);
                 }else if (lex.equals("PROG")){
                     return new Token(TipoToken.PCProg, lex);
                 }else if (lex.equals("INT")){
                     return new Token(TipoToken.PCInt, lex);
                 }else if (lex.equals("LER")){
                     return new Token(TipoToken.PCLer, lex);
                 }else if (lex.equals("IMPRIMIR")){
                     return new Token(TipoToken.PCImprimir, lex);
                 }else if (lex.equals("SE")){
                     return new Token(TipoToken.PCSe, lex);
                 }else if (lex.equals("SENAO")){
                     return new Token(TipoToken.PCSenao, lex);
                 }else if (lex.equals("ENTAO")){
                     return new Token(TipoToken.PCEntao, lex);
                 }else if (lex.equals("ENQTO")){
                     return new Token(TipoToken.PCEnqto, lex);
                 }else if (lex.equals("INI")){
                     return new Token(TipoToken.PCIni, lex);
                 }else if (lex.equals("FIM")){
                     return new Token(TipoToken.PCFim, lex);
                 }else{                     
                     return null;
                 }
             }
         }
     }
     private Token cadeia(){// identifica nossa cadeira (digitos especiais, como \n)
         int estado = 1;
         while(true){
             char c = (char) myfile.lerProximoCaractere();
             
             if(estado == 1){
                 if(c == '"'){
                     estado = 2;
                 }else{
                     return null;
                 }
             }else if(estado == 2){
                 if(c == '\n'){
                     return null;
                 }
                 if(c == '"'){
                     return new Token(TipoToken.Cadeia, myfile.getLexema());
                 }
             }
         }
     }
     
     private Token fim(){// funcao para identificar fim do arquivo
         int Lido = myfile.lerProximoCaractere();
         if(Lido == -1){
             return new Token(TipoToken.EOF,"END FILE");
         }
         return null;
     }
  
   
    private void espacosEcomentarios() {// identifica espacos e comentarios; maquina de estados
        int estado = 1;
        while(true) {
            char c = (char) myfile.lerProximoCaractere() ;
            if(estado == 1) {
                if(Character.isWhitespace(c) || c == ' ') {// identifica espaco em branco
                    estado = 2;
                }else if(c == '#') {// identifica inicio de comentario
                    estado = 3;
                }else {
                    myfile.retroceder();
                    return;
                }
            }else if(estado == 2) {
                if(c == '#') {// verifica novamente se e um comentario
                    estado = 3;
                }else if(!(Character.isWhitespace(c) || c == ' ')) {
                    myfile.retroceder();
                    return;
                }
            }else if(estado == 3) {// identificou comentario
                if(c == '\n') {// troca o comentario por um pula linha para ignorar o comentario
                return;
                }
            }
        }
    }
     
       public Token proximoToken() {//funcao para identificar o token testando um por um
        Token proximo = null;
        espacosEcomentarios(); // primeiro remove os espacos e comentarios
        espacosEcomentarios();
        myfile.confirmar(); // confimar para continuar lendo arquivo
        
        proximo = fim(); // verifica se e o fim do arquivo
        if (proximo == null) {// nao encontrou o lexema
            myfile.zerar();
        } else {
            myfile.confirmar();// econtrou o lexema
            return proximo;
        }
        proximo = palavrasChave();// verifica se e palavra chave
        if (proximo == null) {//nao encontrou o lexema como palavra chave
            myfile.zerar(); // volta pro inicio e testa proximo se e outro tipo de token
        } else {
            myfile.confirmar();// encontrou lexema
            return proximo; // testa proximo token
        }
        proximo = variavel();// verifica se e variavel
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        proximo = numeros();
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        proximo = operadorAritmetico();
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        proximo = operadorRelacional();
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        proximo = delemitadorAtrib();
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        proximo = Parenteses();
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        proximo = cadeia();
        if (proximo == null) {
            myfile.zerar();
        } else {
            myfile.confirmar();
            return proximo;
        }
        System.out.println("------- ATENCAO ERRO LEXICO -------");// caso nao encontre o lexema em nenhum dos token definidos, nao pertence ao alfabeto da linguagem
        System.out.println("Error "+myfile.toString());//imprime o erro
        return null;
    }
}