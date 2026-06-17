#include <string>
#include "abinen.hpp"
#include <iostream>


struct Elem {
    bool esOperador;   // true si es +, -, *, /
    char operador;     // solo válido si esOperador = true
    double valor;      // solo válido si esOperador = false

    // Constructores de comodidad
    Elem(double v) : esOperador(false), operador(0), valor(v) {}
    Elem(char op) : esOperador(true), operador(op), valor(0) {}
};
float evalua(Abin<Elem> &a, typename Abin<Elem>::nodo n){
    if(a.NODO_NULO!= n){
        if(a.elemento(n).esOperador){
           if(a.elemento(n).operador=='+'){
            a.elemento(n).valor=evalua(a,a.hijoIzqdo(n))+evalua(a,a.hijoDrcho(n));
           }
           if(a.elemento(n).operador=='*'){
            a.elemento(n).valor=evalua(a,a.hijoIzqdo(n))*evalua(a,a.hijoDrcho(n));
           }
           if(a.elemento(n).operador=='-'){
            a.elemento(n).valor=evalua(a,a.hijoIzqdo(n))-evalua(a,a.hijoDrcho(n));
           }
           if(a.elemento(n).operador=='/'){
            a.elemento(n).valor=evalua(a,a.hijoIzqdo(n))/evalua(a,a.hijoDrcho(n));
           }
            a.elemento(n).esOperador=false;
            a.elemento(n).operador=0;
            return a.elemento(n).valor;
        }
        else{
            return a.elemento(n).valor;
        }
        
    }
}




int main() {

    Abin<Elem> A;   // Árbol de expresión

    // Creamos nodos
    // Representa: 7 * ((15 - 3.2) / 2)

    // Nodo raíz: '*'
    A.insertarRaiz(Elem('*'));
    auto r = A.raiz();

    // Hijo izquierdo de raíz: '7'
    A.insertarHijoIzqdo(r, Elem(7.0));

    // Hijo derecho de raíz: '/'
    A.insertarHijoDrcho(r, Elem('/'));
    auto div = A.hijoDrcho(r);

    // Hijo izquierdo de '/'
    A.insertarHijoIzqdo(div, Elem('-'));
    auto menos = A.hijoIzqdo(div);

    // Subárbol (15 - 3.2)
    A.insertarHijoIzqdo(menos, Elem(15.0));
    A.insertarHijoDrcho(menos, Elem(3.2));

    // Hijo derecho de '/'
    A.insertarHijoDrcho(div, Elem(2.0));

    // Evaluamos el árbol
    float f=evalua(A, A.raiz());
    std::cout<<"Resultado: "<<f;

    return 0;
}