#ifndef CAJA_PUNTERO_H
#define CAJA_PUNTERO_H
#include <Caja_etiqueta.h>
class Caja_etiqueta;

class Caja_puntero
{
    public:
        Caja_puntero(Caja_etiqueta *);
        virtual ~Caja_puntero();

        Caja_etiqueta *etiqueta;
        Caja_puntero *siguiente;
    protected:

    private:
};

#endif // CAJA_PUNTERO_H
