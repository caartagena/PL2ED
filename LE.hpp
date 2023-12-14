#ifndef LE_H
#define LE_H
#include "pedidos.hpp"
#include <iostream>
using namespace std;

class NodoLista
{
public:
    NodoLista(Pedido e, NodoLista *sig = NULL)
    {
        this->elemento = e;
        this->siguiente = sig;
    };

private:
    friend class LE;
    NodoLista *siguiente;
    Pedido elemento;
};

class LE
{
public:
    LE() : primero(nullptr), ultimo(nullptr), longitud(0) {}
    int get_longitud();
    void insertar_derecha(Pedido elemento, LE &pedidosServidos)
    {
        NodoLista *nuevo_nodo = new NodoLista(elemento);

        if (pedidosServidos.es_vacia())
        {
            pedidosServidos.primero = nuevo_nodo;
            pedidosServidos.ultimo = nuevo_nodo;
            pedidosServidos.longitud++;
        }
        else
        {
            pedidosServidos.ultimo->siguiente = nuevo_nodo;
            pedidosServidos.ultimo = nuevo_nodo;
            pedidosServidos.longitud++;
        }
    };
    void insertar_izquierda(Pedido elemento);
    void insertar_enPosicion(int indice, Pedido elemento);
    bool es_vacia()
    {
        return ((primero == NULL) && (ultimo == NULL));
    }
    void mostrarPedidos()
    {
        NodoLista *nodoActual = this->primero;
        {
            cout << "Pedido: " << nodoActual->elemento.getNumPedido() << endl;
            cout << "Nombre del cliente: " << nodoActual->elemento.getNombreCliente() << endl;
            cout << "Situacion: " << nodoActual->elemento.getSituacion() << endl;
            cout << "Numero de personas: " << nodoActual->elemento.getNumPersonas() << endl;
            cout << "Hora: " << nodoActual->elemento.getHora() << endl;
            cout << "Preferencia de menu: " << nodoActual->elemento.getPreferenciaMenu() << endl;
            nodoActual = nodoActual->siguiente;
        }
    }
    Pedido ver_primero();
    Pedido ver_ultimo();
    Pedido ver_posicion(int indice);
    void borrar_izquierda();
    void borrar_posicion(int indice);
    void vaciar_lista();
    void mostrar(LE &lista)
    {
        NodoLista *aux = lista.primero;
        while (aux != NULL)
        {
            cout << endl;
            cout << "Numero de pedido: " << aux->elemento.getNumPedido() << endl;
            cout << "Nombre del cliente: " << aux->elemento.getNombreCliente() << endl;
            cout << "Situacion: " << aux->elemento.getSituacion() << endl;
            cout << "Numero de personas: " << aux->elemento.getNumPersonas() << endl;
            cout << "Hora: " << aux->elemento.getHora() << endl;
            cout << "Preferencia de menu: " << aux->elemento.getPreferenciaMenu() << endl;
            cout << endl;
            aux = aux->siguiente;
        }
    }
    void insertarPorPrioridad(bool prioritario, Pedido elemento);

private:
    NodoLista *primero;
    NodoLista *ultimo;
    int longitud;
};

#endif // LE_H
