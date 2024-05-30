#ifndef PLANETA_H
#define PLANETA_H
#include <iostream>
#include <string>
#include "Robot.h"
#include "Enigma.h"
#include "Alienigena.h"
#include "Piloto.h"
#include "Sephiroth.h"
#include "Personaje.h"
using namespace std; 

class Planeta {
    private:
        string nombre;
        string historia; 
        Personaje* personajes[10];
        int persona;
        Enigma enigma;
    public: 
        Planeta();
        Planeta(string nom, string histOria);
        ~Planeta();
        //getters
        string getNombre(){return nombre;} //getter para el nombre del planeta
        string getHistoria(){return historia;} //getter para la historia del planeta

        //setters
        void setNombre(string nom); 
        void setHistoria(string _historia);

        //Metodos
        void crear_juego(bool crear);
        void addPiloto(string nom, int edAd, string origen, string hist_pers, int exp_anios, int horas_v, string lug_trab);
        void addRobot(string nom, string hist_per, string fuerxa, string hab);
        void addAlienigena(string nom, string hist_per, string puesto);
        void addSephiroth(string nom, string hist_per, string mot, string puEsto);
        void consultarP(string personaje);
        void robot_atacar(Personaje* objetivo);
        void piloto_ataca(Personaje* objetivo2);
};

Planeta::Planeta(){
    nombre = "Aura";
    historia = "Nuevo planeta descubierto en 1789, por el cientifico Aurelius Corner de origen ruso";
    persona = 0;
}

Planeta::Planeta(string nom, string histOria){
    nombre = nom; 
    historia = histOria; 
}

Planeta::~Planeta(){
    for(int i = 0; i < persona ; i++){
        delete personajes[i];
    }
}
void Planeta::setNombre(string nom){
    nombre = nom;
}
void Planeta::setHistoria(string _historia){
    historia = _historia;
}

void Planeta::crear_juego(bool crear) {
    if (crear) {
        cout << "Todos los objetos han sido creados. Puedes iniciar el juego." << endl;
    } else {
        cout << "Faltan objetos por crear. No se puede iniciar el juego." << endl;
    }
}

void Planeta::addPiloto(string nom, int edAd, string origen, string hist_pers, int exp_anios, int horas_v, string lug_trab){
    personajes[persona] = new Piloto(nom, edAd, origen, hist_pers, exp_anios, horas_v, lug_trab);
    persona++;
}

void Planeta::addRobot(string nom, string hist_per, string fuerxa, string hab){
    personajes[persona] = new Robot(nom, hist_per, fuerxa, hab);
    persona++;
}

void Planeta::addAlienigena(string nom, string hist_per, string puesto){
    personajes[persona] = new Alienigena(nom, hist_per, puesto);
    persona++;
}

void Planeta::addSephiroth(string nom, string hist_per, string mot, string puEsto){
    personajes[persona] = new Sephiroth(nom, hist_per,mot,puEsto);
    persona++;
}

void Planeta::consultarP(string personaje) {
    for (int i = 0; i < persona; i++) {
        if (personajes[i]->getNombreP() == personaje) {
            personajes[i]->imprimir_Personaje();
            break;  // Assuming you only want to print the first matching personaje
        } else{
            cout << "Personaje no encontrado. " << endl; 
        }
    }
}

void Planeta::robot_atacar(Personaje* objetivo){
    Robot* robot_atacante;
    if (robot_atacante->getHab() == "laser"){
        cout << objetivo << " ha atacado existosamente " << endl;
        enigma.puntaje_adquirido(true);
    } else{
        cout << objetivo << " no ha atacado " << endl;
    }
}

void Planeta::piloto_ataca(Personaje* objetivo2){
    Piloto* piloto_atacante;
    if (piloto_atacante -> getHoras() == 20){
        cout << "Has logrado adivinar y atacar " << objetivo2 << endl;
        enigma.puntaje_adquirido(true);
    } else{
        cout << objetivo2 << " no ha sido atacado" << endl;
    }
}


#endif