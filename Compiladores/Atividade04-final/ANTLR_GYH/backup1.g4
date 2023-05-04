grammar Gyh;

@header{
	import java.util.ArrayList;
}

@members{
	private String _varName;
	private int _varTipo;
	private String _varValue;
	private Simbolos _varSimbolo;
	private Tabela_Hash tabela_Hash = new Tabela_Hash();

	public void verificaVar(String nomeVar){
		if(!tabela_Hash.existe(nomeVar)){
			System.out.println("Erro Semantico. Motivo: Variavel nao declarada!" + nomeVar);
		}

	}
}

NUMINT : ('0'..'9')+;
NUMREAL: ('0'..'9')+ '.' ('0'..'9')+;
VARIAVEL : ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'0'..'9')*;
CADEIA : '\'' ( ESC_SEQ | ~('\''|'\\') )* '\'';
OP_ARIT1: '+' | '-';
OP_ARIT2: '*' | '/';
OP_REL : '>' | '>=' | '<' | '<=' | '!=' | '==';
fragment
ESC_SEQ : '\\\'';
COMENTARIO : '#' ~('\n'|'\r')* '\r'? '\n' {skip();};
WS : ( ' ' |'\t' | '\r' | '\n') {skip();};
	
programa : ':' 'DEC' listaDeclaracoes ':' 'PROG' listaComandos EOF;
listaDeclaracoes : declaracao listaDeclaracoes | declaracao;

declaracao : VARIAVEL ':' tipoVar {
						_varName =_input.LT(-3).getText();
						_varTipo =0; //_input.LT(-1).getText();
						_varValue = null;
						_varSimbolo = new Simbolos(_varName, _varTipo, _varValue);
						if(!tabela_Hash.existe(_varName)){
							tabela_Hash.add(_varSimbolo);
							System.out.println("Adicionado um Simbolo" + _varSimbolo);
						}
						else{
							System.out.println("Erro Semantico. tentando adicionar dnv o: " + _varSimbolo);
						}
};

tipoVar : 'INT' | 'REAL';
expressaoAritmetica : termoAritmetico (OP_ARIT1 termoAritmetico)*;
termoAritmetico : fatorAritmetico (OP_ARIT2 fatorAritmetico)*;

fatorAritmetico : NUMINT | NUMREAL | VARIAVEL {verificaVar(_input.LT(-1).getText());
								} | '(' expressaoAritmetica ')';

expressaoRelacional : expressaoRelacional operadorBooleano termoRelacional | termoRelacional;
termoRelacional : expressaoAritmetica OP_REL expressaoAritmetica | '(' expressaoRelacional ')';
operadorBooleano : 'E' | 'OU';
listaComandos : comando listaComandos |comando;
comando : comandoAtribuicao | comandoEntrada | comandoSaida | comandoCondicao | comandoRepeticao | subAlgoritmo;
comandoAtribuicao : VARIAVEL {verificaVar(_input.LT(-1).getText());
								} ':=' expressaoAritmetica;
comandoEntrada : 'LER' VARIAVEL;
comandoSaida : 'IMPRIMIR' (VARIAVEL | CADEIA);
comandoCondicao : 'SE' expressaoRelacional 'ENTAO' comando | 'SE' expressaoRelacional 'ENTAO' comando 'SENAO' comando;	
comandoRepeticao : 'ENQTO' expressaoRelacional comando;
subAlgoritmo : 'INI' listaComandos 'FIM';