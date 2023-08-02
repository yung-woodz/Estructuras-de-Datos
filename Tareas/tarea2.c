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
NODO *insertar(NODO* r, int nro_reserva, char nombre, char destino);

int main (){

    int op;

    NODO *raiz, *R=NULL;

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


        switch (op) {
            case 1:

                raiz=creaArbol(R);

            break;

            case 2:

                

            break;

            case 3:

                

            break;

            case 5:

                

            break;
            case 6:

                

            break;
            
        }
        

        printf("\n");
        system("pause");

    }while(op != 6);


}

NODO* creaArbol(NODO* r) {

    int nro_reserva;
    char nombre[20];
    char destino[20];

    printf("Ingrese el número de reserva: ");
    scanf("%d", &nro_reserva);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Elimina el salto de línea de fgets

    printf("Ingrese el destino: ");
    fgets(destino, sizeof(destino), stdin);
    destino[strcspn(destino, "\n")] = '\0'; // Elimina el salto de línea de fgets

    r = insertar(r, nro_reserva, nombre, destino);

    return r;
}

NODO *insertar(NODO* r, int nro_reserva, char nombre, char destino){

    if (r == NULL) {
        r = (NODO*)malloc(sizeof(NODO));
        r->nro_reserva = nro_reserva;
        strcpy(r->nombre, nombre);
        strcpy(r->destino, destino);
        r->izq = NULL;
        r->der = NULL;
    } else if (nro_reserva < r->nro_reserva) {
        r->izq = insertar(r->izq, nro_reserva, nombre, destino); // Insertar en el subárbol izquierdo
    } else {
        r->der = insertar(r->der, nro_reserva, nombre, destino); // Insertar en el subárbol derecho
    }

    
    return r;

}