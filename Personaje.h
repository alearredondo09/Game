/*  
*  Proyecto Juego_Rol clase Personaje
*  Alejandra Arredondo
*  A01711434
*  05/06/2024
*  La clase Personaje tiene una relación de tipo herencia con las clases Alienigena, Robot, Piloto y Sephiroth, siendo esta clase
*  padre de mis clases anteriormente mencionadas. 
* 
*  Se establecesn metodos que se sobreescibiran en las clases hijas y a su vez, sus atributos se usarán en las clases hijas. 
*/
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream> // biblioteca que es utilizada para operaciones de entrada y salida

class Personaje{
    protected: 
        // atributos de mi clase personaje
        std::string nombre; 
        int nivel;
        int salud;
        int ataque;


    public: 
        Personaje(); //constructor por default de mi clase Personaje
        Personaje(std::string nom, int _nivel, int _salud, int _ataque); // constructor parametrizado de mi clase Personaje
        std::string getNom(); // getter para nombre
        int getNivel(); // getter para nivel
        int getSalud(); // getter para salud
        int getAtaque(); // getter para ataque
        void setNombre(std::string nom); //setter para nombre
        void setNivel(int _nivel); // setter de nivel
        void setSalud(int _salud); // setter de salud
        void setAtaque(int _ataque); // setter de ataque
        virtual void imprimir_personaje(); //imprime la informacion del personaje
        virtual void atacar(Personaje* objetivo) = 0; //funcion que permite que el personaje ataque
        virtual void recibirDanio(int danio) = 0; // funcion que permite recibir danio
        virtual void mostrarEstado() = 0; // funcion que muestra el estado del personaje
};

Personaje::Personaje(){
    nombre = "Anakin";
    nivel = 5;
    salud = 50;
    ataque = 5; 
}

Personaje::Personaje(std::string nom, int _nivel, int _salud, int _ataque){
    nombre = nom; 
    nivel = _nivel;
    salud = _salud;
    ataque = _ataque;
}

std::string Personaje::getNom(){return nombre;}

int Personaje::getNivel(){return nivel;}

int Personaje::getSalud(){return salud;}

int Personaje::getAtaque(){return ataque;}


void Personaje::setNombre(std::string nom){
    nombre = nom;
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

/*
*  imprimir_personaje() es un metodo cuya función será imprimir los atributos de mi personaje 
*  estos atributos son nombre, nivel, salud, ataque y defensa. Este método sera sobrescribido en sus clases hijas. 
* @param N/A
* @return N/A
*/
void Personaje::imprimir_personaje(){
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Nivel: " << nivel << "\n";
    std::cout << "Salud: " << salud << "\n"; 
    std::cout << "Ataque: " << ataque << "\n"; 
}



#endif