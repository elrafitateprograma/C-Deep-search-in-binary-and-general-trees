#include "abinen.hpp"
#include <iostream>
template<typename T>
int altura(Abin<T> &a, typename Abin<T>::nodo n){
    if(a.NODO_NULO!=n){
        return (1+std::max(altura(a,a.hijoIzqdo(n)), altura(a,a.hijoDrcho(n))));
    }
    else{
        return -1;
    }
}

template <typename T>
int equilibrio(Abin<T> &a, typename Abin<T>::nodo n){
    if(a.NODO_NULO!= n){
        return (std::max(std::abs(altura(a,a.hijoIzqdo(n))-altura(a,a.hijoDrcho(n))),std::max(equilibrio(a,a.hijoIzqdo(n)),equilibrio(a,a.hijoDrcho(n)))));
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
	//a.insertarHijoIzqdo(nodos,4);
    int i=equilibrio(a,a.raiz());
    std::cout<<i;
	
}