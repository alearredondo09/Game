/*
*  Proyecto Juego_Rol clase Planeta
*  Alejandra Arredondo
*  A01711434
*  05/06/2024
*  La clase Planeta es una clase de tipo composición con mis clases Enigma y de tipo Personaje, está clase crea objetos de tipo Planeta
* el cual me permite establecer el combate a través de los personajes que se crean para componer a mi clase planeta
* esta clase tendrá metodos que me permitirán establecer el combate , mostrar el estado de mi planeta y agregar personajes a mi clase. 
* 
*/
#ifndef PLANETA_
#define PLANETA_
#include <iostream> // biblioteca que es utilizada para operaciones de entrada y salida
#include "Personaje.h" // incluye la clase personaje
#include "Enigma.h" // incluye la clase enigma

class Planeta{
    private: 
        // atributos, arreglo y objeto que conforman la composición a mi clase Planeta
        std::string nombre;
        std::string historia;
        Personaje* personajes[4];
        Enigma enigma;
    public: 
        Planeta(); // constructor por default
        Planeta(std::string nom, std::string hist, Personaje* p1, Personaje* p2, Personaje* p3, Personaje* p4,Enigma enig); // constructor parametrizado
        ~Planeta(); // destructor de planeta
        std::string getNombre(); // getter de nombre
        std::string getHist(); // getter de historia
        Enigma getEnigma(); // getter de enigma
        void setNombre(std::string nom); // setter de  nombre
        void setHist(std::string hist); // setter de historia
        void setEnignma(Enigma& enig); // setter de enigma
        void mostrarEstado(); // metodo para mostrar el estado del planeta
        void simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* villano, Enigma enig); // metodo para simular el combate entre los personajes
        void agregarPersonaje(int num_personaje, Personaje* p1); // metodo para agregar personajes al arreglo de personajes
        void imprimirPersonajes();
};

Planeta::Planeta(){
    nombre = "Aura";
    historia = "planeta desconocido hasta 1849"; // mejorar la historia del planeta
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

/*
*  simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* villano, Enigma enig)
*  
* Este metodo obtiene cuatro personajes y un enigma, para poder atacar, a su vez, pide una respuesta para el enigma creado, si este es correcto, 
* el combate termina, sin embargo, si no es adivinada la respuesta, el combate seguirá, hasta que alguno de los personajes ya no tenga salud y muera. 
*
* @param recibe apuntadores de personaje que son creados y a su vez recibe un enigma que debera ser resuelto
* @return N/A
*/
void Planeta::simularCombate(Personaje* p1, Personaje* p2, Personaje* p3, Personaje* villano, Enigma enig){
    bool correcto = true;
    int ataque;

    while (correcto){
        // Primer personaje ataca al villano
        std::cout << "Primer personaje en atacar: " << p1->getNom() << std::endl;
        p1->atacar(villano);
        villano->mostrarEstado();
        if (villano->getSalud() <= 0) {
            std::cout << villano->getNom() << " ha sido derrotado." << std::endl;
            break;
        }

        // Segundo personaje ataca al villano
        std::cout << "Segundo personaje en atacar: " << p2->getNom() << std::endl;
        p2->atacar(villano);
        villano->mostrarEstado();
        if (villano->getSalud() <= 0) {
            std::cout << villano->getNom() << " ha sido derrotado." << std::endl;
            break;
        }

        // Tercer personaje ataca al villano
        std::cout << "Tercer personaje en atacar: " << p3->getNom() << std::endl;
        p3->atacar(villano);
        villano->mostrarEstado();
        if (villano->getSalud() <= 0) {
            std::cout << villano->getNom() << " ha sido derrotado." << std::endl;
            break;
        }

        // Villano ataca a un personaje
        std::cout << villano->getNom() << " a que personaje quieres atacar?" << std::endl;
        std::cout << "Los personajes que puedes atacar son: " << std::endl;
        std::cout << "Ingresa 1 si quieres atacar a: " << p1->getNom() << std::endl;
        std::cout << "Ingresa 2 si quieres atacar a: " << p2->getNom() << std::endl;
        std::cout << "Ingresa 3 si quieres atacar a: " << p3->getNom() << std::endl;
        std::cin >> ataque;

        if (ataque == 1) {
            villano->atacar(p1);
            p1->mostrarEstado();
        } else if (ataque == 2) {
            villano->atacar(p2);
            p2->mostrarEstado();
        } else if (ataque == 3) {
            villano->atacar(p3);
            p3->mostrarEstado();
        } else {
            std::cout << "Debes elegir uno de los números anteriores " << std::endl;
        }

        // Verificar si algún personaje ha sido derrotado
        if (p1->getSalud() <= 0) {
            std::cout << p1->getNom() << " ha sido derrotado." << std::endl;
            break;
        }
        if (p2->getSalud() <= 0) {
            std::cout << p2->getNom() << " ha sido derrotado." << std::endl;
            break;
        }
        if (p3->getSalud() <= 0) {
            std::cout << p3->getNom() << " ha sido derrotado." << std::endl;
            break;
        }
        if (p1->getSalud() <= 0 && p2->getSalud() <= 0 && p3->getSalud() <= 0) {
            std::cout << "Todos los personajes han sido derrotados. " << villano->getNom() <<  " gana el combate." << std::endl;
            break;
        }

        // Intentar adivinar el enigma
        std::cin.ignore();
        std::string respuesta;
        std::cout << "Intenta resolver el enigma: " << enig.getPregunta() << std::endl;
        std::cout << "Respuesta: ";
        std::getline(std::cin, respuesta);

        if (respuesta == enig.getRespuestaCorrecta()) {
            std::cout <<"Ha resuelto el enigma correctamente. El combate termina!" << std::endl;
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

/*
* agregarPersonaje() este metodo  agrega los personajes creados en arreglo de apuntadores de tipo Personaje 
* y los pone en ciertas posiciones del arreglo.
* 
* @param num de personaje, la posición y el apuntador de personaje que se debe de agregar.
* @return N/A
*/

void Planeta::agregarPersonaje(int num_personaje, Personaje* p1){
    if (num_personaje < 4) {
        personajes[num_personaje] = p1;
    } else {
        std::cout << "No se pueden agregar más personajes, el arreglo está lleno." << std::endl;
    }
}

void Planeta::mostrarEstado(){
    std::cout << "El planeta tiene el nombre de: " << nombre << std::endl;
    std::cout << "\nLa historia de este planeta es: " << historia << std::endl;
    std::cout << "\nEl enigma que estaras adivinando se denomina: " << enigma.getNombre() << "\n\n" << std::endl;
}

/*
* imprimirPersonajes() este metodo imprime todos los personajes que están en el arreglo de tipo Personaje
* 
* @param N/A
* @return N/A
*/
void Planeta::imprimirPersonajes(){
    for (int i = 0; i < 4; i++){
        personajes[i]->imprimir_personaje() ;
        std::cout << "-----------------------------------------------------------------" << std::endl;
    }
}







#endif 


