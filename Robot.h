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
    public:
        Robot();
        Robot(string nom, string hist_per, string fuerxa, string hab);
        Robot(string nom, int edAd, string hist_pers, string hab, string fuerxa, int anio);
        string getFuerxa(){return fuerza_fisica;}

        int getAnioFab(){return anio_fabricacion;}

        string getHab(){return habilidad_tecnicas;}

        void setFuerxa(string fuerxa);

        void setHab(string hab);

        void setAnioFab(int anio);

        void manipulacion_magnetica(bool manipulacion);

        void imprimir_Personaje();
        void accion(bool inspeccionar);
};

Robot::Robot() : Personaje(){
    fuerza_fisica = " fuerza extremadamente alta";
    anio_fabricacion = 1998;
};
Robot::Robot(string nom, string hist_per, string fuerxa, string hab) : Personaje( nom, hist_per){
    fuerza_fisica = fuerxa; 
    habilidad_tecnicas = hab;
    anio_fabricacion = 1998;
}
Robot::Robot(string nom, int edAd, string hist_pers, string hab, string fuerxa, int anio) : Personaje(nom,edAd,hist_pers){
    fuerza_fisica = fuerxa;
    habilidad_tecnicas = hab; 
    anio_fabricacion = anio;
}

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
    Personaje::imprimir_Personaje();
    cout << "Cuya habilidad tecnica es: " << habilidad_tecnicas << " ."; 
    cout << " Estas habilidades le permiten al robot desarrollarse de mejor manera en la historia, teniendo la oportunidad de sobresalir en algunos ambitos" ;
    cout << " A su vez su fuerza, la cual es " << fuerza_fisica << " le permite tener mejor alcance y agarre de las cosas al hacer actividades fisicas."; 
    cout << " Si bien, el robot fue fabricado en " << anio_fabricacion << " se siguen manteniendo intacto y sin malgaste alguno. " << endl;  
}

void Robot::accion(bool inspeccionar){
    if (inspeccionar){
        cout << "El robot ha inspeccionado. " << endl;
    } else {
        cout << "El robot no ha inspeccionado. " << endl;
    }
}

#endif