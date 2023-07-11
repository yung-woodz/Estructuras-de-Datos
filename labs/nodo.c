#ifndef _FUNC_H
#define _FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"


NODO* insertaNodo(NODO *h)
{
 NODO *aux,*nuevo;

 if(h!=NULL)
 {
        aux=h;
        while(aux->siguiente!=NULL) aux =aux->siguiente;
        nuevo= (struct nodo *)malloc(sizeof(struct nodo));
        nuevo->num = rand()%100;
        nuevo->siguiente = NULL;
        aux->siguiente = nuevo;

 }
 else
    {
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo->num=rand()%100;
    nuevo->siguiente= NULL;
    h=nuevo;
    }

return h;

}

NODO* crearLista(int n)
{
 NODO *aux, *lista=NULL, *nuevo;
 int cont=0;
 if(n>0)
 {
     lista= (struct nodo *)malloc(sizeof(struct nodo));
     lista->num =rand()%100;
     lista->siguiente = NULL;
     aux = lista;
     cont =1;
     while(cont!=n)
     {
         nuevo = (struct nodo *)malloc(sizeof(struct nodo));
         nuevo->num=rand()%100;
         nuevo->siguiente = NULL;
         aux->siguiente = nuevo;
         aux = aux->siguiente;
         cont++;
     }
 }

 return lista;
}

void imprimirLista(NODO *aux)
{
    if(aux!= NULL)
    {
        while(aux!=NULL)
        {
            printf("[%d]",aux->num);
            aux = aux->siguiente;
        }
        printf("\n\n");
    }
    else
        {
        printf("Lista vacia\n\n");
        }

}

void printlista(FILE *fd, NODO *r)
{
	if ( r != NULL ) {

        while (r->siguiente!=NULL)
        {
		fprintf(fd, "[%d] ",r->num);
        r= r->siguiente;
        }
        fprintf(fd, "[%d] ",r->num);
    }
    else
    fprintf(fd, "Lista sin datos ");

}

#endif



