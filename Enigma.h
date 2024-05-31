#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string>

class Enigma{
    private:
        std::string nombre;
        int puntaje;

    public:

        Enigma();
        Enigma(std::string nom, int punt);
        std::string getNombre();
        int getPuntaje();
        void setNom(std::string nom);
        void setPunt(int punt);
        void puntaje_adquirido(bool solucion);
};

Enigma::Enigma(){
    nombre = "fuego";
    puntaje = 0;
}
Enigma::Enigma(std::string nom, int punt){
    nombre = nom;
    puntaje = punt;
}
std::string Enigma::getNombre(){
    return nombre;
}
int Enigma::getPuntaje(){
    return puntaje;
}
void Enigma::puntaje_adquirido(bool solucion){
    if (solucion){
        int ventaja = 2;
        puntaje += ventaja;
        std::cout << "El puntaje es de " << puntaje << std::endl;
    } else {
        std::cout << "El puntaje es el mismo " << std::endl;
    }
}

#endif