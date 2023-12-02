#include "reserva2.hpp"
#ifndef LDE_HPP
#define LDE_HPP
#include <iostream>
using namespace std;

const int ASCENDENTE=0;
const int DESCENDENTE=1;

class Nodo
{
    private:
        Reserva2 valor;
        Nodo *siguiente;
        Nodo *anterior;
    friend class Lista;

    public:
        Nodo(Reserva2 v, Nodo *sig = NULL, Nodo *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef Nodo *pnodo;

class Lista
{
    private:
        pnodo cabeza, fin, actual;

    public:
        Lista() {cabeza=actual=fin=NULL; }
        ~Lista();
        void insertarNodo(Reserva2 v, char c);
        void insertarNodoIntAntes(Reserva2 v, int posicion);
        void borrarNodo(Reserva2 v,char c);
        bool listaVacia();
        void mostrarLista();
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        Reserva2 valorActual();
};




#endif // LDE_HPP

