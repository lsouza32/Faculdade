grammar Gyh;

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
declaracao : VARIAVEL ':' tipoVar;
tipoVar : 'INT' | 'REAL';
expressaoAritmetica : termoAritmetico (OP_ARIT1 termoAritmetico)*;
termoAritmetico : fatorAritmetico (OP_ARIT2 fatorAritmetico)*;
fatorAritmetico : NUMINT | NUMREAL | VARIAVEL | '(' expressaoAritmetica ')';
expressaoRelacional : expressaoRelacional operadorBooleano termoRelacional | termoRelacional;
termoRelacional : expressaoAritmetica OP_REL expressaoAritmetica | '(' expressaoRelacional ')';
operadorBooleano : 'E' | 'OU';
listaComandos : comando listaComandos |comando;
comando : comandoAtribuicao | comandoEntrada | comandoSaida | comandoCondicao | comandoRepeticao | subAlgoritmo;
comandoAtribuicao : VARIAVEL ':=' expressaoAritmetica;
comandoEntrada : 'LER' VARIAVEL;
comandoSaida : 'IMPRIMIR' (VARIAVEL | CADEIA);
comandoCondicao : 'SE' expressaoRelacional 'ENTAO' comando | 'SE' expressaoRelacional 'ENTAO' comando 'SENAO' comando;	
comandoRepeticao : 'ENQTO' expressaoRelacional comando;
subAlgoritmo : 'INI' listaComandos 'FIM';