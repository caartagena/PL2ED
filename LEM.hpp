#include <iostream>
#include "LE.hpp"
#include "pedidos.hpp"
using namespace std;

LE::~LE()
{
	// dtor
}

int LE::get_longitud()
{
	return longitud;
}

void LE::insertar_izquierda(Pedido elemento)
{
	NodoLista *nuevo_nodo = new NodoLista(elemento);

	if (es_vacia())
	{
		primero = nuevo_nodo;
		ultimo = nuevo_nodo;
		longitud++;
	}
	else
	{
		nuevo_nodo->siguiente = primero;
		primero = nuevo_nodo;
		longitud++;
	}
}

void LE::insertar_enPosicion(int posicion, Pedido elemento)
{
}

Pedido LE::ver_primero()
{
	if (!es_vacia())
	{
		return primero->elemento;
	}
}

Pedido LE::ver_ultimo()
{
	if (!es_vacia())
	{
		return ultimo->elemento;
	}
}

Pedido LE::ver_posicion(int posicion)
{
	if (!es_vacia())
	{
		NodoLista *aux = primero;

		for (int i = 1; i < posicion; i++)
		{
			aux = aux->siguiente;
		}

		return aux->elemento;
	}
}

bool LE::es_vacia()
{
	return ((primero == NULL) && (ultimo == NULL));
}

void LE::borrar_izquierda()
{
	if (!es_vacia())
	{
		NodoLista *aux = primero;

		if (longitud == 1)
		{
			primero = NULL;
			ultimo = NULL;
		}
		else
		{
			primero = primero->siguiente;
			aux->siguiente = NULL;
		}
		delete aux;
		longitud--;
	}
}

void LE::borrar_posicion(int posicion)
{
	if (es_vacia())
	{
		cout << "No existe la posicion" << endl;
	}
	else
	{

		if (posicion == 0)
		{
			borrar_izquierda();
		}

		else
		{
			NodoLista *aux = primero;

			for (int i = 1; i < posicion - 1; i++)
			{
				aux = aux->siguiente;
			}
			NodoLista *borrar = aux->siguiente;
			if (borrar->siguiente == NULL)
			{
				ultimo = aux;
			}

			aux->siguiente = borrar->siguiente;

			borrar->siguiente = NULL;

			delete borrar;
			longitud--;
		}
	}
}

void LE::vaciar_lista()
{
	if (!es_vacia())
	{
		borrar_izquierda();
		return vaciar_lista();
	}
	else
	{
		cout << "Lista vaciada." << endl;
	}
}

void LE::insertarPorPrioridad(bool prioritario, Pedido elemento)
{
}
