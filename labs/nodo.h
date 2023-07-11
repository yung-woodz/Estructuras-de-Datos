#ifndef _NODO_H
#define _NODO_H

typedef struct nodo {
    	
	    int num;
	    struct nodo *siguiente;
}NODO;

NODO* insertaNodo(NODO *h);
NODO* crearLista(int n);
void imprimirLista(NODO *aux);
void printlista(FILE *fd, NODO *r);

#endif
