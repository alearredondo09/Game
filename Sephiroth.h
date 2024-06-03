#ifndef SEPHIROTH_H
#define SEPHIROTH_H
#include <iostream>
#include <string>
#include "Personaje.h"

class Sephiroth : public Personaje{
    private:
        std::string puesto;
    
    public: 
        Sephiroth();
        Sephiroth(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string _puesto);
        ~Sephiroth();
        std::string getPuesto();
        void setPuesto(std::string _puesto);
        void imprimir_personaje(); //imprime la informacion del personaje        
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();
};

Sephiroth::Sephiroth() : Personaje(){
    puesto = "comandante";
}

Sephiroth::Sephiroth(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string _puesto) : Personaje(nom, _edad, _nivel, _salud, _ataque, _defensa){
    puesto = _puesto;
}

Sephiroth::~Sephiroth(){
    std::cout << "Sephiroth (villano) destruido" << std::endl;
}

std::string Sephiroth::getPuesto(){
    return puesto;
}

void Sephiroth::setPuesto(std::string _puesto){
    puesto = _puesto;
}

void Sephiroth::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "El puesto de este villano es " << puesto << std::endl;
}

void Sephiroth::atacar(Personaje* objetivo){
    int danio = ataque; 
    std::string puest;
    bool correcto = true;

    while (correcto){
        std::cout << "Dime el puesto que tienes, las opciones son:\ncomandante\nlider supremo\ngeneral\nsicario\nteniente\nDame el puesto de tu sephiroth: ";
        std::getline(std::cin, puest);
        setPuesto(puest);
        if (puesto == "comandante"){
            danio += 5;
        } else if(puesto == "lider supremo"){
            danio += 10;
        } else if (puesto == "general"){
            danio += 4;
        } else if(puesto == "teniente"){
            danio += 2;
        } else{
            std::cout << "Inserta un valor correcto" << std::endl;
            break;
            system("cls");
        }
        objetivo->recibirDanio(danio);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
        break;
    }
}

void Sephiroth::recibirDanio(int danio){
    int daniioRecibido = danio - defensa;
    if (daniioRecibido > 0){
        salud -= daniioRecibido;
    }
}

void Sephiroth::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Puesto:" << puesto << std::endl;
}


#endif