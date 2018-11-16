#include "Elemento.h"


/*
Constructor del elemento, asigna al Siguiente nulo y le da Etiqueta al actual
Recibe una Etiqueta
No devuelve nada
*/
Elemento::Elemento(char eti){
    siguiente=NULL;
    etiqueta = eti;
}


/*
Destructor de todos los Elementos
No recibe nada
No devuelve nada
*/
void Elemento::destruirTodo()
{
    if(siguiente)
    {
        siguiente->destruirTodo();
    }
    delete this;
}
