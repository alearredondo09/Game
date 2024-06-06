#include <iostream>
//#include <unistd.h>
#include "Planeta.h"
#include "Robot.h"
#include "Alienigena.h"
#include "Piloto.h"
#include "Sephiroth.h"
#include "Enigma.h"

int main() {
    Robot* robot1 = new Robot();
    Alienigena* alien = new Alienigena() ;
    Piloto* poe = new Piloto();
    Sephiroth* sephiroth = new Sephiroth();
    Enigma enig("Enigma del fuego", "Soy mas ligero que el aire, pero cientos de personas no pueden levantarme. Que soy?", "burbuja");
    Planeta aura;
    bool ciclo = true;
    int jugar, eleccion_batalla;
    int edad_robot, edad_alien, edad_piloto, edad_sephiroth;
    std::string nombre_robot, nombre_piloto, nombre_alien, nombre_sephiroth, nombre_planeta;
    std::string habilidad_robot, habilidad_alien;
    std::string vehiculo_piloto;
    std::string puesto;
    std::string personaje1;
    std::string personaje2;
    while (ciclo){
        std::cout << "Este juego es totalmente ficticio, esta bajo tu responsabilidad si lo juegas o no.\nIngresa 0 si no quieres jugar\nIngresa 1 si quieres jugar" << std::endl;
        std::cin >> jugar;
        if (jugar == 0) {
            std::cout << "Saliendo del juego..." << std::endl;
            break;
        } else if (jugar == 1) {
            std::cin.ignore(); // Ignora el salto de línea después de la lectura de jugar
            std::cout << "Debemos de crear los personajes a usar." << std::endl;
            std::cout << "Nuestro primer personaje es un robot. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_robot);
            robot1->setNombre(nombre_robot);

            std::cout << "Nuestro segundo personaje es un alienigena. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_alien);
            alien -> setNombre(nombre_alien);

            std::cout << "Nuestro tercer personaje es un piloto. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_piloto);
            poe -> setNombre(nombre_piloto);

            std::cout << "Nuestro cuarto personaje es un villano. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_sephiroth);
            sephiroth -> setNombre(nombre_sephiroth);

            std::cout << "Dame el nombre del planeta: ";
            std::getline(std::cin, nombre_planeta);
            aura.setNombre(nombre_planeta);
            aura.agregarPersonaje(0, robot1);
            aura.agregarPersonaje(1, alien);
            aura.agregarPersonaje(2, poe);
            aura.agregarPersonaje(3, sephiroth);

            std::cout << "Explicacion del juego: " << std::endl;
            std::cout << "El juego consiste en utilizar a tus personajes que acabas de crear para atacar a " << sephiroth->getNom() << " ." << std::endl;
            std::cout << "La rutina es utilizar las acciones que te indica que le pertenece a cada personaje y asi atacar" << std::endl;
            std::cout << "Despues de atacar tendras que adivinar el enigma, si logras adivinarlo, el combate se acaba, sino seguiras hasta adivinar el enigma o que tu salud se acabe. " << std::endl;
            
            aura.simularCombate(robot1, alien,poe, sephiroth, enig);

            delete robot1; // Libera la memoria después de usar el objeto
            delete alien; // Libera la memoria después de usar el objeto
            delete poe; // Libera la memoria después de usar el objeto
            delete sephiroth; // Libera la memoria después de usar el objeto

        } else {
            std::cout << "Debes ingresar un valor valido" << std::endl;

        }
    }
    return 0;
}
