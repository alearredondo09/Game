#include <iostream>
#include <string>
#include "Personaje.h"
#include "Alienigena.h"
#include "Robot.h"
#include "Enigma.h"
#include "Sephiroth.h"
#include "Planeta.h"

using namespace std;

// establecer la edad solamente en años

int main(){

//Alienigena(string nom, int edAd, string hist_pers, string colOr, string puesto, int medallas) : Personaje(nom,edAd,hist_pers){
    Alienigena allien("Vektor",189,"Venusitato","Verde","Militar comandante",18);
    allien.levitar(true);
    allien.teletransportarse(false);
    allien.control_mental(false);
    allien.cambiar_forma(true);
    allien.imprimir_Personaje();

    Robot robot1;
    robot1.setNombreP("Duali");
    robot1.setHistoria(" nacido en la cuna de sus padres"),
    robot1.setFuerxa(" alta");
    robot1.setHab("Control menatl");

    Enigma enigma("Puntero",9);
    enigma.puntaje_adquirido(true);

    Sephiroth sephiroth;
    sephiroth.setNombreP("DarkVather");
    sephiroth.setMotivo("Discriminacion");
    sephiroth.setPuesto("comandante de las tropas para batalla");
    sephiroth.imprimir_Personaje();

    Piloto piloto("Dude", 36, "Venezuela", "familia de dinero", 9, 378, "Aeromexico");
    piloto.imprimir_Personaje();

    

    

    return 0;
}
