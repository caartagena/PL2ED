#include "ABB.hpp"
#include "Mesas.hpp"
#include <iostream>
#include <string>

using namespace std;

ABB::ABB()
{
    raiz = NULL;
    // ctor
}

ABB::ABB(NodoABB *r)
{
    raiz = r;
}

ABB::~ABB()
{
    // dtor
}



void ABB::verInOrden_nMesa(NodoABB *arb, int n_mesa) // Ver ABB en inorden
{
    if (arb)
    {
        verInOrden_nMesa(arb->hi, n_mesa); // Recursion para la rama izquierda
        if (n_mesa == arb->valor.getNumMesa())
        {
            arb->toString(); // Mostrar nombre
        }
        verInOrden_nMesa(arb->hd, n_mesa); // Recursion para la rama derecha
    }
}


void ABB::insertar(Mesas mesa, ABB &arbol)
{
    NodoABB *nuevo;
    nuevo = new NodoABB(mesa);
    if (arbol.raiz == NULL)
    {
        arbol.raiz = nuevo;
    }
    else
    {
        NodoABB *aux = arbol.raiz;
        NodoABB *padre;
        while (aux != NULL)
        {
            padre = aux;
            if (nuevo->valor.getNumMesa() > aux->valor.getNumMesa())
            {
                aux = aux->hd;
            }
            else
            {
                aux = aux->hi;
            }
        }
        if (nuevo->valor.getNumMesa() < padre->valor.getNumMesa())
        {
            padre->hi = nuevo;
        }
        else
        {
            padre->hd = nuevo;
        }
    }
}
