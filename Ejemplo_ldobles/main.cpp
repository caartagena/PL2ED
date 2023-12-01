#include "listas_dobles.h"

#include <iostream>

using namespace std;



int main() {

    Lista lista;

    cout << "Insertamos nodo 20 al final" << endl;

    lista.insertarNodo(20,'f');
    lista.mostrarLista(0);

    cout << "Insertamos nodo 10 al final" << endl;

    lista.insertarNodo(10,'f');
    lista.mostrarLista(0);

    cout << "Insertamos nodo 40 al principio" << endl;

    lista.insertarNodo(40,'p');
    lista.mostrarLista(0);


    cout << "Insertamos nodo 30 al principio" << endl;

    lista.insertarNodo(30,'p');
    lista.mostrarLista(0);


    cout << endl;
    cout << "Mostrar lista hacia adelante" << endl;

    lista.mostrarLista(0);

    cout << endl;
    cout << "Mostrar lista hacia atras" << endl;
    lista.mostrarLista(1);

    cout << "Insertamos nodo 25 antes de 10" << endl;
    lista.insertarNodoIntAntes(25,10);
    lista.mostrarLista(0);


    cout << "Borramos nodo 10" << endl;

    lista.borrarNodo(10,'f');
    lista.mostrarLista(0);

    cout << "Borramos nodo 30" << endl;

    lista.borrarNodo(30,'p');
    lista.mostrarLista(0);


return 0;

}

