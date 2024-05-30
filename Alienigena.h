#ifndef ALIENIGENA_H
#define ALIENIGENA_H
#include <iostream>
#include <string>
#include "Personaje.h"
using namespace std;


class Alienigena : public Personaje{
    private: 
        string color;
        string puesto_batalla;
        int num_medallas;
    public: 
        Alienigena():Personaje(){
            color = " ";
            puesto_batalla = " ";
            num_medallas = 4;
        };
        Alienigena(string nom, string hist_per, string puesto) : Personaje(nom, hist_per){
            puesto_batalla = puesto;
        };
        Alienigena(string nom, int edAd,  string hist_pers, string colOr, string puesto, int medallas) : Personaje(nom,edAd,hist_pers){
            color = colOr; 
            puesto_batalla = puesto; 
            num_medallas = medallas; 
        }
        string getColor() {return color;}
        string getPuesto() {return puesto_batalla;}
        int getMedallas() {return num_medallas;}
        void setColor(string colOr);
        void setPuesto(string puesto);
        void setMedallas(int medallas);
        void levitar(bool levitar);
        void teletransportarse(bool teletrans);
        void control_mental(bool control);
        void cambiar_forma(bool cambio);
        
        // Sobrescribir la función imprimir_Personaje
        void imprimir_Personaje();
        void accion(bool atacar);
};

void Alienigena::setColor(string colOr){
    color = colOr;
}

void Alienigena::setPuesto(string puesto){
    puesto_batalla = puesto;
}

void Alienigena::setMedallas(int medallas){
    num_medallas = medallas;
}

void Alienigena::imprimir_Personaje(){
    Personaje::imprimir_Personaje();
    cout << "Algunos datos interesantes de nuestro personaje es que su color es: ";
    cout << getColor() << ", su puesta de batalla es " << getPuesto() << " y su numero";
    cout << " de medallas ganadas es de " << getMedallas() << ". Increible no lo crees? " << endl;
}

void Alienigena::accion(bool atacar){
    if (atacar){
        cout << "El alienigena ataco." << endl;
    } else {
        cout << "El alienigena no ataco." << endl;
    }
}

#endif