#include "abinen.hpp"
#include "colabi.hpp"
template <typename T>
bool comprueba(Abin<T> &a){
    typename Abin<T>::nodo n = a.raiz();
    Cola<typename Abin<T>::nodo> C;
    
    bool hueco=false;
    if(n!=a.NODO_NULO){
        do{
            if(!C.vacia()){
                n=C.frente();
                C.pop();
            }
            if(a.hijoIzqdo(n)!=a.NODO_NULO && a.elemento(a.hijoIzqdo(n)) > a.elemento(n)){
                return false;
            }
            

            if(a.hijoDrcho(n)!=a.NODO_NULO && a.elemento(a.hijoDrcho(n))> a.elemento(n)){
                return false;
            }
            

            if(a.hijoDrcho(n)!= a.NODO_NULO && a.hijoIzqdo(n)== a.NODO_NULO){
                return false;
            }


            if(a.NODO_NULO==a.hijoIzqdo(n)){
                hueco=true;
            }
            else{
                if(hueco){
                    return false;
                }
                C.push(a.hijoIzqdo(n));
            }

            if(a.NODO_NULO==a.hijoDrcho(n)){
                hueco=true;
            }
            else{
                if(hueco){
                    return false;
                }
                C.push(a.hijoDrcho(n));
            }


        }while(!C.vacia());
        return true;
    }
}