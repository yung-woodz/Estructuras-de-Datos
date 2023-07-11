#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int edad;
    struct Nodo *sig;
}Nodo;

Nodo *agregar(Nodo *p, int edad);

int main(){

    Nodo *L, *p;
    int n;

    L = NULL;

    scanf("%d", &n);
    agregar(p, n);


}

Nodo *agregar(Nodo *p, int edad){

    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->edad = edad;
    nuevo->sig = NULL;
    
    return p;
}