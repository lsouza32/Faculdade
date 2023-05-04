#include <iostream>

using namespace std;

class aviao{
    string fabricante;
    string status;
    int modelo;

public:

    void setFabricante(string fabricante){
        this->fabricante= fabricante;
    }

    void  setStatus(string status){
        this->status= status;
    }
    void setModelo(int modelo){
        this->modelo= modelo;
    };

    string getFabricante(){
        return fabricante;
    }
    string getStatus(){
        return status;
    }

    int getModelo(){
        return modelo;
    }

    void voar(){
        setStatus("VOANDO");
    }

    void taxiar(){
        setStatus("TAXIANDO");
    }

    void pousar(){
        setStatus("POUSANDO!");
    }

};

int main() {

    aviao aeronave;

    aeronave.setFabricante("boeing");
    aeronave.setModelo(474);
    aeronave.voar();

    cout << "Aeronave " << aeronave.getFabricante() << " " << aeronave.getModelo() << endl;
    cout << "esta " << aeronave.getStatus() << endl;

    return 0;
}
