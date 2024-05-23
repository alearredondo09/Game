#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>

using namespace std;

class Personaje{
    protected:
        string nombre;
        int edad;
        string historia_personal;
    public:
        // Declaraciones de los constructores
        Personaje();
        Personaje(string nom, string hist_per);
        Personaje(string nom, int edAd, string hist_pers);
        string getNombreP() { return nombre; }
        int getEdad() { return edad; }
        string getHistoria() { return historia_personal; }

        void setNombreP(string nom);
        void setEdad(int edAd);
        void setOrigen(string origen);
        void setHistoria(string hist_per);

        void imprimir_Personaje(); // Declarar como función pura virtual
};

Personaje::Personaje(){
    nombre = "";
    edad = 0;
    historia_personal = ""; 
}

Personaje::Personaje(string nom, string hist_per){
    nombre = nom;
    edad = 0;
    historia_personal = hist_per; 
}

Personaje::Personaje(string nom, int edAd, string hist_pers){
    nombre = nom;
    edad = edAd;
    historia_personal = hist_pers;
}

void Personaje::setNombreP(string nom){
    nombre = nom;
}

void Personaje::setEdad(int edAd){
    edad = edAd;
}

void Personaje::setHistoria(string hist_per){
    historia_personal = hist_per;
}



#endif
