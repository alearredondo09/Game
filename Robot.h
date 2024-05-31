#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>
#include "Personaje.h"

class Robot : public Personaje{
    private: 
        std::string habilidad; 
    public: 
        Robot();
        Robot(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string hab);
        ~Robot();
        std::string getHab();
        void setHab(std::string hab);
        void imprimir_personaje(); //imprime la informacion del personaje
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();
};

Robot::Robot(){
    habilidad = " ";
}
Robot::Robot(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string hab) : Personaje(nom, _edad, _nivel, _salud, _ataque, _defensa){
    habilidad = hab;
}

Robot::~Robot(){
    std::cout << "Destructor de Robot llamado" << std::endl;
}

std::string Robot::getHab(){
    return habilidad;
}

void Robot::setHab(std::string hab){
    habilidad = hab;
}

void Robot::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "Habilidad: " << habilidad << std::endl;
}

void Robot::atacar(Personaje* objetivo){
    int danio = ataque; 
    if (habilidad == "laser"){
        danio += 5;
    }
    objetivo->recibirDanio(danio);
}

void Robot::recibirDanio(int danio){
    int daniioRecibido = danio - defensa;
    if (daniioRecibido > 0){
        salud -= daniioRecibido;
    }
}

void Robot::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Habilidad:" << habilidad << std::endl;
}

#endif