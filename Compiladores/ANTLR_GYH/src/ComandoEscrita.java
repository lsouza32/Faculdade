
public class ComandoEscrita extends Comando {
	private String id;
	
	@Override
	public String generateCode() {
		return "printf(\"%d\","+ id +");\n";
	}
	
	public ComandoEscrita(String id) {
		this.id=id;
	}


	public String getId() {
		return id;
	}


	public void setId(String id) {
		this.id = id;
	}
	
}
