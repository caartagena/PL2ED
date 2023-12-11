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
    NodoABB(Mesas valor, NodoABB *izq = NULL, NodoABB *der = NULL);
    virtual ~NodoABB();
    void toString();

protected:
private:
    friend class ABB;
    Mesas valor;
    NodoABB *hi, *hd;
};

class ABB
{
public:
    ABB();
    ABB(NodoABB *r);
    ABB(Mesas valor, NodoABB *hIz = NULL, NodoABB *hDer = NULL);
    virtual ~ABB();
    void insertar(Mesas mesa, ABB &arbol);
    void verInOrden();
    void verInOrden_nMesa(NodoABB *nodo, int n_mesa);
    void verInOrden_nMesa(int n_mesa);
    void insertarMesas(Mesas mesa, ABB &arbol);
private:
    NodoABB *raiz;
};

#endif // ABB_H
