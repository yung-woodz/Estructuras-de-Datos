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
NODO *insertar(NODO *r, int nro_reserva, char nombre[], char destino[]);
NODO *eliminar(NODO *r, int nro_reserva);
NODO *encontrarMinimo(NODO *r);
NODO* buscarRegistro(NODO *r, int nro_reserva);
void mostrarPorDestino(NODO *r, char destino[]);
void mostrarOrdenado(NODO *r);

int main (){

    int op, aux;

    NODO *raiz = NULL;

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

                raiz=creaArbol(raiz);

            break;

            case 2:

                printf("Ingrese el su numero de reserva a eliminar: \n");
                scanf("%d", &aux);

                eliminar(raiz, aux);

            break;

            case 3:

                printf("Ingrese el numero de reserva a buscar: ");
                int num;
                scanf("%d", &num);
                NODO* encontrado = buscarRegistro(raiz, num);
                if (encontrado != NULL){
                    printf("Registro encontrado:\n");
                    printf("\nNumero de reserva: %d\n", encontrado->nro_reserva);
                    printf("Nombre: %s\n", encontrado->nombre);
                    printf("Destino: %s\n\n", encontrado->destino);
                } else{
                    printf("Registro no encontrado\n");
                }

            break;

            case 4:

                printf("Ingrese el nombre del destino: ");
                char destino[20];
                fflush(stdin);
                fgets(destino, sizeof(destino), stdin);
                destino[strcspn(destino, "\n")] = '\0';
                mostrarPorDestino(raiz, destino);

            break;
            case 5:

                printf("Reservas ordenadas por numero de reserva:\n");
                mostrarOrdenado(raiz);
                
            break;
            
        }
        

        printf("\n");
        system("pause");

    }while(op != 6);


}

NODO* creaArbol(NODO* r){

    int nro_reserva;
    char nombre[20];
    char destino[20];

    printf("Ingrese el numero de reserva: ");
    scanf("%d", &nro_reserva);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    fflush(stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Elimina el salto de línea

    printf("Ingrese el destino: ");
    fgets(destino, sizeof(destino), stdin);
    fflush(stdin);
    destino[strcspn(destino, "\n")] = '\0'; 

    r = insertar(r, nro_reserva, nombre, destino);

    return r;
}

NODO *insertar(NODO *r, int nro_reserva, char nombre[], char destino[]){

    if (r == NULL) {
        r = (NODO*)malloc(sizeof(NODO));
        r->nro_reserva = nro_reserva;
        strcpy(r->nombre, nombre);
        strcpy(r->destino, destino);
        r->izq = NULL;
        r->der = NULL;
    } else if (nro_reserva < r->nro_reserva) {
        r->izq = insertar(r->izq, nro_reserva, nombre, destino); // Insertar en el subarbol izquierdo
    } else {
        r->der = insertar(r->der, nro_reserva, nombre, destino); // Insertar en el subarbol derecho
    }

    
    return r;

}

NODO *eliminar(NODO *r, int nro_reserva) {
    if (r == NULL) {
        return r;
    }

    if (nro_reserva < r->nro_reserva) {
        // El nodo a eliminar esta en el subarbol izquierdo
        r->izq = eliminar(r->izq, nro_reserva);
    } else if (nro_reserva > r->nro_reserva) {
        // El nodo a eliminar esta en el subarbol derecho
        r->der = eliminar(r->der, nro_reserva);
    } else {
        //Nodo sin hijos
        if (r->izq == NULL && r->der == NULL) {
            free(r);
            r = NULL;
        }
        //Nodo con un hijo
        else if (r->izq == NULL) {
            NODO* temp = r;
            r = r->der;
            free(temp);
        } else if (r->der == NULL) {
            NODO* temp = r;
            r = r->izq;
            free(temp);
        }
        //Nodo con dos hijos
        else {
            NODO* temp = encontrarMinimo(r->der);
            r->nro_reserva = temp->nro_reserva;
            strcpy(r->nombre, temp->nombre);
            strcpy(r->destino, temp->destino);
            r->der = eliminar(r->der, temp->nro_reserva);
        }
    }

    return r;
}

NODO *encontrarMinimo(NODO *r) {
    if (r == NULL) {
        return NULL;
    }
    while (r->izq != NULL) {
        r = r->izq;
    }
    return r;
}

NODO* buscarRegistro(NODO *r, int nro_reserva) {
    if (r == NULL || r->nro_reserva == nro_reserva) {
        return r;
    }

    if (nro_reserva < r->nro_reserva) {
        return buscarRegistro(r->izq, nro_reserva); // Buscar en el subarbol izquierdo
    } else {
        return buscarRegistro(r->der, nro_reserva); // Buscar en el subarbol derecho
    }
}

void mostrarPorDestino(NODO *r, char destino[]) {
    if (r == NULL) {
        return;
    }

    mostrarPorDestino(r->izq, destino);

    if (strcmp(r->destino, destino) == 0) {
        printf("\nNumero de reserva: %d\n", r->nro_reserva);
        printf("Nombre: %s\n", r->nombre);
        printf("Destino: %s\n\n", r->destino);
    }

    mostrarPorDestino(r->der, destino);
}

void mostrarOrdenado(NODO *r) {
    if (r != NULL) {
        mostrarOrdenado(r->izq);
        printf("Numero de reserva: %d\n", r->nro_reserva);
        printf("Nombre: %s\n", r->nombre);
        printf("Destino: %s\n\n", r->destino);
        mostrarOrdenado(r->der);
    }
}