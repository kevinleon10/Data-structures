#ifndef ARBOLARREGLOPADRE_H
#define ARBOLARREGLOPADRE_H
typedef int nodo;

class ArbolArregloPadre
{
public:
    ArbolArregloPadre();
    virtual ~ArbolArregloPadre();
    void Vaciar();
    bool Vacio();
    void PonerRaiz(char);
    void AgregarHijo(char,nodo);
    void AgregarUltimoHijo(char,nodo);
    void BorrarHoja(nodo);
    void ModificarEtiqueta(char,nodo);
    nodo Raiz();
    nodo Padre(nodo);
    nodo HijoMasIzquierdo(nodo);
    nodo HermanoDerecho(nodo);
    char Etiqueta(nodo);
    bool EsHoja(nodo);
    void ImprimirArbol();
    int Traducir(char);

    struct cajaArray
    {
        char etiq;
        int father;

        cajaArray() {}
        cajaArray(char a, int b)
        {
            etiq=a;
            father=b;
        }
        ~cajaArray() {}
    };
    cajaArray arbol[50];
    int ultLleno;
protected:
private:
};

#endif // ARBOLARREGLOPADRE_H

