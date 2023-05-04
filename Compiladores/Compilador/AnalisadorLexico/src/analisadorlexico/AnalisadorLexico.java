//https://drive.google.com/drive/folders/1pj3kOjbh3DBm-iVPl2xc5YFOSVdy9rRM?usp=sharing
package analisadorlexico;

/**
 *
 * @author danie
 */
public class AnalisadorLexico {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Lex lex = new Lex(args[0]);
        
        Token t = null;
        
        while((t = lex.proximoToken()).tipo != TipoToken.EOF){ // looping para ler todos os tokens; t recebe proximo token até chegar no fim
            System.out.println(t);
        }
        System.out.println(t);
    }
    
}
