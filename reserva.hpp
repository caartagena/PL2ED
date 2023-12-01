#ifndef RESERVA_HPP
#define RESERVA_HPP
#include <stdlib.h>
#include <iostream>
#include <random>
#include <string>
using namespace std;
/*• Número de reserva.
• Nombre del cliente.
• Situación deseada: Terraza o Interior.
• Número de personas: máximo 8 personas por mesa.
• Hora de la reserva: 13:00, 14:00 o 15:00.
• Preferencia de menú: vegano, sin Gluten, completo.
Estas reservas se deben de almacenar en una lista doblemente enlazada*/

int generarNumeroAleatorio(int min, int max)
{
    random_device rd;
    default_random_engine generador(rd());
    uniform_int_distribution<int> distribucion(min, max);
    return distribucion(generador);
}

//Clase Reserva
class Reserva{
    private:
        int numReserva;
        string nombreCliente;
        string situacion;
        int numPersonas;
        string hora;
        string preferenciaMenu;
        Reserva *siguiente;
        Reserva *anterior;
    public:
        Reserva();
        Reserva(int numReserva, string nombreCliente, string situacion, int numPersonas, string hora, string preferenciaMenu);
        ~Reserva();
        int getNumReserva();
        string getNombreCliente();
        string getSituacion();
        int getNumPersonas();
        string getHora();
        string getPreferenciaMenu();
        void getSiguiente();
        void getAnterior();
        Reserva generarReservaAle();
        void insertarReserva(int numReserva, string nombreCliente, string situacion, int numPersonas, string hora, string preferenciaMenu);
        Reserva mostrarReservas();
        void mostrarReservasInverso();
        void borrarReserva(int numReserva);
        void borrarReservaInicio();
        void borrarReservaFinal();
        void borrarReservaPosicion(int numReserva);
        bool listaVacia();
        void generarReserva();
        void mostrarReserva();
};




#endif // RESERVA_HPP