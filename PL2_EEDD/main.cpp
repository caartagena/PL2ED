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

LDE lde;
int main(){
    for (int i=0;i<10;i++){
        Reserva2 reserva=generarReservaAle();
        LDE.insertarNodo(reserva,'f',LDE);
        cout<<endl;
    }
    cout<<endl<<"Comprobamos que se ha insertado correctamente: "<<endl;
    LDE.mostrarLista(LDE);

    int entrada = -1;
    while (entrada != 0)
    {
        cout << "|--------------------------------------------------------------Restaurante cpp------------------------------------------------------------------------------------------------|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "|1. Mostrar el contenido del árbol de mesas con recorrido Inorden, mostrando de cada mesa: número, situación y número de pedidos atendidos hasta el momento.                  |" << endl;
        cout << "|2. Borrar una mesa concreta que indique el usuario.                                                                                                                          |" << endl;
        cout << "|3. Crear una nueva mesa, solicitando los datos al usuario, e insertarla en el ABB de mesas.                                                                                  |" << endl;
        cout << "|4. Generar aleatoriamente un número de reservas y añadirlos a la lista doble de reservas. Se pedirá al usuario el número de reservas a generar.                              |" << endl;
        cout << "|5. Mostrar en pantalla los datos de la lista de reservas.                                                                                                                    |" << endl;
        cout << "|6. Vaciar la lista de reservas.                                                                                                                                              |" << endl;
        cout << "|7. Solicitar por teclado un tipo de menú y eliminar de la lista doble todas las reservas de ese menú.                                                                        |" << endl;
        cout << "|8. Solicitar por teclado un turno y atender todas las reservas de ese turno, creando los pedidos que sea posible y cambiando de turno a los que no hayamos podido atender.   |" << endl;
        cout << "|9. Solicitar por teclado una mesa y mostrar en pantalla sus datos y la lista de pedidos atendidos.                                                                           |" << endl;
        cout << "|10. Solicitar por teclado una situación y mostrar en pantalla los datos de las mesas (con sus pedidos atendidos) de esa situación.                                           |" << endl;
        cout << "|0. Salir.                                                                                                                                                                    |" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

        cin >> entrada;
        switch (entrada)
        {
        case 0:
            break;
        case 1:
            generarReservas(12);
            break;
        case 2:
            mostrarTodasReservas();
            break;
        case 3:
            sacarMostrarReservas();
            break;
        case 4:
            generarMesas(20);
            break;
        case 5:
            mostrarMesas();
            break;
        case 6:
            sacarMesas();
            break;
        case 7:
            simulacion7();
            break;
        case 8:
            simulacion8();
            break;
        case 9:
            simulacion9();
            break;
        default:
            break;
        }
    }
}
