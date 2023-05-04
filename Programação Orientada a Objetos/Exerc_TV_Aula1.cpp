#include <iostream>

using namespace std;

class televisao{
    string fabricante;
    int num_serie;
    string modelo;
    int canal;
    string entrada;
    bool status;

public:
    void setFabricante(string fabricante){
        this->fabricante=fabricante;
    }
    string getFabricante(){
        return fabricante;
    }
    void setNum_serie(int num_serie){
        this->num_serie=num_serie;
    }
    int getNum_serie(){
        return num_serie;
    }
    void setModelo(string modelo){
        this->modelo= modelo;
    }
    string getModelo(){
        return modelo;
    }
    void setCanal(int canal){
        this->canal= canal;
    }
    int getCanal(){
        return canal;
    }
    void setEntrada(string entrada){
        this->entrada=entrada;
    }
    string getEntrada(){
        return entrada;
    }
    void on(){
        status= true;
    }
    void off(){
        status= false;
    }
    void mudar_canal(int mudar_canal){
        canal=mudar_canal;
    }

};

int main() {

    return 0;
}
