#include<stdio.h>
#include<stdlib.h>
//Declarar struct
typedef struct {
    int numerador, denominador;
    struct nodo *sig;
}nodo;

// FUNCIONES

nodo *agregar(nodo *lista, int n);
nodo *imprimir(nodo *aux);
nodo *sumaLista(nodo *lista, int n);

int main() {
    nodo *lista = NULL;

    int n, op, op1, op2, op3;

    do{

        do{
            
            system("cls");
            printf("\t\tLISTA ENLAZADA\n");
            printf("\t--Seleccione una opcion--\n");
            printf("\t1. Ingresar(2)\n");
            printf("\t2. Eliminar(1)\n");
            printf("\t3. Calcular(2)\n");
            printf("\t4. Efectuar(4)\n");
            printf("\t5. Ordenar(2)\n");
            printf("\t6. Salir\n");
            printf("\n     -> ");
            scanf("%d", &op);

        }while(op < 1 || op > 6);


        switch(op){

            case 1: // INGRESAR (2)

                do{
                    system("cls");
                    printf("\t\tINGRESAR\n");
                    printf("\t--Seleccione una opcion--\n");
                    printf("\t1. Ingresar nodos desde el teclado\n");
                    printf("\t2. Ingresar valor en posicion especifica\n");
                    printf("\t3. Volver\n");
                    printf("\n     -> ");
                    scanf("%d", &op1);

                }while(op1 < 1 || op1 > 3);

                switch(op1){
                    case 1: // ingresar nodos desde el teclado
                        printf("cuantos nodos quieres?: \n");
                        scanf("%d", &n);

                        lista = agregar(lista, n);
                        imprimir(lista);

                    break;

                    case 2: // ingresar un valor en una posicion especifica

                       imprimir(lista);

                    break;

                    case 3:
                        // No es necesario colocar algo aquí ya que esta dentro de un
                        // bucle infinito y puede volver al menu
                    break;
                }
        

            break;
            
            case 2: // ELIMINAR (1)

                do{
                    system("cls");
                    printf("\t\tELIMINAR\n");
                    printf("\t--Seleccione una opcion--\n");
                    printf("\t1. Elmininar un valor de la lista\n");
                    printf("\t2. Volver\n");
                    printf("\n     -> ");
                    scanf("%d", &op2);

                }while(op2 < 1 || op2 > 2);

                switch(op2){

                    case 1:

                        //Hacer codigo<-----

                    break;

                    case 2:
                    break;

                }

            break;

            case 3: // CALCULAR (2)

                

                do{
                    system("cls");
                    printf("\t\tCALCULAR\n");
                    printf("\t--Seleccione una opcion--\n");
                    printf("\t1. Calcular la suma de los elementos de la lista\n");
                    printf("\t2. Calcular el producto de los elementos de la lista\n");
                    printf("\t3. Volver\n");
                    printf("\n     -> ");
                    scanf("%d", &op3);

                }while(op3 < 1 || op3 > 3);

                switch(op3){

                    case 1: // SUMA

                        lista = sumaLista(lista, n);
                        sumaLista(lista, n);
                        // revisar codigo
                        printf("(%i,%i)", lista->numerador, lista->denominador);

                    break;

                    case 2: // MULTIPLICACION
                    break;

                }



            break;

            case 4: // EFECTUAR (4)
                // HACER CODIGO
            break;

            case 5: // ORDENAR (2)

                // HACER CODIGO

            break;

            case 6:
                exit(0);
            break;          

        }

        printf("\n");
        system("pause");

    }while(op != 6);

}

nodo *agregar(nodo *lista, int n){

    nodo *nuevovalor = NULL;

    int numerador, denominador, i;

    if(lista == NULL){

        nodo *actual = NULL;

        for(i = 0 ; i<n ; i++){

            printf("Ingrese el valor %d: \n", i+1);
            printf("\t->Numerador: ");
            scanf("%d", &numerador);
            fflush(stdin);

            do{

                printf("\t->Denominador: ");
                scanf("%d", &denominador);
                fflush(stdin);

                if(denominador == 0){
                    printf("\t\tERROR\n");
                    printf("\tUNA FRACCION NO DEBE TENER DENOMINADOR 0\n");
                }

            }while(denominador == 0);

            

            nuevovalor = (nodo*)malloc(sizeof(nodo));
            nuevovalor->numerador = numerador;
            nuevovalor->denominador = denominador;
            nuevovalor->sig = NULL;

            if(lista == NULL){
                lista = nuevovalor;
                actual = nuevovalor;
            }else{
                actual->sig = nuevovalor;
                actual = nuevovalor;
            }   

        } 

        

    }  

    return lista;
    
} 


nodo *imprimir(nodo *aux){

    nodo *temporal = aux;

    if(temporal != NULL){
        while (temporal != NULL){
          printf("(%i,%i) ", temporal->numerador, temporal->denominador);
          temporal = temporal->sig;
        }

        printf ("\n\n");

    }else printf ("Lista vacia\n\n");
}

nodo *sumaLista(nodo *lista, int n){

    int i, sumNum = 0, sumDen = 1;

    if(lista != NULL){

        for(i = 0 ; i < n ; i++){

            sumNum = sumNum * lista->denominador + lista->numerador * sumDen;
            sumDen = sumDen * lista->denominador;
            lista = lista->sig;

        }

    }
    
}

