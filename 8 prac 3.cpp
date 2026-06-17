#include "abin_E-S.hpp"
#include <algorithm>
template<typename T>
bool comparar(Abin<T> a){
    Abin<T>b=a;
    b.insertarHijoIzqdo(b.hijoIzqdo(b.hijoIzqdo(b.raiz())),5);
    return recu_com(a,a.raiz(),b,b.raiz());
}

template<typename T>
bool recu_com(Abin<T> a, typename Abin<T>::nodo na, Abin<T> b, typename Abin<T>::nodo nb){
    if(na!=a.NODO_NULO){
        if((a.hijoIzqdo(na)== a.NODO_NULO && b.hijoIzqdo(nb)!=b.NODO_NULO) ||(a.hijoIzqdo(na)!= a.NODO_NULO && b.hijoIzqdo(nb)==b.NODO_NULO)
            ||(a.hijoDrcho(na)==a.NODO_NULO && b.hijoDrcho(nb)!=b.NODO_NULO) || (a.hijoDrcho(na)!=a.NODO_NULO && b.hijoDrcho(nb)==b.NODO_NULO)){
                return false;
            }
            else{
                return recu_com(a,a.hijoIzqdo(na),b,b.hijoIzqdo(nb)) && recu_com(a,a.hijoDrcho(na),b,b.hijoDrcho(nb));
            }
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
	//a.insertarHijoIzqdo(nodos,4);
	nodos=a.hijoDrcho(a.raiz());
	bool t=comparar(a);
	if(t){
        std::cout<<"po mu bien";
    }
    else{
        std::cout<<"no ta bien";
    }
    return 0;
}
