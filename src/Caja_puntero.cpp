#include "Caja_puntero.h"
#include <Caja_etiqueta.h>

//Constructor de la clase Caja_puntero.
Caja_puntero::Caja_puntero(Caja_etiqueta *nodoEtiqueta)
{
        siguiente= 0;
        etiqueta = nodoEtiqueta;
}

Caja_puntero::~Caja_puntero()
{
    //dtor
}
