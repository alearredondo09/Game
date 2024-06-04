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
        Alienigena(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string hab); // constructor parametrizado
        ~Alienigena();
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

Alienigena::Alienigena(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string hab): Personaje(nom, _edad, _nivel, _salud, _ataque, _defensa){
    nombre = nom;
    edad = _edad; 
    nivel = _nivel;
    salud = _salud;
    ataque = _ataque;
    defensa = _defensa;
    habilidad = hab;
}
Alienigena::~Alienigena(){
    std::cout << "Alienigena destruido" << std::endl;
}

std::string Alienigena::getHabilidad(){
    return habilidad;
}

void Alienigena::setHabilidad(std::string hab){
    habilidad = hab;
}

void Alienigena::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "Nivel: " << nivel << "\n";
    std::cout << "Salud: " << salud << "\n"; 
    std::cout << "Ataque: " << ataque << "\n"; 
    std::cout << "Defensas " << defensa << "\n";
    std::cout << "Habilidad " << habilidad << std::endl;
}

void Alienigena::atacar(Personaje* objetivo){
    int danio = ataque;
    std::string habi;
    bool correcto = true;
    while (correcto) {
        std::cout << "Dime la habilidad que tienes, las opciones son:\ntelepatia\nveneno\nlevitar\ncamuflaje\nDame la habilidad de tu alien: ";
        std::getline(std::cin, habi);
        setHabilidad(habi);
        if (habilidad == "veneno") {
            danio += 7;
            correcto = true;
        } else if (habilidad == "telepatia") {
            danio += 6;
            correcto = true;
        } else if (habilidad == "levitar") {
            danio += 9;
            correcto = true;
        } else if (habilidad == "camuflaje") {
            danio += 4;
            correcto = true;
        } else {
            std::cout << "Agrega una opcion valida:" << std::endl;
        }
        objetivo->recibirDanio(danio);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
        break;        
    }
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