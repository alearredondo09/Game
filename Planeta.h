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
        void simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* villano, Enigma enig);
        void agregarPersonaje(int num_personaje, Personaje* p1);
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
    for (int i = 0; i < 4; ++i) {
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

void Planeta::simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* villano, Enigma enig){
    bool correcto = true;
    int ataque;

    while (correcto){
        // Primer personaje ataca al villano
        std::cout << "Primer personaje en atacar: " << p1->getNom() << std::endl;
        p1->atacar(villano);
        std::cout << "La salud del villano es: " << villano->getSalud() << std::endl;
        if (villano->getSalud() <= 0) {
            std::cout << villano->getNom() << " ha sido derrotado." << std::endl;
            break;
        }

        // Segundo personaje ataca al villano
        std::cout << "Segundo personaje en atacar: " << p2->getNom() << std::endl;
        p2->atacar(villano);
        std::cout << "La salud del villano es: " << villano->getSalud() << std::endl;
        if (villano->getSalud() <= 0) {
            std::cout << villano->getNom() << " ha sido derrotado." << std::endl;
            break;
        }

        // Tercer personaje ataca al villano
        std::cout << "Tercer personaje en atacar: " << p3->getNom() << std::endl;
        p3->atacar(villano);
        std::cout <<"La salud del villano es : " << villano->getSalud() << std::endl;
        if (villano->getSalud() <= 0) {
            std::cout << villano->getNom() << " ha sido derrotado." << std::endl;
            break;
        }

        // Villano ataca a un personaje
        std::cout << "Sephiroth, a que personaje quieres atacar?" << std::endl;
        std::cout << "Los personajes que puedes atacar son: " << std::endl;
        std::cout << "Ingresa 1 si quieres atacar a: " << p1->getNom() << std::endl;
        std::cout << "Ingresa 2 si quieres atacar a: " << p2->getNom() << std::endl;
        std::cout << "Ingresa 3 si quieres atacar a: " << p3->getNom() << std::endl;
        std::cin >> ataque;
        std::cin.ignore();

        if (ataque == 1) {
            villano->atacar(p1);
            std::cout << "La salud de" << p1->getNom() << " es: " << p1->getSalud() << std::endl;
        } else if (ataque == 2) {
            villano->atacar(p2);
            std::cout << "La salud de " << p2->getNom() << " es: " << p2->getSalud() << std::endl;
        } else if (ataque == 3) {
            villano->atacar(p3);
            std::cout << "La salud de " << p3->getNom() << " es: " << p3->getSalud() << std::endl;
        } else {
            std::cout << "Debes elegir uno de los números anteriores " << std::endl;
        }

        // Verificar si algún personaje ha sido derrotado
        if (p1->getSalud() <= 0) {
            std::cout << p1->getNom() << " ha sido derrotado." << std::endl;
        }
        if (p2->getSalud() <= 0) {
            std::cout << p2->getNom() << " ha sido derrotado." << std::endl;
        }
        if (p3->getSalud() <= 0) {
            std::cout << p3->getNom() << " ha sido derrotado." << std::endl;
        }
        if (p1->getSalud() <= 0 && p2->getSalud() <= 0 && p3->getSalud() <= 0) {
            std::cout << "Todos los personajes han sido derrotados. Sephiroth gana el combate." << std::endl;
            break;
        }

        // Intentar adivinar el enigma
        std::string respuesta;
        std::cout << "Iintenta resolver el enigma: " << enig.getPregunta() << std::endl;
        std::cout << "Respuesta: ";
        std::getline(std::cin, respuesta);

        if (respuesta == enig.getRespuestaCorrecta()) {
            std::cout <<"Ha resuelto el enigma correctamente. ¡El combate termina!" << std::endl;
            correcto = false;
            break;
        } else {
            std::cout << "Respuesta incorrecta. El combate continua." << std::endl;
        }

        if (!correcto) {
            break;
        }
    }
}

void Planeta::agregarPersonaje(int num_personaje, Personaje* p1){
    if (num_personaje < 4) {
        personajes[num_personaje] = p1;
    } else {
        std::cout << "No se pueden agregar más personajes, el arreglo está lleno." << std::endl;
    }
}







#endif 


