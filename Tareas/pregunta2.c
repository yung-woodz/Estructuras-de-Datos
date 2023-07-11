#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define M 12
#define N 7

typedef struct {
    int id;
    char empresa[20];
}Datos;

void tamano(int *m, int *n);
void llenado(Datos pila[M][N], int m, int n);
void push(Datos pila[M][N], int m, int n);
void pop(Datos pila[M][N], int m, int n);
void peek(Datos pila[M][N], int m, int n);

void tamano(int *m, int *n) {
    do {
        printf("Ingrese el tamano de su pila M (0 < M < %d): \n", M);
        scanf("%d", m);
        fflush(stdin);
    } while (0 > *m || *m > M);

    do {
        printf("Ingrese el tamano de su pila N (0 < N < %d): \n", N);
        scanf("%d", n);
        fflush(stdin);
    } while (0 > *n || *n > N);

    system("cls");
}

void llenado(Datos pila[M][N], int m, int n){

    int i, j;

    for (i = m - 1; i >= 0; i--) {
        for(j = 0 ; j < n ; j++){

            pila[i][j].id = 0;

        }
        
    }

}

void push(Datos pila[M][N], int m, int n) {

    int op, op1, i;
    int pilaLlena = 0;
   
    do{

        printf("Ingrese en donde quiere ingresar el contenedor \n");
        scanf("%d", &op);
        fflush(stdin);
        if(op < 1 || op > n){
            system("cls");
            printf("Error, ingrese una opcion valida\n");
        }

    }while(op < 1 || op > n);

    srand(time(NULL));

    for (i = m - 1; i >= 0; i--) {
        if (pila[i][op-1].id == 0) {
            pila[i][op-1].id = rand() % 900 + 100;

            printf("Empresa: ");
            fgets(pila[i][op-1].empresa, sizeof(pila[i][op-1].empresa), stdin);

            printf("ID: %d\n", pila[i][op-1].id);
            printf("Empresa: %s\n", pila[i][op-1].empresa);

            return;
        }

        if (i == 0) {
            pilaLlena = 1; // La pila está llena si llegamos al final del bucle
        }
    }


    if (pilaLlena) {
        system("cls");
        printf("\tLa pila seleccionada está llena\n");

        do {
            printf("¿Qué desea hacer?\n");
            printf("1. Seleccionar otra pila\n");
            printf("2. Volver al menú\n");
            printf("\n     -> ");
            scanf("%d", &op1);
            fflush(stdin);

            if (op1 < 1 || op1 > 2) {
                system("cls");
                printf("Error, ingrese una opción válida\n");
            }
        } while (op1 < 1 || op1 > 2);

        if (op1 == 1) {
            pilaLlena = 0; 
            push(pila, m, n); 
        }
    }
    
}

void pop(Datos pila[M][N], int m, int n){

    int op, op1, i, j;

    Datos aux[M];
   
    do{

        printf("Ingrese en que pila se encuentra el container\n");
        printf("que desea eliminar: ");
        scanf("%d", &op);
        fflush(stdin);
        if(op < 1 || op > n){
            system("cls");
            printf("Error, ingrese una opcion valida\n");
        }

    }while(op < 1 || op > n);

    for (i = 0 ; i < m ; i++){

        if(pila[i][op-1].id != 0){

            printf("ID: %d\n", pila[i][op-1].id);
            printf("Empresa: %s\n", pila[i][op-1].empresa);

        }

    }

    do{

        printf("Ingrese la ID del contenedor para sacarlo: ");
        scanf("%d", &op1);
        fflush(stdin);

    }while(op1 < 0 || op1 > 999);

    for (i = 0; i < m; i++) {

        if (pila[i][op-1].id == op1) {

            for (j = i + 1; j < m; j++) {

                strcpy(aux[j-1].empresa, pila[j][op-1].empresa);
                aux[j-1].id = pila[j][op-1].id;

            }

            strcpy(pila[i][op-1].empresa, "");
            pila[i][op-1].id = 0;

            for (j = i + 1; j < m; j++) {

                strcpy(pila[j][op-1].empresa, aux[j-1].empresa);
                pila[j][op-1].id = aux[j-1].id;

            }

            printf("Contenedor eliminado :3\n");

        }


    }

    
}

void peek(Datos pila[M][N], int m, int n) {
    int op, i;
   
    do {
        printf("Ingrese la pila el cual desea obtener el valor superior: ");
        scanf("%d", &op);
        fflush(stdin);
        
        if (op < 1 || op > n) {
            system("cls");
            printf("Error, ingrese una opcion valida\n");
        }
    } while (op < 1 || op > n);

    for (i = m - 1; i >= 0; i--) {
        if (pila[i][op-1].id != 0) {
            printf("ID: %d\n", pila[i][op-1].id);
            printf("Empresa: %s\n", pila[i][op-1].empresa);
            return;
        }
    }

}

int main() {

    int m, n, op;
    tamano(&m, &n);

    Datos pila[M][N];

    llenado(pila, m, n);

    do {

        system("cls");

        do {

            printf("Bienvenido al contenedor\n");
            printf("\tIngrese la opcion que desea realizar\n");
            printf("1. Ingresar contenedor\n");
            printf("2. Imprimir contenedor\n");
            printf("3. Sacar contenedor\n");
            printf("4. peek\n");
            printf("5. Salir\n");
            printf("\n     -> ");
            scanf("%d", &op);
            fflush(stdin);

        } while(op < 1 || op > 5);

        switch(op) {

            case 1:
                push(pila, m, n);
            break;

            case 3:
                pop(pila, m, n);
            break;

            case 4:
                peek(pila, m, n);
            break;

            case 5:
                exit(0);
            break;
        }

        system("pause");

    } while(op != 5);

    return 0;
}