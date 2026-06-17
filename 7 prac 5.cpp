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
bool pseudo(Abin<T> &a, typename Abin<T>::nodo n, int i){
    if(n!=a.NODO_NULO){
        if(i==1){
            if((a.hijoIzqdo(n)!=a.NODO_NULO && a.hijoDrcho(n)==a.NODO_NULO) || (a.hijoIzqdo(n)==a.NODO_NULO && a.hijoDrcho(n)!=a.NODO_NULO)){
                return false;
            }
        }
        i=i-1;
        return (pseudo(a,a.hijoIzqdo(n),i) && pseudo(a,a.hijoDrcho(n),i));
    }
    else{
        return true;
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
    int i=altura(a,a.raiz());
	if(pseudo(a, a.raiz(), i)){
        std::cout<<"Lo es";
    }
    else{
        std::cout<<"No";
    }
}