#ifndef NODOABB_H
#define NODOABB_H
#include "string.h"
#include <iostream>
#include "Mesa.h"

using namespace std;

class NodoABB
{
    public:
        NodoABB();
        NodoABB(Mesa nombre, int n_mesa, int capacidad, string localizacion, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();
        void toString();

    protected:

    private:
        friend class ABB;
        Mesa nombre;
        int n_mesa;
        char zona;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H

