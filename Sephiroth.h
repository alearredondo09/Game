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
        Sephiroth() : Personaje(){
            motivo = "Nunca le ha gustado ser oprimido por la sociedad"; 
            puesto = " lider tiranico";
        };
        Sephiroth(string nom, string hist_per, string mot, string puEsto) : Personaje(nom, hist_per){
            motivo = mot; 
            puesto = puEsto; 
        }
        string getMotivo(){return motivo;}
        string getPuesto(){return puesto;}
        void setMotivo(string mot);
        void setPuesto(string puEsto);
        void atacar(bool ataque);
        void imprimir_Personaje();

};

void Sephiroth::setMotivo(string mot){
    motivo = mot;
}
void Sephiroth::setPuesto(string puEsto){
    puesto = puEsto; 
}
void Sephiroth::atacar(bool ataque){
    if (ataque){
        cout << "El ataque ha sido realizado. " << endl; 
    } else{
        cout << "El ataque no ha sido realizado. " << endl; 
    }
}
void Sephiroth::imprimir_Personaje(){
    cout << " Esta historia esta compuesta por nuestro Sephiroth, el cual es nuestro villano, cuyo nombre es" << getNombreP(); 
    cout << " el rol que desarrolla en esta historia es de villano con un puesto de " << getPuesto() << ". Sus ataques son dados por "; 
    cout << getMotivo() << endl; 
}

# endif