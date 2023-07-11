/*  Deivid Anyel Sandoval Cid 21.538.458-6
    Dilan Alonso Toro Moraga 20.956.529-3   */

#include<stdio.h>
#include<stdlib.h>
//Declarar struct
typedef struct {
    int numerador, denominador;
    int indice;
    struct nodo *sig;
}nodo;

// FUNCIONES

nodo *agregar(nodo *lista, int n);
nodo *eliminarLista(nodo *lista);
nodo *eliminarNodo(nodo *lista);
void actualizarIndices(nodo *lista);
nodo *imprimir(nodo *aux);
double sumarFracciones(nodo *lista);
int mcd(int a, int b);
void multiplicarFracciones(nodo *lista);
nodo *insertar(nodo *lista,int posicion);
nodo *buscarElemento(nodo *lista);
void buscarMayor(nodo *lista,int bandera);
nodo *ordenarAsc(nodo *lista);

int main() {
    nodo *lista = NULL;

    int n, op, op1, op2, op3, op4, posicion,bandera=0;

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

            case 1: // INGRESAR ****LISTO****

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
                        if(lista!=NULL){
                            //Funcion eliminar///////////////
                            eliminarLista(lista);
                            lista = NULL;
                            printf("cuantos nodos quieres?: ");
                            scanf("%d", &n);
                            lista = agregar(lista, n);
                            imprimir(lista);       
                        }else{
                            printf("cuantos nodos quieres?: ");
                            scanf("%d", &n);
                            lista = agregar(lista, n);
                            imprimir(lista);
                        }

                    break;

                    case 2: // ingresar un valor en una posicion especifica

                       imprimir(lista);
                        if(lista!=NULL){
                            printf("En que posicion desea ingresar un nuevo nodo?: ");
                            scanf("%d",&posicion);
                       
                            lista = insertar(lista,posicion);
                            printf("Se ha remplazado exitosamente\n");
                            imprimir(lista);      
                        }
                    break;

                    case 3:
                        // No es necesario colocar algo aqui ya que esta dentro de un
                        // bucle infinito y puede volver al menu
                    break;
                }
        

            break;
            
            case 2: // ELIMINAR ****LISTO****

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

                        imprimir(lista);
                        if(lista != NULL){
                            lista = eliminarNodo(lista);
                        }

                    break;

                    case 2:
                    break;

                }

            break;

            case 3: // CALCULAR ****LISTO****

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

                        sumarFracciones(lista);

                    break;

                    case 2: // MULTIPLICACION

                        multiplicarFracciones(lista);

                    break;

                }



            break;

            case 4: // EFECTUAR (4)

                do{
                    system("cls");
                    printf("\t\tEFECTUAR\n");
                    printf("\t--Seleccione una opcion--\n");
                    printf("\t1. Buscar un elemento de la lista\n");
                    printf("\t2. Buscar el elemento de mayor valor e indicar la primera posicion en que se encuentra\n");
                    printf("\t3. Buscar el elemento de menor valor, imprimirlo e indicar cuantas veces se repite\n");
                    printf("\t4. Efectuar la division del elemento de mayor valor por el de menor valor\n");
                    printf("\t5. Volver\n");
                    printf("\n     -> ");
                    scanf("%d", &op4);
                }while(op4 < 1 || op4 > 5);

                

                while (op4<1 || op4>5)
                {
                    printf("\n##Ingrese una opcion valida##");
                    printf("\n     -> ");
                    scanf("%d", &op4);
                }
                switch (op4){
                case 1:
                        if(lista!=NULL){
                            lista = buscarElemento(lista);
                        }else{
                            printf("\n\tLista Vacia");
                        }

                    break;
                case 2:
                        bandera=0;
                        if(lista!=NULL){
                            buscarMayor(lista,bandera);
                            imprimir(lista);
                        }else{
                            printf("\n\tLista Vacia");
                        }

                    break;
                case 3:
                        bandera=1;
                        if(lista!=NULL){
                            buscarMayor(lista,bandera);
                            imprimir(lista);
                        }else{
                            printf("\n\tLista Vacia");
                        }
                    break;
                case 4:
                        bandera=3;
                        if(lista!=NULL){
                            buscarMayor(lista,bandera);
                        }else{
                            printf("\n\tLista Vacia");
                        }
                    break;
                
                default:
                    break;
                }
                
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
            nuevovalor->indice = i+1;

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
    printf ("\n");
    if(temporal != NULL){
        while (temporal != NULL){
          printf("| %d. (%i,%i) ",temporal->indice ,temporal->numerador, temporal->denominador);
          temporal = temporal->sig;
        }
        printf ("|");
        printf ("\n\n");
    }else printf ("Lista vacia\n\n");
}

double sumarFracciones(nodo *lista) {
    nodo *actual = lista;
    double denominador_comun = 1.0;
    double resultado = 0.0;
    
    // Calcular el denominador común
    while (actual != NULL) {
        denominador_comun = denominador_comun * actual->denominador;
        actual = actual->sig;
    }
    
    actual = lista;
    while (actual != NULL) {
        resultado = resultado + (actual->numerador * (denominador_comun / actual->denominador));
        actual = actual->sig;
    }
    
    // Simplificar la fracción resultante
    double mcd_val = mcd(resultado, denominador_comun);
    resultado = resultado / mcd_val;
    denominador_comun = denominador_comun / mcd_val;
    
    // Crear la fracción simplificada
    nodo *fraccion = (nodo*)malloc(sizeof(nodo));
    fraccion->numerador = resultado;
    fraccion->denominador = denominador_comun;
    fraccion->sig = NULL;
    
    // Imprimir la fracción simplificada
    printf("El resultado es: (%.0f,%.0lf)", resultado, denominador_comun);
    
    return resultado;
}

int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void multiplicarFracciones(nodo *lista) {
    nodo *actual = lista;
    int numerador_total = 1;
    int denominador_total = 1;

    // Multiplicar los numeradores y los denominadores
    while (actual != NULL) {
        numerador_total *= actual->numerador;
        denominador_total *= actual->denominador;
        actual = actual->sig;
    }

    // Simplificar la fracción resultante utilizando el MCD
    int divisor_comun = mcd(numerador_total, denominador_total);
    numerador_total /= divisor_comun;
    denominador_total /= divisor_comun;

    // Imprimir el resultado
    printf("El resultado es: (%i,%i)", numerador_total, denominador_total);
}

nodo *insertar(nodo *lista,int posicion){
    nodo *nuevovalor=lista;
    int numerador, denominador;
    while(nuevovalor!=NULL){
        if(nuevovalor->indice==posicion){
            printf("Ingrese el valor %d: \n", posicion);
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
            nuevovalor->numerador = numerador;
            nuevovalor->denominador = denominador;

        }
        nuevovalor=nuevovalor->sig;
    }
    return lista;
}

nodo *buscarElemento(nodo *lista){
    nodo *temporal=lista;
    int aux=0,numerador,denominador;
    printf("\n\tIngrese el elemento que desea buscar \n");
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
    while (temporal!=NULL){
        if(temporal->numerador==numerador || temporal->denominador==denominador){
            printf("\nEl elemento si se encuentra en la lista\n");
            printf("Posicion del elemento: nodo %d \n",temporal->indice);
            imprimir(lista);
            aux=1;
        }
        temporal=temporal->sig;
    }

    if(aux==0){
        printf("\nEl elemento no se encuentra en la lista\n");
    }
    return lista;
}

void buscarMayor(nodo *lista,int bandera){

    nodo *temporal=lista,*segundoT=lista,*tercerT=lista;
    int mayor=0,menor=0,cont=-1;
    float numerador1,denominador1,numerador2,denominador2;
    float div1,div2,menorDiv,mayorDiv,resultDiv;

    while(temporal!=NULL){

        numerador1 = (float) temporal->numerador;
        denominador1= (float) temporal->denominador;
        div1= numerador1/denominador1;

        while(segundoT!=NULL){

            numerador2=(float) segundoT->numerador;
            denominador2=(float) segundoT->denominador;
            div2= numerador2/denominador2;
            //comparar si es mayor
            if(div1>div2){
                mayor=temporal->indice;
                mayorDiv=div1;
            }else{
                mayor=segundoT->indice;
                mayorDiv=div2;
            }
            //menor valor
            if (div1<div2)
            {
                menor=temporal->indice;
                menorDiv=div1;
            }else{
                menor=segundoT->indice;
                menorDiv=div2;
            }

            segundoT=segundoT->sig;
        }
        temporal=temporal->sig;
    }
    while(tercerT!=NULL){

        numerador1 = (float) tercerT->numerador;
        denominador1= (float) tercerT->denominador;
        div1= numerador1/denominador1;

        if(menorDiv==div1){
            cont++;
        }
        
        tercerT=tercerT->sig;
    }
    
    
    resultDiv=mayorDiv/menorDiv;

    if(bandera==0){
        printf("\nEl elemento de mayor valor se encuentra en la posicion: %d\n",mayor);
    }
    if (bandera==1){
        printf("\nEl elemento de menor valor se en encuentra en la posicion: %d\n",menor);
        printf("\nY se repite %d vez/veces en la lista \n",cont);
    }

    if (bandera==3){
        printf("\nEl resultado de el mayor valor dividido el menor valor es: %f\n",resultDiv);
    }
    
}

nodo *eliminarLista(nodo *lista){

    nodo *actual = lista;
    nodo *siguiente = NULL;

    while(actual != NULL){

        siguiente = actual->sig;
        free(actual);
        actual = siguiente;

    }

}

nodo *eliminarNodo(nodo *lista){

    nodo *actual = lista;
    nodo *anterior = NULL;

    int numerador, denominador;

    if(lista != NULL){
        printf("Ingrese el valor a eliminar: \n");
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
    }

    while(actual != NULL && (actual->numerador != numerador && actual->denominador != denominador)){
        anterior = actual;
        actual = actual->sig;
    }

    if(actual == NULL){
        // Si el valor no se encuentra en la lista
        return lista;
    }

    if(anterior == NULL){
        // El nodo que contiene el valor es la "cabeza" de la lista
        lista = actual->sig;
        actualizarIndices(lista);
        imprimir(lista);
        printf("\nValor eliminado exitosamente\n");
    } else{
        // El nodo que contiene el valor está en medio o al final de la lista
        anterior->sig = actual->sig;
        actualizarIndices(lista);
        imprimir(lista);
        printf("\nValor eliminado exitosamente\n");
    }

    free(actual);
    return lista;

}

void actualizarIndices(nodo *lista){
    int i = 1;
    nodo *temp = lista;
    while(temp != NULL){
        temp->indice = i;
        i++;
        temp = temp->sig;
    }
}

nodo *ordenarAsc(nodo *lista){

    nodo *temporal=lista,*segundoT=lista,*tercerT=lista, *aux = NULL, *actual = NULL, *listaNueva = NULL;
    int mayor=0,menor=0,cont=-1;
    float numerador1,denominador1,numerador2,denominador2;
    float div1,div2,menorDiv,mayorDiv,resultDiv;

    while(temporal!=NULL){

        numerador1 = (float) temporal->numerador;
        denominador1= (float) temporal->denominador;
        div1= numerador1/denominador1;

        while(segundoT!=NULL){

            numerador2=(float) segundoT->numerador;
            denominador2=(float) segundoT->denominador;
            div2= numerador2/denominador2;
            //menor valor
            if (div1<div2)
            {
                menor=temporal->indice;
                menorDiv=div1;
            }else{
                menor=segundoT->indice;
                menorDiv=div2;
            }

            segundoT=segundoT->sig;
        }
        temporal=temporal->sig;
    }

    while(tercerT != NULL){
        if(menor == tercerT->indice){

            aux = (nodo*)malloc(sizeof(nodo));
            aux->numerador = tercerT->numerador;
            aux->denominador = tercerT->denominador;
            aux->sig = NULL;

            if(listaNueva == NULL){
                listaNueva = aux;
                actual = aux;
            }else{
                actual->sig = aux;
                actual = aux;
            }

        }
        tercerT = tercerT->sig;

    }

}

