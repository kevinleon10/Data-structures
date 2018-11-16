#include "Nodo_puntero.h"

Nodo_puntero::Nodo_puntero(Nodo_etiqueta *nodoEtiqueta)
{
    siguiente = 0;
    etiqueta = nodoEtiqueta;
}

Nodo_puntero::~Nodo_puntero()
{
    //
}

