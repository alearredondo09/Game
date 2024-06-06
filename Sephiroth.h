#ifndef SEPHIROTH_H
#define SEPHIROTH_H
#include <iostream>
#include <string>
#include "Personaje.h"

class Sephiroth : public Personaje{
    private:
        std::string puesto;
        int defensa;
    
    public: 
        Sephiroth();
        Sephiroth(std::string nom, int _nivel, int _salud, int _ataque, std::string _puesto, int defensa);
        std::string getPuesto();
        void setPuesto(std::string _puesto);
        void setDefensa(int _defensa); // setter de defensa
        int getDefensa(); // getter para defensa
        void imprimir_personaje(); //imprime la informacion del personaje        
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();
};

Sephiroth::Sephiroth() : Personaje(){
    puesto = " ";
    defensa = 3;
}

Sephiroth::Sephiroth(std::string nom, int _nivel, int _salud, int _ataque, std::string _puesto, int defens) : Personaje(nom, _nivel, _salud, _ataque){
    puesto = _puesto;
    defensa = defens;
}

std::string Sephiroth::getPuesto(){return puesto;}

int Sephiroth::getDefensa(){return defensa;}

void Sephiroth::setPuesto(std::string _puesto){
    puesto = _puesto;
}

void Sephiroth::setDefensa(int _defensa){
    defensa = _defensa;
}

void Sephiroth::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "El puesto de este villano es " << puesto << std::endl;
}

void Sephiroth::atacar(Personaje* objetivo){
    int ataqu;
    int opcion;
    while (true){
        int opcion;
        std::cout << "Dime el puesto que tienes, las opciones son:\nIngresa 1 para comandante\nIngresa 2 para lider supremo\nDame el puesto de tu sephiroth: ";
        std::cin >> opcion;
        if (opcion == 1){
            setAtaque(12);
            puesto = "comandante";
            break;
        } else if(opcion == 2){
            setAtaque(15);
            puesto = "lider supremo";
            break;
        } else{
            std::cout << "Inserta un valor correcto" << std::endl;
        }
    }
        objetivo->recibirDanio(ataque);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
}

void Sephiroth::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = salud - ataque + defensa;
        setSalud(sal);
    }
}

void Sephiroth::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Puesto:" << puesto << std::endl;
}


#endif