#include "ArbolArregloPadre.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

/**
Constructor que inicializa la raiz del arbol
No recibe parametros
No devuelve nada
*/
ArbolArregloPadre::ArbolArregloPadre()
{
    ultLleno = -1;
}

/**
Destructor que borra completamente el arbol
No recibe parametros
No devuelve nada
*/
ArbolArregloPadre::~ArbolArregloPadre()
{
    ultLleno = -1;
}

/**
Vaciar borra todas las etiquetas del arbol
No recibe parametros
No devuelve nada
*/
void ArbolArregloPadre::Vaciar()
{
    ultLleno = -1;
}

/**
Vacio revisa si el arbol esta vacio
No recibe parametros
Devuelve un booleano
*/
bool ArbolArregloPadre::Vacio()
{
    if(ultLleno == -1)
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
void ArbolArregloPadre::PonerRaiz(char elem)
{
    ultLleno = 1;
    arbol[ultLleno].etiq = elem;
    arbol[ultLleno].father = -1;
}

/**
AgregarHijo le agrega un hijo mas izquierdo al nodo indicado
Recibe la etiqueta a poner al nodo nuevo y el nodo del que va a ser hijo
No devuelve nada
*/
void ArbolArregloPadre::AgregarHijo(char elem,nodo nPadre)
{
    ultLleno++;
    arbol[ultLleno].etiq = elem;
    arbol[ultLleno].father = nPadre;
}

/**
AgregarUltHijo le agrega un hijo mas derecho al nodo indicado
Recibe la etiqueta a poner al nodo nuevo y el nodo del que va a ser hijo
No devuelve nada
*/
void ArbolArregloPadre::AgregarUltimoHijo(char elem,nodo nPadre)
{
    ultLleno++;
    arbol[ultLleno].etiq = elem;
    arbol[ultLleno].father = nPadre;
}

/**
BorrarHoja borra el nodo indicado solo si es una hoja
Recibe el nodo a borrar
No devuelve nada
*/
void ArbolArregloPadre::BorrarHoja(nodo elem)
{
    if(EsHoja(elem))
    {
            for(nodo j=elem;j<=ultLleno;j++)
            {
            arbol[j].etiq = arbol[j+1].etiq;
            arbol[j].father = arbol[j+1].father;
            }
            ultLleno--;
            for(nodo k=elem;k<=ultLleno;k++)
            {
                if(arbol[k].father>elem)
                {
                    arbol[k].father--;
                }
            }
    }
    else
    {
        cout << "El nodo no es una hoja y no se puede borrar." << endl;
    }
}

/**
ModificarEtiqueta cambia la etiqueta de un nodo
Recibe la etiqueta a cambiar al nodo y el nodo al que se le quiere cambiar
No devuelve nada
*/
void ArbolArregloPadre::ModificarEtiqueta(char elem,nodo pos)
{
    arbol[pos].etiq = elem;
}

/**
Raiz busca la raiz del arbol
No recibe nada
Devuelve un nodo
*/
nodo ArbolArregloPadre::Raiz()
{
    if(!Vacio())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/**
Padre busca el padre del nodo indicado
Recibe el nodo al que le va a buscar el padre
Devuelve un nodo
*/
nodo ArbolArregloPadre::Padre(nodo elem)
{
    return arbol[elem].father;
}

/**
HijoMasIzquierdo devuelve el primer hijo del nodo indicado
Recibe el nodo al que le va a buscar el hijo mas izquierdo
Devuelve un nodo
*/
nodo ArbolArregloPadre::HijoMasIzquierdo(nodo elem)
{
    nodo j = elem+1;
    while((j != ultLleno) && (arbol[j].father != elem))
    {
        j++;
    }
    if(arbol[j].father == elem)
    {
        return j;
    }
    else
    {
        return -1;
    }
}

/**
HermanoDerecho busca el hermano derecho del nodo indicado
Recibe el nodo al que le va a buscar el hermano derecho
Devuelve un nodo
*/
nodo ArbolArregloPadre::HermanoDerecho(nodo elem)
{
    nodo j = elem+1;
    while((j != ultLleno) && (arbol[elem].father != arbol[j].father))
    {
        j++;
    }
    if(arbol[elem].father == arbol[j].father)
    {
        return j;
    }
    else
    {
        return -1;
    }
}

/**
Etiqueta devuelve la etiqueta del nodo indicado
Recibe el nodo al que le va a buscar la etiqueta
Devuelve un nodo
*/
char ArbolArregloPadre::Etiqueta(nodo i)
{
    return arbol[i].etiq;
}

/**
EsHoja dice si un nodo del arbol es hoja
Recibe el nodo al que se desea saber si es hoja
Devuelve un booleano
*/
bool ArbolArregloPadre::EsHoja(nodo elem)
{
    bool hoja = false;
    nodo j = elem+1;
    while((arbol[j].father != elem) && (j != ultLleno+1))
    {
        j++;
    }
    if(j == ultLleno+1)
    {
        hoja = true;
    }
    return hoja;
}

/**
ImprimirArbol imprime las etiquetas con su padre respectivo
No recibe nada
No devuelve nada
*/
void ArbolArregloPadre::ImprimirArbol()
{
    for(nodo i=1; i<=ultLleno; i++)
    {
        cout << arbol[i].etiq << "   ";
    }
    cout << endl;
    for(nodo j=1; j<=ultLleno; j++)
    {
        cout << arbol[j].father << "   ";
    }
    cout << endl;
}

/**
Traducir traduce las etiquetas en sus respectivos nodos
Recibe el elemento que se va a buscar en el arbol
Devuelve un nodo
*/
int ArbolArregloPadre::Traducir(char pos)
{
    int i = 1;
    while(arbol[i].etiq != pos)
    {
        i++;
    }
    return i;
}
