#include "abin_E-S.hpp"
#include <algorithm>

void reflex(Abin<int>&a, typename Abin<int>::nodo na, Abin<int>&b, typename Abin<int>::nodo nb){
    if(a.NODO_NULO!=a.hijoIzqdo(na)){
        b.insertarHijoDrcho(nb,a.elemento(a.hijoIzqdo(na)));
        reflex(a,a.hijoIzqdo(na),b,b.hijoDrcho(nb));
    }
    if(a.NODO_NULO!=a.hijoDrcho(na)){
        b.insertarHijoIzqdo(nb,a.elemento(a.hijoDrcho(na)));
        reflex(a,a.hijoDrcho(na),b,b.hijoIzqdo(nb));
    }
}

Abin<int> reflejado(Abin<int>& a){
    Abin<int> b;
    b.insertarRaiz(a.elemento(a.raiz()));
    reflex(a,a.raiz(),b,b.raiz());
    return b;
}

int main(){
	Abin<int> a;
	a.insertarRaiz(1);
	a.insertarHijoIzqdo(a.raiz(), 2);
	a.insertarHijoDrcho(a.raiz(),3);
	typename Abin<int>::nodo nodos=a.hijoIzqdo(a.raiz());
	a.insertarHijoIzqdo(nodos, 4);
	a.insertarHijoDrcho(nodos,5);
	nodos=a.hijoDrcho(a.raiz());
	a.insertarHijoIzqdo(nodos, 6);
	a.insertarHijoDrcho(nodos,7);
	nodos=a.hijoDrcho(nodos);
	a.insertarHijoIzqdo(nodos,8);
	a.insertarHijoDrcho(nodos, 9);
	Abin<int> b=reflejado(a);
    typename Abin<int>::nodo n=b.raiz();
    std::cout<<b.elemento(n);
    n=b.hijoIzqdo(n);
    std::cout<<b.elemento(n);
    n=b.hijoIzqdo(n);
    std::cout<<b.elemento(n);
}