#include "reserva2.hpp"
#include "LDEM.hpp"
#include <iostream>

using namespace std;

Reserva2::Reserva2(){}
Reserva2::Reserva2(int numReserva, string nombreCliente, string situacion, int numPersonas, string hora, string preferenciaMenu){
    numReserva=numReserva;
    nombreCliente=nombreCliente;
    situacion=situacion;
    numPersonas=numPersonas;
    hora=hora;
    preferenciaMenu=preferenciaMenu;
}
Reserva2::~Reserva2(){}
Reserva2 generarReservaAle(){
    Reserva2* reserva=new Reserva2();
    int numReserva=getNumReserva();
    string nombreCliente=getNombreCliente();
    string situacion=getSituacion();
    int numPersonas=getNumPersonas();
    string hora=getHora();
    string preferenciaMenu=getPreferenciaMenu();
    cout<<"Reserva generada: "<<endl;
    cout<<"Numero de reserva: "<<numReserva<<endl;
    cout<<"Nombre del cliente: "<<nombreCliente<<endl;
    cout<<"Situacion: "<<situacion<<endl;
    cout<<"Numero de personas: "<<numPersonas<<endl;
    cout<<"Hora: "<<hora<<endl;
    cout<<"Preferencia de menu: "<<preferenciaMenu<<endl;
    cout<<endl;
    return *reserva;
}

int main(){
    Lista lista;
    for (int i=0;i<10;i++)
    {
        Reserva2 reserva=generarReservaAle();
        lista.insertarNodo(reserva,'p');
    }
    
    return 0;
}