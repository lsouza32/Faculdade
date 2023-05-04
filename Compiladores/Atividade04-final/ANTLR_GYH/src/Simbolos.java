
public class Simbolos {
	private String name;
	private int type;
	private String value;
	
	public static final int REAL   = 1;
	public static final int INT    = 0;
	
	public String generateCode() {
		String str;
		if(type==INT) str= "\tint "+name+";\n";      //int nome;
		else str= "\tdouble "+name+";\n";
		return str;
	}
	
	public Simbolos(String name, int type, String value) {
		this.name=name;
		this.type=type;
		this.value=value;
		
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}
	
	@Override
	public String toString() {
		return "Simbolos [name=" + this.name + "type" + type + " value=" + value +"]";
		
	}

}
