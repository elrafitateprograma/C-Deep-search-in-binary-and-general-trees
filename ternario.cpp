#include "agen.hpp"
#include <algorithm>
#include <iostream>
template <typename T>
bool ternario(Agen<T>& a, typename Agen<T>::nodo n){
    if(n==a.NODO_NULO){
        return true;
    }
    else if(numerohijos(a,a.hijoIzqdo(n))!=3 && numerohijos(a,a.hijoIzqdo(n))!=0 && n!=a.raiz()){
        return false;
    }
    else{
        typename Agen<T>::nodo aux=a.hijoIzqdo(n);
        bool flag=true;
        while(aux!=a.NODO_NULO){
            flag=ternario(a,aux);
            aux=a.hermDrcho(aux);
        }
        return flag;
    }
}


template <typename T>
int numerohijos(Agen<T> a, typename Agen<T>::nodo n){
    int x=0;
    if(a.NODO_NULO == n){
        return x;
    }
    else{
        while (n!=a.NODO_NULO){
            x++;
            n=a.hermDrcho(n);
        }
        std::cout<<"n hijos: "<<x<<std::endl;
        return x;
    }
}


int main(){
	Agen<int> a;
	a.insertarRaiz(1);
	a.insertarHijoIzqdo(a.raiz(),2);
	Agen<int>::nodo n=a.hijoIzqdo(a.raiz());
	a.insertarHermDrcho(n,2);
	a.insertarHermDrcho(a.hermDrcho(n),2);
	a.insertarHijoIzqdo(n,3);
	n=a.hijoIzqdo(n);
	a.insertarHermDrcho(n,3);
    a.insertarHermDrcho(a.hermDrcho(n),3);
	n=a.padre(n);
	n=a.hermDrcho(a.hermDrcho(n));
	a.insertarHijoIzqdo(n,3);
	n=a.hijoIzqdo(n);
	a.insertarHermDrcho(n,3);
	a.insertarHermDrcho(a.hermDrcho(n),3);
	bool t=ternario(a, a.raiz());
    if(t){
        std::cout<<"Ta bien";
    }
    else{
        std::cout<<"Ta mal";
    }
	
	return 0;
}