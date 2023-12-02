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
int contador=1;
Reserva2 generarReservaAle(){
    Reserva2 reserva;
    int numReserva=contador;
    string nombreCliente = reserva.getNombreCliente();
    string situacion = reserva.getSituacion();
    int numPersonas = reserva.getNumPersonas();
    string hora = reserva.getHora();
    string preferenciaMenu = reserva.getPreferenciaMenu();

    reserva.setNumReserva(contador);
    reserva.setNombreCliente(nombreCliente);
    reserva.setSituacion(situacion);
    reserva.setNumPersonas(numPersonas);
    reserva.setHora(hora);
    reserva.setPreferenciaMenu(preferenciaMenu);
    contador++;
    return reserva;
}


Lista lista;
int main(){
    for (int i=0;i<10;i++){
        Reserva2 reserva=generarReservaAle();
        lista.insertarNodo(reserva,'f',lista);
        cout<<endl;
    }
    cout<<endl<<"Comprobamos que se ha insertado correctamente: "<<endl;
    lista.mostrarLista(lista);
}