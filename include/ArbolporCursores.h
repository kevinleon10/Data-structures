#ifndef ARBOLPORCURSORES_H
#define ARBOLPORCURSORES_H
#include <iostream>

using namespace std;

class ArbolporCursores
{
    public:
        //Operadores Basicos del Arbol
        ArbolporCursores();
        void Destruir();
        void Vaciar();
        bool Vacio();
        void PonerRaiz(char);
        int Traducir(char);
        void AgregarHijo(char, int);
        void AgregarUltimoHijo(char, int);
        bool EsHoja(int);
        void BorrarHoja(int);
        void ModificarEtiqueta(char, int);
        int Raiz();
        int Padre(int);
        int HijoMasIzquierdo(int);
        int HermanoDerecho(int);
        char Etiqueta(int);
        void Imprimir();

        struct Caja
        {
            char etiq;
            int hmi;
            int hd;

            Caja() {}
            ~Caja() {}
        };

        //Atributos
        Caja* arbol;
        int pilaD;
        int ultimaPilaD;
        int tamano;

    protected:
    private:
};

#endif // ARBOLPORCURSORES_H
