#ifndef ABB_HPP
#define ABB_HPP
#include "mesas.hpp"
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

private:
    // Funciones auxiliares
    void auxContador(Nodo *nodo);
    void auxAltura(Nodo *nodo, int nivel);
};

#endif // ABB_H
