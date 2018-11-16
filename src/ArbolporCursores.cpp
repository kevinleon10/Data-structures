#include "ArbolporCursores.h"
#include <sstream>

using namespace std;


/*
Inicializa el array que contiene los nodos del Arbol y los atributos del Arbol. Ademas asigna los siguientes disponibles
Recibe el tamano del arreglo
No devuelve nada
*/
ArbolporCursores::ArbolporCursores()
{
    int m = 30;
    arbol = new Caja[m+1];
    pilaD = 1;
    int i = 1;
    while (i<=m)
    {
        if (i<m)
        {
            arbol[i].hd = i + 1;
        }
        if (i==m)
        {
            arbol[i].hd = NULL;
            ultimaPilaD = i;
        }
        ++i;
    }
    tamano = m;
}


/*
Destruye el array y le asigna -1 a los atributos
No recibe nada
No devuelve nada
*/
void ArbolporCursores::Destruir()
{
    delete arbol;
    pilaD = -1;
    tamano = -1;
    ultimaPilaD = -1;
}


/*
Vacia el arbol
No recibe nada
No devuelve nada
*/
void ArbolporCursores::Vaciar()
{
    delete arbol;
    arbol = new Caja[tamano+1];
    pilaD = 1;
    int i = 1;
    while (i<=tamano)
    {
        if (i<tamano)
        {
            arbol[i].hd = i + 1;
        }
        if (i==tamano)
        {
            arbol[i].hd = NULL;
            ultimaPilaD = i;
        }
        ++i;
    }
}


/*
Se fija si el arbol esta vacio
No recibe nada
Devuelve un booleano
*/
bool ArbolporCursores::Vacio()
{
    if (pilaD==1) return true;
    else return false;
}


/*
Le asigna Etiqueta a la Raiz
Recibe una Etiqueta
No devuelve nada
*/
void ArbolporCursores::PonerRaiz(char elem)
{
    pilaD = arbol[1].hd;
    arbol[1].etiq = elem;
    arbol[1].hmi = NULL;
    arbol[1].hd = NULL;
}

/*
Convierte de Etiqueta a nodo
Recibe un char
Devuelve un nodo
*/
int ArbolporCursores::Traducir(char elem)
{
    int i=0;
    while(arbol[i].etiq!=elem && i<=tamano)
    {
        ++i;
    }
    if (arbol[i].etiq==elem)
    {
        return i;
    }
    else return 0;
}


/*
Le agrega un nodo como Hijo Mas Izquierdo a otro nodo
Recibe una Etiqueta y un nodo
No devuelve nada
*/
void ArbolporCursores::AgregarHijo(char elem, int Padre)
{
    if(pilaD!=0)
    {
        if (Padre<=tamano)
        {
            if (arbol[Padre].hmi==NULL)
            {
                arbol[Padre].hmi = pilaD;
                arbol[pilaD].etiq = elem;
                arbol[pilaD].hmi = NULL;
                int temp = pilaD;
                pilaD = arbol[pilaD].hd;
                arbol[temp].hd = NULL;
            }
            else
            {
                int temp = arbol[Padre].hmi;
                arbol[Padre].hmi = pilaD;
                arbol[pilaD].etiq = elem;
                arbol[pilaD].hmi = NULL;
                int temp2 = pilaD;
                pilaD = arbol[pilaD].hd;
                arbol[temp2].hd = temp;
            }
            if (ultimaPilaD==pilaD) ultimaPilaD=0;
        }
    }
}


/*
Le agrega un nodo como Ultimo Hijo a otro nodo
Recibe una Etiqueta y un nodo
No devuelve nada
*/
void ArbolporCursores::AgregarUltimoHijo(char elem, int Padre)
{
    if (pilaD!=0)
    {
        if (Padre<=tamano)
        {
            if (arbol[Padre].hmi==NULL)
            {
                arbol[Padre].hmi = pilaD;
                arbol[pilaD].etiq = elem;
                arbol[pilaD].hmi = NULL;
                int temp = pilaD;
                pilaD = arbol[pilaD].hd;
                arbol[temp].hd = NULL;
            }
            else
            {
                if (arbol[arbol[Padre].hmi].hd==NULL)
                {
                    arbol[arbol[Padre].hmi].hd = pilaD;
                    arbol[pilaD].etiq = elem;
                    arbol[pilaD].hmi = NULL;
                    int temp = pilaD;
                    pilaD = arbol[pilaD].hd;
                    arbol[temp].hd = NULL;
                }
                else
                {
                    int j = arbol[Padre].hmi;
                    while(arbol[j].hd!=NULL)
                    {
                        j = arbol[j].hd;
                    }
                    arbol[j].hd = pilaD;
                    arbol[pilaD].etiq = elem;
                    arbol[pilaD].hmi = NULL;
                    int temp = pilaD;
                    pilaD = arbol[pilaD].hd;
                    arbol[temp].hd = NULL;
                }
            }
            if (ultimaPilaD==pilaD) ultimaPilaD=0;
        }
    }
}


/*
Devuelve si un nodo es una Hoja(No tiene Hijos)
Recibe un nodo
Devuelve un booleano
*/
bool ArbolporCursores::EsHoja(int elem)
{
    bool hoja = false;
    if (elem<=tamano)
    {
        if (arbol[elem].hmi==NULL)
        {
            hoja = true;
        }
    }
    return hoja;
}


/*
Borra un nodo si es una Hoja
Recibe un nodo
No devuelve nada
*/
void ArbolporCursores::BorrarHoja(int elem)
{
    if (elem<=tamano)
    {
        if(EsHoja(elem))
        {
            arbol[elem].etiq = NULL;
            if (ultimaPilaD==NULL)
            {
                ultimaPilaD = elem;
                int j = 1;
                while (elem!=arbol[j].hd && elem!=arbol[j].hmi)
                {
                    ++j;
                }
                if(elem==arbol[j].hd)
                {
                    arbol[j].hd = arbol[elem].hd;
                }
                else if (elem==arbol[j].hmi)
                {
                    arbol[j].hmi = arbol[elem].hd;
                }
            }
            else
            {
                arbol[ultimaPilaD].hd = elem;
                ultimaPilaD = elem;
                int j = 1;
                while (elem!=arbol[j].hd && elem!=arbol[j].hmi)
                {
                    ++j;
                }
                if(elem==arbol[j].hd)
                {
                    arbol[j].hd = arbol[elem].hd;
                }
                else if (elem==arbol[j].hmi)
                {
                    arbol[j].hmi = arbol[elem].hd;
                }
            }
            arbol[elem].hd = 0;
        }
    }

}


/*
Modifica la Etiqueta de un nodo
Recibe una Etiqueta y un nodo
No devuelve nada
*/
void ArbolporCursores::ModificarEtiqueta(char etiqueta, int elem)
{
    if (elem<=tamano)
    {
        arbol[elem].etiq = etiqueta;
    }
}


/*
Devuelve la Raiz
No recibe nada
Devuelve un nodo
*/
int ArbolporCursores::Raiz()
{
    return 1;
}


/*
Devulve el Padre de un nodo
Recibe un nodo
Devuelve un nodo
*/
int ArbolporCursores::Padre(int elem)
{
    int i = 1;
    while (arbol[i].hmi!=elem && i<=tamano)
    {
        ++i;
    }
    if (i>tamano)
    {
        int j = 1;
        while (arbol[j].hd!=elem && j<=tamano)
        {
            ++j;
        }
        if (j>tamano)
        {
            return 0;
        }
        else Padre(j);
    }
    else
    {
        return i;
    }
}


/*
Devuelve el Hijo Mas Izquierdo del nodo
Recibe un nodo
Devuelve un nodo
*/
int ArbolporCursores::HijoMasIzquierdo(int elem)
{
    if (elem<=tamano)
    {
        return arbol[elem].hmi;
    }
}


/*
Devuelve el Hermano Derecho del nodo
Recibe un nodo
Devuelve un nodo
*/
int ArbolporCursores::HermanoDerecho(int elem)
{
    if (elem<=tamano)
    {
        return arbol[elem].hd;
    }
}


/*
Devuelve la etiqueta de un nodo
Recibe un nodo
Devuelve una Etiqueta
*/
char ArbolporCursores::Etiqueta(int elem)
{
    if (elem<=tamano)
    {
        return arbol[elem].etiq;
    }
}


/*
Imprime el Array
No recibe nada
No devuelve nada
*/
void ArbolporCursores::Imprimir()
{
    cout << "Pos" << "  HMI" << "   " << "Etiq" << "  " << "HD-SD" << endl;
    for (int i=1; i<=tamano; ++i)
    {
        cout << i << "     " << arbol[i].hmi << "      " << arbol[i].etiq << "      " << arbol[i].hd << endl;
    }
}
