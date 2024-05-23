#ifndef PLANETA_H
#define PLANETA_H
#include <iostream>
#include <string>
#include "Robot.h"
#include "Enigma.h"
#include "Alienigena.h"
#include "Piloto.h"
#include "Sephiroth.h"
#include "Personaje.h"
using namespace std; 

class Planeta {
    private:
        string nombre;
        string historia; 
        Robot robot;
        Alienigena alien;
        Piloto piloto;
        Sephiroth villano;
        Enigma enigma; 

    public: 
        Planeta(){}
        Planeta(string nom, string histOria){
            nombre = nom; 
            historia = histOria; 
        }
        string getNombre(){return nombre;}
        string getHistoria(){return historia;}



};

#endif