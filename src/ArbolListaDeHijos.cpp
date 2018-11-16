#include "ArbolListaDeHijos.h"
#include <Caja_etiqueta.h>
#include <Caja_puntero.h>
#include <iostream>
#include <new>
#include <Cola.h>

using namespace std;

/**
Constructor que inicializa la raiz del arbol
No recibe parametros
No devuelve nada
*/
ArbolListaDeHijos::ArbolListaDeHijos()
{
    raizArbol = 0;
}

/**
Destructor que borra completamente el arbol
No recibe parametros
No devuelve nada
*/
ArbolListaDeHijos::~ArbolListaDeHijos()
{
       // delete this;
}

/**
Vaciar borra todas las etiquetas del arbol
No recibe parametros
No devuelve nada
*/
void ArbolListaDeHijos::Vaciar()
{
    nodo posNodo = raizArbol;
    if(raizArbol->etiqueta == posNodo->etiqueta){
        raizArbol = 0 ;
    }else{
    if(EsHoja(posNodo))
    {
        nodo nodoPadre = Padre(posNodo);
        Caja_puntero *nodoHijo = nodoPadre->HijoMasIzquierdo;
        if((nodoHijo->etiqueta == posNodo)&&(nodoHijo->siguiente == 0))
        {
            nodoHijo =0;
        }
        else if(nodoHijo->etiqueta == posNodo)
        {
            nodoPadre->HijoMasIzquierdo = nodoHijo->siguiente;
            nodoHijo =0;
        }
        else
        {
            while(nodoHijo->siguiente->etiqueta != posNodo)
            {
                nodoHijo = nodoHijo->siguiente;
            }
            nodoHijo->siguiente = nodoHijo->siguiente->siguiente;
            nodoHijo = nodoHijo->siguiente;
            nodoHijo =0;
        }
        nodo nodo1 = Raiz();
        while(nodo1->siguiente != posNodo)
        {
            nodo1 = nodo1->siguiente;
        }
        nodo1->siguiente = posNodo->siguiente;
        posNodo = 0;
    }
    }
    numNodos =0;
}

/**
Vacio revisa si el arbol esta vacio
No recibe parametros
Devuelve un booleano
*/
bool ArbolListaDeHijos::Vacio()
{
    if(raizArbol == 0){
        return true;
    }else{
        return false;
    }
}

/**
AgregarHijo le agrega un hijo mas izquierdo al nodo indicado
Recibe la etiqueta a poner al nodo nuevo y el nodo del que va a ser hijo
No devuelve nada.
*/
void ArbolListaDeHijos::AgregarHijo( char valor, nodo padre)
{
    nodo agregarEtiqueta = new Caja_etiqueta(valor);
    Caja_puntero *agregarPuntero = new Caja_puntero(agregarEtiqueta);
    nodo iteradorEtiqueta = padre;

    while(iteradorEtiqueta->siguiente!=0){
         iteradorEtiqueta= iteradorEtiqueta->siguiente;
    }
    iteradorEtiqueta->siguiente = agregarEtiqueta;

    if(padre->HijoMasIzquierdo != 0){
        Caja_puntero *punteroSiguiente = padre->HijoMasIzquierdo;
        padre->HijoMasIzquierdo = agregarPuntero;
        agregarPuntero->siguiente = punteroSiguiente;
    }else{
        padre->HijoMasIzquierdo = agregarPuntero;
    }
    numNodos++;

}

/**
AgregarUltimoHijo le agrega un hijo mas derecho al nodo indicado
Recibe la etiqueta a poner al nodo nuevo y el nodo del que va a ser hijo
No devuelve nada.
*/
void ArbolListaDeHijos::AgregarUltimoHijo( char valor, nodo padre )
{
    nodo agregarEtiqueta = new Caja_etiqueta(valor);
    Caja_puntero *agregarPuntero = new Caja_puntero(agregarEtiqueta);
    nodo iteradorEtiqueta = padre;
    Caja_puntero *iteradorPuntero = padre->HijoMasIzquierdo;

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

    numNodos++;
}

/**
BorrarHoja borra el nodo indicado solo si es una hoja
Recibe el nodo a borrar
No devuelve nada
*/
void ArbolListaDeHijos::BorrarHoja(nodo posNodo)
{
    if(raizArbol->etiqueta == posNodo->etiqueta){
        delete posNodo;
        raizArbol = 0 ;
    }else{
    if(EsHoja(posNodo))
    {
        nodo nodoPadre = Padre(posNodo);
        Caja_puntero *nodoHijo = nodoPadre->HijoMasIzquierdo;
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
        nodo nodo1 = Raiz();
        while(nodo1->siguiente != posNodo)
        {
            nodo1 = nodo1->siguiente;
        }
        nodo1->siguiente = posNodo->siguiente;
        delete posNodo;
    }
    }
    numNodos--;
}


/**
PonerRaiz crea la raiz del arbol
Recibe un elemento que es la etiqueta a poner en la raiz
No devuelve nada
*/
void ArbolListaDeHijos::PonerRaiz(char valor)
{
    nodo agregarEtiqueta = new Caja_etiqueta(valor);
    raizArbol = agregarEtiqueta;
    numNodos++;
}

/**
Raiz busca la raiz del arbol
No recibe nada
Devuelve un nodo
*/
nodo ArbolListaDeHijos::Raiz()
{
    return raizArbol;
}

/**
Padre busca el padre del nodo indicado
Recibe el nodo al que le va a buscar el padre
Devuelve un nodo
*/
nodo ArbolListaDeHijos::Padre(nodo hijo)
{
    nodo iteradorEtiqueta = raizArbol;
    Caja_puntero *iteradorPuntero = raizArbol->HijoMasIzquierdo;
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

/**
HijoMasIzquierdo devuelve el primer hijo del nodo indicado
Recibe el nodo al que le va a buscar el hijo mas izquierdo
Devuelve un nodo
*/
nodo ArbolListaDeHijos::HijoMasIzquierdo(nodo padre){
        if(padre->HijoMasIzquierdo == 0 ){
            return 0;
        }else{
            return padre->HijoMasIzquierdo->etiqueta;
        }
}

/**
HijoMasDerecho devuelve el Ultimo hijo del nodo indicado
Recibe el nodo al que le va a buscar el hijo mas derecho
Devuelve un nodo
*/
nodo ArbolListaDeHijos::HijoMasDerecho(nodo padre){

        Caja_puntero *n = padre->HijoMasIzquierdo;
        Caja_puntero *n1 = padre->HijoMasIzquierdo;
        if(n==0){
            return 0;
        }else{
            n1=n->siguiente;
        while(n1!=0){
            n=n1;
            n1=n1->siguiente;
        }
        return n->etiqueta;
        }
}


/**
HermanoDerecho busca el hermano derecho del nodo indicado
Recibe el nodo al que le va a buscar el hermano derecho
Devuelve un nodo
*/
nodo ArbolListaDeHijos::HermanoDerecho(nodo Hijo)
{
    nodo iteradorEtiqueta = raizArbol;
    Caja_puntero *iteradorPuntero = raizArbol->HijoMasIzquierdo;
    bool encontrado=false;

    while(iteradorEtiqueta != 0 && encontrado==false){
        while(iteradorPuntero != 0 && encontrado==false){
            if(iteradorPuntero->etiqueta->etiqueta == Hijo->etiqueta){
                encontrado=true;
                if(iteradorPuntero->siguiente!=0){
                    iteradorEtiqueta = iteradorPuntero->siguiente->etiqueta;
                }else{
                    iteradorEtiqueta=0;
                }
            }else{
                iteradorPuntero=iteradorPuntero->siguiente;
            }
        }
        if(!encontrado){
            iteradorEtiqueta=iteradorEtiqueta->siguiente;
            iteradorPuntero = iteradorEtiqueta->HijoMasIzquierdo;
        }
    }
    if(encontrado == true){
        return iteradorEtiqueta;
    }else{
        iteradorEtiqueta=0;
        return iteradorEtiqueta;
    }
}

char ArbolListaDeHijos::Etiqueta(nodo NodoActual)
{
    return NodoActual->etiqueta;
}

/**
ModificarEtiqueta cambia la etiqueta de un nodo
Recibe la etiqueta a cambiar al nodo y el nodo al que se le quiere cambiar
No devuelve nada
*/
void ArbolListaDeHijos::ModificarEtiqueta( char valor, nodo nodoModificar)
{
    nodoModificar->etiqueta=valor;
}

/**
Traducir, traduce las etiquetas en sus respectivos nodos
Recibe el elemento que se va a buscar en el arbol
Devuelve un nodo
*/
nodo ArbolListaDeHijos::Traducir(char etiqueta)
{
    nodo iteradorEtiqueta = raizArbol;
    while(iteradorEtiqueta->etiqueta != etiqueta){
        iteradorEtiqueta=iteradorEtiqueta->siguiente;
    }
    return iteradorEtiqueta;
}

/**
EsHoja dice si un nodo del arbol es hoja
Recibe el nodo al que se desea saber si es hoja
Devuelve un booleano
*/
bool ArbolListaDeHijos::EsHoja(nodo NodoHoja)
{
    return (NodoHoja->HijoMasIzquierdo == 0);
}

/**
NumElem devuelve la cantidad de nodos del Arbol.
Devuelve un entero.
*/
int ArbolListaDeHijos::numElem(){
    return numNodos;
}

