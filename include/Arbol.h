#ifndef ARBOL_H
#define ARBOL_H
#include <Nodo_etiqueta.h>
#include <Nodo_puntero.h>

class Arbol
{
       public:
        Arbol();
        virtual ~Arbol();
        void Vaciar();
        bool Vacio();
        void AgregarHijo(char, Nodo_etiqueta *);
        void AgregarUltimoHijo( char, Nodo_etiqueta *);
        void BorrarHoja(Nodo_etiqueta *);
        void PonerRaiz(char);
        Nodo_etiqueta* Raiz();
        Nodo_etiqueta* Padre(Nodo_etiqueta *);
        Nodo_etiqueta* HijoMasIzquierdo(Nodo_etiqueta *);
        Nodo_etiqueta* HermanoDerecho(Nodo_etiqueta *);
        char Etiqueta(Nodo_etiqueta *);
        void ModificarEtiqueta( char, Nodo_etiqueta *);
        bool EsHoja(Nodo_etiqueta *);

        Nodo_etiqueta *nodo;

        Nodo_etiqueta* traducir(char);

    protected:
    private:
};

#endif // ARBOL_H
