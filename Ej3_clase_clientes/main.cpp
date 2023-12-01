#include "cliente.h"
#define TAM 20
#define TAM2 2

void leerclientes(Cliente vc[], int tam);
void escribirclientes(Cliente vc[], int tam);
float calcularmedia(Cliente vc[], int tam);
void generarclientes(Cliente vc[], int tam);

int main()
{
    Cliente vc2[TAM2];
    Cliente vc[TAM];
    float mediasaldo;
    srand(time(NULL));
    leerclientes(vc2, TAM2);
    mediasaldo=calcularmedia(vc2, TAM2);
    cout << "\n\nSaldo medio de los clientes leídos es: " << mediasaldo<<endl;
    escribirclientes(vc2, TAM2);

    generarclientes(vc, TAM);
    mediasaldo=calcularmedia(vc, TAM);
    cout << "\n\nSaldo medio de los clientes generados es: " << mediasaldo<<endl;
    escribirclientes(vc, TAM);

    Cliente c1;
    Cliente c2("Ana",4,6);
    Cliente *c3 = new Cliente("Luisa",14,8.2);
    Cliente c4 = Cliente("Antonio",2,7.3);
    cout << "\n\nVamos a enseñar ";
    c2.escribeCliente();
    cout << "\n\nVamos a destruir ";
    (*c3).escribeCliente();
    cout << endl;
    delete c3;
    cout << "\n\nFin programa\n" << endl;
    return 0;
}

void leerclientes(Cliente vc[], int tam){
    cout << "\n\nVamos a leer los " << tam << " clientes:\n";
    for(int i=0;i<tam;i++)
        vc[i].leeCliente();
}

void generarclientes(Cliente vc[], int tam){
    cout << "\nGenerando los " << tam << " clientes:\n";
    for(int i=0;i<tam;i++)
        vc[i].generaCliente();
}


void escribirclientes(Cliente vc[], int tam){
    cout << "\n\nVamos a mostrar los " << tam << " clientes:\n";
    for(int i=0;i<tam;i++)
        vc[i].escribeCliente();
}
float calcularmedia(Cliente vc[],int tam){
    float res=0;
    for(int i=0;i<tam;i++)
        res=res+vc[i].dameSaldo();
    res=res/tam;
    return res;
}
