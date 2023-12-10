#include "LDE.hpp"
#include <iostream>
using namespace std;

void Lista::insertarNodo(Reserva2 v, char c, Lista &lista)
{
    pnodo nuevo;
    nuevo = new Nodo(v);
    char tipoInsercion;
    tipoInsercion = c;

    if (tipoInsercion == 'p')
    { // Inserción por el Principio
        if (lista.cabeza == NULL)
        {
            lista.cabeza = nuevo;
            lista.fin = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
        }
        else
        {
            nuevo->siguiente = lista.cabeza;
            lista.cabeza->anterior = nuevo;
            nuevo->anterior = NULL;
            lista.cabeza = nuevo;
        }
    }
    else if (tipoInsercion == 'f')
    { // Inserción por el Final
        if (lista.cabeza == NULL)
        {
            lista.cabeza = nuevo;
            lista.fin = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
        }
        else
        {
            lista.fin->siguiente = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = lista.fin;
            lista.fin = nuevo;
        }
    }
    else
    {
        cout << "Error en el tipo de inserción" << endl;
    }
}
void Lista::borrarNodo(Reserva2 v, char c, Lista &lista)
{
    char tipoBorrado;
    tipoBorrado = c;

    if (tipoBorrado == 'f')
    { // Eliminaci�n por el final
        pnodo aux = NULL;
        if (cabeza == fin)
        { // S�lo hay elemento
            aux = fin;
            cabeza = fin = NULL;
            aux = NULL;
            delete aux;
        }
        else
        {
            aux = fin;
            fin = fin->anterior;
            aux->anterior = NULL; // a�ado yo seg�n transparencias
            fin->siguiente = NULL;
            delete aux;
        }
    }
    else if (tipoBorrado == 'p')
    { // Eliminaci�n por el Principio
        pnodo aux = NULL;
        if (cabeza == fin)
        { // S�lo hay elemento
            aux = cabeza;
            cabeza = fin = NULL;
            aux = NULL;
            delete aux;
        }
        else
        {
            aux = cabeza;
            cabeza = cabeza->siguiente;
            aux->siguiente = NULL; // a�ado yo seg�n transparencias
            cabeza->anterior = NULL;
            delete aux;
        }
    }
    cout << "Nodo borrado" << endl;
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
