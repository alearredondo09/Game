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
        Enigma(){
            nombre = " El enigma de la palabra oculta";
            puntaje = 0;
        }
        Enigma(string nOm, int punt){
            nombre = nOm; 
            puntaje = punt; 
        }
        string getNombreE(){return nombre;}
        int getPuntaje(){return puntaje;}
        void setNombreE(string nom); 
        void puntaje_adquirido(bool solucion);

}; 

void Enigma::setNombreE(string nOm){
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