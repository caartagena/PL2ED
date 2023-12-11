#ifndef LDE_H
#define LDE_H
#include "Reserva2.h"
#include <iostream>

const int ASCENDENTE=0;
const int DESCENDENTE=1;


class LDE
{
    public:
        //LDE();
        LDE() {cabeza=actual=fin=NULL; }
        virtual ~LDE();
        //~LDE();
        void insertarNodo(Reserva2 v, char c,LDE& lista);
        void insertarNodoIntAntes(Reserva2 v, int posicion);
        void borrarNodo(Reserva2 v,char c,LDE& lista);
        bool listaVacia(LDE& lista);
        void mostrarLista(LDE& lista);
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();

    protected:

    private:
        pnodo cabeza, fin, actual;
};

#endif // LDE_H
