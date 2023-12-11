#include "Gestion.h"




// AQUI VAN TODOS LOS METODOS



Gestion::Gestion()
{

    int n_mesa[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    static int indice_mesa = 0;
    int numero_de_mesa()
    {
        int mesa = n_mesa[indice_mesa];
        indice_mesa = (indice_mesa + 1) % (sizeof(n_mesa) / sizeof(n_mesa[0]));
        return mesa;
    }

    int capacidad[] = {4, 8};
    int capacidadAle()
    {
        int capacidadAleatorio = generarNumeroAleatorio(0, sizeof(capacidad) / sizeof(capacidad[0]) - 1);
        return capacidad[capacidadAleatorio];
    }

    string localizacionAleMesas()
    {
        int localizacionAleatoria = generarNumeroAleatorio(0, sizeof(localizacion) / sizeof(localizacion[0]) - 1);
        return localizacion[localizacionAleatoria];
    }

    Arbol_mesas = new ABB(numero_de_mesa, capacidadAle, localizacionAleMesas);
    //ctor
}

Gestion::~Gestion()
{
    //dtor
}

ABB *Gestor::getArbol(){
    return Arbol_mesas;
}

// FALTA EL VOID CON LA OPCION 1 Y 2


