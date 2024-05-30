#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string>

using namespace std; 

class Enigma{
    private: 
        string nombre;
        int puntaje = 0;
    public: 
        Enigma();
        Enigma(string nOm, int punt);
        string getNombreE()const{return nombre;}
        int getPuntaje()const{return puntaje;}
        void setNombreE(const string nom); 
        void puntaje_adquirido(bool solucion);

}; 

Enigma::Enigma(){
    nombre = " El enigma de la palabra oculta";
    puntaje = 0;
}
Enigma::Enigma(string nOm, int punt){
    nombre = nOm; 
    puntaje = punt; 
}
void Enigma::setNombreE(const string nOm){
    nombre = nOm; 
}
void Enigma::puntaje_adquirido(bool solucion){;
    if (solucion){
        int ventaja = 2; 
        cout << "El puntaje es de " << puntaje + ventaja << endl; 
    } else {
        cout << "El puntaje es el mismo" << endl;
    }
}


#endif