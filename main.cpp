#include <stdio.h>
#include <iostream>

using namespace std;

#include "ManejadorDeArchivos.h"

void crear(ManejadorDeArchivos *manejador);
void buscar(ManejadorDeArchivos *manejador);
void modificar(ManejadorDeArchivos *manejador);
void eliminar(ManejadorDeArchivos *manejador);

int main(){

    enum{
        OPC_EXIT,
        OPC_MOSTRAR,
        OPC_AGREGAR,
        OPC_BUSCAR,
        OPC_MODIFICAR,
        OPC_ELIMINAR
    };

    ManejadorDeArchivos *manejador = new ManejadorDeArchivos();
    int opc;

    do{

        cout << "****Menu***" << endl << endl
        <<OPC_MOSTRAR <<") Ver pokemon"<< endl
        <<OPC_AGREGAR <<") Agregar pokemon"<< endl
        <<OPC_BUSCAR <<") Buscar pokemon"<< endl
        <<OPC_MODIFICAR <<") Modificar pokemon"<< endl
        <<OPC_ELIMINAR <<") Eliminar pokemon"<< endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc){
            case OPC_MOSTRAR:
                manejador->mostrarTodo();
                break;
            case OPC_AGREGAR:
                crear(manejador);
                break;
            case OPC_BUSCAR:
                buscar(manejador);
                break;
            case OPC_MODIFICAR:
                modificar(manejador);
                break;
            case OPC_ELIMINAR:
                eliminar(manejador);
                break;
        }

        system("pause");
        system("cls");
    }while(opc != OPC_EXIT);
    return 1;
}

void crear(ManejadorDeArchivos *manejador){
    char nombre[20];
    char tipo[20];
    int generacion;
    int eleccionShiny;
    bool shiny;

    cout << "Nombre: ";
    cin.getline(nombre,20);
    fflush(stdin);
    cout << "Tipo: ";
    cin.getline(tipo,20);
    fflush(stdin);
    cout << "Generacion: ";
    cin >> generacion;
    cin.ignore();
    cout << "Es shiny? 1-Si 2-No: ";
    cin >> eleccionShiny;
    shiny = eleccionShiny == 1;

    Pokemon *miPokemon = new Pokemon(nombre,tipo,generacion,shiny);

    manejador->crear(miPokemon);
}

void buscar(ManejadorDeArchivos *manejador){
    char nombre[20];

    cout << "Ingrese el pokemon a encontrar: ";
    cin.getline(nombre,30);
    fflush(stdin);

    manejador->buscar(nombre);
}


void modificar(ManejadorDeArchivos *manejador){
    char nombre[20];

    cout << "Ingrese el pokemon a modificar: ";
    cin.getline(nombre,30);
    fflush(stdin);

    manejador->modificar(nombre);
}

void eliminar(ManejadorDeArchivos *manejador){
    char nombre[20];

    cout << "Ingrese el pokemon a eliminar: ";
    cin.getline(nombre,30);
    fflush(stdin);

    manejador->eliminar(nombre);
}



