#ifndef ARBOLHMIHDAPUNTAPADRE_H
#define ARBOLHMIHDAPUNTAPADRE_H
#include "CajaArbolHmiHdAPadre.h"
typedef CajaArbolHmiHdAPadre nodo;

class ArbolHmiHdApuntaPadre
{
public:
    ArbolHmiHdApuntaPadre();
    virtual ~ArbolHmiHdApuntaPadre();
    void Vaciar();
    bool Vacio();
    void PonerRaiz(char);
    void AgregarHijo(char,nodo*);
    void AgregarUltimoHijo(char,nodo*);
    void BorrarHoja(nodo*);
    void ModificarEtiqueta(char,nodo*);
    nodo* Raiz();
    nodo* Padre(nodo*);
    nodo* HijoMasIzquierdo(nodo*);
    nodo* HermanoDerecho(nodo*);
    char Etiqueta(nodo*);
    bool EsHoja(nodo*);
    nodo* Traducir(char);
    nodo* BuscarPreordenRec(nodo*,char);
    void ImprimirPreorden();
    void ImprimirPreordenRec(nodo*);
    void DestruirRec(nodo*);

    nodo *raizArbol;
protected:
private:
};

#endif // ARBOLHMIHDAPUNTAPADRE_H
