#ifndef ABB_HPP
#define ABB_HPP
#include "mesas.hpp"
#include "LDE.hpp"
#include "LE.hpp"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

class ArbolABB
{
private:
    //// Clase local de Lista para Nodo de ArbolBinario:
    class Nodo
    {
    public:
        // Constructor:
        Nodo(Mesas &dat, Nodo *izq = nullptr, Nodo *der = nullptr) : dato(dat), izquierdo(izq), derecho(der) {}
        // Miembros:
        Mesas dato;
        Nodo *izquierdo;
        Nodo *derecho;
    };

    // Punteros de la lista, para cabeza y nodo actual:
    Nodo *raiz;
    Nodo *actual;
    int contador;
    int altura;

public:
    // Constructor y destructor básicos:
    ArbolABB() : raiz(nullptr), actual(nullptr) {}
    // Insertar en árbol ordenado:
    void insertarMesasOrdenadas(Mesas dat, ArbolABB &arbol);
    void mostrarMesasInOrder(Nodo *r);
    void eliminarMesaNR(int numMesa, int numPersonas, string situacion, ArbolABB &arbol);
    bool Vacio(Nodo *r) { return r == nullptr; }
    Nodo *getRaiz() { return raiz; }
    void inicializarMesas(Nodo *nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }

        nodo->dato.setOcupada(false);

        inicializarMesas(nodo->izquierdo);
        inicializarMesas(nodo->derecho);
    }
    bool esMesaAdecuada(Reserva2 &reserva, Mesas &mesa)
    {
        if (mesa.getOcupada() == true)
        {
            return false;
        }

        if (reserva.getNumPersonas() > mesa.getNumMesa())
        {
            return false;
        }

        if (reserva.getSituacion() != mesa.getSituacion())
        {
            return false;
        }

        return true;
    }
    bool buscarMesaAdecuada(Nodo *nodo, Reserva2 &reserva, Pedido &pedido, Lista &lista);
    void buscarYMostrarMesa(Nodo *nodo, int numMesa)
    {
        if (nodo == nullptr)
        {
            cout << "No se encontró la mesa con el número " << numMesa << endl;
            return;
        }

        if (nodo->dato.getNumMesa() == numMesa)
        {
            cout << "Mesa numero: " << nodo->dato.getNumMesa() << endl;
            cout << "Capacidad de la mesa: " << nodo->dato.getNumPersonas() << endl;
            cout << "Situacion de la mesa: " << nodo->dato.getSituacion() << endl;
            cout << "Pedidos atendidos: " << endl;
            nodo->dato.mostrarPedidos();
            return;
        }

        if (nodo->dato.getNumMesa() < numMesa)
        {
            buscarYMostrarMesa(nodo->derecho, numMesa);
        }
        else
        {
            buscarYMostrarMesa(nodo->izquierdo, numMesa);
        }
    }
    void buscarYMostrarMesaSituacion(Nodo *nodo, const string &situacion)
    {
        if (nodo == nullptr)
        {
            return;
        }

        if (nodo->dato.getSituacion() == situacion)
        {
            cout << "Mesa numero: " << nodo->dato.getNumMesa() << endl;
            cout << "Capacidad de la mesa: " << nodo->dato.getNumPersonas() << endl;
            cout << "Situacion de la mesa: " << nodo->dato.getSituacion() << endl;
            cout << "Pedidos atendidos: " << endl;
            nodo->dato.mostrarPedidos();
        }

        buscarYMostrarMesaSituacion(nodo->derecho, situacion);
        buscarYMostrarMesaSituacion(nodo->izquierdo, situacion);
    }
    int cantidadDeNodos(Nodo *nodo)
    {
        if (nodo == nullptr)
        {
            return 0;
        }

        return 1 + cantidadDeNodos(nodo->derecho) + cantidadDeNodos(nodo->izquierdo);
    }

private:
    // Funciones auxiliares
    void
    auxContador(Nodo *nodo);
    void auxAltura(Nodo *nodo, int nivel);
};

#endif // ABB_H
