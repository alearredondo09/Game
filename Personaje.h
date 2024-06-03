#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>

/*
Clase creada el 10 de Mayo
Esta clase es la clase padre que va a heredar sus atributos y metodos a las clases hijas
*/

class Personaje{
    protected: 
        // atributos de mi clase personaje
        std::string nombre; 
        int edad;
        int nivel;
        int salud;
        int ataque;
        int defensa;


    public: 
        Personaje(); //constructor por default de mi clase Personaje
        Personaje(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa); // constructor parametrizado de mi clase Personaje
        virtual ~Personaje()=0; //destructor 
        std::string getNom(); // getter para nombre
        int getEdad(); // getter para edad
        int getNivel(); // getter para nivel
        int getSalud(); // getter para salud
        int getAtaque(); // getter para ataque
        int getDefensa(); // getter para defensa
        void setNombre(std::string nom); //setter para nombre
        void setEdad(int _edad); //setter para edad
        void setNivel(int _nivel); // setter de nivel
        void setSalud(int _salud); // setter de salud
        void setAtaque(int _ataque); // setter de ataque
        void setDefensa(int _defensa); // setter de defensa
        virtual void imprimir_personaje(); //imprime la informacion del personaje
        virtual void atacar(Personaje* objetivo) = 0; //funcion que permite que el personaje ataque
        virtual void recibirDanio(int danio) = 0; // funcion que permite recibir danio
        virtual void mostrarEstado() = 0; // funcion que muestra el estado del personaje
};

Personaje::Personaje(){
    nombre = "Anakin";
    edad = 27;
    nivel = 5;
    salud = 10,
    ataque = 5; 
    defensa = 5;
}

Personaje::Personaje(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa){
    nombre = nom;
    edad = _edad; 
    nivel = _nivel;
    salud = _salud;
    ataque = _ataque;
    defensa = _defensa;
}

Personaje::~Personaje() {
    std::cout << "Destructor de Personaje llamado" << std::endl;
}

std::string Personaje::getNom(){return nombre;}

int Personaje::getEdad(){return edad;}

int Personaje::getNivel(){return nivel;}

int Personaje::getSalud(){return salud;}

int Personaje::getAtaque(){return ataque;}

int Personaje::getDefensa(){return defensa;}

void Personaje::setNombre(std::string nom){
    nombre = nom;
}

void Personaje::setEdad(int _edad){
    edad = _edad;
}

void Personaje::setNivel(int _nivel){
    nivel = _nivel;
}

void Personaje::setSalud(int _salud){
    salud = _salud;
}

void Personaje::setAtaque(int _ataque){
    ataque = _ataque;
}

void Personaje::setDefensa(int _defensa){
    defensa = _defensa;
}

void Personaje::imprimir_personaje(){
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Edad: " << edad << "\n";
}





#endif