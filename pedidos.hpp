#ifndef PEDIDOS_HPP
#define PEDIDOS_HPP

#include <iostream>
#include <string>

using namespace std;

class Pedido
{
private:
    int numPedido;
    string nombreCliente;
    string situacion;
    int numPersonas;
    string hora;
    string preferenciaMenu;
    int numMesa;

public:
    Pedido();
    Pedido(int numPedido, string nombreCliente, string situacion, int numPersonas, string hora, string preferenciaMenu, int numMesa);
    ~Pedido();
    void mostrarDatos() const
    {
        cout << "numPedido: " << numPedido << endl;
        cout << "nombreCliente: " << nombreCliente << endl;
        cout << "situacion: " << situacion << endl;
        cout << "numPersonas: " << numPersonas << endl;
        cout << "hora: " << hora << endl;
        cout << "preferenciaMenu: " << preferenciaMenu << endl;
        cout << "numMesa: " << numMesa << endl;
        cout << endl;
    }
    int getNumPedido();
    string getNombreCliente();
    string getSituacion();
    int getNumPersonas();
    string getHora();
    string getPreferenciaMenu();
    int getNumMesa();
    void setNumPedido(int);
    void setNombreCliente(string);
    void setSituacion(string);
    void setNumPersonas(int);
    void setHora(string);
    void setPreferenciaMenu(string);
    void setNumMesa(int);
};
// GETTERS Y SETTERS
int Pedido::getNumPedido()
{
    return this->numPedido;
}
string Pedido::getNombreCliente()
{
    return this->nombreCliente;
}
string Pedido::getSituacion()
{
    return this->situacion;
}
int Pedido::getNumPersonas()
{
    return this->numPersonas;
}
string Pedido::getHora()
{
    return this->hora;
}
string Pedido::getPreferenciaMenu()
{
    return this->preferenciaMenu;
}
int Pedido::getNumMesa()
{
    return this->numMesa;
}
void Pedido::setNumPedido(int numPedido)
{
    this->numPedido = numPedido;
}
void Pedido::setNombreCliente(string nombreCliente)
{
    this->nombreCliente = nombreCliente;
}
void Pedido::setSituacion(string situacion)
{
    this->situacion = situacion;
}
void Pedido::setNumPersonas(int numPersonas)
{
    this->numPersonas = numPersonas;
}
void Pedido::setHora(string hora)
{
    this->hora = hora;
}
void Pedido::setPreferenciaMenu(string preferenciaMenu)
{
    this->preferenciaMenu = preferenciaMenu;
}
void Pedido::setNumMesa(int numMesa)
{
    this->numMesa = numMesa;
}

#endif // PEDIDOS_HPP