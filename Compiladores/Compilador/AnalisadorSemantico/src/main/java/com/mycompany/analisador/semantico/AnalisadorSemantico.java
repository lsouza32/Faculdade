package com.mycompany.analisador.semantico;

import com.mycompany.analisador.semantico.TabelaDeSimbolos.TipoGyh;
 
public class AnalisadorSemantico extends GyhBaseVisitor<Void> { // Classe visitor responsavel por criar a tabela de símbolos

    TabelaDeSimbolos tabela;    // Cria uma unica tabela de simbolos    
     
    @Override
    public Void visitPrograma(GyhParser.ProgramaContext ctx){
     // gera a tabela de simbolos
     // parametro ctx Contexto-> Gerado pelo analisador sintatico da regra Programa
        tabela = new TabelaDeSimbolos();    // gera a tabela de simbolos
        return super.visitPrograma(ctx); // return -> Definido pelo antlr. Nao usamos
    }
    
    @Override
    public Void visitDeclaracao(GyhParser.DeclaracaoContext ctx){
    //adiciona as variaveis declaradas na tabela
    //parametro ctx Contexto -> gerado pelo analisador sintatico da regra Declaracao
    
        String nomeVar = ctx.VARIAVEL().getText();  // Pega o nome da variavel
        String strTipoVar = ctx.tipoVar().getText();// Pega o tipo da variavel
        TipoGyh tipoVar;                            // Variavel auxiliar para adicionar na tabela
        //System.out.println("================="+strTipoVar); // teste
        tipoVar = switch(strTipoVar){            
            case "INT" -> TipoGyh.INTEIRO;  // Se inteiro-> atribui o tipo inteiro
            case "REAL" -> TipoGyh.REAL;        // Se real-> atribui o tipo real
            default -> TipoGyh.INVALIDO;         // Se nenhum dos 2 -> invalido
        };        
        
        if(tabela.existe(nomeVar)) {// Caso a variavel ja exista gera um erro de redeclaração de variavel
            GyhSemanticoUtils.adicionarErroSemantico(ctx.VARIAVEL().getSymbol(), "Variável " + nomeVar + " já existe");
        }else{
            //Caso contrario adiciona a variavel na tabela de simbolos
            tabela.adicionar(nomeVar, tipoVar);
        }      
        return super.visitDeclaracao(ctx); // return -> return -> Definido pelo antlr. Nao usamos
    }

    @Override
    public Void visitComandoAtribuicao(GyhParser.ComandoAtribuicaoContext ctx){     
     //Verifica se o tipo da expressao corresponde ao tipo da variavel      
     //parametro ctx Contexto -> gerado pelo analisador sintatico da regra ComandoAtribuicao      
     
        TipoGyh tipoExpressao = GyhSemanticoUtils.verificarTipo(tabela, ctx.expressaoAritmetica());  // Verifica o tipo da expressao Aritmetica
        
        if(tipoExpressao != TipoGyh.INVALIDO) {// caso a variavel nao for invalida
            String nomeVar = ctx.VARIAVEL().getText();  //variavel auxiliar
            
            if(!tabela.existe(nomeVar)){
                // Erro caso a variavel nao existe na tabela
                GyhSemanticoUtils.adicionarErroSemantico(ctx.VARIAVEL().getSymbol(), " Variável " + nomeVar + " não declarada");
            }
            else { // caso a variavel ja existir
                TipoGyh tipoVariavel = GyhSemanticoUtils.verificarTipo(tabela, nomeVar); 
                // Verifica o tipo e da erro caso o tipo for diferente
                if(tipoVariavel != tipoExpressao){
                    //System.out.println("----------------"+tipoVariavel); //teste
                    GyhSemanticoUtils.adicionarErroSemantico(ctx.VARIAVEL().getSymbol(), "Variável " + nomeVar + " não compatível com a expressão");
                }
            }
        }
        return super.visitComandoAtribuicao(ctx);// return -> Definido pelo antlr. Nao usamos
    }    
     
    @Override
    public Void visitComandoEntrada(GyhParser.ComandoEntradaContext ctx) {
      //Verifica se esta tentando ler uma variavel nao declarada
      //parametro ctx Contexto gerado pelo analisador sintatico da regra ComandoEntrada
        String nomeVar = ctx.VARIAVEL().getText();
        if(!tabela.existe(nomeVar)){
            GyhSemanticoUtils.adicionarErroSemantico(ctx.VARIAVEL().getSymbol(), "Variável " + nomeVar + " nao declarada");
        }
        return super.visitComandoEntrada ( ctx );// return -> Definido pelo antlr. Nao usamos
    }  
     
    @Override
    public Void visitExpressaoAritmetica(GyhParser.ExpressaoAritmeticaContext ctx){
     //Verifica o tipo da expressaoAritmetica
     //@param ctx Contexto gerado pelo analisador sintatico da regra ExpressaoAritmetica
        GyhSemanticoUtils.verificarTipo(tabela, ctx);
        return super.visitExpressaoAritmetica (ctx);// return -> Definido pelo antlr. Nao usamos
    }
}
