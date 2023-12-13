#ifndef Mesas_HPP
#define Mesas_HPP
#include "pedidos.hpp"
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
    Pedido *ultimo;
    Pedido *primero;

public:
    Mesas();
    Mesas(int numMesa, int numPersonas, string situacion, bool ocupada, Pedido *ultimo, Pedido *primero);
    ~Mesas();
    void mostrarDatos() const
    {
        cout << "numMesa: " << numMesa << endl;
        cout << "numPersonas: " << numPersonas << endl;
        cout << "situacion: " << situacion << endl;
        cout << "ocupada: " << ocupada << endl;
        cout << endl;
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
Pedido *Mesas::getUltimo()
{
    return this->ultimo;
}
Pedido *Mesas::getPrimero()
{
    return this->primero;
}
void Mesas::setUltimo(Pedido *ultimo)
{
    this->ultimo = ultimo;
}
void Mesas::setPrimero(Pedido *primero)
{
    this->primero = primero;
}
void Mesas::setOcupada(bool ocupada)
{
    this->ocupada = ocupada;
}

#endif // Mesas_HPP