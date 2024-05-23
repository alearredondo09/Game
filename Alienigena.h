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
        Alienigena(){
            color = " ";
            puesto_batalla = " ";
            num_medallas = 0;
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

void Alienigena::levitar(bool levitar){
    if(levitar == true){
            cout << "El personaje esta levitando. " << endl;
    } else {
        cout << "No pudo levitar nada. Ni su propia alma. " << endl; 
    }
}

void Alienigena::teletransportarse(bool teletrans){
    if (teletrans == true){
        cout << "El personaje se teletransporto al destino exitosamente." << endl;
    } else{
        cout << "No pudo teletransportarse correctamente. Suerte a la proxima." << endl;
    }
}

void Alienigena::control_mental(bool control){
    if (control == true){
        cout << "El control mental se hizo exitosamente" << endl;
    } else{
        cout << "El control mental no fue realizado exitosamente, suerte la siguiente." << endl; 
    }
}

void Alienigena::cambiar_forma(bool cambio){
    if(cambio){
        cout << "El cambio de forma ha sido realizado exitosamente." << endl;
    } else{
        cout << "El cambio de forma no se ha realizado exitosamente." << endl; 
    }
}

void Alienigena::imprimir_Personaje(){
    cout << "Nuestra histora se desarrolla alrededor de un personaje" ;
    cout << " este personaje es " << getNombreP() << " el cual vive";
    cout << " en el planeta Aura y cuya edad es" << getEdad() << " anios. ";
    cout << "A partir de ahi se da una historia que el";
    cout << " narrara. ''" << getHistoria() << "'' "  << endl;
    cout << "Algunos datos interesantes de nuestro personaje es que su color es: ";
    cout << getColor() << ", su puesta de batalla es " << getPuesto() << " y su numero";
    cout << " de medallas ganadas es de " << getMedallas() << ". Increible no lo crees? " << endl;
}

#endif