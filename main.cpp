#include "reserva2.hpp"
#include "LDEM.hpp"
#include "LE.hpp"
#include "mesas.hpp"
#include "ABBM.hpp"
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
// Generar reservas aleatorias
Reserva2::Reserva2() {}

Reserva2::~Reserva2() {}

Pedido::Pedido() {}

Pedido::~Pedido() {}

Mesas::Mesas() {}

Mesas::~Mesas() {}

int contador = 1;
string generarNombreCliente()
{
    string vnombres[30] = {"Juan", "Eva", "Ana", "Alicia", "Laura", "Pedro", "Marcos", "Mariano", "Javier", "Jorge", "Sergio", "Sara", "Sandra", "Sonia", "Sofia", "Santiago", "Samuel", "Raul", "Ramon", "Rafael", "Pablo", "Oscar", "Omar", "Nuria", "Natalia", "Miguel", "Manuel", "Luis", "Lucia", "Lorena"};
    string nombreCliente = vnombres[generarNumeroAleatorio(0, 29)];
    return nombreCliente;
}
string generarSitucaion()
{
    string vsituacion[2] = {"Terraza", "Interior"};
    string situacion = vsituacion[generarNumeroAleatorio(0, 1)];
    return situacion;
}
int generarNumPersonas()
{
    int numPersonas = generarNumeroAleatorio(1, 8);
    return numPersonas;
}
int generarHora()
{
    int hora = generarNumeroAleatorio(13, 15);
    return hora;
}
string generarPreferenciaMenu()
{
    string vpreferenciaMenu[3] = {"Vegano", "Sin_Gluten", "Completo"};
    string preferenciaMenu = vpreferenciaMenu[generarNumeroAleatorio(0, 2)];
    return preferenciaMenu;
}
// Generar mesas aleatorias

int numMesa = 0;
int generarNumMesa()
{
    numMesa++;
    return numMesa;
}
int generarCapacidad()
{
    int capacidades[2] = {4, 8};
    int capacidad = generarNumeroAleatorio(0, 1);
    return capacidades[capacidad];
}
string generarLocalizacion()
{
    string localizaciones[2] = {"Terraza", "Interior"};
    int localizacion = generarNumeroAleatorio(0, 1);
    return localizaciones[localizacion];
}

Reserva2 generarReservaAle()
{
    Reserva2 reserva;
    reserva.setNumReserva(contador);
    reserva.setNombreCliente(generarNombreCliente());
    reserva.setSituacion(generarSitucaion());
    reserva.setNumPersonas(generarNumPersonas());
    reserva.setHora(generarHora());
    reserva.setPreferenciaMenu(generarPreferenciaMenu());
    contador++;
    return reserva;
}

Pedido generarPedido(Reserva2 reserva)
{
    Pedido pedido;
    pedido.setNumPedido(reserva.getNumReserva());
    pedido.setNombreCliente(reserva.getNombreCliente());
    pedido.setSituacion(reserva.getSituacion());
    pedido.setNumPersonas(reserva.getNumPersonas());
    pedido.setHora(reserva.getHora());
    pedido.setPreferenciaMenu(reserva.getPreferenciaMenu());
    return pedido;
}

Mesas generarMesaAle()
{
    Mesas mesa;
    mesa.setNumMesa(generarNumMesa());
    mesa.setNumPersonas(generarCapacidad());
    mesa.setSituacion(generarLocalizacion());
    mesa.setOcupada(false);
    cout << "Mesa generada" << endl;
    cout << endl;
    return mesa;
}

Lista lista;
LE listaEnlazada;
ArbolABB arbol;

void cantidad_de_reservas()
{
    int cantidad;
    cout << "Introduzca la cantidad de reservas que desea generar: ";
    cin >> cantidad;
    cout << endl;
    for (int i = 0; i < cantidad; i++)
    {
        Reserva2 reserva = generarReservaAle();
        lista.insertarNodo(reserva, lista);
        cout << endl;
        cout << endl;
    }
}

void insertarMesas()
{
    for (int i = 0; i < 20; i++)
    {
        Mesas mesa = generarMesaAle();
        arbol.insertarMesasOrdenadas(mesa, arbol);
    }
}

void generarMesaPorConsola()
{
    Mesas mesa;
    int numPersonas;
    string situacion;
    cout << "Introduzca el numero de personas de la mesa: " << endl;
    cin >> numPersonas;
    cout << "Introduzca la localizacion: " << endl;
    cin >> situacion;
    mesa.setNumMesa(generarNumMesa());
    mesa.setNumPersonas(numPersonas);
    mesa.setSituacion(situacion);
    mesa.setOcupada(false);
    arbol.insertarMesasOrdenadas(mesa, arbol);
}

void eliminarMesaPorConsla()
{
    int numMesa;
    // int numPersonas;
    // string situacion;
    cout << "Introduzca el numero de mesa que desea eliminar: (0 para eliminar por numero de personas y situacion): ";
    cin >> numMesa;
    /*if (numMesa == 0)
    {
        cout << "Introduzca el numero de personas que desea eliminar: ";
        cin >> numPersonas;
        cout << "Introduzca la situacion que desea eliminar: ";
        cin >> situacion;
        arbol.eliminarMesaNR(0, numPersonas, situacion, arbol);
    }
    else
    {*/
    arbol.eliminarMesaNR(numMesa, 0, "A", arbol);
    //}
}

void atenderReservasTurno()
{
    arbol.inicializarMesas(arbol.getRaiz());
    int turno;
    cout << "Introduzca el turno que desea atender: ";
    cin >> turno;
    int cuantos = lista.ContarHora(turno, lista);
    for (int i = 0; i < cuantos; i++)
    {
        Reserva2 reserva;
        reserva = lista.buscarHora(turno, lista);
        cout << "Reservas atendida: " << reserva.getNumReserva() << endl;
        Pedido pedido = generarPedido(reserva);
        arbol.buscarMesaAdecuada(arbol.getRaiz(), reserva, pedido);
    }
}

int main()
{
    insertarMesas();
    int entrada = -1;
    while (entrada != 0)
    {
        cout << "|--------------------------------------------------------------Restaurante cpp------------------------------------------------------------------------------------------------|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "|1. Mostrar el contenido del Arbol de mesas con recorrido Inorden, mostrando de cada mesa: numero, situacion y numero de pedidos atendidos hasta el momento.                  |" << endl;
        cout << "|2. Borrar una mesa concreta que indique el usuario.                                                                                                                          |" << endl;
        cout << "|3. Crear una nueva mesa, solicitando los datos al usuario, e insertarla en el ABB de mesas.                                                                                  |" << endl;
        cout << "|4. Generar aleatoriamente un numero de reservas y añadirlos a la lista doble de reservas. Se pedira al usuario el numero de reservas a generar.                              |" << endl;
        cout << "|5. Mostrar en pantalla los datos de la lista de reservas.                                                                                                                    |" << endl;
        cout << "|6. Vaciar la lista de reservas.                                                                                                                                              |" << endl;
        cout << "|7. Solicitar por teclado un tipo de menu y eliminar de la lista doble todas las reservas de ese menu.                                                                        |" << endl;
        cout << "|8. Solicitar por teclado un turno y atender todas las reservas de ese turno, creando los pedidos que sea posible y cambiando de turno a los que no hayamos podido atender.   |" << endl;
        cout << "|9. Solicitar por teclado una mesa y mostrar en pantalla sus datos y la lista de pedidos atendidos.                                                                           |" << endl;
        cout << "|10. Solicitar por teclado una situacion y mostrar en pantalla los datos de las mesas (con sus pedidos atendidos) de esa situacion.                                           |" << endl;
        cout << "|0. Salir.                                                                                                                                                                    |" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cin >> entrada;
        switch (entrada)
        {
        case 0:
            break;
        case 1:
            arbol.mostrarMesasInOrder(arbol.getRaiz());
            break;
        case 2:
            eliminarMesaPorConsla();
            break;
        case 3:
            generarMesaPorConsola();
            break;
        case 4:
            cantidad_de_reservas();
            break;
        case 5:
            lista.mostrarLista(lista);
            break;
        case 6:
            lista.borrarListaEntera(lista);
            break;
        case 7:
            lista.borrarNodoMenu(lista);
            break;
        case 8:
            atenderReservasTurno();
            break;
        case 9:
            lista.ContarHora(13, lista);
            break;
        case 10:

            break;
        default:
            break;
        }
    }
}