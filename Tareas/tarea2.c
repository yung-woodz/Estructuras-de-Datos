#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct{

    int nro_reserva;
    char nombre[20];
    char destino[20];
    struct NODO *izq;
    struct NODO *der;


}NODO;

NODO *creaArbol(NODO *r);
NODO *insertar(NODO *r, int valor);

int main (){

    int op;
    NODO *raiz, *R=NULL;
    raiz=creaArbol(R);

    do{

        do{
            
            system("cls");
            printf("\t\tSISTEMA DE RESERVACION\n");
            printf("\t\t     DE DRAGONES\n\n");
            printf("\t1. Realizar reserva\n");
            printf("\t2. Cancelar reserva\n");
            printf("\t3. Buscar registro\n");
            printf("\t4. Mostrar reserva por destino\n");
            printf("\t5. Mostrar reservas ordenadas\n");
            printf("\t6. Salir\n");
            printf("\n     -> ");
            scanf("%d", &op);

        }while(op < 1 || op > 6);

        

        printf("\n");
        system("pause");

    }while(op != 6);


}

NODO* creaArbol(NODO* r) {

    if (r == NULL) {
        r = (NODO*)malloc(sizeof(NODO));
        r->nro_reserva = 54; // Mediana del intervalo [10,98]
        strcpy(r->nombre, "");
        r->izq = NULL;
        r->der = NULL;
    }

    return r;
}

NODO *insertar(NODO *r, int valor){ // acá el valor será generado aleatoriamente

    if (r == NULL) {
        r = (NODO*)malloc(sizeof(NODO));
        r->nro_reserva = valor;
        r->izq = NULL;
        r->der = NULL;
    } else if (valor < r->nro_reserva) {
        r->izq = insertar(r->izq, valor); // Insertar en el subárbol izquierdo
    } else {
        r->der = insertar(r->der, valor); // Insertar en el subárbol derecho
    }

    return r;

}