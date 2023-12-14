#include "LDE.hpp"

#include <iostream>
using namespace std;

void Lista::insertarNodo(Reserva2 v, Lista &lista)
{
    pnodo nuevo;
    nuevo = new NodoReserva(v);

    if (lista.cabeza == NULL)
    {
        lista.cabeza = nuevo;
        lista.fin = nuevo;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    else
    {
        pnodo actual = lista.cabeza;
        while (actual != NULL)
        {
            // Compara la reserva actual con la nueva reserva
            if (actual->valor.getHora() > nuevo->valor.getHora() ||
                (actual->valor.getHora() == nuevo->valor.getHora() && actual->valor.getSituacion() > nuevo->valor.getSituacion()) ||
                (actual->valor.getHora() == nuevo->valor.getHora() && actual->valor.getSituacion() == nuevo->valor.getSituacion() && actual->valor.getNumPersonas() > nuevo->valor.getNumPersonas()))
            {
                // Inserta el nuevo nodo antes del nodo actual
                nuevo->siguiente = actual;
                nuevo->anterior = actual->anterior;
                if (actual->anterior != NULL)
                {
                    actual->anterior->siguiente = nuevo;
                }
                else
                {
                    // Si el nodo actual es la cabeza de la lista, actualiza la cabeza
                    lista.cabeza = nuevo;
                }
                actual->anterior = nuevo;
                return;
            }
            actual = actual->siguiente;
        }
        // Si llegamos al final de la lista sin encontrar un lugar para insertar, inserta al final
        lista.fin->siguiente = nuevo;
        nuevo->anterior = lista.fin;
        lista.fin = nuevo;
        nuevo->siguiente = NULL;
    }
}

void Lista::borrarListaEntera(Lista &lista)
{
    pnodo aux;
    aux = lista.cabeza;
    while (aux != NULL)
    {
        lista.cabeza = lista.cabeza->siguiente;
        delete aux;
        aux = lista.cabeza;
    }
    lista.cabeza = NULL;
    lista.fin = NULL;
    cout << "Lista borrada" << endl;
}

void Lista::borrarNodoMenu(Lista &lista)
{
    string TipoMenu;
    cout << "Introduzca el tipo de menu que desea borrar: " << endl;
    cin >> TipoMenu;
    pnodo aux = lista.cabeza;
    while (aux != NULL)
    {
        if (aux->valor.getPreferenciaMenu() == TipoMenu)
        {
            pnodo nodoAEliminar = aux;
            if (aux == lista.cabeza)
            {
                lista.cabeza = lista.cabeza->siguiente;
                if (lista.cabeza != NULL)
                {
                    lista.cabeza->anterior = NULL;
                }
                aux = lista.cabeza;
            }
            else if (aux == lista.fin)
            {
                lista.fin = lista.fin->anterior;
                if (lista.fin != NULL)
                {
                    lista.fin->siguiente = NULL;
                }
                aux = NULL;
            }
            else
            {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
                aux = aux->siguiente;
            }
            delete nodoAEliminar;
            cout << "Nodo borrado" << endl;
        }
        else
        {
            aux = aux->siguiente;
        }
    }
}

void Lista::mostrarLista(Lista &lista)
{
    pnodo aux;
    aux = lista.cabeza;
    while (aux != NULL)
    {
        aux->valor.mostrarDatos();
        aux = aux->siguiente;
    }
}

bool Lista::listaVacia(Lista &lista)
{
    return lista.cabeza == NULL;
}

void Lista::esSiguiente()
{
    if (actual)
        actual = actual->siguiente;
}

void Lista::esAnterior()
{
    if (actual)
        actual = actual->anterior;
}

void Lista::esPrimero()
{
    actual = cabeza;
}

void Lista::esUltimo()
{
    actual = fin;
}

bool Lista::esActual()
{
    return actual != NULL;
}

Reserva2 Lista::buscarHora(int turno, Lista &lista)
{
    pnodo aux, prev = NULL;
    aux = lista.cabeza;
    while (aux != NULL)
    {
        if (aux->valor.getHora() == turno)
        {
            if (prev == NULL)
            {
                lista.cabeza = aux->siguiente;
            }
            else
            {
                prev->siguiente = aux->siguiente;
            }

            Reserva2 reservaAtendida = aux->valor;
            delete aux;
            return reservaAtendida;
        }
        prev = aux;
        aux = aux->siguiente;
    }
    return Reserva2();
}

int Lista::ContarHora(int hora, Lista &lista)
{
    pnodo aux;
    aux = lista.cabeza;
    int contador = 0;
    while (aux != NULL)
    {
        if (aux->valor.getHora() == hora)
        {
            contador++;
        }
        aux = aux->siguiente;
    }
    return contador;
}