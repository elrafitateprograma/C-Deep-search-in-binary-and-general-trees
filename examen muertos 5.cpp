#include "agen.hpp"
#include <algorithm>
#include <iostream>
#include <vector>


typedef struct {
    bool vivo;
    float oros;

}muerto;

bool compruebanietos(Agen<muerto> &a, typename Agen<muerto>::nodo n){
    if(a.NODO_NULO!=n && a.elemento(n).vivo){
        return true;
    }
    else if(a.NODO_NULO==n){
        return false;
    }
    else{
        typename Agen<muerto>::nodo aux=a.hijoIzqdo(n);
        bool flag=false;
        while(aux!=a.NODO_NULO){
            flag=flag || compruebanietos(a,aux);
            aux=a.hermDrcho(aux);
        }
        return flag;
    }
    
}

int hijosvivos(Agen<muerto> &a, typename Agen<muerto>::nodo n, std::vector<typename Agen<muerto>::nodo> &hijos){
    int x=0;
    while(n!=a.NODO_NULO){
        if(a.elemento(n).vivo){
            x++;
            hijos.push_back(n);
        }
        else{
            if(compruebanietos(a,n)){
                x++;
                hijos.push_back(n);
            }
        }
        n=a.hermDrcho(n);
    }
    return x;
}

void descendencia(Agen<muerto> &a, typename Agen<muerto>::nodo n){
    typename Agen<muerto>::nodo aux=a.hijoIzqdo(n);
    std::vector<typename Agen<muerto>::nodo> hijos;
    int x=hijosvivos(a,aux, hijos);
    if(x==0){
        a.elemento(n).oros=0;
    }
    else{
        float reparto=a.elemento(n).oros/x;
        for(size_t i=0; i<hijos.size(); i++){
            a.elemento(hijos[i]).oros=reparto;
            if(!a.elemento(hijos[i]).vivo){
                semurio(a,hijos[i]);
            }
        }
        a.elemento(n).oros=0;
        hijos.clear();
    }
    

}

void semurio(Agen<muerto> &a, typename Agen<muerto>::nodo n){
    a.elemento(n).vivo=false;
    descendencia(a,n);

}