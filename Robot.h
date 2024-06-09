/*
*  Proyecto Juego_Rol clase Robot
*  Alejandra Arredondo
*  A01711434
*  05/06/2024
*  La clase Robot tiene una relación de tipo herencia con la clase Personaje, esta clase es hija de mi clase Personaje
*  Se crean los objetos de tipo Robot y se establecen varios metodos que se sobreescriben
*  de la clase padre.
*/
#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>
#include "Personaje.h"

class Robot : public Personaje{
    private: 
        //atributos
        std::string habilidad; 
    public: 
        Robot(); // constructor por default
        Robot(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string hab); // constructor parametrizado
        std::string getHab(); //getter de habilidad
        void setHab(std::string hab); // setter de habilidad
        void imprimir_personaje(); //imprime la informacion del personaje
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();

};

Robot::Robot(){
    habilidad = " teletransportarse ";
}
Robot::Robot(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string hab) : Personaje(nom,  _nivel, _salud, _ataque){
    habilidad = hab;
}

std::string Robot::getHab(){
    return habilidad;
}

void Robot::setHab(std::string hab){
    habilidad = hab;
}

/*
*  imprimir_persona() imprime el metodo de la clase Personaje imprimer_personaje()
*  y a su vez imprime la habilidad que tiene el personaje.
* 
* @param N/A
* @return N/A
*/
void Robot::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "La habilidad de " << nombre << " es: " << habilidad << std::endl;
}

/*
* atacar() es un metodo de sobreescritura que contiene un ciclo while que establece que mientras sea
* verdadero, el usuario va a poder decidir la habilidad del Robot, a partir de esa decisión podrá establecer
* el valor de su ataque y acatar a un personaje. 
* 
* @param Personaje* objetivo, debe ser una instancia de Personaje
* @return N/A
*/
void Robot::atacar(Personaje* objetivo){
    int opcion;
    while (true){
        std::cout << "Dime la habilidad que tienes, las opciones son:" ;
        std::cout << "\nIngresa 1 para desintegracion\nIngresa 2 teletransportarse\nDame la habilidad de tu robot: ";
        std::cin >> opcion;

        if (opcion == 1){
            setAtaque(5); 
            habilidad = "desintegracion";
            std::cout << "tu habilidad " << habilidad << " le resto 5 puntos de salud a " << objetivo->getNom() << std::endl;
            break;
        } else if(opcion == 2){
            setAtaque(5);
            habilidad = "teletransportarse";
            std::cout << "La habilidad " << habilidad << " le acaba de restar 5 puntos de salud a " << objetivo->getNom() << std::endl;
            break;
        } else{
            std::cout << "Ingresa un valor valido" << std::endl;
        }
    }
        objetivo->recibirDanio(ataque);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
}

/*
*  recibirDanio() es un metodo de sobreescritura que contiene un condicional en donde si el ataque
*  es mayor a cero, podra proceder a restarle a la salud el ataque que recibe Robot.
*
*  @param int ataque, es el valor de ataque que se le restará a la salud
*  @ return N/A
*/
void Robot::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = salud - ataque;
        setSalud(sal);
    }
}

/*
*  mostrarEstado() es un metodo que imprime la informacion de mi Robot que importa para que el usuario
*  sepa el estado de su personaje y la habilidad que tiene.
* 
* @param N/A
*  @return N/A
*/
void Robot::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Habilidad:" << habilidad << std::endl;
}


#endif