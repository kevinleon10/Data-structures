//#include "Cola.h"
//
//
///*
//Metodo que inicializa los atributos de la Cola
//No recibe nada
//No devuelve nada
//*/
//Cola::Cola()
//{
//    tamMaximo=30;
//    numElementos=0;
//    primero=0;
//    ultimo=-1;
//}
//
///*
//Pone en cero todos los elementos de la cola.
//No recibe nada
//No devuelve nada
//*/
//Cola::~Cola()
//{
//    numElementos=0;
//    primero=0;
//    ultimo=0;
//}
//
///*
//Devuelve si la cola esta vacia
//No recibe nada
//Devuelve un booleano
//*/
//bool Cola::Vacia()
//{
//    bool vacia;
//    if(numElementos==0){
//        vacia=true;
//    }else{
//        vacia=false;
//    }
//    return vacia;
//}
//
///*
//Mete un Elemento en la Cola, cambiando el Frente
//Recibe un Elemento
//No devuelve nada
//*/
//void Cola::Encolar(nodo *elemento){
//    if(numElementos<tamMaximo){
//        if(ultimo==tamMaximo){
//            ultimo=-1;
//        }
//        numElementos=numElementos+1;
//        ultimo=ultimo+1;
//        cola[ultimo]=elemento;
//    }
//}
//
///*
//Saca el Frente de la Cola, cambiando el Frente.
//No recibe nada
//No devuelve nada
//*/
//nodo* Cola::Desencolar(){
//    nodo *elementoRecuperado;
//    if(numElementos>0){
//        numElementos=numElementos-1;
//        elementoRecuperado = cola[primero];
//        if(primero==tamMaximo){
//            primero=0;
//        }
//        primero=primero+1;
//    }
//    return elementoRecuperado;
//}
//
///*
//Devuelve el Frente de la Cola
//No recibe nada
//Devuelve un Elemento
//*/
//int Cola::Frente(){
//    return primero;
//}
//
///*
//Devuelve el numero de elementos
//No recibe nada
//Devuelve un entero
//*/
//int Cola::NumElem(){
//    return numElementos;
//}
//
///*
//Devuelve el elemento de una posicion
//Recibe una posicion de la cola(frente)
//Devuelve un char
//*/
//nodo* Cola::Etiqueta(int pos){
//    return cola[pos];
//}
