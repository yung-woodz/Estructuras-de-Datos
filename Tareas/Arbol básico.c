#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
struct nodoarbol{ 
       int clave;
       struct nodoarbol *izq;
       struct nodoarbol *der;
};
typedef struct nodoarbol NODO; //DEFINICION DE TIPO NODO
 
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
NODO *creaArbol(NODO *r);
void inorden(NODO *R);
void preorden(NODO *R);
void postorden(NODO *R);
void treefree(NODO *R);
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*-----------------------<FUNCION PRINCIPAL>--------------------------------*/


int main(){
       NODO *raiz, *R=NULL;
       printf("\n\n\tOperaciones sobre arboles Binarios\n\n\t Creacion del arbol binario");
       raiz=creaArbol(R);

       printf("\n\n preorden \t");
       preorden(raiz); //LLAMADO A FUNCION DE RECORRIDO EN PREORDEN
       printf("\n\n inorden \t");
       inorden(raiz); //LLAMADO A FUNCION DE RECORRIDO EN INORDEN
       printf("\n\n postorden \t");
       postorden(raiz); //LLAMADO A FUNCION DE RECORRIDO EN POSTORDEN
       getch();
       treefree(raiz); //LIBERACION DE MEMORIA DEL ARBOL.
       R=NULL; //ASIGNACION DE UN VALOR NULO A LA RAIZ.
       return 0;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

NODO* creaArbol(NODO* r) {

    int valor;

    printf("\n\t Ingrese el valor del nodo: ");
    scanf("%d", &valor);

    if (valor > 0) {
       r = (NODO*)malloc(sizeof(NODO));
       r->clave = valor;
       r->izq = creaArbol(r->izq);
       r->der = creaArbol(r->der);
    } else {
       r = NULL;
    }

    return r;
}

void preorden(NODO *rarbol){
       if(rarbol!=NULL){
              printf(" %d ",rarbol->clave);
              preorden(rarbol->izq);
              preorden(rarbol->der);
       }
}


void inorden(NODO *rarbol){
       if(rarbol!=NULL){
              inorden(rarbol->izq);
              printf(" %d ",rarbol->clave);
              inorden(rarbol->der);
       }
}

void postorden(NODO *rarbol){
       if(rarbol!=NULL){
              postorden(rarbol->izq);
              postorden(rarbol->der);
              printf(" %d ",rarbol->clave);
       }
}


void treefree(NODO *rarbol){
       if(rarbol!=NULL){
              treefree(rarbol->izq);
              treefree(rarbol->der);
              free(rarbol);
       }
}
