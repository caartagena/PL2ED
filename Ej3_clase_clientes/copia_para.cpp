#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include "cliente.h"
#define TAM 20
using namespace std;

string vnombres[8]={"Juan","Eva","Ana","Alicia","Laura","Pedro","Marcos","Mariano"};

struct CLIENTE{
    string nombre;//char nombre[40];
    int tel;
    float saldo;
};
void escribecliente(CLIENTE c);
void leeclienter(CLIENTE * c);
//CLIENTE leeclientev(void);
void leerclientes(CLIENTE vc[]);
void escribirclientes(CLIENTE vc[]);
float calcularmedia(CLIENTE vc[]);

void generarclientes(CLIENTE vc[]);
CLIENTE generacliente(void);
int generatel(void);
int generasaldo(void);
string generanombre(void);
//void generanombre(char nombrec[]);

int main()
{
    CLIENTE vc[TAM];
    float mediasaldo;
    srand(time(NULL));
//    leerclientes(vc);
    generarclientes(vc);
    mediasaldo=calcularmedia(vc);
    cout << "\n\nMedia de saldo de los clientes: " << mediasaldo<<endl;
    escribirclientes(vc);
    cout << "\n\nFin programa\n" << endl;
    return 0;
}
CLIENTE generacliente(void){
    CLIENTE c;
    c.nombre=generanombre();
    c.tel=generatel();
    c.saldo=generasaldo();
    return c;
}
string generanombre(void){
    int i;
    i=rand()%8;
    return vnombres[i];
}

int generatel(void){
    int r;
    r=rand()%400000000+600000000;
    return r;
}
int generasaldo(void){     //valores entre 1000 y 10000
    int r;
    r=rand()%9001+1000;
    return r;
}
void leerclientes(CLIENTE vc[]){
    cout << "\n\nVamos a leer los " << TAM << " clientes:\n";
    for(int i=0;i<TAM;i++)
//        vc[i]=leeclientev();
        leeclienter(&vc[i]);
}

void generarclientes(CLIENTE vc[]){
    cout << "\n\nVamos a generar los " << TAM << " clientes:\n";
    for(int i=0;i<TAM;i++)
        vc[i]=generacliente();
}


void escribirclientes(CLIENTE vc[]){
    cout << "\n\nVamos a mostrar los " << TAM << " clientes:\n";
    for(int i=0;i<TAM;i++)
        escribecliente(vc[i]);
}
float calcularmedia(CLIENTE vc[]){
    float res=0;
    for(int i=0;i<TAM;i++)
        res=res+vc[i].saldo;
    res=res/TAM;
    return res;
}
/*
CLIENTE leeclientev(void){
    CLIENTE c;
    cout <<"\n Dame el nombre:";
    cin >> c.nombre;
    cout <<"\n Dame el telefono:";
    cin >> c.tel;
    cout <<"\n Dame el saldo:";
    cin >> c.saldo;
    return c;
}
*/
void leeclienter(CLIENTE * c){
    cout << "\n Dame el nombre:";
    cin >> c->nombre;
    cout << "\n Dame el telefono:";
    cin >> c->tel;
    cout << "\n Dame el saldo:";
    cin >> c->saldo;
}
void escribecliente(CLIENTE c){
    cout << "\n" <<c.nombre << " - " << c.tel << " - " << c.saldo;
}
