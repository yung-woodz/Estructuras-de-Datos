#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{

    int dato;
    struct nodo *sig;
    
}Nodo;

Nodo *crearNodo(int dato){

    Nodo *n=malloc(sizeof(Nodo));
    n->dato=dato;
    n->sig=NULL;
    return n;

}

void imprimirNodo(Nodo *n){
    printf("%d\n", n->dato);
}