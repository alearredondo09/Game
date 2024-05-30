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
        string getNombreP() const{ return nombre; }
        int getEdad()const { return edad; }
        string getHistoria() { return historia_personal; }

        void setNombreP(string nom);
        void setEdad(int edAd);
        void setHistoria(string hist_per);

        virtual void imprimir_Personaje(); // Declarar como función pura virtual
        virtual void accion();
};

Personaje::Personaje(){
    nombre = "";
    edad = 25;
    historia_personal = ""; 
}

Personaje::Personaje(string nom, string hist_per){
    nombre = nom;
    edad = 18;
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

void Personaje::imprimir_Personaje(){
    cout << "Esta historia se encuentra compuesta por nuestro personaje " << nombre << " ese personaje tiene una edad de " << edad << " anios. \nLa historia que este personaje es " << historia_personal << ". \n";
}

void Personaje::accion(){
    cout << "El personaje puede o no realizar una accion, lo descubriremos. " << endl;
}

#endif
