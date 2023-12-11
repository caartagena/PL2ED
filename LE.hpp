#ifndef LE_H
#define LE_H
#include "pedidos.hpp"
#include <iostream>
using namespace std;

class NodoLista
{
public:
    NodoLista(Pedido e, NodoLista *sig = NULL);

private:
    friend class LE;
    NodoLista *siguiente;
    Pedido elemento;
};

class LE
{
public:
    LE()
    {
        primero = NULL;
        ultimo = NULL;
        longitud = 0;
    };
    int get_longitud();
    void insertar_derecha(Pedido elemento);
    void insertar_izquierda(Pedido elemento);
    void insertar_enPosicion(int indice, Pedido elemento);
    bool es_vacia();
    Pedido ver_primero();
    Pedido ver_ultimo();
    Pedido ver_posicion(int indice);
    void borrar_izquierda();
    void borrar_posicion(int indice);
    void vaciar_lista();
    void mostrar(LE &lista);
    void insertarPorPrioridad(bool prioritario, Pedido elemento);

private:
    NodoLista *primero;
    NodoLista *ultimo;
    int longitud;
};

#endif // LE_H
