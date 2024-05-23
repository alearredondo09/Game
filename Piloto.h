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
        Piloto () : Personaje(){
            experiencia_anios = 0;
            horas_vuelo = 0;
            lugar_trabajo = " "; 
        }
        Piloto(string nom, int edAd, string origen, string hist_pers, int exp_anios, int horas_v, string lug_trab) : Personaje(nom,edAd,hist_pers){
            experiencia_anios = exp_anios;
            horas_vuelo = horas_v; 
            lugar_trabajo = lug_trab; 
        }
        int getExperiencia(){return experiencia_anios;}
        int getHoras(){return horas_vuelo;}
        string getLugarTrab(){return lugar_trabajo;}
        void setExperiencia(int exp_anios);
        void setHoras(int horas_v);
        void setLugarTrab(string lug_trab);
        void aviar(bool aviar);
        void atacar_aviones(bool atacar);
        void imprimir_Personaje();
};

void Piloto::setExperiencia(int exp_anios){
    experiencia_anios = exp_anios;

}
void Piloto::setHoras(int horas_v){
    horas_vuelo = horas_v; 
}
void Piloto::setLugarTrab(string lug_trab){
    lugar_trabajo = lug_trab;
}
void Piloto::aviar(bool aviar){
    if (aviar){
        cout << "El piloto " << getNombreP() << " esta volando el avion" << endl;
    } else {
        cout << " El piloto " << getNombreP() << " no pudo aviar el avion. Intentalo mas tarde" << endl; 
    }
}
void Piloto::atacar_aviones(bool atacar){
    if (atacar){
        cout << "El avion esta siendo atacado. " << endl;
    } else {
        cout << "El avion no ha sido atacado. " << endl;
    }
}

 /*experiencia_anios = 0;
            horas_vuelo = 0;
            lugar_trabajo = " ";
*/
void Piloto::imprimir_Personaje(){
    cout << "Esta historia tiene un personaje cuyo nombre es " << getNombreP() << " y su profesion es ser piloto. " ;
    cout << " Este piloto tiene " << getExperiencia() << " anios de experiencia volando aviones y tiene " << getHoras() ; 
    cout << " de vuelo y su lugar de trabajo es " << getLugarTrab() << " /n Este personaje tiene una historia unica " ; 
    cout << getHistoria() << ". Este es un gran personaje. " << endl; 
}


#endif