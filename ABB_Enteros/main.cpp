#include <iostream>
#include "ABB_Enteros.h"

using namespace std;

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}

int main()
{
   // Un árbol de enteros
   ArbolABB ArbolInt;

   // Inserción de nodos en árbol:
   cout << "\nInserto el 10, y queda asi:\n";
   ArbolInt.Insertar(10);
   cout << "\tAltura de arbol " << ArbolInt.AlturaArbol() << endl;
   cout << "\tInOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "\tPreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "\tPostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(10);
   cout << "\nBorro el 10 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cout << "\nInserto el 10, 5 y 4, y queda asi:\n";
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(5);
   ArbolInt.Insertar(4);
   cout << "\tAltura de arbol " << ArbolInt.AlturaArbol() << endl;
   cout << "\tInOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "\tPreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "\tPostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(4);
   cout << "\nBorro el 4 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cout << "\nInserto el 3 y el 1, y queda asi:\n";
   ArbolInt.Insertar(3);
   ArbolInt.Insertar(1);
   cout << "\tAltura de arbol " << ArbolInt.AlturaArbol() << endl;
   cout << "\tInOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "\tPreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "\tPostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(10);
   cout << "\nBorro el 10 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(3);
   cout << "\nBorro el 3 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(1);
   cout << "\nBorro el 1 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cout << "\nInserto el 10, y el 15 y queda asi:\n";
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(15);
   cout << "\tAltura de arbol " << ArbolInt.AlturaArbol() << endl;
   cout << "\tInOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "\tPreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "\tPostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(15);
   cout << "\nBorro el 15 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cout << "\nInserto el 10, 15 y 20 y queda asi:\n";
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(15);
   ArbolInt.Insertar(20);
   cout << "\tAltura de arbol " << ArbolInt.AlturaArbol() << endl;
   cout << "\tInOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "\tPreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "\tPostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(5);
   cout << "\nBorro el 5 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(15);
   cout << "\nBorro el 15 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cout << "\nInserto el 15, 25, 6, 8 y 4 y queda asi:\n";
   ArbolInt.Insertar(15);
   ArbolInt.Insertar(25);
   ArbolInt.Insertar(6);
   ArbolInt.Insertar(8);
   ArbolInt.Insertar(4);
   cout << "\tAltura de arbol " << ArbolInt.AlturaArbol() << endl;
   cout << "\tInOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "\tPreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "\tPostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(6);
   cout << "\nBorro el 6 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(10);
   cout << "\nBorro el 10 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(245);
   cout << "\nBorro el 245 y queda asi: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 20 " << ArbolInt.Altura(20) << endl;
   cout << "Altura de 8 " << ArbolInt.Altura(8) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   cin.get();
   return 0;
}
