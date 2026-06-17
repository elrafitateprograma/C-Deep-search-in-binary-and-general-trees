#include "agen.hpp"

#include <algorithm>

#include <string>

#include <iostream>
#include <queue>
#include <utility> // para std::pair

template <typename T>
void imprimirArbolGeneral(const Agen<T>& a){
    
    
    std::queue<std::pair<typename Agen<T>::nodo, int>> cola; // nodo y su nivel
    cola.push({a.raiz(), 0});
    int nivel_actual = 0;
    
    std::cout << "Nivel 0: ";
    
    while(!cola.empty()){
        auto [n, nivel] = cola.front();
        cola.pop();
        
        if(nivel > nivel_actual){
            nivel_actual = nivel;
            std::cout << "\nNivel " << nivel_actual << ": ";
        }
        
        // Imprime el nodo
        std::cout << a.elemento(n) << " ";
        
        // Inserta sus hijos en la cola
        typename Agen<T>::nodo hijo = a.hijoIzqdo(n);
        while(hijo != a.NODO_NULO){
            cola.push({hijo, nivel + 1});
            hijo = a.hermDrcho(hijo);
        }
    }
    std::cout << std::endl;
}


template <typename T>
void cambio(Agen<T> a){
    Agen<T> b;
    b.insertarRaiz(a.elemento(a.raiz()));
    cambio_rec(a,a.raiz(),b,b.raiz());
    imprimirArbolGeneral(b);

}

template <typename T>
void cambio_rec(const Agen<T>& a, typename Agen<T>::nodo na, Agen<T>& b, typename Agen<T>::nodo nb){
    if(na!=a.NODO_NULO){
        typename Agen<T>::nodo aux=a.hijoIzqdo(na);
        while(aux!=a.NODO_NULO){
            b.insertarHijoIzqdo(nb,a.elemento(aux));
            cambio_rec(a,aux,b,b.hijoIzqdo(nb));
            aux=a.hermDrcho(aux);
        }
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
	cambio(a);
	
	return 0;
}