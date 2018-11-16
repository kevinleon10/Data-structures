#ifndef CAJA_ETIQUETA_H
#define CAJA_ETIQUETA_H
#include <Caja_puntero.h>
class Caja_puntero;

class Caja_etiqueta
{
    public:
        Caja_etiqueta();
        Caja_etiqueta(char);
        virtual ~Caja_etiqueta();

        char etiqueta;
        Caja_puntero *HijoMasIzquierdo;
        Caja_etiqueta *siguiente;

    protected:

    private:
};

#endif // CAJA_ETIQUETA_H
