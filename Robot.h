#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>
#include "Personaje.h"

using namespace std;

//Meter el array al constructor 

class Robot : public Personaje{
    private: 
        string fuerza_fisica;
        int anio_fabricacion; 
        string habilidad_tecnicas;
        int habilidades; 
    public:
        Robot() : Personaje(){
            fuerza_fisica = " fuerza extremadamente alta";
            anio_fabricacion = 1998;
        };
        Robot(string nom, string hist_per, string fuerxa, string hab) : Personaje( nom, hist_per){
            fuerza_fisica = fuerxa; 
            habilidad_tecnicas = hab;
            anio_fabricacion = 1998;
        }
        Robot(string nom, int edAd, string hist_pers, string hab, string fuerxa, int anio) : Personaje(nom,edAd,hist_pers){
            fuerza_fisica = fuerxa;
            habilidad_tecnicas = hab; 
            anio_fabricacion = anio;
        }

        string getFuerxa(){return fuerza_fisica;}

        int getAnioFab(){return anio_fabricacion;}

        string getHab(){return habilidad_tecnicas;}

        void setFuerxa(string fuerxa);

        void setHab(string hab);

        void setAnioFab(int anio);

        void manipulacion_magnetica(bool manipulacion);

        void agregaHabilidad(string hab);

        void imprimir_Habilidades();

        void imprimir_Personaje();
};

void Robot::setFuerxa(string fuerxa){
    fuerza_fisica = fuerxa;
}

void Robot::setAnioFab(int anio){
    anio_fabricacion = anio;
}  

void Robot::setHab(string hab){
    habilidad_tecnicas = hab; 
}

void Robot::manipulacion_magnetica(bool manipulacion){
    if (manipulacion){
        cout << "La manipulacion magnetica fue realizada correctamente." << endl;
    } else{
        cout << "La manipulacion magnetica no fue realizada. Suerte para la proxima." << endl;
    }
} 


void Robot::imprimir_Personaje(){
    cout << "Esta historia tiene un personaje llamado " << getNombreP() << " y cuyas habilidad tecnica es: " << getHab() ; 
    cout << "Estas habilidades le permiten al robot desarrollarse de mejor manera en la historia, teniendo la oportunidad de sobresalir en algunos ambitos" ;
    cout << " A su vez su fuerza, la cual es " << getFuerxa() << " le permite tener mejor alcancé y agarre de las cosas al hacer actividades fisicas."; 
    cout << " Si bien, el robot fue fabricado en " << getAnioFab() << " se siguen manteniendo intacto y sin malgaste alguno. " << endl;  
}

#endif