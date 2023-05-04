import java.util.ArrayList;
import java.util.HashMap;

public class Tabela_Hash {
	private HashMap<String, Simbolos> table;
	
	public ArrayList<Simbolos> getAll(){
		ArrayList<Simbolos> list = new ArrayList<Simbolos>();
		for(Simbolos simbolo: table.values()) {
			list.add(simbolo);
		}
		return list;
	}
		
	public Tabela_Hash() {
		table = new HashMap<String, Simbolos>();
	}
	
	public void add(Simbolos simbolo) {
		table.put(simbolo.getName(), simbolo);
	}
	
	public boolean existe(String name) {
		return table.get(name)!= null;					// se não é null, quer dizer que existe
	}

	public Simbolos get(String NomeSimbolo) {
		return table.get(NomeSimbolo);
	}
	
}
