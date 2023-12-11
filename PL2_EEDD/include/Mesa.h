#ifndef MESA_H
#define MESA_H


class Mesa
{
    public:
        Mesa();
        Mesa(int n_mesa, int capacidad, string localizacion);
        virtual ~Mesa();

        void setN_mesa(int n_mesa);
        void setCapacidad(int capacidad);
        void setLocalizacion(string localizacion);

        int getN_mesa();
        int getCapacidad();
        string getLocalizacion();
        void toString();

        Mesas *next;

    protected:

    private:
        int N_mesa;
        int Capacidad;
        string Localizacion;
};

#endif // MESA_H
