#ifndef ABB_HPP
#define ABB_HPP
#include "mesas.hpp"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
class NodoABB
{
public:
    NodoABB();
    NodoABB(Mesas valor, NodoABB *izq = NULL, NodoABB *der = NULL);
    void toString();

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
    void verInOrden_nMesa(NodoABB *nodo, int n_mesa);
    void insertarMesasOrdenadas(Mesas mesa, ABB &arbol);

private:
    NodoABB *raiz;
};

#endif // ABB_H
