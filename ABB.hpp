#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <string>
#include "mesas.hpp"
#include <iostream>
using namespace std;
class NodoABB
{
public:
    NodoABB();
    NodoABB(Mesa valor, int n_mesa, int capacidad, string localizacion, NodoABB *izq = NULL, NodoABB *der = NULL);
    virtual ~NodoABB();
    void toString();

protected:
private:
    friend class ABB;
    Mesa valor;
    int n_mesa;
    int capacidad;
    string localizacion;
    NodoABB *hi, *hd;
};

class ABB
{
public:
    ABB();
    ABB(NodoABB *r);
    ABB(Mesa valor, int n_mesa, int capacidad, string localizacion, NodoABB *hIz = NULL, NodoABB *hDer = NULL);
    virtual ~ABB();
    void insertar(Mesa mesa);
    void verInOrden();
    void verInOrden_nMesa(NodoABB *nodo, int n_mesa);
    void verInOrden_nMesa(int n_mesa);
    void insertar(Mesa nombre, int n_mesa, int capacidad, string localizacion);
    void verInOrden_Mesa(int n_mesa);

protected:
private:
    NodoABB *raiz;
    void verInOrden(NodoABB *arb);
    void verInOrden_Mesa(int n_mesa);
    void insertar(Mesa nombre, int n_mesa, int capacidad, string localizacion);
};

#endif // ABB_H
