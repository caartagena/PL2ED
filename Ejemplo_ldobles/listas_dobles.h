#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED

#include <iostream>

const int ASCENDENTE=0;
const int DESCENDENTE=1;

class Nodo
{
    private:
        int valor;
        Nodo *siguiente;
        Nodo *anterior;
    friend class Lista;

    public:
        Nodo(int v, Nodo *sig = NULL, Nodo *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef Nodo *pnodo;

class Lista
{
    private:
        pnodo cabeza, fin, actual;

    public:
        Lista() {cabeza=actual=fin=NULL; }
        ~Lista();
        void insertarNodo(int v, char c);
        void insertarNodoIntAntes(int v, int posicion);
        void borrarNodo(int v,char c);
        bool listaVacia();
        void mostrarLista(int);
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        int valorActual();
};

#endif // LISTAS_DOBLES_H_INCLUDED
