#ifndef PLANETA_
#define PLANETA_
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "Personaje.h"
#include "Enigma.h"

class Planeta{
    private: 
        std::string nombre;
        std::string historia;
        Personaje* personajes[4];
        Enigma enigma;
    public: 
        Planeta();
        Planeta(std::string nom, std::string hist, Personaje* p1, Personaje* p2, Personaje* p3, Personaje* p4,Enigma enig);
        ~Planeta();
        std::string getNombre();
        std::string getHist();
        Enigma getEnigma();
        void setNombre(std::string nom);
        void setHist(std::string hist);
        void setEnignma(Enigma& enig);
        void mostrarEstado();
        void simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* p4, Enigma enig);
        void agregarPersonaje(Personaje* p1);
        Personaje* buscarPersonaje(std::string nom1);
};

Planeta::Planeta(){
    nombre = "Aura";
    historia = "planeta desconocido hasta 1849";
}
Planeta::Planeta(std::string nom, std::string hist, Personaje* p1, Personaje* p2, Personaje* p3, Personaje* p4, Enigma enig){
    nombre = nom;
    historia = hist;
    enigma = enig;
    personajes[0] = p1;
    personajes[1] = p2;
    personajes[2] = p3;
    personajes[3] = p4;
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

void Planeta::simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* p4, Enigma enig){
    bool correcto = true; 
    std::string resp;
    Personaje* ganador = nullptr; 
    while(correcto){
    // Randomly select an attacker
        int turno = rand() % 4;
        // Randomly select a target that is not the attacker
        int objetivo;
        do {
            objetivo = rand() % 4;
            personajes[turno]->atacar(personajes[objetivo]);
            for (int i = 0; i < 4; i++) {
                personajes[i]->mostrarEstado();
            }
        } while (objetivo != turno);



        std::cout << "El nombre del enigma es: " << enig.getNombre() << std::endl;
        std::cout << enig.getPregunta() << std::endl;
        std::cout << "Dame la respuesta del enigma: " << std::endl;
        std::getline(std::cin, resp);
        if (resp == enig.getRespuestaCorrecta()) {
            std::cout << "Respuesta correcta!" << std::endl;
            std::cout << "Fin del combate. " << std::endl;

            ganador = personajes[0]; // Initialize ganador to the first character
            for (int i = 1; i < 4; i++) {
                if (personajes[i]->getSalud() > ganador->getSalud()) {
                    ganador = personajes[i];
                }
            }
            std::cout << "El personaje ganador es: " << ganador->getNom() << " con una salud de " << ganador->getSalud() << std::endl;
            break; 

        } else {
            std::cout << "Sigue el combate :)" << std::endl;
        }
        // Check if the combat should continue
        for (int i = 0; i < 4; i++) {
            if (personajes[i]->getSalud() <= 0) {
                correcto = false;
                break;
            }
        }
    }
}


void Planeta::agregarPersonaje(Personaje* p1){
    int num_personajes;
    if (num_personajes < 4) {
        personajes[num_personajes] = p1;
        num_personajes++;
    } else {
        std::cout << "No se pueden agregar más personajes, el arreglo está lleno." << std::endl;
    }
}







#endif 


