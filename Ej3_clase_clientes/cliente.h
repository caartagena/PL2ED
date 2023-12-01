#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


class Cliente
 {
    private:
        string nombre;
        int tel;
        float saldo;
    public:
        Cliente();
        Cliente(string n, int t, float s);
        ~Cliente();
        void escribeCliente();
        void leeCliente();
        float dameSaldo();
        void generaCliente();
};

#endif // CLIENTE_H
