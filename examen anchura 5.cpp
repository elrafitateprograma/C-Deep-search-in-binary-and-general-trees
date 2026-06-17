#include "abinen.hpp"
#include "colabi.hpp"
void cifrado(Abin<char> &a, char cad[]){
    int i=0;
    if(cad[i]!='\0'){
    typename Abin<char>::nodo n=a.raiz();
    
    i++;
    Cola <typename Abin<char>::nodo> C;
    
        do{

        
        if(!C.vacia()){
            n=C.frente();
            C.pop();
        }
        
        if(cad[i]!='\0'){
            a.insertarHijoIzqdo(n,cad[i]);
            i++;
            C.push(a.hijoIzqdo(n));
            if(cad[i]!='\0'){
                a.insertarHijoDrcho(n,cad[i]);
                i++;
                C.push(a.hijoDrcho(n));
            }
        }
    }while(cad[i]!='\0');
        
    }
}

void leer(Abin<char> &a, typename Abin<char>::nodo n){
    if(n!=a.NODO_NULO){
        std::cout<<a.elemento(n);
        leer(a,a.hijoIzqdo(n));
        leer(a,a.hijoDrcho(n));
    }
}

int main(){
    Abin<char> a;
    char *cad={"HOLA MUNDO\0"};
    a.insertarRaiz(cad[0]);
    cifrado(a,cad);
    std::cout<<std::endl;
    leer(a,a.raiz());
}