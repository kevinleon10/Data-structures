#ifndef CAJAARBOLHMIHDAPUNTAHI_H
#define CAJAARBOLHMIHDAPUNTAHI_H

class CajaArbolHmiHdApuntaHi
{
    public:
        CajaArbolHmiHdApuntaHi(char);
        virtual ~CajaArbolHmiHdApuntaHi();

        char etiq;
        CajaArbolHmiHdApuntaHi *hijoIzq;
        CajaArbolHmiHdApuntaHi *hermDer;
        CajaArbolHmiHdApuntaHi *padre;
        CajaArbolHmiHdApuntaHi *hermIzq;
    protected:
    private:
};

#endif // CAJAARBOLHMIHDAPUNTAHI_H
