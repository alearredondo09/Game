/*
*  Proyecto Juego_Rol clase Piloto
*  Alejandra Arredondo
*  A01711434
*  05/06/2024
*  La clase Piloto tiene una relación de tipo herencia con la clase Personaje, esta clase es hija de mi clase Personaje
*  Se crean los objetos de tipo Piloto y se establecen varios metodos que se sobreescriben
*  de la clase padre.
*/

#ifndef PILOTO_H
#define PILOTO_H
#include <iostream>  // biblioteca que es utilizada para operaciones de entrada y salida
#include "Personaje.h" // incluye la clase Personaje

class Piloto : public Personaje{
    private: 
        // atributos
        std::string vehiculo;
    public: 
        Piloto(); // constructor por default
        Piloto(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo); // constructor parametizado
        std::string getVehiculo(); // getter de vehiculo
        void setVehiculo(std::string _vehiculo); // setter de vehiculo
        void imprimir_personaje(); // metodo que imprime la informacion del personaje        
        void atacar(Personaje* objetivo); //metodo que permite que el personaje a atacar
        void recibirDanio(int danio); // metodo que permite recibir danio
        void mostrarEstado(); // metodo que muestra el estado del personaje
};

Piloto::Piloto(){
    vehiculo = "dron";
}
Piloto::Piloto(std::string nom, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo) : Personaje(nom, _nivel, _salud, _ataque){
    vehiculo = _vehiculo;
}

std::string Piloto::getVehiculo(){
    return vehiculo;
}
void Piloto::setVehiculo(std::string _vehiculo){
   vehiculo = _vehiculo;
}

/*
*  imprimir_persona() imprime el metodo de la clase Personaje imprimer_personaje()
*  y a su vez imprime el vehiculo que tiene el personaje.
* 
* @param N/A
* @return N/A
*/
void Piloto::imprimir_personaje(){
    Personaje::imprimir_personaje();
    std::cout << "El vehiculo de" << nombre << " es: " << vehiculo << std::endl;
}

/*
* atacar() es un metodo de sobreescritura que contiene un ciclo while que establece que mientras sea
* verdadero, el usuario va a poder decidir el vehiculo del Piloto, a partir de esa decisión podrá establecer
* el valor de su ataque y acatar a un personaje. 
* 
* @param Personaje* objetivo, debe ser una instancia de Personaje
* @return N/A
*/

void Piloto::atacar(Personaje* objetivo){
    while (true){
        int opcion;
        std::cout << "Dime el vehiculo que tienes, las opciones son:\nIngresa 1 para crucero "; 
        std::cout << "\nIngresa 2 para tanque\nIngresa 3 para dron\nDame el vehiculo de " << nombre << " : ";
        std::cin >> opcion;

        if (opcion == 1){
            setAtaque(3);
            vehiculo = "crucero";
            std::cout << "Tu vehiculo " << vehiculo << " le ha restado 3 puntos de salud a " << objetivo->getNom() << std::endl;
            break;
        } else if(opcion == 2){
            setAtaque(5);
            vehiculo = "tanque";
            std::cout << "Tu vehiculo " << vehiculo << " le ha restado 5 puntos de salud a " << objetivo->getNom() << std::endl;
            break;
        } else if(opcion == 3){
            setAtaque(4);
            vehiculo = "dron";
            std::cout << "Tu vehiculo " << vehiculo << " le ha restado 4 puntos de salud a " << objetivo->getNom() << std::endl;            
            break;
        } else {
            std::cout << "Ingresa una de las opciones anteriores." << std::endl;
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
void Piloto::recibirDanio(int ataque){
    int sal;
    if (ataque > 0){
        sal = getSalud() - ataque;
        setSalud(sal);
    }
}

/*
*  mostrarEstado() es un metodo que imprime la informacion de mi Piloto que importa para que el usuario
*  sepa el estado de su personaje y el vehiculo que tiene.
* 
* @param N/A
*  @return N/A
*/
void Piloto::mostrarEstado() {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << salud << ", Vehiculo:" << vehiculo << std::endl;
}


#endif