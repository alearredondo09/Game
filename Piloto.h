#ifndef PILOTO_H
#define PILOTO_H
#include <iostream>
#include <string>
#include "Personaje.h"

using namespace std;

class Piloto : public Personaje{
    private:
        int experiencia_anios;
        int horas_vuelo; 
        string lugar_trabajo; 
    public: 
        Piloto ();
        Piloto(string nom, int edAd, string origen, string hist_pers, int exp_anios, int horas_v, string lug_trab) ;
        int getExperiencia(){return experiencia_anios;}
        int getHoras(){return horas_vuelo;}
        string getLugarTrab(){return lugar_trabajo;}
        void setExperiencia(int exp_anios);
        void setHoras(int horas_v);
        void setLugarTrab(string lug_trab);
        void imprimir_Personaje();
        void accion(bool pilotear, int h_vuelos);
};

Piloto::Piloto () : Personaje(){
    experiencia_anios = 0;
    horas_vuelo = 0;
    lugar_trabajo = " "; 
}

Piloto::Piloto(string nom, int edAd, string origen, string hist_pers, int exp_anios, int horas_v, string lug_trab) : Personaje(nom,edAd,hist_pers){
    experiencia_anios = exp_anios;
    horas_vuelo = horas_v; 
    lugar_trabajo = lug_trab; 
}

void Piloto::setExperiencia(int exp_anios){
    experiencia_anios = exp_anios;

}
void Piloto::setHoras(int horas_v){
    horas_vuelo = horas_v; 
}
void Piloto::setLugarTrab(string lug_trab){
    lugar_trabajo = lug_trab;
}

void Piloto::imprimir_Personaje(){
    Personaje::imprimir_Personaje();
    cout << " Este piloto tiene " << getExperiencia() << " anios de experiencia volando aviones y tiene " << getHoras() ; 
    cout << " de vuelo y su lugar de trabajo es " << getLugarTrab() << "\nEste personaje tiene una historia unica " ; 
    cout << getHistoria() << ". Este es un gran personaje. " << endl; 
}

void Piloto::accion(bool pilotear, int h_vuelos){
    if (pilotear){
        cout << "El piloto ha atacado mas de " << h_vuelos << " de su experiencia en horas de vuelo. " << endl;
    } else {
        cout << "El piloto ha atacado menos de " << h_vuelos << " de su experiencia en horas de vuelo. " << endl;
    }
}


#endif