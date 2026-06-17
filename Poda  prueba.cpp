#include "agen.hpp"
#include <algorithm>
#include <iostream>
template<typename T>
Agen<T> recu(Agen<T> A){
	int x;
	std::cout<<"Determina un elemento para hacer poda"<<std::endl;
	std::cin>>x;
	encontrar(A,A.raiz(),x);
	return A;
}
template<typename T>
void encontrar(Agen<T> &A, typename Agen<T>::nodo n, int x){
	if (x!=A.elemento(n)){
		typename Agen<T>::nodo aux = A.hijoIzqdo(n);
		while(aux!= A.NODO_NULO){
			encontrar(A,aux,x);
			aux = A.hermDrcho(aux);
		}
	}
	else{
		//std::cout<<"Encontrado";
		borrar(A,n);
		
	}
}
template<typename T>
void borrar(Agen<T> &B, typename Agen<T>::nodo n){
	if(n!=B.NODO_NULO){
		typename Agen<T>::nodo aux = B.hijoIzqdo(n);
		while (aux!=B.NODO_NULO){
			borrar(B,aux);
			aux = B.hermDrcho(aux);
			B.eliminarHijoIzqdo(n);
		}
	}
	
}

template<typename T>
int contar(Agen<T> a, typename Agen<T>::nodo n){
	if (n==a.NODO_NULO){
		return 0;
	}
	else{
		typename Agen<T>::nodo aux = a.hijoIzqdo(n);
		int g=0;
		while(aux!=a.NODO_NULO){
			g=( contar(a,aux)) +g;
			aux=a.hermDrcho(aux);
			
		}
		return g+1;
	}
}


int main(){
	Agen<int> A;
	A.insertarRaiz(1);
	A.insertarHijoIzqdo(A.raiz(), 2);
	Agen<int>::nodo n = A.hijoIzqdo(A.raiz());
	A.insertarHermDrcho(n,3);
	n = A.hermDrcho(n);
	A.insertarHermDrcho(n,4);
	n = A.hijoIzqdo(A.raiz());
	A.insertarHijoIzqdo(n, 5);
	n=A.hijoIzqdo(n);
	A.insertarHermDrcho(n, 6);
	n= A.hermDrcho(n);
	A.insertarHermDrcho(n,7);
	n = A.hijoIzqdo(A.raiz());
	n = A.hermDrcho(A.hermDrcho(n));
	A.insertarHijoIzqdo(n, 8);
	n= A.hijoIzqdo(n);
	A.insertarHermDrcho(n,9);
	int t=contar(A, A.raiz());
	std::cout<<"Antes : "<<t<<std::endl;
	Agen<int> F =  recu(A);
	t=contar(F, F.raiz());
	std::cout<<"Despues : "<<t<<std::endl;
}
