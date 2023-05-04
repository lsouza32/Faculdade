// Arrumamos o erro do comentario na primeira linha (analisador lexico)
// Não conseguimos arrumar o erro  No programa2.gyh, disponibilizado, está
//reconhecendo <Var,INt>, ele reconhece como "INt" sendo uma variavel. Isso está afetando um pouco o Sintatico no programa 10;
// No sintatico também ocorre um erro caso tente usar a "ATRIBUICAO" antes de um "INI";

//video: https://drive.google.com/file/d/1We1RguyaiV9G4tWTo3OSORz_1_gjypWB/view?usp=sharing

package analisadorsintatico;

import analisadorlexico.Lex;


// classe principal para construir o Analisador
public class MyMain {
    public static void main(String args[]){
        Lex lex= new Lex(args[0]); // args[0] pra ler pela linha de comando
        AnalisadorSintatico sintaxe= new AnalisadorSintatico(lex); // recebe o analisador lexíco como parametro para ser iniciado
        sintaxe.programa(); // Análise Sintática top-down
                            // constrói lista na ordem em que os elementos vão aparecendo
                            // Nessa etapa são analisados todos os matchs (entre os tokens)
                            // caso aconteça algum problema, o Analisador sintático acusará, como esperado de uma análise sintática.
    }
}
