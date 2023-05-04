import java.util.ArrayList;

public class ComandoCondicao extends Comando{
	private String condicao;
	private ArrayList<Comando>listTrue;
	private ArrayList<Comando>listFalse;
	
	
	public ComandoCondicao(String cond, ArrayList<Comando> lt, ArrayList<Comando>lf) {
		this.condicao=cond;
		this.listTrue=lt;
		this.listFalse=lf;
	}
	
	public String generateCode() {
		String str = "if ("+condicao+") {\n";
		for(Comando cmd: listTrue) {
			str+=cmd.generateCode();
		}
		str+="}\n";      // fechando o if
		
		if(listFalse.size()>0) {
			str+="else {\n";
			for(Comando cmd: listFalse) {
				str+=cmd.generateCode();
			}
			str+="}\n";
		}
	return str;
	} 
	
}
