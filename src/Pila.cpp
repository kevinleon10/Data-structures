#include "Pila.h"
#include <sstream>

using namespace std;


/*
Metodo que inicializa los atributos de la Pila
No recibe nada
No devuelve nada
*/
void Pila::Iniciar()
{
    NumElem = 0;
    tope = NULL;
}


/*
Destruye cada Elemento de la Pila, llamando el Destructor de todos los Elementos
No recibe nada
No devuelve nada
*/
void Pila::Destruir()
{
    tope->destruirTodo();
    NumElem = -1;
}


/*
Devuelve si la Pila esta vacia
No recibe nada
Devuelve un booleano
*/
bool Pila::Vacia()
{
    if (tope==NULL) return true;
    else return false;
}


/*
Vacia la Pila, elemento por elemento
No recibe nada
No devuelve nada
*/
void Pila::Vaciar()
{
    while (tope!=NULL)
    {
        tope=tope->siguiente;
        NumElem = 0;
    }
}


/*
Transforma de tipo char a tipo Elemento
Recibe una Etiqueta
Devuelve un Elemento
*/
Elemento* Pila::Traducir(char eti)
{
    Elemento* nuevo = new Elemento(eti);
    return nuevo;
}


/*
Mete un Elemento en la Pila, cambiando el Tope
Recibe un Elemento
No devuelve nada
*/
void Pila::Meter(Elemento* nuevo)
{
    nuevo->siguiente = tope;
    tope = nuevo;
    NumElem += 1;
}


/*
Saca el Tope de la Pila, cambiando el Tope
No recibe nada
No devuelve nada
*/
void Pila::Sacar()
{
    if (tope!=NULL)
    {
        tope = tope->siguiente;
        NumElem -= 1;
    }
}


/*
Devuelve el Tope de la Pila
No recibe nada
Devuelve un Elemento
*/
Elemento* Pila::Tope()
{
    return tope;
}


/*
Devuelve el numero de Elementos de la Pila
No recibe nada
Devuelve un int
*/
int Pila::NumeroElementos()
{
    return NumElem;
}


/*
Devuelve la Etiqueta del Tope
Recibe un Elemento
No devuelve nada
*/
char Pila::Etiqueta(Elemento* TOP)
{
    return TOP->etiqueta;
}
