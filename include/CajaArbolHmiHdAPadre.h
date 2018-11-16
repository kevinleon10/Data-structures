#ifndef NODOARBOLHMIHDAPADRE_H
#define NODOARBOLHMIHDAPADRE_H

class CajaArbolHmiHdAPadre
{
    public:
        CajaArbolHmiHdAPadre(char);
        virtual ~CajaArbolHmiHdAPadre();

        char etiq;
        CajaArbolHmiHdAPadre *hermDer;
        CajaArbolHmiHdAPadre *hijoIzq;
        CajaArbolHmiHdAPadre *padre;
    protected:
    private:
};

#endif // NODOARBOLHMIHDAPADRE_H
