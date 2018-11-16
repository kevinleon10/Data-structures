#include "Caja_etiqueta.h"

/*
Contructor de la clase Caja_etiqueta;
*/
Caja_etiqueta::Caja_etiqueta(char valor)
{
    etiqueta=valor;
    HijoMasIzquierdo = 0;
    siguiente = 0;
    }

Caja_etiqueta::Caja_etiqueta(){
    HijoMasIzquierdo = 0;
    siguiente = 0;
};

Caja_etiqueta::~Caja_etiqueta()
{
    //dtor
}

