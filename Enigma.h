#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <string>

class Enigma {
private:
    std::string nombre;
    std::string pregunta;
    std::string respuesta_correcta;

public:
    Enigma();
    Enigma(std::string nom, std::string preg, std::string resp);
    std::string getNombre();
    std::string getPregunta();
    std::string getRespuestaCorrecta();
    void setNombre(std::string nom);
    void setPregunta(std::string pregunt);
    void setRespuesta(std::string resp);
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
