#ifndef LDE_HPP
#define LDE_HPP
#include "reserva2.hpp"
#include "pedidos.hpp"
#include <iostream>
using namespace std;

const int ASCENDENTE = 0;
const int DESCENDENTE = 1;

class NodoReserva
{
private:
    Reserva2 valor;
    NodoReserva *siguiente;
    NodoReserva *anterior;

    friend class Lista;

public:
    NodoReserva(Reserva2 v, NodoReserva *sig = NULL, NodoReserva *ant = NULL)
    {
        valor = v;
        siguiente = sig;
        anterior = ant;
    }
};
class NodoPedido
{
private:
    Pedido valor;
    NodoPedido *siguiente;
    NodoPedido *anterior;

    friend class Lista;

public:
    NodoPedido(Pedido p, NodoPedido *sig = NULL, NodoPedido *ant = NULL)
    {
        valor = p;
        siguiente = sig;
        anterior = ant;
    }
};
typedef NodoReserva *pnodo;
typedef NodoPedido *pnodo2;

class Lista
{
private:
    pnodo cabeza, fin, actual;
    pnodo2 cabeza2, fin2, actual2;

public:
    Lista() { cabeza = actual = fin = NULL; }
    Lista() { cabeza2 = actual2 = fin2 = NULL; };
    void insertarNodo(Reserva2 v, char c, Lista &lista);
    void insertarNodoPedido(Pedido p, char c, Lista &lista);
    void insertarNodoIntAntes(Reserva2 v, int posicion);
    void borrarNodo(Reserva2 v, char c, Lista &lista);
    void borrarNodoPedido(Pedido p, char c, Lista &lista);
    void borrarListaEntera(Lista &lista);
    void borrarNodoMenu(Lista &lista);
    bool listaVacia(Lista &lista);
    void mostrarLista(Lista &lista);
    void esSiguiente();
    void esAnterior();
    void esPrimero();
    void esUltimo();
    bool esActual();
};

#endif // LDE_HPP
