#include "abin_E-S.hpp"
#include <algorithm>

int altura(Abin<int>&a, typename Abin<int>::nodo n){
    if(n!=a.NODO_NULO){
        return(std::max(altura(a,a.hijoIzqdo(n)),altura(a,a.hijoDrcho(n)))+1);
    }
    else{
        return -1;
    }
}
int equilibrado(Abin<int>&a, typename Abin<int>::nodo n){
    if(a.NODO_NULO!=n){
        return (std::max(std::abs(altura(a,a.hijoIzqdo(n))- altura(a,a.hijoDrcho(n))),std::max(equilibrado(a,a.hijoIzqdo(n)),equilibrado(a,a.hijoDrcho(n)))));
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
	//a.insertarHijoDrcho(nodos, 4);
	int t=equilibrado(a,a.raiz());
    std::cout<<t;
}