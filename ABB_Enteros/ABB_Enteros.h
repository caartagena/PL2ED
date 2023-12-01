#ifndef ABB_ENTEROS_H_INCLUDED
#define ABB_ENTEROS_H_INCLUDED
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
    Nodo(const int dat, Nodo *izq = NULL, Nodo *der = NULL) : dato(dat), izquierdo(izq), derecho(der) {}
    // Miembros:
    int dato;
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
  ArbolABB() : raiz(NULL), actual(NULL) {}
  ~ArbolABB() { Podar(raiz); }
  // Insertar en árbol ordenado:
  void Insertar(const int dat);
  // Borrar un elemento del árbol:
  void Borrar(const int dat);
  // Función de búsqueda:
  bool Buscar(const int dat);
  // Comprobar si el árbol está vacío:
  bool Vacio(Nodo *r) { return r == NULL; }
  // Comprobar si es un nodo hoja:
  bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
  // Contar número de nodos:
  const int NumeroNodos();
  const int AlturaArbol();
  // Calcular altura de un int:
  int Altura(const int dat);
  // Devolver referencia al int del nodo actual:
  int &ValorActual() { return actual->dato; }
  // Moverse al nodo raiz:
  void Raiz() { actual = raiz; }
  // Aplicar una función a cada elemento del árbol:
  void InOrden(void (*func)(int &), Nodo *nodo = NULL, bool r = true);
  void PreOrden(void (*func)(int &), Nodo *nodo = NULL, bool r = true);
  void PostOrden(void (*func)(int &), Nodo *nodo = NULL, bool r = true);

private:
  // Funciones auxiliares
  void Podar(Nodo *&);
  void auxContador(Nodo *);
  void auxAltura(Nodo *, int);
};

#endif // ABB_ENTEROS_H_INCLUDED
