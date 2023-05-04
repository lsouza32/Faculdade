#include <iostream>
using namespace std;

class aeronave{
    
public:
    string alcance;
    string fabricante;
    string modelo;
    bool militar;
    bool armamento;
    
public:
    void setAlcance(string alcance){
        this->alcance= alcance;
    }
    void setFabricante(string fabricante){
        this->fabricante= fabricante;
    }
    void setModelo(string modelo){
        this->modelo= modelo;
    }
    bool setMilitar(bool militar){
        this->militar= militar;
    }
    bool setArmamento(bool armamento){
        this->armamento= armamento;
    }
    
};

class Drone: public aeronave{
    string assas;

public:
    void setAssas(string assas){
        this->assas=assas;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
