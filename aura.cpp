#include <iostream>
#include "Planeta.h"
#include "Robot.h"
#include "Alienigena.h"
#include "Piloto.h"
#include "Sephiroth.h"
#include "Enigma.h"

using namespace std;

int main() {
    // Crear personajes
    //Robot(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string hab);
    Robot* r1 = new Robot("RobotX", 12, 4, 5, 3, 5,"laser");
    //Alienigena(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string hab); // constructor parametrizado
    Alienigena* a1 = new Alienigena("AlienY", 78,6,4,8, 1, "veneno");
    // std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string _vehiculo
    Piloto* p1 = new Piloto("PilotoZ", 37,2,9,3,1, "nave Espacial");
    //Sephiroth(std::string nom, int _edad, int _nivel, int _salud, int _ataque, int _defensa, std::string _puesto);
    Sephiroth* s1 = new Sephiroth("SephirothA", 52, 3, 4,5,6,"general");

    // Crear enigma
    Enigma enigma("El enigma del destino", 5);

    // Crear planeta usando el constructor vacío
    Planeta aura;

    // Mostrar estado inicial del planeta
    aura.mostrarEstado();

    // Simular combate
    aura.simularCombate(r1, a1);
    aura.simularCombate(r1,s1);


    delete r1;
    delete a1;
    delete p1;
    delete s1;

    return 0;
}
