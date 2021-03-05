#ifndef MANEJADORDEARCHIVOS_H
#define MANEJADORDEARCHIVOS_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define NOMBRE_ARCHIVO "archivo.bin"
#define NOMBRE_ARCHIVO_TEMP "archivoTemp.bin"

#include "Pokemon.h"

class ManejadorDeArchivos{
    private:
    
    public:
        ManejadorDeArchivos();
        ~ManejadorDeArchivos();

        void mostrarTodo();
        void crear(Pokemon *pokemon);
        void buscar(char nombre[20]);
        void modificar(char nombre[20]);
        void eliminar(char nombre[20]);
};

ManejadorDeArchivos::ManejadorDeArchivos(){

}

ManejadorDeArchivos::~ManejadorDeArchivos(){

}

void ManejadorDeArchivos::crear(Pokemon *miPokemon){
    ofstream archivo(NOMBRE_ARCHIVO, ios::app|ios::binary);
    archivo.write((char *)miPokemon,sizeof(Pokemon));
    archivo.close();
}

void ManejadorDeArchivos::mostrarTodo(){
    Pokemon *miPokemon = new Pokemon();

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    } else {
        while(archivo.read((char *)miPokemon,sizeof(Pokemon))){
            cout << endl;
            miPokemon->mostrar();
            cout << endl;
        }
    }

    archivo.close();
}

void ManejadorDeArchivos::buscar(char nombre[20]){
    Pokemon *miPokemon = new Pokemon();
    bool encontrado = false;

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    } else {
        while(archivo.read((char *)miPokemon,sizeof(Pokemon))){
            if(strcmp(miPokemon->nombre,nombre)== 0){
                cout << endl;
                miPokemon->mostrar();
                cout << endl;
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << endl << "No se encontro el registro" << endl;
        }
    }

    archivo.close();
}

void ManejadorDeArchivos::modificar(char nombre[20]){
    char nombreTemp[20];
    char tipoTemp[20];
    char generacionTemp[20];
    char shinyTemp[20];


    Pokemon *miPokemon = new Pokemon();
    bool encontrado = false;

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);
    ofstream archivoTemp(NOMBRE_ARCHIVO_TEMP, ios::app|ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    } else {
        while (archivo.read((char *)miPokemon,sizeof(Pokemon))){
            if(strcmp(miPokemon->nombre,nombre) == 0){
                cout << "Presiona ENTER para omitir edicion del campo." << endl;

                cout << "Nombre(" << miPokemon->nombre << "): ";
                fflush(stdin);
                cin.getline(nombreTemp,20);
                if(strcmp(nombreTemp,"")) strcpy(miPokemon->nombre, nombreTemp);

                cout << "Tipo(" << miPokemon->tipo << "): ";
                fflush(stdin);
                cin.getline(tipoTemp,20);
                if(strcmp(tipoTemp,"")) strcpy(miPokemon->tipo, tipoTemp);

                cout << "Generacion(" << miPokemon->generacion << "): ";
                fflush(stdin);
                cin.getline(generacionTemp,20);
                if(strcmp(generacionTemp,"")) miPokemon->generacion = atoi(generacionTemp);

                cout << "Shiny(" << ((miPokemon->shiny)?"Si":"No") << ") 1-Si 2-No: ";
                fflush(stdin);
                cin.getline(shinyTemp,20);
                if(strcmp(generacionTemp, "")) miPokemon->shiny = atoi(generacionTemp) == 1;

                encontrado = true;
            }
            archivoTemp.write((char *)miPokemon,sizeof(Pokemon));
        }

        if(!encontrado) cout << endl << "No se encontro el registro" << endl;
    }

    archivo.close();
    archivoTemp.close();

    remove(NOMBRE_ARCHIVO);
    rename(NOMBRE_ARCHIVO_TEMP,NOMBRE_ARCHIVO);
}

void ManejadorDeArchivos::eliminar(char nombre[20]){
    Pokemon *miPokemon = new Pokemon();
    bool encontrado = false;

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);
    ofstream archivoTemp(NOMBRE_ARCHIVO_TEMP, ios::app|ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    } else {
        while (archivo.read((char *)miPokemon,sizeof(Pokemon))){
            if(strcmp(miPokemon->nombre,nombre) == 0){
                cout << "Registro eliminado"<< endl;
                encontrado = true;
            }else{
                archivoTemp.write((char *)miPokemon,sizeof(Pokemon));
            }
        }

        if(!encontrado) cout << endl << "No se encontro el registro" << endl;
    }

    archivo.close();
    archivoTemp.close();

    remove(NOMBRE_ARCHIVO);
    rename(NOMBRE_ARCHIVO_TEMP,NOMBRE_ARCHIVO);
}

#endif