#include "agen.hpp"
#include <algorithm>
#include <iostream>
template<typename T>
int altura(Agen<T> A, typename Agen<T>::nodo n){
	if (n==A.NODO_NULO){
		return 0;
	}
	else{
		typename Agen<T>::nodo aux = A.hijoIzqdo(n);
		int g = 0;
		while(aux!=A.NODO_NULO){
			g= std::max(altura(A,aux),g);
			
			aux=A.hermDrcho(aux);
		}
		return g+1;
	}
}





int main(){
	Agen<int> A;
	A.insertarRaiz(1);
	A.insertarHijoIzqdo(A.raiz(), 2);
	Agen<int>::nodo n = A.hijoIzqdo(A.raiz());
	A.insertarHermDrcho(n,2);
	n = A.hermDrcho(n);
	A.insertarHermDrcho(n,2);
	n = A.hijoIzqdo(A.raiz());
	A.insertarHijoIzqdo(n, 3);
	n=A.hijoIzqdo(n);
	A.insertarHermDrcho(n, 3);
	n= A.hermDrcho(n);
	A.insertarHermDrcho(n,3);
	n = A.hijoIzqdo(A.raiz());
	n = A.hermDrcho(A.hermDrcho(n));
	A.insertarHijoIzqdo(n, 5);
	n= A.hijoIzqdo(n);
	A.insertarHermDrcho(n,5);

	int t = altura(A,n);
	std::cout<<t;
}
