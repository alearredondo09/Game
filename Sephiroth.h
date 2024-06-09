/*
* Proyecto Juego de Rol clase Sephiroth
* Alejandra Arredondo 
* A01711434
* 05/06/2024
* Version : v.8
* Esta clase define objetos de tipo Sephiroth que contiene los atributos de su clase padre Personaje (relacion de herencia) e implementa sus propios atributos
*/
#ifndef SEPHIROTH_H
#define SEPHIROTH_H
#include <iostream>
#include <string>
#include "Personaje.h"

class Sephiroth : public Personaje{
    private:
        //atributos de mi clase sephiroth
        std::string puesto;
        int defensa;
    
    public: 
        Sephiroth(); // constructor por default
        Sephiroth(std::string nom, int _nivel, int _salud, int _ataque, std::string _puesto, int defensa); // constructor parametrizado
        std::string getPuesto(); // getter de puesto
        void setPuesto(std::string _puesto); // setter de puesto
        void setDefensa(int _defensa); // setter de defensa
        int getDefensa(); // getter para defensa
        void imprimir_personaje(); //imprime la informacion del personaje        
        void atacar(Personaje* objetivo); //funcion que permite que el personaje ataque
        void recibirDanio(int danio); // funcion que permite recibir danio
        void mostrarEstado();
};

//
Sephiroth::Sephiroth() : Personaje(){
    puesto = "lider supremo";
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

/*
* imprimir_personaje() Imprime los atributos de mi clase Sephiroth 
* 
* llama el metodo de mi clase Personaje (de la cual esta heredando) imprimir_personaje() 
* la cual tiene las caracteristicas de mi personaje e incluye el puesto de mi objeto Sephirtoh. 
* 
* @param N/A
* @return N/A
*/
void Sephiroth::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "El puesto de " << nombre << " es " << puesto << std::endl;
    std::cout << "La defensa de " << nombre << " es: " << defensa << std::endl;
}

/*
* atacar() es un metodo de sobreescritura que contiene un ciclo while que establece que mientras sea
* verdadero, el usuario va a poder decidir el puesto de Sephiroth, a partir de esa decisión podrá establecer
* el valor de su ataque y acatar a un personaje. 
* 
* @param Personaje* objetivo, debe ser un objeto creado de tipo Personaje
* @return N/A
*/

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
            std::cout << "Tu puesto " << puesto << " le ha quitado 12 puntos de salud a " << objetivo->getNom() << std::endl;
            break;
        } else if(opcion == 2){
            setAtaque(15);
            puesto = "lider supremo";
            std::cout << "Tu puesto " << puesto << " le ha quitado 15 puntos de salud a " << objetivo->getNom() << std::endl;
            break;
        } else{
            std::cout << "Inserta un valor correcto" << std::endl;
        }
    }
        objetivo->recibirDanio(ataque);
        std::cout << nombre << " ataca a " << objetivo->getNom() << std::endl;
}

/*
*  recibirDanio() es un metodo de sobreescritura que contiene un condicional en donde si el ataque
*  es mayor a cero, podra proceder a restarle a la salud el ataque que recibe pero a su vez sumarle 
*  que tiene Sephiroth.
*
*  @param int ataque, es el valor de ataque que se le restará a la salud
*  @ return N/A
*/
void Sephiroth::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = salud - ataque + defensa;
        setSalud(sal);
    }
}

/*
*  mostrarEstado() es un metodo que nos imprime el estado del personaje incluye su nombre, nivel, salud y puesto
*  
*  @param N/A
*  @return N/A
*/
void Sephiroth::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Puesto: " << puesto << "\n\n" << std::endl;
}


#endif