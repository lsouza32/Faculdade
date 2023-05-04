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


//----------------------------------------
	private String _expressaoVar;
	private String _expressaoConteudo;

	private String _condicao;
	private ArrayList<Comando> _condTrue = new ArrayList<Comando>();
	private ArrayList<Comando> _condFalse = new ArrayList<Comando>();

	private String _writeVar;
	private String _readVar;
	private ArrayList<Comando> listCmd = new ArrayList<Comando>();
	private ArrayList<Comando> listAux = new ArrayList<Comando>();
	private ProgramaGyh programa = new ProgramaGyh();
//----------------------------------------

	public void generateCommand(){
		programa.generateTarget();
		System.out.println("\n-> Gera codigo");
}



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

//OP_ARIT1: '+' |  '-' ;

//OP_ARIT2: '*' |  '/' ;

OP_REL : '>' | '>=' | '<' | '<=' | '!=' | '==';
fragment
ESC_SEQ : '\\\'';
COMENTARIO : '#' ~('\n'|'\r')* '\r'? '\n' {skip();};
WS : ( ' ' |'\t' | '\r' | '\n') {skip();};
	
programa : ':' 'DEC' listaDeclaracoes ':' 'PROG' listaComandos EOF
		{
		System.out.println("Programa: TabelaVar");
		programa.setTabelaVar(tabela_Hash);
		programa.setComando(listCmd);
		}
;


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

//expressaoAritmetica : termoAritmetico (OP_ARIT1 termoAritmetico)*;

expressaoAritmetica: termoAritmetico 
					'+' {_expressaoConteudo+=" + ";}
 				termoAritmetico 
				| termoAritmetico 
					'-' {_expressaoConteudo+=" - ";}
			 	termoAritmetico
				| termoAritmetico;

//termoAritmetico : fatorAritmetico (OP_ARIT2 fatorAritmetico)*;

termoAritmetico: fatorAritmetico 
					'*' {_expressaoConteudo+=" * ";}
 				fatorAritmetico 
				| fatorAritmetico 
					'/' {_expressaoConteudo+=" / ";}
			 	fatorAritmetico
				| fatorAritmetico;

fatorAritmetico : NUMINT   {_expressaoConteudo+=_input.LT(-1).getText();}
			  | NUMREAL  {_expressaoConteudo+=_input.LT(-1).getText();}
			  | VARIAVEL {_expressaoConteudo+=_input.LT(-1).getText();};
			 // | '(' expressaoAritmetica ')';





operadorBooleano : 'E' | 'OU';

listaComandos : (comando
			  {
				listCmd.addAll(listAux);
				listAux.removeAll(listAux);
			  }
			 )+;

comando : comandoAtribuicao | comandoEntrada | comandoSaida | comandoCondicao | comandoRepeticao | subAlgoritmo;

comandoAtribuicao : VARIAVEL {verificaVar(_input.LT(-1).getText());
						_expressaoVar =_input.LT(-1).getText();			
						}
						 ':=' {_expressaoConteudo="";}
						expressaoAritmetica
							    {
								ComandoAtribuicao cmd = new ComandoAtribuicao(_expressaoVar, _expressaoConteudo);
								listAux.add(cmd);
							    };

comandoEntrada : 'LER' VARIAVEL 
					{verificaVar(_input.LT(-1).getText());
					_readVar = _input.LT(-1).getText();
					ComandoLeitura cmd = new ComandoLeitura(_readVar);
					listAux.add(cmd);
					System.out.println(cmd.toString());
					};

comandoSaida : 'IMPRIMIR' (VARIAVEL {verificaVar(_input.LT(-1).getText());
							   _writeVar = _input.LT(-1).getText();
						        ComandoEscrita cmd = new ComandoEscrita(_writeVar);
						        listAux.add(cmd);
							   System.out.println(cmd.toString());
						
								} |'IMPRIMIR' CADEIA);

comandoCondicao : 'SE' {_condicao=" ";}
			   expressaoRelacional 'ENTAO' 
			   comando {
					_condTrue.addAll(listAux);
					listAux.removeAll(listAux);
					}


			   ('SENAO' comando
					{
					_condFalse.addAll(listAux);
					listAux.removeAll(listAux);
					}

				)?

				{ComandoCondicao cmd = new ComandoCondicao(_condicao,_condTrue, _condFalse);
				listAux.add(cmd);
				};	


expressaoRelacional : expressaoAritmetica 
				   OP_REL {_condicao+=" "; _condicao+=_input.LT(-1).getText();}
				   expressaoAritmetica {_condicao+=" "; _condicao+=_expressaoConteudo;_expressaoConteudo="";}
			       | termoRelacional
				  {_condicao+=" "; _condicao+=_expressaoConteudo;_expressaoConteudo="";}
				  ;

termoRelacional :            {_expressaoConteudo="";}
				expressaoAritmetica 
				OP_REL    {_condicao+=" "; _condicao+=_input.LT(-1).getText();}
				expressaoAritmetica 
			   |           
				'('	{_condicao=" (";}
				    expressaoRelacional 
			     ')'	{_condicao+=" )";};

comandoRepeticao : 'ENQTO' expressaoRelacional comando;

subAlgoritmo : 'INI' listaComandos 'FIM';