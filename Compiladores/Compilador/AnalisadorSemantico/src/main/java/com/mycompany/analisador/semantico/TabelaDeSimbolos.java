package com.mycompany.analisador.semantico;
import java.util.Map;
import java.util.HashMap;

public class TabelaDeSimbolos {//Armazena simbolos 

    public enum TipoGyh {//todos os tipos de variavel
        INTEIRO,
        REAL,
        INVALIDO
    }

    class EntradaTabelaDeSimbolos {// tabela de variaveis simbolo
        String nome;    // Nome da variável
        TipoGyh tipo;   // Tipo da variável

        private EntradaTabelaDeSimbolos ( String nome, TipoGyh tipo ) {//contrutor de variavel
            this.nome = nome;
            this.tipo = tipo;
        }
    }

    private final Map<String, EntradaTabelaDeSimbolos> tabela;// instancia a tabela como map

    public TabelaDeSimbolos() {//contrutor para tabela de simbolos
        this.tabela = new HashMap<>();
    }

    public void adicionar(String nome, TipoGyh tipo) {// adiciona simbolo na tabela 
        tabela.put(nome, new EntradaTabelaDeSimbolos(nome, tipo));
    }

    public boolean existe(String nome) {//Verifica se um simbolo existe na tabela
        return tabela.containsKey(nome);
    }

    public TipoGyh verificar(String nome) {//verifica o tipo de simbolo na tabela
        return tabela.get(nome).tipo;
    }
}