#include "abin_E-S.hpp"
#include <algorithm>
#include <vector>

template<typename T>
bool recu(Abin<T> A){
	bool flag = (esto(A,A.raiz())<1 || esto(A,A.raiz())>-1);
	if(flag){
		flag=avl(A, A.raiz());
	}
	return flag;
}

template<typename T>
bool avl(Abin<T> A, typename Abin<T>::nodo n){
	if (n==A.NODO_NULO){
		return true;
	}
	else{	
		if(A.hijoIzqdo(n) != A.NODO_NULO && A.hijoDrcho(n) != A.NODO_NULO){
			return (A.elemento(A.hijoIzqdo(n)) < A.elemento(n) && A.elemento(A.hijoDrcho(n)) > A.elemento(n) && avl(A,A.hijoIzqdo(n)) && avl(A,A.hijoDrcho(n)));
		}
		else if(A.hijoIzqdo(n) == A.NODO_NULO && A.hijoIzqdo(n) != A.NODO_NULO){
			return (A.elemento(A.hijoDrcho(n)) > A.elemento(n) && avl(A,A.hijoDrcho(n)));
		}
		else if(A.hijoIzqdo(n) != A.NODO_NULO && A.hijoIzqdo(n) == A.NODO_NULO){
			return (A.elemento(A.hijoIzqdo(n)) < A.elemento(n) && avl(A,A.hijoIzqdo(n)));
		}
		else{
			return true;
		}
	}
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
	a1.insertarHijoIzqdo(a1.raiz(), 3);
	a1.insertarHijoDrcho(a1.raiz(), 6);
	nodos = a1.hijoIzqdo(a1.raiz());
	a1.insertarHijoIzqdo(nodos, 1);
	a1.insertarHijoDrcho(nodos, 4);
	nodos = a1.hijoDrcho(a1.raiz());
	a1.insertarHijoIzqdo(nodos, 2);
	a1.insertarHijoDrcho(nodos, 7);
	//cout<<"TOMATE";
	bool t=recu(a1);
	if (t){
		std::cout<<"Es bien";
	}
	else{
		std::cout<<"Es mal";
	}
}
