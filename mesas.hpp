#ifndef Mesas_HPP
#define Mesas_HPP
#include "pedidos.hpp"
#include "LE.hpp"
#include <iostream>
#include <string>
using namespace std;

class Mesas
{
private:
    int numMesa;
    int numPersonas;
    string situacion;
    bool ocupada;
    LE pedidosServidos;

public:
    Mesas();
    Mesas(int numMesa, int numPersonas, string situacion, bool ocupada, Pedido *primero, Pedido *ultimo, LE pedidosServidos);
    ~Mesas();
    void mostrarDatos() const
    {
        cout << "numMesa: " << numMesa << endl;
        cout << "numPersonas: " << numPersonas << endl;
        cout << "situacion: " << situacion << endl;
        cout << "ocupada: " << ocupada << endl;
        cout << "Pedidos servidos: " << endl;
        cout << endl;
    }
    void insertarPedido(Pedido pedido, LE &pedidosServidos)
    {
        pedidosServidos.insertar_derecha(pedido, pedidosServidos);
        cout << "Pedido insertado" << endl;
        cout << "Numero de pedido: " << pedido.getNumPedido() << endl;
        cout << "Nombre de Cliente: " << pedido.getNombreCliente() << endl;
        cout << "Numero de personas: " << pedido.getNumPersonas() << endl;
        cout << "Hora: " << pedido.getHora() << endl;
        cout << "Preferencia de menu: " << pedido.getPreferenciaMenu() << endl;
        cout << endl;
    }
    void mostrarPedidos()
    {
        pedidosServidos.mostrar(pedidosServidos);
    }
    int getNumMesa();
    int getNumPersonas();
    string getSituacion();
    Pedido *getUltimo();
    Pedido *getPrimero();
    bool getOcupada();
    void setNumMesa(int);
    void setNumPersonas(int);
    void setSituacion(string);
    void setUltimo(Pedido *);
    void setPrimero(Pedido *);
    void setOcupada(bool);
    LE &getPedidosServidos();
};

int Mesas::getNumMesa()
{
    return this->numMesa;
}
int Mesas::getNumPersonas()
{
    return this->numPersonas;
}
string Mesas::getSituacion()
{
    return this->situacion;
}
bool Mesas::getOcupada()
{
    return this->ocupada;
}
void Mesas::setNumMesa(int numMesa)
{
    this->numMesa = numMesa;
}
void Mesas::setNumPersonas(int numPersonas)
{
    this->numPersonas = numPersonas;
}
void Mesas::setSituacion(string situacion)
{
    this->situacion = situacion;
}
void Mesas::setOcupada(bool ocupada)
{
    this->ocupada = ocupada;
}

LE &Mesas::getPedidosServidos()
{
    return this->pedidosServidos;
}
#endif // Mesas_HPP