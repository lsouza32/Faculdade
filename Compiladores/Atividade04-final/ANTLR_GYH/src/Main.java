import java.io.IOException;
import java.util.HashMap;

import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

public class Main {
	
	/*
	public static void main(String[] args){
		HashMap<Integer, String> carro= new HashMap<Integer, String>();
		
		carro.put(1, "Corolla");
		carro.put(2, "Uno");
		carro.put(3, "Jeep");
		carro.put(4, "Pulse");
		carro.put(5, "Strada");
		
		for(int i=0; i<=carro.size(); i++) {
		System.out.println(carro.get(i));
		}
		
		System.out.println("\n-----------------");
		carro.remove(2);
		System.out.println("\n-----------------\n");
		
		for(String c: carro.values()) {
			System.out.println(c);
			}
	}
	*/
	
	public static void main(String[] args) throws IOException {
		CharStream cs = CharStreams.fromFileName("programa1.gyh");
		GyhLexer lexer = new GyhLexer(cs);
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		GyhParser parser = new GyhParser(tokens);
		parser.programa();
		parser.generateCommand();
		
		//Token t;
		//while((t=lexer.nextToken()).getType()!= Token.EOF) {
			//System.out.println("<"+ GyhParser.VOCABULARY.getDisplayName(t.getType()) +"," + t.getText()+ ">" );
		//}
		
		
		
	}
	
}
