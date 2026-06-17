#include "abin_E-S.hpp"
#include <algorithm>
template<typename T>
int recu(Abin<T> A){
	return esto(A,A.raiz());
}

template<typename T>
int esto(Abin<T> A, typename Abin<T>::nodo n){
	if (n==A.NODO_NULO){
		return 0;
	}
	else{
		return (std::max(std::abs(altura(A, A.hijoIzqdo(n)) - altura(A, A.hijoDrcho(n))), std::max(esto(A, A.hijoIzqdo(n)), esto(A, A.hijoDrcho(n)))));
	}
}

template<typename T>
int altura(Abin<T> A, typename Abin<T>::nodo n){
	if (n==A.NODO_NULO){
		return -1;
	}
	else{
		return (1+ std::max(altura(A,A.hijoIzqdo(n)), altura(A, A.hijoDrcho(n))));
	}
}


int main(){
	Abin<int> a1;
	typedef typename Abin<int>::nodo nod;
	nod nodos;
	a1.insertarRaiz(5);
	a1.insertarHijoIzqdo(a1.raiz(), 7);
	a1.insertarHijoDrcho(a1.raiz(), 8);
	nodos = a1.hijoIzqdo(a1.raiz());
	a1.insertarHijoIzqdo(nodos, 4);
	a1.insertarHijoDrcho(nodos, 4);
	nodos = a1.hijoDrcho(a1.raiz());
	a1.insertarHijoIzqdo(nodos, 3);
	a1.insertarHijoDrcho(nodos, 3);
	nodos = a1.hijoDrcho(nodos);
	a1.insertarHijoIzqdo(nodos, 1);
	cout<<"TOMATE";
	int t=recu(a1);
	cout<<t;
}
