#ifndef PEDIDO_H
#define PEDIDO_H


class Pedido
{
    public:
        Pedido(int n_mesa, string nombre, int n_personas, string tipo, string localizacion);
        virtual ~Pedido();
        Pedido *next;

    protected:

    private:
};

#endif // PEDIDO_H
