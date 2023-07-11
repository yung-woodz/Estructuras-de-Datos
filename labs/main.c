#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int main ()
{
    NODO *h=NULL;
    int n;

    printf("ingrese cantidad de elementos(nodos)\n");
    scanf("%d",&n);
    h=crearLista(n);
    imprimirLista(h);

    FILE *fdin, *fdout;

     	/* Abre archivo de entrada */
     	fdin = fopen("archivo.txt", "r");

     	if ( fdin == NULL )
     	{
		printf("No pudo abrir archivo de entrada %s \n", "archivo.txt");
        	exit(0);
     	}

     	/* Crea archivo de salida */
     	fdout = fopen("salida.txt", "w");

     	if ( fdout == NULL )
     	{
		printf("No pudo crear archivo de salida \n");
        	exit(0);
     	}

	printlista(fdout,h);

}
