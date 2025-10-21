#include <iostream>
using namespace std;
/*
El escritor Mario Vargas Llosa, ha terminado de escribir un libro.
Mas bien tiene un monton de hojas
sueltas, que contienen el numero de pagina. Pero no tan sueltas.
La mitad de las hojas esta en una pila
INICIO ordenada descendentemente desde el tope hacia la base
y la otra mitad esta en otra pila, FIN,
ordenada ascendentemente desde el tope hacia la base. 
El escritor necesita ordenar su “libro”, para lo
cual le solicita desarrollar el algoritmo juntar(),
usando C++. Este debe fusionar ambas pilas (que son
recibidas como parametros) en una tercera pila, TODO,
la cual debe estar ordenada ascendentemente
desde el tope hacia la base. Consideraciones, 
solo se permiten utilizar los TDA de pila y cola
*/
//Pila inicio  ordenada descendentemente 
//Pila fin     ordenada ascendentemente
//Todo deber ser ordenado ascendentemente
typedef int tElemPila;
typedef int tElemCola;
class tPila{
    private :
    // Campos de la clase ...
    public :
        void clear(); 
        int push(tElemPila item) ; 
        void pop(); 
        tElemPila topValue(); 
        int size(); 
};
class tCola {
    private :
    // Campos de la clase ...
    public :
        void clear();
        int enqueue ( tElemCola item );
        void dequeue();
        tElemCola frontValue();
        int size();
};
//Pila inicio  ordenada descendentemente 
//Pila fin     ordenada ascendentemente
tPila *juntar(tPila *inicio,tPila *fin){
    tPila *TODO=new tPila;
    tCola *AUX=new tCola;
    int z=inicio->size();
    for(int i=0;i<z;i++){
        AUX->enqueue(fin->topValue());
        fin->pop();
    }
    for(int i=0;i<z;i++){
        fin->push(AUX->frontValue());
        AUX->dequeue();
    }
    delete AUX;
    for (int i=0;i<z;i++){
        TODO->push(fin->topValue());
        fin->pop();
    }
    for (int i=0;i<z;i++){
        TODO->push(inicio->topValue());
        inicio->pop();
    }
    return TODO;
}