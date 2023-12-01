#include "listas_dobles.h"

using namespace std;

Lista::~Lista()
{
    pnodo aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
        fin=NULL;
}

void Lista::insertarNodo(int v, char c)
{
    pnodo aux;
    char tipoInsercion;
    tipoInsercion=c;

    if(listaVacia()) { // Si la lista est� vac�a
        aux = new Nodo(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserci�n por el final
        aux= new Nodo(v,NULL,NULL);
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    else if (tipoInsercion=='p') {//Inserci�n por el principio
        aux= new Nodo(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}

void Lista::insertarNodoIntAntes(int v, int posicion)
{
    pnodo aux;

    if(listaVacia()) { // Si la lista est� vac�a
        aux = new Nodo(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else   //Inserci�n antes del nodo
    {   actual=cabeza;
        while(actual)
        {
            if (actual->valor != posicion) actual = actual->siguiente;
            else
            {
                aux= new Nodo(v,NULL,NULL);
                aux->siguiente=actual;
                aux->anterior=actual->anterior;
                actual->anterior->siguiente=aux;
                actual->anterior=aux;
                actual = actual->siguiente; //mueve actual para que salga del while.
           }
        }
    }

}

void Lista::borrarNodo(int v,char c)
{
    char tipoBorrado;
    tipoBorrado=c;

    if(tipoBorrado=='f') {//Eliminaci�n por el final
        pnodo aux=NULL;
        if((cabeza==fin)) { //S�lo hay elemento
            aux=fin;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=fin;
            fin=fin->anterior;
            aux->anterior=NULL;  //a�ado yo seg�n transparencias
            fin->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminaci�n por el Principio
        pnodo aux=NULL;
        if((cabeza==fin)) {//S�lo hay elemento
            aux=cabeza;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;  //a�ado yo seg�n transparencias
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}

void Lista::mostrarLista (int orden)
{
    pnodo aux;

    if (orden == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        while(aux) {
            cout << aux->valor << "-> "; aux = aux->siguiente;
        }
    }
    else {
        esUltimo();
        aux = fin;
        while(aux) {
            cout << aux->valor << "-> "; aux = aux->anterior;
        }
    }
    cout << endl;
}

bool Lista::listaVacia()
{
    return cabeza == NULL;
}

void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void Lista::esAnterior()
{
    if(actual) actual = actual->anterior;
}

void Lista::esPrimero()
{
    actual=cabeza;
}

void Lista::esUltimo()
{
    actual=fin;
}

bool Lista::esActual()
{
    return actual != NULL;
}

int Lista::valorActual()
{
    if (!listaVacia()) return actual->valor;
     else return 0;
}


