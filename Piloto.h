#ifndef PILOTO_H
#define PILOTO_H
#include <iostream> 
#include <string>
#include "Personaje.h"

class Piloto : public Personaje{
    private: 
        std::string vehiculo;
    public: 
        Piloto();
        Piloto(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo);
        ~Piloto();
        std::string getVehiculo();
        void setVehiculo(std::string _vehiculo);
        void imprimir_personaje(); //imprime la informacion del personaje        
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();
};

Piloto::Piloto(){
    vehiculo = "nave espacial";
}
Piloto::Piloto(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo) : Personaje(nom, _edad, _nivel, _salud, _ataque, _defensa){
    vehiculo = _vehiculo;
}
Piloto::~Piloto(){
    std::cout << "El destructor de piloto ha sido llamado. " << std::endl;
}
std::string Piloto::getVehiculo(){
    return vehiculo;
}
void Piloto::setVehiculo(std::string _vehiculo){
   vehiculo = _vehiculo;
}
void Piloto::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "El vehiculo de este personaje es: " << vehiculo << std::endl;
}
void Piloto::atacar(Personaje* objetivo){
    int danio = ataque; 
    if (vehiculo == "nave espacial"){
        danio += 5;
    }
    objetivo->recibirDanio(danio);
}

void Piloto::recibirDanio(int danio){
    int daniioRecibido = danio - defensa;
    if (daniioRecibido > 0){
        salud -= daniioRecibido;
    }
}

void Piloto::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Vehiculo:" << vehiculo << std::endl;
}
#endif