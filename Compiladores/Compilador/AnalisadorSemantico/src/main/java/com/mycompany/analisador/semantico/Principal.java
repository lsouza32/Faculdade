// link video analisador sintatico:  https://drive.google.com/file/d/1-BsVwgMkAJzUsmQBQcNCeF48Xxa36wiK/view?usp=sharing
// link explicacao do Lucao analisador lexico: https://drive.google.com/drive/folders/1wO7T_Wan5s4fQQGINyjS2knw2ojL952c?usp=sharing

package com.mycompany.analisador.semantico;

import com.mycompany.analisador.semantico.GyhParser.ProgramaContext;
import java.io.IOException;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

public class Principal {
    public static void main(String args[]) throws IOException {
        CharStream cs = CharStreams.fromFileName(args[0]);// Armazena a entrada em CharStream

        GyhLexer lexer = new GyhLexer(cs);//Chama o lexico 

        CommonTokenStream tokens = new CommonTokenStream(lexer);// Armazena os tokens gerados em uma Tokenstream 

        GyhParser parser = new GyhParser(tokens);// Gera o parser do sintatico

        ProgramaContext arvore = parser.programa();// Gera a arvore de execução atraves do parser 

        AnalisadorSemantico as = new AnalisadorSemantico();// Cria o analisador semantico

        as.visitPrograma(arvore);// Faz a analise semantica a partir da regra Programa

        GyhSemanticoUtils.errosSemanticos.forEach((s) -> System.out.println(s));// printa os erros semanticos
    }
}