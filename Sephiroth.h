#ifndef SEPHIROTH_H
#define SEPHIROTH_H
#include <iostream>
#include "Personaje.h"

using namespace std;

class Sephiroth : public Personaje{
    private: 
        string motivo;
        string puesto; 

    public: 
        Sephiroth();
        Sephiroth(string nom, string hist_per, string mot, string puEsto);
        string getMotivo(){return motivo;}
        string getPuesto(){return puesto;}
        void setMotivo(string mot);
        void setPuesto(string puEsto);
        void imprimir_Personaje();
        void accion(bool atacar, int num);

};

Sephiroth::Sephiroth() : Personaje(){
    motivo = "Nunca le ha gustado ser oprimido por la sociedad"; 
    puesto = " lider tiranico";
};

Sephiroth::Sephiroth(string nom, string hist_per, string mot, string puEsto) : Personaje(nom, hist_per){
    motivo = mot; 
    puesto = puEsto; 
}

void Sephiroth::setMotivo(string mot){
    motivo = mot;
}
void Sephiroth::setPuesto(string puEsto){
    puesto = puEsto; 
}

void Sephiroth::imprimir_Personaje(){
    Personaje::imprimir_Personaje();
    cout << " El rol que desarrolla en esta historia es de villano con un puesto de " << getPuesto() << ". Sus ataques son dados por "; 
    cout << getMotivo() << endl; 
}

void Sephiroth::accion(bool atacar, int num){
    if (atacar){
        cout << "El numero de ataques " << num << " ha sido realizado. " << endl;
    } else {
        cout << "El numero de ataques " << num << " no ha sido realizado. " << endl;
    }
}

# endif