#include "Nodo_etiqueta.h"

Nodo_etiqueta::Nodo_etiqueta(char valor)
{
    etiqueta=valor;
    HijoMasIzquierdo = 0;
    siguiente = 0;
}

Nodo_etiqueta::~Nodo_etiqueta()
{
    //
}
