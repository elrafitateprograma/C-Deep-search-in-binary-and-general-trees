#include "agen.hpp"
#include <algorithm>
#include <iostream>

template <typename T>
typename Agen<T>::nodo busca(Agen<T> &a, typename Agen<T>::nodo n, int x){
    if(a.elemento(n)==x){
            return n;
        }
    else if(n==a.NODO_NULO){          
        return a.NODO_NULO;
    }
    else{
        typename Agen<T>::nodo aux= a.hijoIzqdo(n);
           
            while (aux!=a.NODO_NULO)
            {
                typename Agen<T>::nodo encontrado =busca(a,aux,x);
                if(encontrado!=a.NODO_NULO){
                    
                    return encontrado;
                }
                aux=a.hermDrcho(aux);
            }
            return a.NODO_NULO;
    }
    
}
template <typename T>
void poda(Agen<T>& a, typename Agen<T>::nodo n){
    while(a.hijoIzqdo(n)!=a.NODO_NULO){
        poda(a,a.hijoIzqdo(n));
        a.eliminarHijoIzqdo(n);
    }
}

template <typename T>
void eliminar(Agen<T>& a, int x){
    typename Agen<T>::nodo n=busca(a,a.raiz(),x); 
    std::cout<<a.elemento(n);
    poda(a,n);
    if(a.hijoIzqdo(n)==a.NODO_NULO){
        std::cout<<"Ole, borrao";
    }
    else{
        std::cout<<"I hate niggers";
    }
}



int main(){
	Agen<int> a;
	a.insertarRaiz(1);
	a.insertarHijoIzqdo(a.raiz(),2);
	Agen<int>::nodo n=a.hijoIzqdo(a.raiz());
	a.insertarHermDrcho(n,3);
	a.insertarHermDrcho(a.hermDrcho(n),4);
	a.insertarHermDrcho(a.hermDrcho(a.hermDrcho(n)),5);
	a.insertarHijoIzqdo(n,6);
	n=a.hijoIzqdo(n);
	a.insertarHermDrcho(n,7);
	n=a.padre(n);
	n=a.hermDrcho(a.hermDrcho(a.hermDrcho(n)));
	a.insertarHijoIzqdo(n,8);
	n=a.hijoIzqdo(n);
	a.insertarHermDrcho(n,9);
	a.insertarHermDrcho(a.hermDrcho(n),10);
	eliminar(a, 9);
	
	return 0;
}