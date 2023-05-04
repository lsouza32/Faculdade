package analisadorlexico;


public class Token {
    public String lexema;
    public TipoToken tipo;
    
    
    public Token(TipoToken nome, String lexema) {
        this.tipo=nome; //token recebe o tipo, int, var, etc...
        this.lexema=lexema; // recebe o lexema
    }

    @Override
    public String toString() {// tostring para printar o lexema e seu tipo
         return "<"+tipo+","+lexema+">"; //representação de uma string da classe token
    }
    
    
}
