#include "abin_E-S.hpp"
#include <algorithm>
template <typename T>
int altura(Abin<T> a, typename Abin<T>::nodo t){
    if(t!=a.NODO_NULO){
        return(1+std::max(altura(a,a.hijoIzqdo(t)),altura(a,a.hijoDrcho(t))));
    }
    else{
        return -1;
    }
}
template <typename T>
int equilibrio(Abin<T> a, typename Abin<T>::nodo t){
    if(t!=a.NODO_NULO){
        return(std::max(std::abs(altura(a,a.hijoIzqdo(t))-altura(a,a.hijoDrcho(t))), std::max(equilibrio(a,a.hijoIzqdo(t)), equilibrio(a,a.hijoDrcho(t)))));
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
	int t=equilibrio(a, a.raiz());
	std::cout<<"Equilibrio:"<<t;
}