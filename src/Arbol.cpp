#include "Arbol.h"
#include <Nodo_etiqueta.h>
#include <Nodo_puntero.h>
#include <iostream>
#include <new>

using namespace std;

Arbol::Arbol()
{
    nodo = 0;
}

Arbol::~Arbol()
{
    //
}

void Arbol::Vaciar()
{
    //vaciar la mierda..
}

bool Arbol::Vacio()
{
    if(nodo==0){
        return true;
    }else{
        return false;
    }
}

void Arbol::AgregarHijo( char valor, Nodo_etiqueta *padre)
{
    Nodo_etiqueta *agregarEtiqueta = new Nodo_etiqueta(valor);
    Nodo_puntero *agregarPuntero = new Nodo_puntero(agregarEtiqueta);
    Nodo_etiqueta *iteradorEtiqueta = padre;
    //Nodo_puntero *iteradorPuntero = padre->HijoMasIzquierdo;


    while(iteradorEtiqueta->siguiente!=0){
         iteradorEtiqueta= iteradorEtiqueta->siguiente;
    }
    iteradorEtiqueta->siguiente = agregarEtiqueta;

    if(padre->HijoMasIzquierdo != 0){
        Nodo_puntero *punteroSiguiente = padre->HijoMasIzquierdo;
        padre->HijoMasIzquierdo = agregarPuntero;
        agregarPuntero->siguiente = punteroSiguiente;
    }else{
        padre->HijoMasIzquierdo = agregarPuntero;
    }

}

void Arbol::AgregarUltimoHijo( char valor, Nodo_etiqueta *padre )
{
    Nodo_etiqueta *agregarEtiqueta = new Nodo_etiqueta(valor);
    Nodo_puntero *agregarPuntero = new Nodo_puntero(agregarEtiqueta);
    Nodo_etiqueta *iteradorEtiqueta = padre;
    Nodo_puntero *iteradorPuntero = padre->HijoMasIzquierdo;


    while(iteradorEtiqueta->siguiente!=0){
         iteradorEtiqueta= iteradorEtiqueta->siguiente;
    }
    iteradorEtiqueta->siguiente = agregarEtiqueta;

    if(padre->HijoMasIzquierdo != 0){
        while(iteradorPuntero->siguiente != 0){
            iteradorPuntero=iteradorPuntero->siguiente;
        }
        iteradorPuntero->siguiente=agregarPuntero;
    }else{
        padre->HijoMasIzquierdo = agregarPuntero;
    }
}

void Arbol::BorrarHoja(Nodo_etiqueta *posNodo)
{
    if(nodo->etiqueta == posNodo->etiqueta){
        delete posNodo;
    }else{
    if(EsHoja(posNodo))
    {
        Nodo_etiqueta *nodoPadre = Padre(posNodo);
        Nodo_puntero *nodoHijo = nodoPadre->HijoMasIzquierdo;
        if((nodoHijo->etiqueta == posNodo)&&(nodoHijo->siguiente == 0))
        {
            delete nodoHijo;
        }
        else if(nodoHijo->etiqueta == posNodo)
        {
            nodoPadre->HijoMasIzquierdo = nodoHijo->siguiente;
            delete nodoHijo;
        }
        else
        {
            while(nodoHijo->siguiente->etiqueta != posNodo)
            {
                nodoHijo = nodoHijo->siguiente;
            }
            nodoHijo->siguiente = nodoHijo->siguiente->siguiente;
            nodoHijo = nodoHijo->siguiente;
            delete nodoHijo;
        }
        Nodo_etiqueta *nodo1 = Raiz();
        while(nodo1->siguiente != posNodo)
        {
            nodo1 = nodo1->siguiente;
        }
        nodo1->siguiente = posNodo->siguiente;
        delete posNodo;
    }
    }
}

void Arbol::PonerRaiz(char valor)
{
    Nodo_etiqueta *agregarEtiqueta = new Nodo_etiqueta(valor);
    nodo = agregarEtiqueta;
}

Nodo_etiqueta* Arbol::Raiz()
{
    return nodo;
}

Nodo_etiqueta* Arbol::Padre(Nodo_etiqueta *hijo)
{
    Nodo_etiqueta *iteradorEtiqueta = nodo;
    Nodo_puntero *iteradorPuntero = nodo->HijoMasIzquierdo;
    bool encontrado=false;

    while(iteradorEtiqueta != 0 && encontrado==false){
        while(iteradorPuntero != 0 && encontrado==false){
            if(iteradorPuntero->etiqueta->etiqueta == hijo->etiqueta){
                encontrado=true;
            }else{
                iteradorPuntero=iteradorPuntero->siguiente;
            }
        }
        if(!encontrado){
            iteradorEtiqueta=iteradorEtiqueta->siguiente;
            iteradorPuntero = iteradorEtiqueta->HijoMasIzquierdo;
        }
        }
    return iteradorEtiqueta;
}

Nodo_etiqueta* Arbol::HijoMasIzquierdo(Nodo_etiqueta *padre)
{
    return padre->HijoMasIzquierdo->etiqueta;
}

Nodo_etiqueta* Arbol::HermanoDerecho(Nodo_etiqueta *Hijo)
{
    Nodo_etiqueta *iteradorEtiqueta = nodo;
    Nodo_puntero *iteradorPuntero = nodo->HijoMasIzquierdo;
    bool encontrado=false;

    while(iteradorEtiqueta != 0 && encontrado==false){
        while(iteradorPuntero != 0 && encontrado==false){
            if(iteradorPuntero->etiqueta->etiqueta == Hijo->etiqueta){
                encontrado=true;
                iteradorEtiqueta = iteradorPuntero->siguiente->etiqueta;
            }else{
                iteradorPuntero=iteradorPuntero->siguiente;
            }
        }
        if(!encontrado){
            iteradorEtiqueta=iteradorEtiqueta->siguiente;
            iteradorPuntero = iteradorEtiqueta->HijoMasIzquierdo;
        }
    }
    return iteradorEtiqueta;
}

char Arbol::Etiqueta(Nodo_etiqueta *NodoActual)
{
    return NodoActual->etiqueta;
}

void Arbol::ModificarEtiqueta( char valor, Nodo_etiqueta *nodoModificar)
{
    nodoModificar->etiqueta=valor;
}

Nodo_etiqueta* Arbol::traducir(char etiqueta)
{
    Nodo_etiqueta *iteradorEtiqueta = nodo;
    while(iteradorEtiqueta->etiqueta != etiqueta){
        iteradorEtiqueta=iteradorEtiqueta->siguiente;
    }
    return iteradorEtiqueta;
}

bool Arbol::EsHoja(Nodo_etiqueta *NodoHoja)
{
    return (NodoHoja->HijoMasIzquierdo == 0);
}
