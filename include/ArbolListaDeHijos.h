#ifndef ARBOLLISTADEHIJOS_H
#define ARBOLLISTADEHIJOS_H
#include <Caja_etiqueta.h>
#include <Nodo_puntero.h>
#include "iostream"
typedef Caja_etiqueta* nodo;

using namespace std;
class ArbolListaDeHijos
{
    public:
        ArbolListaDeHijos();
        virtual ~ArbolListaDeHijos();
        void Vaciar();
        bool Vacio();
        void AgregarHijo(char, nodo);
        void AgregarUltimoHijo( char, nodo);
        void BorrarHoja(nodo);
        void PonerRaiz(char);
        nodo Raiz();
        nodo Padre(nodo);
        nodo HijoMasIzquierdo(nodo);
        nodo HermanoDerecho(nodo);
        char Etiqueta(nodo);
        void ModificarEtiqueta( char, nodo);
        bool EsHoja(nodo);
        nodo Traducir(char);
        int numElem();
        nodo HijoMasDerecho(nodo);

        nodo raizArbol = 0;
        int numNodos =0;

    protected:

    private:
};

#endif // ARBOLLISTADEHIJOS_H

