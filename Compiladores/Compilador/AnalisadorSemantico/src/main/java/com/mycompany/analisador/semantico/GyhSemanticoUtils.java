package com.mycompany.analisador.semantico;

import java.util.ArrayList;
import org.antlr.v4.runtime.Token;
import java.util.List;

// Metodos que verificam os erros semanticos
 
public class GyhSemanticoUtils {
    public static List<String> errosSemanticos = new ArrayList<>();                                                         // OS erros semanticos serão armazenados nessa lista
    
    
     //parametro t Token gerador do erro
     //parametro mensagem Mensagem do erro semantico     
    public static void adicionarErroSemantico (Token t, String mensagem) {      
        int linha = t.getLine();                // recupera a linha do erro
        int coluna = t.getCharPositionInLine(); // coluna do erro
        errosSemanticos.add (String.format ("---- Atenção Erro em %d:%d - %s", linha, coluna, mensagem));                            // inclui o erro na lista errosSemanticos
    }
    
    
     //Verifica se conteudo recebido por parametro e Expressão Aritmetica
     //retorna o Tipo do contexto passado por parametro
    public static TabelaDeSimbolos.TipoGyh verificarTipo (TabelaDeSimbolos tabela, GyhParser.ExpressaoAritmeticaContext ctx) {
        TabelaDeSimbolos.TipoGyh ret = null;         // Variável TipoGyh que será retornada
        for (var ta : ctx.termoAritmetico()) {                                
            TabelaDeSimbolos.TipoGyh aux = verificarTipo(tabela, ta);
            if ( ret == null ) {// inicializar o tipo da variável de retorno    
                ret = aux;// Reporta um erro semântico caso o tipo do novo termo em aux for diferente do que estava armazenado em ret
            }                                                                                                                                  
            else if (ret != aux && aux != TabelaDeSimbolos.TipoGyh.INVALIDO) {
                adicionarErroSemantico (ctx.start, "Expressao " + ctx.getText() + " é incompatível entre os tipos");      // Adiciona o erro semântico na lista
                ret = TabelaDeSimbolos.TipoGyh.INVALIDO;        // indicador que houve um erro invalidando a sequencia  e não irA mais entrar no "se" acima                                                                      
            }
        }
        return ret;
    }

    
    // Semelhante ao metodo acima, porem agora para tratar problemas com base no Fator Aritmetico
     
    public static TabelaDeSimbolos.TipoGyh verificarTipo(TabelaDeSimbolos tabela, GyhParser.TermoAritmeticoContext ctx){
        TabelaDeSimbolos.TipoGyh ret = null;
        for(var fa : ctx.fatorAritmetico()){
            TabelaDeSimbolos.TipoGyh aux = verificarTipo(tabela, fa);
            if(ret == null){
                ret = aux;
            }
            else if (ret != aux && aux != TabelaDeSimbolos.TipoGyh.INVALIDO){
                adicionarErroSemantico (ctx.start, "Termo " + ctx.getText() + " é incompatível entre os tipos");
                ret = TabelaDeSimbolos.TipoGyh.INVALIDO;
            }
        }
        return ret;
    }

    
    public static TabelaDeSimbolos.TipoGyh verificarTipo (TabelaDeSimbolos tabela, GyhParser.FatorAritmeticoContext ctx){         
        if (ctx.NUMINT() != null){
            return TabelaDeSimbolos.TipoGyh.INTEIRO;  // se em NUMINT receber algo diferente de NULL, portanto é um número inteiro de fato
        }
        else if (ctx.NUMREAL()!=null){
            return TabelaDeSimbolos.TipoGyh.REAL;
        }
        else if(ctx.VARIAVEL() != null) {                    // se em VARIAVEL receber algo diferente de NULL, sera feito a verificação se está no programa
            String nomeVar = ctx.VARIAVEL().getText();
            if (!tabela.existe(nomeVar)){        // caso nao existir , será retornado um erro semantico
                adicionarErroSemantico(ctx.VARIAVEL().getSymbol(), "Variável " + nomeVar + " não declarada");
                return TabelaDeSimbolos.TipoGyh.INVALIDO;
            }
            return verificarTipo(tabela, nomeVar);     // retorna simultaneamente ao tempo em que verifica os tipos de variavel
        }
        return verificarTipo(tabela, ctx.expressaoAritmetica()); // caso nao se enquadre nos termos acima, só pode ser expressão aritmetica
    }
    
   
    public static TabelaDeSimbolos.TipoGyh verificarTipo(TabelaDeSimbolos tabela, String nomeVar){
        return tabela.verificar (nomeVar);
    }
}