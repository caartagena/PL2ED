#include "cliente.h"

Cliente::Cliente(){}
Cliente::Cliente(string n, int t, float s){
            nombre=n;
            tel=t;
            saldo=s;
        }
Cliente::~Cliente() {cout << "\nDestruido el cliente " << nombre; }

void Cliente::leeCliente(void)
{
    cout << "\n Dame el nombre:";
    cin >> nombre;
    cout << "\n Dame el telefono:";
    cin >> tel;
    cout << "\n Dame el saldo:";
    cin >> saldo;
}

void Cliente::escribeCliente(){
    cout << "\n" <<nombre << " - " << tel << " - " << saldo;
}

float Cliente::dameSaldo(){
    return saldo;
}

void Cliente::generaCliente(){
    string vnombres[8]={"Juan","Eva","Ana","Alicia","Laura","Pedro","Marcos","Mariano"};
    nombre=vnombres[rand()%8];
    tel=rand()%400000000+600000000;
    saldo=rand()%9001+1000;
}
