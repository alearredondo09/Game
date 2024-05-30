#include <iostream>
#include <string>
#include "Planeta.h"

using namespace std;

// establecer la edad solamente en años



int main(){
    
    // variables
    Robot* robot1 = new Robot();
    Planeta aura;   
    string nombre_planeta;
    bool inicio_juego;
    int eleccion_personaje;
    string nombre_personaje; 
    string historia_personaje;
    string nivel_fuerza;
    string hab;

    cout << "Esta historia es una historia basada en mi propia imaginacion, todo es ficticio.\n";
    cout << "Para iniciar deberas decirme si quieres iniciar el juego:\nPon 1 para iniciar el juego\nSino el juego no sera comenzado\n";
    cin >> inicio_juego;
    cin.ignore(); // Limpia el buffer después de leer un booleano/entero

// hacer un ciclo para poder pedirle al usuario algo valido 
    if (inicio_juego == 1) {
        cout << "Para iniciar debemos de crear el planeta en donde viviras.\n";
        cout << "Tu podras elegir el nombre de tu planeta. Escribe el nombre de planeta: ";
        cin >> nombre_planeta;
        aura.setNombre(nombre_planeta);
        cout << aura.getNombre()<< endl;
        cout << "Tu podras elegir que personaje ser de una lista que se muestra a continuacion: \n";
        cout << "1 - Robot \n2 - Alienigena \n3 - Piloto\n";
        cout << "Cual vas a elegir?: ";
        cin >> eleccion_personaje;
        cin.ignore(); // Limpia el buffer después de leer un entero


         if (eleccion_personaje == 1){
            cout << "Ahora que elegiste ser el robot debemos comenzar a crear nuestro personaje\n";
            cout << "Debemos iniciar eligiendo el nombre del robot. Como te gustaria llamarte?: ";
            cin >> nombre_personaje; 
            robot1->setNombreP(nombre_personaje);
            cin.ignore(); // Limpia el buffer después de leer un entero
            // string hist_per, string fuerxa, string hab
            cout << "Este personaje tiene que tener una historia, dime la historia de este personaje: " << endl;
            getline(cin, historia_personaje);

            robot1->setHistoria(historia_personaje);
            cout << "Dame que nivel de fuerza tiene el robot: " << endl;
            getline(cin,nivel_fuerza);
            robot1->setFuerxa(nivel_fuerza);
            cout << "Dame la habilidad que tiene el robot: " << endl,
            getline(cin, hab);
            robot1->setHab(hab);
            robot1->imprimir_Personaje();
            


         } else if (eleccion_personaje == 2){

         } else if (eleccion_personaje == 3){

         } else{
            cout << "Ese no es un personaje valido. Vuelve a intentarlo \n";
         }


    } else {
        cout << "Juego no iniciado.\n";
    }

    
    delete robot1;
    return 0;
}
