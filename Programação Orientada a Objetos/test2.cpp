#include <iostream>

using namespace std;

class automovel{
    string fabricante;
    string categoria;
    int ano;

public:

    void setFabricante(string fabricante){
        this->fabricante= fabricante;
    }

    void  setCategoria(string categoria){
        this->categoria= categoria;
    }
    void setAno(int ano){
        this->ano= ano;
    };

    string getFabricante(){
        return fabricante;
    }
    string getCategoria(){
        return categoria;
    }

    int getAno(){
        return ano;
    }
};

int main() {

    automovel carro;

    carro.setFabricante(" JAGUAR");
    carro.setCategoria("LUXO");
    carro.setAno(2019);

    cout << "Fabricante: " << carro.getFabricante() << endl;
    cout << "Categoria: " << carro.getCategoria() << endl;
    cout << "Ano: " << carro.getAno() << endl;

    return 0;
}
