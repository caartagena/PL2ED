#include "Mesa.h"
#include <iostream>
#include <string>
#include <time.h>

Mesa::Mesa()
{
    //ctor
}

Mesa::Mesa(int N_mesa, int Capacidad, string Localizacion)
{
    this -> N_mesa = N_mesa;
    this -> Capacidad = capacidad;
    this -> Localizacion = localizacion;
    //ctor
}



Mesa::~Mesa()
{
    //dtor
}

void Mesa::setN_mesa(int N_mesa){
    N_mesa= N_mesa;
}

void Mesa::setCapacidad(int Capacidad){
    Capacidad = Capacidad;
}

void Mesa::setLocalizacion(string Localizacion){
    Localizacion = Localizacion;
}


int Mesa::getN_mesa(){
    return N_mesa;
}

int Mesa::getCapacidad(){
    return Capacidad;
}

string Mesa::getLocalizacion(){
    return Localizacion;
}



void Mesa::toString(){
    cout << "Mesa { Numero de mesa: " << N_mesa << ", Capacidad: " << Capacidad<< ", Localización: " << Localizacion << "}" << endl;
}
