#include <iostream>
#include <new>
#include <stdlib.h>
//#include "Pila.h"
#include "Cola.h"
#include <windows.h>
#include <vector>
//#include "ArbolporCursores.h"
//#include "ArbolArregloPadre.h"
//#include "ArbolHmiHdApuntaPadre.h"
//#include "ArbolHmiHdApuntaHi.h"
#include "ArbolListaDeHijos.h"

typedef ArbolListaDeHijos Arbol;
//typedef ArbolporCursores Arbol;
//typedef Caja_etiqueta* nodo;
typedef Caja_etiqueta* nodo;
//typedef int nodo;

using namespace std;

Arbol Copiar(Arbol, Arbol);
nodo HermanoIzquierdo(Arbol, nodo );
void recorridoPorNiveles(Arbol );
int NumNiveles(Arbol);
int NumNivel(Arbol, char);
bool EtiquetasRepetidas(Arbol);
bool EtiquetasRepetidasRe(nodo,Arbol);
int AlturaNodo(Arbol, nodo);
void BorrarSubArbol(Arbol, nodo);
void BorrarSubArbolRe(Arbol, nodo);
void ListarIesimoNivel(Arbol, int);
vector<char> V;
void ListarHijos(nodo, Arbol);
void ListarPreorden(Arbol);
void ListarPreordenRec(nodo, Arbol);
nodo BuscarEtiqueta(char, Arbol);
nodo BuscarEtiqRec(char, nodo, Arbol);
bool Iguales(Arbol, Arbol);
void ListarPreordenPila(Arbol);
int ProfundidadNodo(Arbol, nodo);
void ListarIesimoNivel(Arbol, int);

template<class T, class Y>
class Par
{
public:
    Par() {}
    T tipo1;
    Y tipo2;
};

class Elemento
{
public:
    //Metodos
    Elemento(nodo n1,nodo n2)
    {
        siguiente=NULL;
        Par<nodo,nodo> par1;
        par1.tipo1 = n1;
        par1.tipo2 = n2;
        caja = par1;
    }
    void destruirTodo();
    // Atributos
    Par<nodo,nodo> caja;
    Elemento *siguiente;
};

void Elemento::destruirTodo()
{
    if(siguiente)
    {
        siguiente->destruirTodo();
    }
    delete this;
}

class Pila
{
public:
    //Operadores Basicos de la Pila
    void Iniciar();
    void Destruir();
    bool Vacia();
    void Vaciar();
    void Meter(Elemento*);
    void Sacar();
    Elemento* Tope();
    int NumeroElementos();
    //Atributos de la Pila
    Elemento* tope;
    int NumElem;

protected:
private:
};

void Pila::Iniciar()
{
    NumElem = 0;
    tope = NULL;
}

void Pila::Destruir()
{
    tope->destruirTodo();
    NumElem = -1;
}

bool Pila::Vacia()
{
    if (tope==NULL) return true;
    else return false;
}

void Pila::Vaciar()
{
    while (tope!=NULL)
    {
        tope=tope->siguiente;
        NumElem = 0;
    }
}

void Pila::Meter(Elemento* nuevo)
{
    nuevo->siguiente = tope;
    tope = nuevo;
    NumElem += 1;
}

void Pila::Sacar()
{
    if (tope!=NULL)
    {
        tope = tope->siguiente;
        NumElem -= 1;
    }
}

Elemento* Pila::Tope()
{
    return tope;
}

int Pila::NumeroElementos()
{
    return NumElem;
}

int main()
{
    SetConsoleTitle("Tarea Programada 1  |  Kevin Leon B53845  | Jorge Remon B55825  |  Daniel Varela B57474");
    system("COLOR 73");
    cout << "Digite el numero de modelo que desea utilizar\n1.    Cola\n2.    Pila\n3.    Arbol\n4.    Salir,\n\n En esta entrega se comentaron los modelos Pila y Cola, como lo propuso la profesora." << endl;
    Cola<nodo> c;
    Cola<char> C;
    Pila p;
    Arbol A;
    Arbol A2;
    p.Iniciar();
    int modelo;
    int nivel;
    char elem;
    char elem2;
    nodo traducido; //Descomentar al usar: Lista de hijos, ArbolHmiHdApuntaHi, ArbolHmiHdApuntaPadre.
    //nodo traducido;  //Descomentar al usar: ArbolporCursores, ArbolArregloPadre.
    int operador;
    do{
    cin >> modelo;
    }while(modelo > 4);
    system("cls");
    switch(modelo)
    {
    /*case 1:
        cout << "--Modelo Cola--" << endl << endl;
        cout << "1. Vacia (Retorna verdadero si la Cola esta vacia)\n2. Encolar (Requiere un parametro char)" <<
             "\n3. Desencolar (Elimina el elemento de frente)\n4. Frente\n5. NumElem\n6. Salir" << endl;
        cin >> operador;
        system("cls");
        do
        {
            switch(operador)
            {
            case 1:
                if(C.Vacia())
                {
                    cout << "La cola esta vacia." << endl << endl;
                }
                else
                {
                    cout << "La cola no esta vacia." << endl << endl;
                }
                break;
            case 2:
                cout << "Ingrese la etiqueta que desea encolar." << endl;
                cin >> elem;
                C.Encolar(elem);
                system("cls");
                break;
            case 3:
                C.Desencolar();
                cout << "Ha desencolado un elemento." << endl<<endl;
                break;
            case 4:
                if (!C.Vacia()) cout << "El frente de la cola es: " << C.Etiqueta(C.Frente()) << endl<<endl;
                else cout << "La cola esta vacia" << endl<<endl;
                break;
            case 5:
                cout << "El numero de elementos es: " << C.NumElem() << endl<<endl;
                break;
            case 6:
                break;
            default:
                cout << "Ingrese un numero valido." << endl;
            }
            if(operador!=6){
            cout << "--Modelo Cola--" << endl << endl;
            cout << "1. Vacia (Retorna verdadero si la Cola esta vacia)\n2. Encolar (Requiere un parametro char)" <<
            "\n3. Desencolar (Elimina el elemento de frente)\n4. Frente\n5. NumElem\n6. Salir" << endl;
            cin >> operador;
            system("cls");
            }
        }
        while(operador != 6);
        break;

    case 2:
        cout<<"--Modelo Pila--"<<endl << endl;
        cout << "1. Vacia (Retorna verdadero si la Pila esta vacia)\n2. Meter (Requiere un parametro char)" <<
             "\n3. Sacar (Saca el Elemento Tope de la Pila)\n4. Tope\n5. NumElem\n6. Salir" << endl;
        cin >> operador;
        system("cls");
        do
        {
            switch(operador)
            {
            case 1:
                if(p.Vacia())
                {
                    cout << "La pila esta vacia." << endl << endl;
                }
                else
                {
                    cout << "La pila no esta vacia." << endl << endl;
                }
                break;
            case 2:
                cout << "Ingrese la etiqueta que desea meter." << endl;
                cin >> elem;
                p.Meter(p.Traducir(elem));
                system("cls");
                break;
            case 3:
                p.Sacar();
                cout << "Ha sacado el tope y se ha asignado un nuevo tope." << endl<<endl;
                break;
            case 4:
                if (!p.Vacia())cout << "El tope de la pila es: " << p.Etiqueta(p.Tope()) << endl<<endl;
                else cout << "La pila esta vacia" << endl<<endl;
                break;
            case 5:
                cout << "El numero de elementos es: " << p.NumeroElementos() << endl <<endl;
                break;
            case 6:
                break;
            default:
                cout << "Ingrese un numero valido." << endl;
            }
            if(operador!=6){
            cout<<"--Modelo Pila--"<<endl << endl;
            cout << "1. Vacia (Retorna verdadero si la Pila esta vacia)\n2. Meter (Requiere un parametro char)" <<
             "\n3. Sacar (Saca el Elemento Tope de la Pila)\n4. Tope\n5. NumElem\n6. Salir" << endl;
            cin >> operador;
            system("cls");
            }
        }
        while(operador != 6);
        break;
*/
    case 3:
        cout<< "Para seleccionar el tipo de estructura de datos para el modelo arbol debe leer el manual de usuario." << endl <<endl;
        cout<<"--Modelo Arbol--"<<endl << endl;
          cout << "1. Vacio (Retorna verdadero si el arbol esta vacio)\n2. Poner Raiz (Requiere una etiqueta char)" <<
            "\n3. AgregarHijo (Requiere: una nueva etiqueta - etiqueta del padre )\n4. AgregarUltimoHijo (Requiere: una nueva etiqueta char - etiqueta del padre)\n"<<
            "5. BorrarHoja (Requiere la etiqueta de la hoja)\n6. ModificarEtiqueta (Requiere: la nueva etiqueta - la etiqueta a reemplazar)\n7. Raiz (Retorna la raiz del arbol)\n8. Padre (Retorna el padre de un hijo, requiere la etiqueda del nodo hijo)\n"<<
            "9. HijoMasIzquierdo (Requiere la etiqueta del nodo padre)\n10. HermanoDerecho (Requiere la etiqueta de un nodo al que se busca el hermano derecho)\n11. HermanoIzquierdo (Requiere la etiqueta de un nodo al que se le busca el hermano izquierdo.)"<<
            "\n12. Copiar (Copia A1 en A2)\n13. Recorrido por niveles (Imprimie el arbol recorriendolo por niveles)\n14. ProfundidadNodo (Requiere un nodo al que se le busca la profundidad)" <<
            "\n15. EtiquetasRepetidas (Cuenta la cantidad de etiquetas repetidas en un arbol \n16. AlturaNodo (Requiere un nodo al que le evalua la altitud) \n17. BorrarSubArbol (Requiere un nodo al que le borra un subarbol)\n18. ListarIesimoNivel (Lista los nodos de un nivel que entra como parametro)\n"
            "19. ListarHijos (Lista los hijos del nodo n)\n20. ListarPreorden (Imprime el arbol A en preorden)\n21. BuscarEtiqueta (Requiere la etiqueta a buscar y el arbol dode lo va a buscar)\n22. Iguales (Dice si el arbol A1 y el A2 son iguales)\n"
            "23. ListarPreordenPila (Simula la pila de la recursividad para imprimir el arbol A en preorden)\n24. ListarIesimoNivel (Requiere un entero que representa el nivel que desea listar) \n25.  ProfundidadNodo (Requiere la etiqueta del nodo al que se le calculará la profundidad)\n 26. Salir"<< endl;
            system("cls");
        do
        {
            switch(operador)
            {
            case 1:
                if(A.Vacio())
                {
                    cout << "El arbol esta vacio." << endl << endl;
                }
                else
                {
                    cout << "El arbol no esta vacio." << endl << endl;
                }
                break;
            case 2:
                cout << "Ingrese la etiqueta que desea poner a la raiz" << endl;
                cin >> elem;
                A.PonerRaiz(elem);
                system("cls");
                break;
            case 3:
                cout << "Ingrese la etiqueta del nuevo hijo" << endl;
                cin >> elem;
                system("cls");
                cout << "Ingrese la etiqueta del padre"<<endl;
                cin>>elem2;
                traducido = A.Traducir(elem2);
                A.AgregarHijo(elem, traducido);
                system("cls");
               break;
            case 4:
                cout << "Ingrese la etiqueta del nuevo hijo" << endl;
                cin >> elem;
                system("cls");
                cout << "Ingrese la etiqueta del padre"<<endl;
                cin>>elem2;
                traducido = A.Traducir(elem2);
                A.AgregarUltimoHijo(elem, traducido);
                system("cls");
                break;
            case 5:
                cout << "Ingrese la etiqueta de la hoja a borrar" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                A.BorrarHoja(traducido);
                system("cls");
                break;
            case 6:
                cout << "Ingrese la nueva etiqueta" << endl;
                cin >> elem;
                system("cls");
                cout << "Ingrese la etiqueta a reemplazar"<<endl;
                cin>>elem2;
                traducido = A.Traducir(elem2);
                A.ModificarEtiqueta(elem, traducido);
                system("cls");
                break;
            case 7:
                if(A.Vacio()==false){
                cout<<"La raiz del arbol es "<<A.Etiqueta(A.Raiz())<<endl;
                }else{
                cout<<"El arbol esta vacio."<<endl;
                }
                break;
            case 8:
                cout << "Ingrese la etiqueta del hijo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                cout<<"El padre de "<<elem<<" es "<<A.Etiqueta(A.Padre(traducido))<<endl;
                break;
            case 9:
                cout << "Ingrese la etiqueta del padre" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                cout<<"El hijo mas izquierdo de "<<elem<<" es "<<A.Etiqueta(A.HijoMasIzquierdo(traducido))<<endl;
               break;
            case 10:
                cout << "Ingrese la etiqueta del hijo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                cout<<"El hermano derecho de "<<elem<<" es "<<A.Etiqueta(A.HermanoDerecho(traducido))<<endl;
                break;
            case 11:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                cout<<"El hermano Izquierdo "<<elem<<" es "<<A.Etiqueta(HermanoIzquierdo(A, traducido))<<endl;
                break;
            case 12:
                A2 = Copiar(A, A2);
                recorridoPorNiveles(A2);
                recorridoPorNiveles(A);
                break;
            case 13:
                recorridoPorNiveles(A);
                break;
            case 14:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                cout<<"El nivel es: "<<ProfundidadNodo(A, traducido)<<endl;
                break;
            case 15:
                cout << EtiquetasRepetidas(A) << endl;
                break;
            case 16:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                cout << AlturaNodo(A,traducido);
                break;
            case 17:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                BorrarSubArbol(A, traducido);
                break;
            case 18:
                cout << "Ingrese el nivel a listar" << endl;
                cin >> nivel;
                system("cls");
                ListarIesimoNivel(A, nivel);
                break;
            case 19:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                ListarHijos(traducido,A);
                break;
            case 20:
                ListarPreorden(A);
                break;
            case 21:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = BuscarEtiqueta(elem,A);
                if(traducido==0){
                    cout<<"Nodo no encontrado."<<endl;
                }else{
                    cout<<"Nodo encontrado. "<<endl;
                }
                break;
            case 22:
                if(Iguales(A,A2))
                {
                    cout << "El Arbol 1 y el 2 son iguales." << endl;
                }
                else
                {
                    cout << "El Arbol 1 y el 2 son diferentes." << endl;
                }
                break;
            case 23:
                ListarPreordenPila(A);
                break;
            case 24:
                cout << "Ingrese el nivel que desea listar" << endl;
                cin >> nivel;
                system("cls");
                ListarIesimoNivel( A, nivel);
                break;
            case 25:
                cout << "Ingrese la etiqueta del nodo" << endl;
                cin >> elem;
                system("cls");
                traducido = A.Traducir(elem);
                ProfundidadNodo(A, traducido);
                break;
            case 26:
                break;
            default:
                cout << "Ingrese un numero valido." << endl;
            }
            if(operador != 26){
            cout<<"--Modelo Arbol--"<<endl << endl;
            cout << "1. Vacio (Retorna verdadero si el arbol esta vacio)\n2. Poner Raiz (Requiere una etiqueta char)" <<
            "\n3. AgregarHijo (Requiere: una nueva etiqueta - etiqueta del padre )\n4. AgregarUltimoHijo (Requiere: una nueva etiqueta char - etiqueta del padre)\n"<<
            "5. BorrarHoja (Requiere la etiqueta de la hoja)\n6. ModificarEtiqueta (Requiere: la nueva etiqueta - la etiqueta a reemplazar)\n7. Raiz (Retorna la raiz del arbol)\n8. Padre (Retorna el padre de un hijo, requiere la etiqueda del nodo hijo)\n"<<
            "9. HijoMasIzquierdo (Requiere la etiqueta del nodo padre)\n10. HermanoDerecho (Requiere la etiqueta de un nodo al que se busca el hermano derecho)\n11. HermanoIzquierdo (Requiere la etiqueta de un nodo al que se le busca el hermano izquierdo.)"<<
            "\n12. Copiar (Copia A1 en A2)\n13. Recorrido por niveles (Imprimie el arbol recorriendolo por niveles)\n14. ProfundidadNodo (Requiere un nodo al que se le busca la profundidad)" <<
            "\n15. EtiquetasRepetidas (Cuenta la cantidad de etiquetas repetidas en un arbol \n16. AlturaNodo (Requiere un nodo al que le evalua la altitud) \n17. BorrarSubArbol (Requiere un nodo al que le borra un subarbol)\n18. ListarIesimoNivel (Lista los nodos de un nivel que entra como parametro)\n"
            "19. ListarHijos (Lista los hijos del nodo n)\n20. ListarPreorden (Imprime el arbol A en preorden)\n21. BuscarEtiqueta (Requiere la etiqueta a buscar y el arbol dode lo va a buscar)\n22. Iguales (Dice si el arbol A1 y el A2 son iguales)\n"
            "23. ListarPreordenPila (Simula la pila de la recursividad para imprimir el arbol A en preorden)\n24. ListarIesimoNivel (Requiere un entero que representa el nivel que desea listar) \n25. ProfundidadNodo (Requiere la etiqueta del nodo al que se le calculará la profundidad)\n26. Salir"<< endl;
            cin >> operador;
            system("cls");
            }
        }
        while(operador != 26);
    break;

    case 4:
        cout << "Hasta Luego!" << endl;
        break;
    }

    return 0;
}

Arbol Copiar(Arbol A1, Arbol A2){
    if (A1.Vacio()==false) {
        Cola<nodo> C1;
        Cola<nodo> C2;
        A2.PonerRaiz(A1.Etiqueta(A1.Raiz()));
        C1.Encolar(A1.Raiz());
        C2.Encolar(A2.Raiz());
        nodo n1;
        nodo n2;
        nodo n2siguiente;
        nodo nh1;
        nodo nh2;
        while (!C1.Vacia()) {
            n1 = C1.Desencolar();
            n2 = C2.Desencolar();
            n2siguiente = n2;
            nh1 = A1.HijoMasIzquierdo(n1);
            while (nh1 != 0) {
                A2.AgregarUltimoHijo(A1.Etiqueta(nh1), n2);
                nh2 = A2.HijoMasIzquierdo(n2);
                n2siguiente = A2.HermanoDerecho(nh2);
                while (n2siguiente!=0)
                {
                    nh2 = A2.HermanoDerecho(nh2);
                    n2siguiente=A2.HermanoDerecho(nh2);
                }
                C1.Encolar(nh1);
                C2.Encolar(nh2);
                nh1 = A1.HermanoDerecho(nh1);
              }
        }
    }
    return A2;
}

nodo HermanoIzquierdo(Arbol A, nodo n){
    if(A.Etiqueta(A.Raiz()) == A.Etiqueta(n)){
        return 0;
    }else{
        nodo padre = A.Padre(n);
        nodo iteradorHijos = A.HijoMasIzquierdo(padre);
        nodo iteradorHijosSiguiente = iteradorHijos;
        if(A.Etiqueta(iteradorHijos)==A.Etiqueta(n)){
            return 0;
        }else{
            if(A.HermanoDerecho(iteradorHijos)!=0){
                iteradorHijosSiguiente = A.HermanoDerecho(iteradorHijos);
            }
        bool encontrado = false;
        while (encontrado ==false){
            if(A.Etiqueta(iteradorHijosSiguiente) == A.Etiqueta(n)){
                encontrado=true;
            }else{
            iteradorHijos=iteradorHijosSiguiente;
            iteradorHijosSiguiente=A.HermanoDerecho(iteradorHijosSiguiente);
            }
        }
        return iteradorHijos;
        }
    }
}

void recorridoPorNiveles(Arbol A){
    nodo n = A.Raiz();
    nodo nh;
    if(A.Vacio()==false){
        cout<<"El arbol es: ";
        Cola<nodo> C;
        C.Encolar(n);
        while(C.Vacia()==false){
            n = C.Desencolar();
            cout<<" "<< A.Etiqueta(n);
            nh = A.HijoMasIzquierdo(n);
                while(nh!=0){
                    C.Encolar(nh);
                    nh=A.HermanoDerecho(nh);
                }
        }
        cout<<endl;
    }else{
        cout<<"Arbol vacio"<<endl;
    }
}

bool EtiquetasRepetidas (Arbol A)
{
     bool resultado = true;
    if (!A.Vacio())
    {
        resultado = EtiquetasRepetidasRe(A.Raiz(), A);
    }
    return resultado;
}

bool EtiquetasRepetidasRe(nodo N, Arbol A)
{
    bool repetido = false;
    int i = 0;
    while (!repetido && i<V.size())
    {
        if (A.Etiqueta(N)==V[i])
        {
            repetido = true;
        }
        ++i;
    }
    if (!repetido)
    {
        V.push_back(A.Etiqueta(N));
        N = A.HijoMasIzquierdo(N);
        while (N!=0 && !repetido)
        {
            repetido = EtiquetasRepetidasRe(N, A);
            N = A.HermanoDerecho(N);
        }
    }
    return repetido;
}

int AlturaNodo(Arbol A, nodo N)
{
    int contador = 0;
    N = A.HijoMasIzquierdo(N);
    ++contador;
    while(A.HijoMasIzquierdo(N)!=0 && !A.EsHoja(N) && A.HermanoDerecho(N)!=0)
    {
        contador += AlturaNodo(A,N);
        N = A.HermanoDerecho(N);
    }
    return contador;
}

void BorrarSubArbol(Arbol A, nodo N)
{
    if(!A.Vacio() && N!=0)
    {
        BorrarSubArbolRe(A, N);
        A.BorrarHoja(N);
    }
}
void BorrarSubArbolRe(Arbol A, nodo N)
{
    N = A.HijoMasIzquierdo(N);
    while (N!=0)
    {
        if (A.HermanoDerecho(N)==0 && A.EsHoja(N))
        {
            nodo NH = A.Padre(N);
            A.BorrarHoja(N);
            BorrarSubArbolRe(A,NH);
        }
        else BorrarSubArbolRe(A,N);
        N = A.HermanoDerecho(N);
    }
}

void ListarHijos(nodo posNodo, Arbol a)
{
    posNodo = a.HijoMasIzquierdo(posNodo);
    if(posNodo != 0)
    {
        while(posNodo != 0)
        {
            cout << a.Etiqueta(posNodo) << "   ";
            posNodo = a.HermanoDerecho(posNodo);
        }
        cout << endl;
    }
}

void ListarPreorden(Arbol a)
{
    if(!a.Vacio())
    {
        ListarPreordenRec(a.Raiz(), a);
    }
}

void ListarPreordenRec(nodo posNodo, Arbol a)
{
    cout << a.Etiqueta(posNodo) << "   ";
    posNodo = a.HijoMasIzquierdo(posNodo);
    while(posNodo != 0)
    {
        ListarPreordenRec(posNodo,a);
        posNodo = a.HermanoDerecho(posNodo);
    }
}

nodo BuscarEtiqueta(char etiq, Arbol a)
{
    if(!a.Vacio())
    {
        nodo posNodo = a.Raiz();
        return BuscarEtiqRec(etiq,posNodo,a);
    }
    else
    {
        return 0;
    }
}

nodo BuscarEtiqRec(char etiq, nodo posNodo, Arbol a)
{
    if(a.Etiqueta(posNodo) == etiq)
    {
        return posNodo;
    }
    else
    {
        nodo posNodo3;
        nodo posNodo2 = a.HijoMasIzquierdo(posNodo);
        if (posNodo2!=0)
        {
            posNodo3 = posNodo2;
        }
        while(posNodo2 != 0)
        {
            posNodo2 = BuscarEtiqRec(etiq, posNodo2, a);
            if (posNodo2 == 0)
            {
                posNodo2 = a.HermanoDerecho(posNodo3);
                posNodo3 = posNodo2;
            }
            else
            {
                if (a.Etiqueta(posNodo2) != etiq)
                {
                    posNodo2 = a.HermanoDerecho(posNodo2);
                }
                else
                {
                    return posNodo2;
                }
            }
        }
        return posNodo2;
    }
}

bool Iguales(Arbol a1, Arbol a2)
{
    if(a1.Etiqueta(a1.Raiz()) != a2.Etiqueta(a2.Raiz()))
    {
        return false;
    }
    else
    {
        Cola<nodo> c1;
        Cola<nodo> c2;
        c1.Encolar(a1.Raiz());
        c2.Encolar(a2.Raiz());
        bool igual = true;
        while((!c1.Vacia()) && (igual))
        {
            nodo nh1 = a1.HijoMasIzquierdo(c1.Desencolar());
            nodo nh2 = a2.HijoMasIzquierdo(c2.Desencolar());
            while((nh1 != 0) && (igual))
            {
                if(a1.Etiqueta(nh1) != a2.Etiqueta(nh2))
                {
                    igual = false;
                }
                else
                {
                    c1.Encolar(nh1);
                    c2.Encolar(nh2);
                    nh1 = a1.HermanoDerecho(nh1);
                    nh2 = a2.HermanoDerecho(nh2);
                }
            }
        }
        return igual;
    }
}
void ListarPreordenPila(Arbol a)
{
	if(!a.Vacio())
	{
    		Pila p;
    		cout << a.Etiqueta(a.Raiz()) << "   ";
    		nodo n1 = a.Raiz();
    		nodo n2 = a.HijoMasIzquierdo(n1);
    		Elemento *e = new Elemento(n1,n2);
    		p.Meter(e);
    		do
    		{
        		if((p.Tope()->caja.tipo1 == a.Raiz())&&(p.Tope()->caja.tipo2 == 0))
        		{
            		p.Vaciar();
        		}
        		else
        		{
            		if(p.Tope()->caja.tipo2 == 0)
            		{
                		p.Sacar();
                		if((a.HermanoDerecho(p.Tope()->caja.tipo2)!=0))
                		{
                    		p.Tope()->caja.tipo2 = a.HermanoDerecho(p.Tope()->caja.tipo2);
                		}
                		else
                		{
                    		p.Sacar();
                    		if(p.Tope() != 0)
                    		{
                        	if((p.Tope()->caja.tipo1 == a.Raiz())&&(a.HermanoDerecho(p.Tope()->caja.tipo2) == 0))
                        	{
                            	p.Tope()->caja.tipo2 = 0;
                        	}
                        	else
                        	{
                            	p.Tope()->caja.tipo2 = a.HermanoDerecho(p.Tope()->caja.tipo2);
                        	}
                    	}
                	}
            	}
            	else
            	{
                	cout << a.Etiqueta(p.Tope()->caja.tipo2) << "   ";
                	n1 = p.Tope()->caja.tipo2;
                	n2 = a.HijoMasIzquierdo(n1);
                	e = new Elemento(n1,n2);
                	p.Meter(e);
            	}
        	}
    	}
    	while(!p.Vacia());
    	cout << endl;
	}
}


void ListarIesimoNivel(Arbol A, int n)
{
    if (!A.Vacio())
    {
        Par<int, nodo> p;
        p.tipo2 = A.Raiz();
        p.tipo1 = 1;
        Cola< Par<int, nodo> > C;
        C.Encolar(p);
        while(!C.Vacia()){
            p = C.Desencolar();
            if (p.tipo1 == n) cout<<" "<< A.Etiqueta(p.tipo2);
            nodo nh = A.HijoMasIzquierdo(p.tipo2);
            p.tipo1 = p.tipo1 + 1;
            while (nh != 0)
            {
                p.tipo2 = nh;
                C.Encolar(p);
                nh = A.HermanoDerecho(p.tipo2);
            }
        }
    }
}

int ProfundidadNodo(Arbol A, nodo N)
{
    int profundidad = 1;
    if (!A.Vacio())
    {
        while (N!=A.Raiz())
        {
            ++profundidad;
            N=A.Padre(N);
        }
    }
    return profundidad;
}
