#ifndef NODOLDE_H
#define NODOLDE_H
#include "Reserva2.h"
#include <iostream>
#include "LDE.h"

using namespace std;

class NodoLDE
{
    public:
        NodoLDE(Reserva2 v, Nodo *sig = NULL, Nodo *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
        virtual ~NodoLDE();

    protected:

    private:
        Reserva2 valor;
        Nodo *siguiente;
        Nodo *anterior;

    friend class LDE;
};
typedef Nodo *pnodo;



#endif // NODOLDE_H
