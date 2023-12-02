#ifndef Reserva2_HPP
#define Reserva2_HPP
#include <iostream>
#include <string>
#include <random>
using namespace std;


int generarNumeroAleatorio(int min, int max)
{
    random_device rd;
    default_random_engine generador(rd());
    uniform_int_distribution<int> distribucion(min, max);
    return distribucion(generador);
}


class Reserva2{
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
        void mostrarDatos() const {
        // Imprime todas las variables de la clase aquí. Por ejemplo:
        cout << "numReserva: " << numReserva << endl;
        cout << "nombreCliente: " << nombreCliente << endl;
        cout << "situacion: " << situacion << endl;
        cout << "numPersonas: " << numPersonas << endl;
        cout << "hora: " << hora << endl;
        cout << "preferenciaMenu: " << preferenciaMenu << endl;
    }
};

int contador=1;

int getNumReserva(){
    int numReserva=contador;
    contador++;
    return numReserva;
}

string getNombreCliente(){
    string vnombres[30]={"Juan","Eva","Ana","Alicia","Laura","Pedro","Marcos","Mariano","Javier","Jorge","Sergio","Sara","Sandra","Sonia"
    ,"Sofia","Santiago","Samuel","Raul","Ramon","Rafael","Pablo","Oscar","Omar","Nuria","Natalia","Miguel","Manuel","Luis","Lucia","Lorena"};
    string nombreCliente=vnombres[generarNumeroAleatorio(0,29)];
    return nombreCliente;
}
string getSituacion(){
    string vsituacion[2]={"Terraza","Interior"};
    string situacion=vsituacion[generarNumeroAleatorio(0,1)];
    return situacion;
}

int getNumPersonas(){
    int numPersonas=generarNumeroAleatorio(1,8);
    return numPersonas;
}

string getHora(){
    string vhora[3]={"13:00","14:00","15:00"};
    string hora=vhora[generarNumeroAleatorio(0,2)];
    return hora;
}

string getPreferenciaMenu(){
    string vpreferenciaMenu[3]={"Vegano","Sin Gluten","Completo"};
    string preferenciaMenu=vpreferenciaMenu[generarNumeroAleatorio(0,2)];
    return preferenciaMenu;
}
  

#endif // Reserva2_HPP