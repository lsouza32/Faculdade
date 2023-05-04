#include <iostream>

using namespace std;

class botao{
    string label;
    string color;
    int id;
    bool pressionado;

public:
    void setLabel(string label){
        this->label= label;
    }
    void setColor(string color){
        this->color= color;
    }
    void setId(int id){
        this->id= id;
    }
    string getColor(){
        return color;
    };
    string getLabel(){
        return label;
    }
    int getId(){
        return id;
    }
    bool setPressionar(){
        pressionado= true;
    }
    bool setDesoprimir(){
        pressionado= false;
    }

    string getPressionado(){
        if (pressionado== true){
            return "ESTA PRESSIONADO";
        }
        else{
            return "NAO ESTA PRESSIONADO";
        }
    }
};

int main() {

    botao chave;

    chave.setLabel("LAMPADA");
    chave.setColor("VERMELHO");
    chave.setId(17);
    chave.setDesoprimir();

    cout <<"Label: "<< chave.getLabel() << endl;
    cout<<"Cor: " <<chave.getColor() << endl;
    cout<< "ID: " <<chave.getId() <<endl;
    cout<< "Pressionado: " <<chave.getPressionado();

    return 0;
}
