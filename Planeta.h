#ifndef PLANETA_
#define PLANETA_
#include <iostream>
#include <string>
#include <random>
#include "Personaje.h"
#include "Enigma.h"

class Planeta{
    private: 
        std::string nombre;
        std::string historia;
        Personaje* personajes[2];
        Enigma enigma;
    public: 
        Planeta();
        Planeta(std::string nom, std::string hist, Personaje* p1, Personaje* p2, Enigma enig);
        ~Planeta();
        std::string getNombre();
        std::string getHist();
        Enigma getEnigma();
        void setNombre(std::string nom);
        void setHist(std::string hist);
        void setEnignma(Enigma& enig);
        void mostrarEstado();
        void simularCombate(Personaje* p1, Personaje* p2);
};

Planeta::Planeta(){
    nombre = "Aura";
    historia = "planeta desconocido hasta 1849";
}
Planeta::Planeta(std::string nom, std::string hist, Personaje* p1, Personaje* p2, Enigma enig){
    nombre = nom;
    historia = hist;
    enigma = enig;
    personajes[0] = p1;
    personajes[1] = p2;
}
Planeta::~Planeta() {
    for (int i = 0; i < 2; ++i) {
        delete personajes[i];
    }
}
std::string Planeta::getNombre(){return nombre;}

std::string Planeta::getHist(){return historia;}

Enigma Planeta::getEnigma(){return enigma;}

void Planeta::setNombre(std::string nom){nombre = nom;}

void Planeta::setHist(std::string hist){historia = hist;}

void Planeta::setEnignma(Enigma& enig){enigma = enig;}

void Planeta::mostrarEstado(){
    std::cout << "Planeta: " << nombre << "\nHistoria: " << historia << "\nEnigma: " << enigma.getNombre() << std::endl;
}

void Planeta::simularCombate(Personaje* p1, Personaje* p2){
    std::cout << "Inicio del combate:" << std::endl;
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla para números aleatorios

    while (p1->getSalud() > 0 && p2->getSalud() > 0) {
        int turno = rand() % 2; // Decide aleatoriamente quién ataca primero

        if (turno == 0) {
            p1->atacar(p2);
        } else {
            p2->atacar(p1);
        }

        std::cout << "Estado despues del turno:" << std::endl;
        p1->mostrarEstado();
        p2->mostrarEstado();
        std::cout << "-----------------------------" << std::endl;
    }

    if (p1->getSalud() <= 0) {
        std::cout << p1->getNom() << " ha perdido el combate." << std::endl;
    } else {
        std::cout << p2->getNom() << " ha perdido el combate." << std::endl;
    }
}



#endif 


