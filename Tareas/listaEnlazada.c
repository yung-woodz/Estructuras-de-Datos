#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int numerador, denominador;
    struct nodo *sig;
}nodo;

nodo *crear(nodo *lista);
nodo *agregar(nodo *lista, int numerador, int denominador);

nodo *crear(nodo *lista){

    lista = NULL;
    return lista;

}

nodo *agregar(nodo *lista, int numerador, int denominador){

    nodo *nuevovalor, *aux;
    nuevovalor = (nodo*)malloc(sizeof(nodo));
    nuevovalor->numerador = numerador;
    nuevovalor->denominador = denominador;
    nuevovalor->sig = NULL;

    if(lista == NULL){
        lista = nuevovalor;
    }else{
        aux = lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevovalor;
    }

    return lista;
}

int main (){

    nodo *lista = crear(lista);
    int numerador, denominador, i, n;

    do{
        printf("Cuantos valores desea ingresar?\n");
        scanf("%d", &n);
    } while (n < 0);
    
    for(i = 0 ; i < n ; i++){

        printf("Ingrese el valor %d: \n", i+1);
        scanf("%i%i", &numerador, &denominador);
        lista = agregar(lista, numerador, denominador);

    }

    
    
    while (lista != NULL) {
        printf("(%i,%i)\n", lista->numerador, lista->denominador);
        
        lista = lista->sig;
    }
    
    
    return 0;

}