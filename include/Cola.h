#ifndef COLA_H
#define COLA_H
#include "iostream"

template <class T>
class Cola
{
public:
    Cola();
    virtual ~Cola();
    void Vaciar();
    bool Vacia();
    void Encolar(T);
    T Desencolar();
    int Frente();
    int NumElem();
    T Etiqueta(int);

    int primero;
    int ultimo;
    int numElementos;
    int tamMaximo;
    T cola[30];

protected:
private:
};

template<class T>
Cola<T>::Cola()
{
    tamMaximo=30;
    numElementos=0;
    primero=0;
    ultimo=-1;
}

template<class T>
Cola<T>::~Cola()
{
    numElementos=0;
    primero=0;
    ultimo=0;
}

template<class T>
bool Cola<T>::Vacia()
{
    bool vacia;
    if(numElementos==0)
    {
        vacia=true;
    }
    else
    {
        vacia=false;
    }
    return vacia;
}

template<class T>
void Cola<T>::Encolar(T elemento)
{
    if(numElementos<tamMaximo)
    {
        if(ultimo==tamMaximo)
        {
            ultimo=-1;
        }
        numElementos=numElementos+1;
        ultimo=ultimo+1;
        cola[ultimo]=elemento;
    }
}

template<class T>
T Cola<T>::Desencolar()
{
    T elementoRecuperado;
    if(numElementos>0)
    {
        numElementos=numElementos-1;
        elementoRecuperado = cola[primero];
        if(primero==tamMaximo)
        {
            primero=0;
        }
        primero=primero+1;
    }
    return elementoRecuperado;
}

template<class T>
int Cola<T>::Frente()
{
    return primero;
}

template<class T>
int Cola<T>::NumElem()
{
    return numElementos;
}

template<class T>
T Cola<T>::Etiqueta(int pos)
{
    return cola[pos];
}

#endif // COLA_HG


