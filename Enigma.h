/*
*  Proyecto Juego_Rol clase Enigma
*  Alejandra Arredondo
*  A01711434
*  05/06/2024
*  La clase Enigma es una clase de tipo composición con mi clase Planeta, está clase crea objetos de tipo Enigma
* el cual me permite crear un enigma que tenga tanto su nombre, pregunta como su respuesta.
* 
*/
#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream> // biblioteca que es utilizada para operaciones de entrada y salida

class Enigma {
private:
    // atributos
    std::string nombre;
    std::string pregunta;
    std::string respuesta_correcta;

public:
    Enigma(); // constructor por default 
    Enigma(std::string nom, std::string preg, std::string resp); // constructor parametrizado
    std::string getNombre(); // getter de nombre
    std::string getPregunta(); // getter de pregunta
    std::string getRespuestaCorrecta(); // getter de respuesta
    void setNombre(std::string nom); // setter de nombre
    void setPregunta(std::string pregunt); // setter de pregunta
    void setRespuesta(std::string resp); // setter de respuesta
};

Enigma::Enigma() {
    nombre = "fuego";
    pregunta = "Soy mas ligero que el aire, pero cientos de personas no pueden levantarme. ¿Que soy?";
    respuesta_correcta = "burbuja";
}

Enigma::Enigma(std::string nom, std::string preg, std::string resp) {
    nombre = nom;
    pregunta = preg;
    respuesta_correcta = resp;
}

std::string Enigma::getNombre() {
    return nombre;
}

std::string Enigma::getPregunta() {
    return pregunta;
}

std::string Enigma::getRespuestaCorrecta() {
    return respuesta_correcta;
}

void Enigma::setNombre(std::string nom){
    nombre = nom;
}
void Enigma::setPregunta(std::string pregunt){
    pregunta = pregunt;
}
void Enigma::setRespuesta(std::string resp){
    respuesta_correcta = resp;
}

#endif
