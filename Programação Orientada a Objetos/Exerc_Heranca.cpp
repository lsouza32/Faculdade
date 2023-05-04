#include <iostream>

using namespace std;

class aeronave{
public:
    string fabricante;
    int modelo;

public:
    void setFabricante(string fabricante){
        this->fabricante= fabricante;
    }
    void setModelo(int modelo){
        this->modelo= modelo;
    }
    string getFabricante(){
        return fabricante;
    }
    int getModelo(){
        return modelo;
    }

};

class aviao: public aeronave{
public:
    bool continental;
    int qtd_motores;
    string categoria;

public:
    void setContinental(bool continental){
        this->continental= continental;
    }
    void setCategoria(string categoria){
        this->categoria=categoria;
    }
    void setMotores(int qtd_motores){
        this->qtd_motores= qtd_motores;
    }
    bool getContinental(){
        return continental;
    }
    string getCategoria(){
        return categoria;
    }
    int getMotores() {
        return qtd_motores;
    }
};

class helicoptero: public aeronave{
public:
    string  categoria;
    bool armamento;

public:
    void setCategoria(string categoria){
        this->categoria=categoria;
    }
    bool setArmamento(bool armamento){
        this->armamento= armamento;
    }
    string getCategoria(){
        return categoria;
    }
    bool getArmamento(){
        return armamento;
    }
};

class armamento{
public:
    bool misseis;
    bool metralhadora;

public:
    void setMisseis(bool misseis){
        this->misseis= misseis;
    }
    void setMetralhadora(bool metralhadora){
        this->metralhadora= metralhadora;
    }
    string getMisseis(){
        if (misseis){
            return "TEM MISSEL PA BOSTA";
        }
    }
    string getMetralahora(){
        if (metralhadora){
            return "METRANCA TA PRONTA PRA CANTAR";
        }
    }
};

class aviao_combate: public aviao, public armamento{
    string  modelo;

public:
    //CONSTRUTOR
    aviao_combate(){
        this->categoria= "MILITAR";
    }
    //DESTRUTOR
    ~aviao_combate(){
        cout << "\n\n VIAO FOI DESTRUIDO \n\n"<< endl;
    }
    void setModelo(string modelo){
        this->modelo= modelo;
    }
    string getModelo(){
        return modelo;
    }
};


int main() {

    aviao_combate viao;

    viao.setFabricante("Lukinhas Motors");
    viao.setModelo("322");
    //viao.setCategoria("DO PIOR TIPO");
    viao.setMotores(0);
    viao.setMetralhadora(true);
    viao.setMisseis(true);

    cout<< "Fabricante: " << viao.getFabricante() << endl;
    cout<< "Modelo: " <<viao.getModelo() << endl;
    cout<< "Categoria: " <<viao.getCategoria() << endl;
    cout<< "Motores: " <<viao.getMotores() << endl;
    cout<< "Metralha: " <<viao.getMetralahora() << endl;
    cout<< "Misseis: " <<viao.getMisseis() << endl;


    return 0;
}
