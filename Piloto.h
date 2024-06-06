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
        Piloto(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo);
        std::string getVehiculo();
        void setVehiculo(std::string _vehiculo);
        void imprimir_personaje(); //imprime la informacion del personaje        
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();
};

Piloto::Piloto(){
    vehiculo = " ";
}
Piloto::Piloto(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo) : Personaje(nom, _nivel, _salud, _ataque){
    vehiculo = _vehiculo;
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
    while (true){
        int opcion;
        std::cout << "Dime el vehiculo que tienes, las opciones son:\nIngresa 1 para crucero\nIngresa 2 para tanque\nIngresa 3 para dron\nDame el vehiculo de tu piloto: ";
        std::cin >> opcion;

        if (opcion == 1){
            setAtaque(3);
            vehiculo = "crucero";
            break;
        } else if(opcion == 2){
            setAtaque(5);
            vehiculo = "tanque";
            break;
        } else if(opcion == 3){
            setAtaque(4);
            vehiculo = "dron";
            break;
        } else {
            std::cout << "Ingresa una de las opciones anteriores." << std::endl;
        }   
    }
        objetivo->recibirDanio(ataque);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
}

void Piloto::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = salud - ataque;
        setSalud(sal);
    }
}

void Piloto::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Vehiculo:" << vehiculo << std::endl;
}


#endif