#ifndef NODO_ETIQUETA_H
#define NODO_ETIQUETA_H
#include <Nodo_puntero.h>
class Nodo_puntero;

class Nodo_etiqueta
{
    public:
        Nodo_etiqueta(char);
        virtual ~Nodo_etiqueta();

        char etiqueta;
        Nodo_puntero *HijoMasIzquierdo;
        Nodo_etiqueta *siguiente;

    protected:

    private:
};

#endif // NODO_ETIQUETA_H
