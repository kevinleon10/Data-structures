#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <iostream>

class Elemento
{
    public:
    //Metodos
    Elemento(char);
    void destruirTodo();

    // Atributos
    char etiqueta;
    Elemento *siguiente;

    protected:
    private:
};

#endif // ELEMENTO_H
