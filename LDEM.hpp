#include "LDE.hpp"
#include <iostream>
using namespace std;

Lista::~Lista()
{
    pnodo aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
        fin=NULL;
}

void Lista::insertarNodo(Reserva2 v, char c) 
{
    pnodo aux;
    char tipoInsercion;
    tipoInsercion=c;
    if(listaVacia()) { // Si la lista está vacía
        aux = new Nodo(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserción por el final
        aux= new Nodo(v,NULL,NULL);
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new Nodo(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}

void Lista::borrarNodo(Reserva2 v,char c)
{
    char tipoBorrado;
    tipoBorrado=c;

    if(tipoBorrado=='f') {//Eliminaci�n por el final
        pnodo aux=NULL;
        if(cabeza==fin) { //S�lo hay elemento
            aux=fin;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=fin;
            fin=fin->anterior;
            aux->anterior=NULL;  //a�ado yo seg�n transparencias
            fin->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminaci�n por el Principio
        pnodo aux=NULL;
        if(cabeza==fin) {//S�lo hay elemento
            aux=cabeza;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;  //a�ado yo seg�n transparencias
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}

void Lista::mostrarLista(){
    pnodo aux;
    aux=cabeza;
    while(aux!=NULL){
        aux->valor.mostrarDatos();
        aux=aux->siguiente;
    }
}

bool Lista::listaVacia()
{
    return cabeza == NULL;
}

void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void Lista::esAnterior()
{
    if(actual) actual = actual->anterior;
}

void Lista::esPrimero()
{
    actual=cabeza;
}

void Lista::esUltimo()
{
    actual=fin;
}

bool Lista::esActual()
{
    return actual != NULL;
}

Reserva2 Lista::valorActual() // Cambia 'int' a 'Reserva2'
{
    if (!listaVacia()) return actual->valor;
     else return Reserva2(); // Devuelve un objeto 'Reserva2' vacío
}