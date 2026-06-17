#include "abinen.hpp"
#include <iostream>
template <typename T>
int profundidad (Abin<T> a, typename Abin<T>::nodo n){
    if(n!=a.NODO_NULO){
        return (1+profundidad(a,a.padre(n)));
    }
    else{
        return 0;
    }
}

int main(){
	Abin<int> a;
	a.insertarRaiz(1);
	a.insertarHijoIzqdo(a.raiz(), 2);
	a.insertarHijoDrcho(a.raiz(),2);
	typename Abin<int>::nodo nodos=a.hijoIzqdo(a.raiz());
	a.insertarHijoIzqdo(nodos, 3);
	a.insertarHijoDrcho(nodos,3);
	nodos=a.hijoDrcho(a.raiz());
	a.insertarHijoIzqdo(nodos, 3);
	a.insertarHijoDrcho(nodos,3);
	nodos=a.hijoDrcho(nodos);
	a.insertarHijoIzqdo(nodos,4);
	int t=profundidad(a, nodos);
	std::cout<<"Hay un total de:"<<t;
}