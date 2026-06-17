#include "agen.hpp"
#include <algorithm>
#include <iostream>

template <typename T>
int altura(Agen<T>& a, typename Agen<T>::nodo n){
    if (a.NODO_NULO!=n){
        typename Agen<T>::nodo aux=a.hijoIzqdo(n);
        int g=0;
        while(aux!=a.NODO_NULO){
            g=std::max(g, altura(a,aux));
            aux=a.hermDrcho(aux);
        }
        return g+1;
    }
    else{
        return -1;
    }
}
template <typename T>
int desequilibrio(Agen<T>& a, typename Agen<T>::nodo n){
    if(a.NODO_NULO!=n){
        typename Agen<T>::nodo aux=a.hijoIzqdo(n);
        int g=0;
        while(aux!=a.NODO_NULO){
            g=std::abs(std::max(altura(a,aux), desequilibrio(a,aux)) - std::min(altura(a,aux), desequilibrio(a,aux)));
            aux=a.hermDrcho(aux);
        }
        return g;
    }
    else{
        return 0;
    }
}


int main(){
	Agen<int> a;
	a.insertarRaiz(1);
	a.insertarHijoIzqdo(a.raiz(),2);
	Agen<int>::nodo n=a.hijoIzqdo(a.raiz());
	a.insertarHermDrcho(n,2);
	a.insertarHermDrcho(a.hermDrcho(n),2);
	a.insertarHermDrcho(a.hermDrcho(a.hermDrcho(n)),2);
	a.insertarHijoIzqdo(n,3);
	n=a.hijoIzqdo(n);
	a.insertarHermDrcho(n,3);
	n=a.padre(n);
	n=a.hermDrcho(a.hermDrcho(a.hermDrcho(n)));
	a.insertarHijoIzqdo(n,3);
	n=a.hijoIzqdo(n);
	a.insertarHermDrcho(n,3);
	a.insertarHermDrcho(a.hermDrcho(n),3);
	int t=desequilibrio(a, a.raiz());
	std::cout<<"Total: "<<t;
	return 0;
}