import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;

public class ProgramaGyh {
	private Tabela_Hash tabelaVar;
	private ArrayList<Comando> comando;
	
	
	public ArrayList<Comando> getComando() {
		return comando;
	}

	public void setComando(ArrayList<Comando> comando) {
		this.comando = comando;
	}

	public void generateTarget() {
		StringBuilder str = new StringBuilder();
		
		str.append("#include<stdio.h>\n");
        str.append("#include<stdlib.h>\n\n\n");
        //talvez tenha que incluir mais bibliotecas ...
        str.append("void main(){ \n");
        //for para pegar todos os simbolos da var table
        for(Simbolos simbolo: tabelaVar.getAll()){
            str.append(simbolo.generateCode());
        }

        for(Comando cmd: comando) {
        	str.append(cmd.generateCode());
        }

        str.append("}");// fecha chave da main
        
        try {
        	FileWriter file = new FileWriter(new File("PROGRAMA_GYH.c"));
        	file.write(str.toString());
        	file.close();
        	
        }
        catch(Exception ex) {
        	
        }
        
        
    }

	public Tabela_Hash getTabelaVar() {
		return tabelaVar;
	}

	public void setTabelaVar(Tabela_Hash tabelaVar) {
		this.tabelaVar = tabelaVar;
	}
}

