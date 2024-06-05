#ifndef ALIENIGENA_H
#define ALIENIGENA_H
#include <iostream>
#include <string>
#include "Personaje.h"

class Alienigena : public Personaje{
    private: 
        std::string habilidad;
    public: 
        Alienigena(); // constructor default
        Alienigena(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string hab); // constructor parametrizado
        std::string getHabilidad();
        void setHabilidad(std::string hab);
        void imprimir_personaje(); //imprime la informacion del personaje
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado(); //funcion que muestra el estado del personaje

};

Alienigena::Alienigena(){
    habilidad = "veneno";
}

Alienigena::Alienigena(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string hab): Personaje(nom, _nivel, _salud, _ataque){
    habilidad = hab;
}

std::string Alienigena::getHabilidad(){
    return habilidad;
}

void Alienigena::setHabilidad(std::string hab){
    habilidad = hab;
}

void Alienigena::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "Habilidad " << habilidad << std::endl;
}

void Alienigena::atacar(Personaje* objetivo){
    int danio = ataque;
    int habi;
    while (true) {
        std::cout << "Dime la habilidad que tienes, las opciones son:\nIngresa 1 para telepatia\nIngresa 2 veneno\nDame la habilidad de tu alien: ";
        std::cin >> habi;
        if (habi == 1) {
            danio += 7;
            habilidad = "telepatia";
            std::cout << habilidad;
            break;
        } else if (habi == 2) {
            habilidad = "veneno";
            danio += 6;
            break;
        } else {
            std::cout << "Agrega una opcion valida:" << std::endl;
        }      
    }
        objetivo->recibirDanio(danio);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;  
}

void Alienigena::recibirDanio(int danio){
    int daniioRecibido = danio - defensa;
    if (daniioRecibido > 0){
        salud -= daniioRecibido;
        
    }
}

void Alienigena::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Habilidad:" << habilidad << std::endl;
}


#endif