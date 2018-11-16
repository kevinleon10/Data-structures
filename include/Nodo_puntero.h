#ifndef NODO_PUNTERO_H
#define NODO_PUNTERO_H
#include <Nodo_etiqueta.h>

class Nodo_etiqueta;

class Nodo_puntero
{
    public:
        Nodo_puntero(Nodo_etiqueta *);
        virtual ~Nodo_puntero();

        Nodo_puntero *siguiente;
        Nodo_etiqueta *etiqueta;

    protected:

    private:
};

#endif // NODO_PUNTERO_H
