#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Pokemon{
    public:
        Pokemon();
        Pokemon(char nombre[20],char tipo[20],int generacion,bool shiny);

        char nombre[20];
        char tipo[20];
        int generacion;
        bool shiny;

        void mostrar();
};

Pokemon::Pokemon(){
    
}

Pokemon::Pokemon(char nombre[20],char tipo[20],int generacion,bool shiny){
    strcpy(this->nombre,nombre);
    strcpy(this->tipo,tipo);
    this->generacion = generacion;
    this->shiny = shiny;
}

void Pokemon::mostrar(){
    cout << "Nombre: " << this->nombre << endl
    << "Tipo: " << this->tipo << endl
    << "Generacion: " << this->generacion << endl
    << "Es shiny: " << ((this->shiny)?"Si":"No") << endl;
}
