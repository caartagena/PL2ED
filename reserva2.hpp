#ifndef Reserva2_HPP
#define Reserva2_HPP
#include <iostream>
#include <string>
#include <random>
using namespace std;

class Reserva2
{
private:
    int numReserva;
    string nombreCliente;
    string situacion;
    int numPersonas;
    string hora;
    string preferenciaMenu;
    Reserva2 *siguiente;
    Reserva2 *anterior;

public:
    Reserva2();
    Reserva2(int numReserva, string nombreCliente, string situacion, int numPersonas, string hora, string preferenciaMenu);
    ~Reserva2();
    void mostrarDatos() const
    {
        cout << "numReserva: " << numReserva << endl;
        cout << "nombreCliente: " << nombreCliente << endl;
        cout << "situacion: " << situacion << endl;
        cout << "numPersonas: " << numPersonas << endl;
        cout << "hora: " << hora << endl;
        cout << "preferenciaMenu: " << preferenciaMenu << endl;
        cout << endl;
    }
    int getNumReserva();
    string getNombreCliente();
    string getSituacion();
    int getNumPersonas();
    string getHora();
    string getPreferenciaMenu();
    void setNumReserva(int);
    void setNombreCliente(string);
    void setSituacion(string);
    void setNumPersonas(int);
    void setHora(string);
    void setPreferenciaMenu(string);
};
int Reserva2::getNumReserva()
{
    return this->numReserva;
}
string Reserva2::getNombreCliente()
{
    return this->nombreCliente;
}
string Reserva2::getSituacion()
{
    return this->situacion;
}

int Reserva2::getNumPersonas()
{
    return this->numPersonas;
}

string Reserva2::getHora()
{
    return this->hora;
}

string Reserva2::getPreferenciaMenu()
{
    return this->preferenciaMenu;
}
void Reserva2::setNumReserva(int numReserva)
{
    this->numReserva = numReserva;
    cout << "numReserva: " << numReserva << endl;
}
void Reserva2::setNombreCliente(string nombreCliente)
{
    this->nombreCliente = nombreCliente;
    cout << "nombreCliente: " << nombreCliente << endl;
}
void Reserva2::setSituacion(string situacion)
{
    this->situacion = situacion;
    cout << "situacion: " << situacion << endl;
}
void Reserva2::setNumPersonas(int numPersonas)
{
    this->numPersonas = numPersonas;
    cout << "numPersonas: " << numPersonas << endl;
}
void Reserva2::setHora(string hora)
{
    this->hora = hora;
    cout << "hora: " << hora << endl;
}
void Reserva2::setPreferenciaMenu(string preferenciaMenu)
{
    this->preferenciaMenu = preferenciaMenu;
    cout << "preferenciaMenu: " << preferenciaMenu << endl;
}

#endif // Reserva2_HPP