#include "ABB.hpp"
#include <iostream>
#include <string>
#include "NodoABB.h"
#include "Mesa.h"

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

// constructor que crea �rbolBin con mesas y dos sub�rboles
ABB::ABB(Mesa nombre, int n_mesa, int capacidad, string localizacion, NodoABB *hIz, NodoABB *hDer)
{
    raiz = new NodoABB(nombre, n_mesa, capacidad, localizacion, hIz, hDer);
}

ABB::~ABB()
{
    // dtor
}

void ABB::verInOrden()
{
    verInOrden(raiz);
}
void ABB::verInOrden(NodoABB *arb) // Ver ABB en inorden
{
    if (arb)
    {
        verInOrden(arb->hi); // Recursion para la rama izquierda
        arb->toString();     // Mostrar nombre
        verInOrden(arb->hd); // Recursion para la rama derecha
    }
}

void ABB::verInOrden_nMesa(NodoABB *arb, int n_mesa) // Ver ABB en inorden
{
    if (arb)
    {
        verInOrden_nMesa(arb->hi, n_mesa); // Recursion para la rama izquierda
        if (n_mesa == arb->nombre.getN_mesa())
        {
            arb->toString(); // Mostrar nombre
        }
        verInOrden_nMesa(arb->hd, n_mesa); // Recursion para la rama derecha
    }
}

void ABB::verInOrden_nMesa(int n_mesa)
{
    verInOrden_nMesa(raiz, n_mesa);
}

void ABB::insertar(Mesa mesa) // En este m�todo insertamos un n_mesa en el ABB en orden
{
    int mesa1 = nombre.getN_mesa();
    int mesa2 = nodo->nombre.getN_mesa();
    if ((mesa2 > mesa1) || (mesa2 == mesa1)) // Si la mesa es menor o igual al del nodo ra�z
    {
        if (nodo->hi == NULL) // Si nodo izquierdo vacio:
        {
            NodoABB *nuevo = new NodoABB(n_mesa, capacidad, localizacion); // creo un NodoABB para insertarlo en el ABB
            nodo->hi = nuevo;
        }
        else // nodo no vacio
        {
            insertar(n_mesa, capacidad, localizacion, nodo->hi); // insertamos en nodo izquierdo
        }
    }
    else // Si el nombre es > que el nodo
    {
        if (nodo->hd == NULL) // Comprobamos si el derecho existe o no
        {
            NodoABB *nuevo = new NodoABB(n_mesa, capacidad, localizacion); // Creamos un nuevo nodo x derecha
            nodo->hd = nuevo;
        }
        else // si existe
        {
            insertar(n_mesa, capacidad, localizacion, nodo->hd); // insertamos al nodo derecho
        }
    }
}
