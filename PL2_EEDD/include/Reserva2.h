#ifndef RESERVA2_H
#define RESERVA2_H
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


class reserva2
{
    public:
        reserva2(int numReserva, string nombreCliente, string situacion, int numPersonas, string hora, string preferenciaMenu);
        virtual ~reserva2();

        void mostrarDatos() const {
        cout << "numReserva: " << numReserva << endl;
        cout << "nombreCliente: " << nombreCliente << endl;
        cout << "situacion: " << situacion << endl;
        cout << "numPersonas: " << numPersonas << endl;
        cout << "hora: " << hora << endl;
        cout << "preferenciaMenu: " << preferenciaMenu << endl;
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
        void setNumReserva(int numReserva){
            this->numReserva=numReserva;
        }
        void setNombreCliente(string nombreCliente){
            this->nombreCliente=nombreCliente;
        }
        void setSituacion(string situacion){
            this->situacion=situacion;
        }
        void setNumPersonas(int numPersonas){
            this->numPersonas=numPersonas;
        }
        void setHora(string hora){
            this->hora=hora;
        }
        void setPreferenciaMenu(string preferenciaMenu){
            this->preferenciaMenu=preferenciaMenu;
        }
    protected:

    private:
        int numReserva;
        string nombreCliente;
        string situacion;
        int numPersonas;
        string hora;
        string preferenciaMenu;
        Reserva2 *siguiente;
        Reserva2 *anterior;
};

#endif // RESERVA2_H
