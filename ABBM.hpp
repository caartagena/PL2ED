#include "ABB.hpp"
#include "mesas.hpp"
#include <iostream>
#include <string>

using namespace std;

// Insertar en árbol ordenado por el numero de mesa:

void ArbolABB::insertarMesasOrdenadas(Mesas dat, ArbolABB &arbol)
{
    Nodo *padre = nullptr;
    actual = arbol.raiz;
    // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
    while (!Vacio(actual) && dat.getNumMesa() != actual->dato.getNumMesa())
    {
        padre = actual;
        if (dat.getNumMesa() > actual->dato.getNumMesa())
            actual = actual->derecho;
        else if (dat.getNumMesa() < actual->dato.getNumMesa())
            actual = actual->izquierdo;
    }
    // Si se ha encontrado el elemento, regresar sin insertar
    if (!Vacio(actual))
        return;
    // Si padre es nullptr, entonces el árbol estaba vacío, el nuevo nodo será
    // el nodo raiz
    if (Vacio(padre))
        arbol.raiz = new Nodo(dat);
    // Si el dato es menor que el que contiene el nodo padre, lo insertamos
    // en la rama izquierda
    else if (dat.getNumMesa() < padre->dato.getNumMesa())
        padre->izquierdo = new Nodo(dat);
    // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
    // en la rama derecha
    else if (dat.getNumMesa() > padre->dato.getNumMesa())
        padre->derecho = new Nodo(dat);
    // Si el dato es mayor que el que contiene el nodo padre, lo insertamos en
    // la derecha
    else
        padre->derecho = new Nodo(dat);
}
void ArbolABB::mostrarMesasInOrder(Nodo *r)
{
    if (r != nullptr)
    {
        mostrarMesasInOrder(r->izquierdo);
        cout << "Numero de mesa: " << r->dato.getNumMesa() << endl;
        cout << "Situacion: " << r->dato.getSituacion() << endl;
        cout << "Numero de personas: " << r->dato.getNumPersonas() << endl;
        cout << endl;
        mostrarMesasInOrder(r->derecho);
    }
}
// Elimina la mesa si se introduce un numero de mesa distinto de 0, si el numero de mesa es 0, se eliminara la mesa que tenga el numero de personas y la situacion introducida
void ArbolABB::eliminarMesaNR(int numMesa, int numPersonas, string situacion, ArbolABB &arbol)
{
    Nodo *padre = nullptr;
    actual = arbol.raiz;
    // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
    while (!Vacio(actual))
    {
        if (numMesa != 0)
        {
            if (numMesa != actual->dato.getNumMesa())
            {
                padre = actual;
                if (numMesa > actual->dato.getNumMesa())
                    actual = actual->derecho;
                else if (numMesa < actual->dato.getNumMesa())
                    actual = actual->izquierdo;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (numPersonas != actual->dato.getNumPersonas() && situacion != actual->dato.getSituacion())
            {
                padre = actual;
                if (numPersonas > actual->dato.getNumPersonas())
                {
                    actual = actual->derecho;
                }
                else if (numPersonas < actual->dato.getNumPersonas())
                {
                    actual = actual->izquierdo;
                }
            }
            else
            {
                break;
            }
        }
    }
    // Si se ha encontrado el elemento, proceder a eliminar
    if (!Vacio(actual))
    {
        // Caso 1: Nodo sin hijos
        if (actual->izquierdo == nullptr && actual->derecho == nullptr)
        {
            if (padre == nullptr)
            {
                arbol.raiz = nullptr;
            }
            else if (padre->izquierdo == actual)
            {
                padre->izquierdo = nullptr;
            }
            else
            {
                padre->derecho = nullptr;
            }
            delete actual;
        }
        // Caso 2: Nodo con un solo hijo
        else if (actual->izquierdo == nullptr || actual->derecho == nullptr)
        {
            Nodo *hijo = (actual->izquierdo != nullptr) ? actual->izquierdo : actual->derecho;
            if (padre == nullptr)
            {
                arbol.raiz = hijo;
            }
            else if (padre->izquierdo == actual)
            {
                padre->izquierdo = hijo;
            }
            else
            {
                padre->derecho = hijo;
            }
            delete actual;
        }
        // Caso 3: Nodo con dos hijos
        else
        {
            Nodo *aux = actual->derecho;
            Nodo *padreAux = actual;
            while (aux->izquierdo != nullptr)
            {
                padreAux = aux;
                aux = aux->izquierdo;
            }
            actual->dato = aux->dato;
            if (padreAux->izquierdo == aux)
            {
                padreAux->izquierdo = aux->derecho;
            }
            else
            {
                padreAux->derecho = aux->derecho;
            }
            delete aux;
        }
    }
    else
    {
        cout << "No se ha encontrado la mesa para eliminar." << endl;
    }
}