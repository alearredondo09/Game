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
        Robot(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string hab);
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
Robot::Robot(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string hab) : Personaje(nom,  _nivel, _salud, _ataque){
    habilidad = hab;
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
    int opcion;
    while (true){
        std::cout << "Dime la habilidad que tienes, las opciones son:\nIngresa 1 para desintegracion\nIngresa 2 teletransportarse\nDame la habilidad de tu robot: ";
        std::cin >> opcion;

        if (opcion == 1){
            setAtaque(5); 
            habilidad = "desintegracion";
            std::cout << habilidad << std::endl;
            break;
        } else if(opcion == 2){
            setAtaque(5);
            habilidad = "teletransportarse";
            std::cout << habilidad << std::endl;
            break;
        } else{
            std::cout << "Ingresa un valor valido" << std::endl;
        }
    }
        objetivo->recibirDanio(ataque);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
}

void Robot::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = salud - ataque;
        setSalud(sal);
    }
}

void Robot::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Habilidad:" << habilidad << std::endl;
}


#endif