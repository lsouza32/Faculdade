
public class ComandoAtribuicao extends Comando{
	private String id;
	private String expressao;				//id=exp; \n
	
	public ComandoAtribuicao(String id, String expressao) {
		this.id = id;
		this.expressao = expressao;
	}
	
	@Override
	public String generateCode() {
		return " "+id+ " = " + expressao + ";\n";
	}

}
