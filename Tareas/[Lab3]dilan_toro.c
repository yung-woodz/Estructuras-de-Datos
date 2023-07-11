#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {

    int id;
    char nombre[20];
    float nota;
    struct nodo *siguiente;

}nodo;

nodo *agregar(nodo *cabeza, int n);
nodo *imprimir(nodo *cabeza);

int main (){

    nodo *cabeza = NULL;

    int op, n;

    do{

        do{
            system("cls");
            printf("\t\t----REGISTRO----\n");
            printf("\t---Ingrese opcion---\n");
            printf("\t1. Ingresar datos\n");
            printf("\t2. Imprimir datos (De mayor a menor segun calificacion)\n");
            printf("\t3. Salir\n");
            printf("\n     -> ");
            scanf("%d", &op);
        }while(op < 1 || op > 3);

        switch (op) {
        case 1:

            do{
                printf("Cuantos estudiantes desea ingresar?: ");
                scanf("%d", &n);
            }while(n < 0);
            
            cabeza = agregar(cabeza, n);
            imprimir(cabeza);

        break;
        
        case 2:

            cabeza = imprimir(cabeza);

        break;

        case 3:

            exit(0);

        break;

        }

        printf("\n");
        system("pause");

    }while(op != 3);

}


nodo *agregar(nodo *cabeza, int n){

    nodo *datos = NULL;

    int id, i;
    char nombre[20];
    float nota;

    if(cabeza == NULL){
        
        nodo *actual = NULL;

        for(i = 0 ; i<n ; i++){

            printf("Ingrese la ID (%d): \n", i+1);
            printf("\t->ID: ");
            scanf("%d", &id);
            fflush(stdin);

            printf("Ingrese el nombre completo (%d): \n", i+1);
            printf("\t->Nombre y Apellido: ");
            gets(nombre);
            fflush(stdin);

            printf("Ingrese calificacion %d: \n", i+1);
            printf("\t->Nota: ");
            scanf("%f", &nota);
            fflush(stdin);

            datos = (nodo*)malloc(sizeof(nodo));
            datos->id = id;
            strcpy(datos->nombre, nombre);
            datos->nota = nota;
            datos->siguiente = NULL;

            if(cabeza == NULL){
                cabeza = datos;
                actual = datos;
            }else{
                actual->siguiente = datos;
                actual = datos;
            }

        } 

    }

    return cabeza;
    
}

nodo *imprimir(nodo *cabeza){

    nodo *temporal = cabeza;

    int id;
    char nombre[20];
    float nota;

    printf ("ID                      NOMBRE                       NOTA\n");
    while(temporal != NULL){

        nodo *aux = temporal->siguiente;

        while (aux != NULL && aux != temporal){
            if(aux->nota > temporal->nota){

                id = temporal->id;
                temporal->id = aux->id;
                aux->id = id;

                strcpy(nombre, temporal->nombre);
                strcpy(temporal->nombre, aux->nombre);
                strcpy(aux->nombre, nombre);

                nota = temporal->nota;
                temporal->nota = aux->nota;
                aux->nota = nota;
            }
            aux = aux->siguiente;
        }
        printf("%d                      %s                       %.1f\n", temporal->id, temporal->nombre, temporal->nota);
        temporal = temporal->siguiente;

    }

    return cabeza;

}