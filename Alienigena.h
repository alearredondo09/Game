/*
*  Proyecto Juego_Rol clase Alienigena
*  Alejandra Arredondo
*  A01711434
*  05/06/2024
*  La clase Alienigena tiene una relación de tipo herencia con la clase Personaje, esta clase es hija de mi clase Personaje
*  Se crean los objetos de tipo Piloto y se establecen varios metodos que se sobreescriben
*  de la clase padre.
*/
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
        std::string getHabilidad(); // getter de habilidad
        void setHabilidad(std::string hab); // setter de habilidad
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

/*
*  imprimir_persona() imprime el metodo de la clase Personaje imprimer_personaje()
*  y a su vez imprime la habilidad que tiene el personaje.
* 
* @param N/A
* @return N/A
*/
void Alienigena::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "Habilidad: " << habilidad << std::endl;
}

/*
* atacar() es un metodo de sobreescritura que contiene un ciclo while que establece que mientras sea
* verdadero, el usuario va a poder decidir la habilidad del Alienigena, a partir de esa decisión podrá establecer
* el valor de su ataque y acatar a un personaje. 
* 
* @param Personaje* objetivo, debe ser una instancia de Personaje
* @return N/A
*/

void Alienigena::atacar(Personaje* objetivo){
    int habi;
    while (true) {
        std::cout << "Dime la habilidad que tienes, las opciones son:\nIngresa 1 para telepatia\nIngresa 2 veneno\nDame la habilidad de tu alien: ";
        std::cin >> habi;
        if (habi == 1) {
            setAtaque(7);
            habilidad = "telepatia";
            std::cout << habilidad;
            break;
        } else if (habi == 2) {
            habilidad = "veneno";
            setAtaque(8);
            break;
        } else {
            std::cout << "Agrega una opcion valida:" << std::endl;
        }      
    }
        objetivo->recibirDanio(ataque);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;  
}


/*
*  recibirDanio() es un metodo de sobreescritura que contiene un condicional en donde si el ataque
*  es mayor a cero, podra proceder a restarle a la salud el ataque que recibe Piloto.
*
*  @param int ataque, es el valor de ataque que se le restará a la salud
*  @ return N/A
*/
void Alienigena::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = salud - ataque;
        setSalud(sal);
    }
}

/*
*  mostrarEstado() es un metodo que imprime la informacion de mi Piloto que importa para que el usuario
*  sepa el estado de su personaje y la habilidad que tiene.
* 
* @param N/A
*  @return N/A
*/

void Alienigena::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Habilidad:" << habilidad << std::endl;
}


#endif