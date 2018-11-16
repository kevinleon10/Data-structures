#ifndef PILA_H
#define PILA_H
#include "Elemento.h"

class Pila
{
     public:
    //Operadores Basicos de la Pila
    void Iniciar();
    void Destruir();
    bool Vacia();
    void Vaciar();
    Elemento* Traducir(char);
    void Meter(Elemento*);
    void Sacar();
    Elemento* Tope();
    int NumeroElementos();
    char Etiqueta (Elemento*);

    //Atributos de la Pila
    Elemento* tope;
    int NumElem;

    protected:
    private:
};

#endif // PILA_H

