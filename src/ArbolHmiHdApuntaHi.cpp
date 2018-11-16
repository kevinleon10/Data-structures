#include "ArbolHmiHdApuntaHi.h"
#include "CajaArbolHmiHdApuntaHi.h"
#include <iostream>

using namespace std;

/**
Constructor que inicializa la raiz del arbol
No recibe parametros
No devuelve nada
*/
ArbolHmiHdApuntaHi::ArbolHmiHdApuntaHi()
{
    raizArbol = 0;
}

/**
Destructor que borra completamente el arbol
No recibe parametros
No devuelve nada
*/
ArbolHmiHdApuntaHi::~ArbolHmiHdApuntaHi()
{
 /*if(raizArbol->hijoIzq != 0)
    {
        DestruirRec(Raiz());
    }
    raizArbol = 0;*/

}


/**
DestructorRec borra recursivamente los nodos
Recibe un nodo que evalua y borra
No devuelve nada
*/
void ArbolHmiHdApuntaHi::DestruirRec(nodo posNodo)
{
   /* if(EsHoja(posNodo))
    {
        nodo posNodo2 = posNodo->hermDer;
        BorrarHoja(posNodo);
        if(posNodo2 != 0)
        {
            DestruirRec(posNodo2);
        }
    }
    else
    {
        posNodo = posNodo->hijoIzq;
        while(posNodo != 0)
        {
            DestruirRec(posNodo);
            nodo posNodo3 = posNodo->hermDer;
            BorrarHoja(posNodo);
            posNodo = posNodo3;
        }
    }*/
}



/**
Vaciar borra todas las etiquetas del arbol
No recibe parametros
No devuelve nada
*/
void ArbolHmiHdApuntaHi::Vaciar()
{

}

/**
Vacio revisa si el arbol esta vacio
No recibe parametros
Devuelve un booleano
*/
bool ArbolHmiHdApuntaHi::Vacio()
{
    if(raizArbol == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
PonerRaiz crea la raiz del arbol
Recibe un elemento que es la etiqueta a poner en la raiz
No devuelve nada
*/
void ArbolHmiHdApuntaHi::PonerRaiz(char elem)
{
    raizArbol = new CajaArbolHmiHdApuntaHi(elem);
}

/**
AgregarHijo le agrega un hijo mas izquierdo al nodo indicado
Recibe la etiqueta a poner al nodo nuevo y el nodo del que va a ser hijo
No devuelve nada
*/
void ArbolHmiHdApuntaHi::AgregarHijo(char elem, nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    if(posNodo->hijoIzq == 0)
    {
        posNodo->hijoIzq = new CajaArbolHmiHdApuntaHi(elem);
        posNodo->hijoIzq->padre = posNodo;
    }
    else
    {
        nodo nuevo = new CajaArbolHmiHdApuntaHi(elem);
        nuevo->hermDer = posNodo->hijoIzq;
        nuevo->padre = posNodo;
        posNodo->hijoIzq->hermIzq = nuevo;
        posNodo->hijoIzq = nuevo;
    }
}

/**
AgregarUltHijo le agrega un hijo mas derecho al nodo indicado
Recibe la etiqueta a poner al nodo nuevo y el nodo del que va a ser hijo
No devuelve nada
*/
void ArbolHmiHdApuntaHi::AgregarUltimoHijo(char elem, nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    if(posNodo->hijoIzq == 0)
    {
        posNodo->hijoIzq = new CajaArbolHmiHdApuntaHi(elem);
        posNodo->hijoIzq->padre = posNodo;
    }
    else
    {
        nodo nuevo = new CajaArbolHmiHdApuntaHi(elem);
        nuevo->padre = posNodo;
        posNodo = posNodo->hijoIzq;
        while(posNodo->hermDer != 0)
        {
            posNodo = posNodo->hermDer;
        }
        nuevo->hermDer = posNodo->hermDer;
        posNodo->hermDer = nuevo;
        nuevo->hermIzq = posNodo;
    }
}

/**
BorrarHoja borra el nodo indicado solo si es una hoja
Recibe el nodo a borrar
No devuelve nada
*/
void ArbolHmiHdApuntaHi::BorrarHoja(nodo posNodo)
{
    if(EsHoja(posNodo))
    {
        //nodo posNodo = buscarPreorden(pos);
        nodo posNodo2 = Padre(posNodo);
        if((posNodo2->hijoIzq == posNodo)&&(posNodo->hermDer == 0))
        {
            posNodo2->hijoIzq = 0;
            delete posNodo;
        }
        else
        {
            posNodo2 = posNodo2->hijoIzq;
            if(posNodo2 == posNodo)
            {
                nodo posNodo3 = Padre(posNodo2);
                posNodo3->hijoIzq = posNodo2->hermDer;
                posNodo3->hijoIzq->hermIzq = 0;
                delete posNodo2;
            }
            else
            {
                while(posNodo2->hermDer != posNodo)
                {
                    posNodo2 = posNodo2->hermDer;
                }
                posNodo2->hermDer = posNodo->hermDer;
                posNodo2->hermDer->hermIzq = posNodo2;
                delete posNodo;
            }
        }
    }
}

/**
ModificarEtiqueta cambia la etiqueta de un nodo
Recibe la etiqueta a cambiar al nodo y el nodo al que se le quiere cambiar
No devuelve nada
*/
void ArbolHmiHdApuntaHi::ModificarEtiqueta(char elem, nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    posNodo->etiq = elem;
}

/**
Raiz busca la raiz del arbol
No recibe nada
Devuelve un nodo
*/
nodo ArbolHmiHdApuntaHi::Raiz()
{
    return raizArbol;
}

/**
Padre busca el padre del nodo indicado
Recibe el nodo al que le va a buscar el padre
Devuelve un nodo
*/
nodo ArbolHmiHdApuntaHi::Padre(nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    if(posNodo == Raiz())
    {
        return 0;
    }
    else
    {
        return posNodo->padre;
    }
}

/**
HijoMasIzquierdo devuelve el primer hijo del nodo indicado
Recibe el nodo al que le va a buscar el hijo mas izquierdo
Devuelve un nodo
*/
nodo ArbolHmiHdApuntaHi::HijoMasIzquierdo(nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    return posNodo->hijoIzq;
}

/**
HermanoDerecho busca el hermano derecho del nodo indicado
Recibe el nodo al que le va a buscar el hermano derecho
Devuelve un nodo
*/
nodo ArbolHmiHdApuntaHi::HermanoDerecho(nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    return posNodo->hermDer;
}

/**
Etiqueta devuelve la etiqueta del nodo indicado
Recibe el nodo al que le va a buscar la etiqueta
Devuelve un nodo
*/
char ArbolHmiHdApuntaHi::Etiqueta(nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    return posNodo->etiq;
}

/**
EsHoja dice si un nodo del arbol es hoja
Recibe el nodo al que se desea saber si es hoja
Devuelve un booleano
*/
bool ArbolHmiHdApuntaHi::EsHoja(nodo posNodo)
{
    //nodo posNodo = buscarPreorden(pos);
    return (posNodo->hijoIzq == 0);
}

/**
Traducir traduce las etiquetas en sus respectivos nodos
Recibe el elemento que se va a buscar en el arbol
Devuelve un nodo
*/
nodo ArbolHmiHdApuntaHi::Traducir(char elem)
{
    if(!Vacio())
    {
        nodo posNodo = Raiz();
        return BuscarPreordenRec(posNodo, elem);
    }
    else
    {
        return 0;
    }
}

/**
BuscarPreordeRec busca en todo el arbol el nodo con la etiqueta indicada
Recibe el nodo que esta buscando y la etiqueta del nodo a buscar
Devuelve un nodo
*/
nodo ArbolHmiHdApuntaHi::BuscarPreordenRec(nodo posNodo, char elem)
{
    if(posNodo->etiq == elem)
    {
        return posNodo;
    }
    else
    {
        nodo posNodo3;
        nodo posNodo2 = posNodo->hijoIzq;
        if (posNodo2!=0)
        {
            posNodo3 = posNodo2;
        }
        while(posNodo2 != 0)
        {
            posNodo2 = BuscarPreordenRec(posNodo2, elem);
            if (posNodo2 == 0)
            {
                posNodo2 = posNodo3->hermDer;
                posNodo3 = posNodo2;
            }
            else
            {
                if (posNodo2->etiq!=elem)
                {
                    posNodo2 = posNodo2->hermDer;
                }
                else
                {
                    return posNodo2;
                }
            }
        }
        return posNodo2;
    }
}

/**
ImprimirPreorden imprime el arbol si no esta vacio
No recibe nada
No devuelve nada
*/
void ArbolHmiHdApuntaHi::ImprimirPreorden()
{
    if(!Vacio())
    {
        ImprimirPreordenRec(Raiz());
    }
}

/**
ImprimirPreordenRec imprime la etiqueta del nodo que recibe
Recibe el nodo a imprimir
No devuelve nada
*/
void ArbolHmiHdApuntaHi::ImprimirPreordenRec(nodo posNodo)
{
    cout << posNodo->etiq << "   ";
    posNodo = posNodo->hijoIzq;
    while(posNodo != 0)
    {
        ImprimirPreordenRec(posNodo);
        posNodo = posNodo->hermDer;
    }
}
