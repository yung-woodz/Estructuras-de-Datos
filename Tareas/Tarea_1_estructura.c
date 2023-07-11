#include<stdio.h>
#include<stdlib.h>
//Declarar struct
typedef struct {
    int numerador, denominador;
    struct nodo *sig;
}nodo;

//Declarar Funciones 
nodo *opcion1(nodo *lista); 
nodo *opcion2();
nodo *opcion3();
nodo *opcion4();
nodo *opcion5();
nodo *opcion6();
nodo *opcion7();
//lista vacia
nodo *crear(nodo *lista);
//agragar nodo
nodo *agregar(nodo *lista, int numerador, int denominador);

//INT MAIN
int main(){
    nodo *lista;
    int menu;
    //Menu
    while(menu!=8){
        printf("Presione 1 para ingresar elementos\n");
        printf("Presione 2 para eliminar uno o mas elementos especificos\n");
        printf("Presione 3 para mostrar la suma de todos los elementos\n");
        printf("Presione 4 para mostrar el producto de todos los elementos\n");
        printf("Presione 5 para buscar un elemento \n");
        printf("Presione 6 para mostrar el cuociente entre el mayor y menor valor\n");
        printf("Presione 7 para ordenar la lista\n");
        printf("Presione 8 para salir del programa\n");
        printf("%c",175);
        scanf("%d",&menu);
        switch (menu){
        case 1:
            
            lista = opcion1(lista);

            printf("\nPresione cualquier tecla para volver al menu...\n");
        break;
        case 2:
            system("cls");
            opcion2();

            printf("\nPresione cualquier tecla para volver al menu...\n");
            getch();
            system("cls");
        break;
        case 3:
            system("cls");
            opcion3();

            printf("\nPresione cualquier tecla para volver al menu...\n");
            getch();
            system("cls");
        break;
        case 4:
            system("cls");
            opcion4();

            printf("\nPresione cualquier tecla para volver al menu...\n");
            getch();
            system("cls");
        break;
        case 5:
            system("cls");
            opcion5();

            printf("\nPresione cualquier tecla para volver al menu...\n");
            getch();
            system("cls");
        break;
        case 6:
            system("cls");
            opcion6();

            printf("\nPresione cualquier tecla para volver al menu...\n");
            getch();
            system("cls");
        break;
        case 7:
            system("cls");
            opcion7();

            printf("\nPresione cualquier tecla para volver al menu...\n");
            getch();
            system("cls");
        break;
        case 8:
            exit(-1);
        default:
            system("cls");
            printf("##Ingrese una opcion valida##\n");
        break;
        }
    }
    
}

///FUNCIONES///  

//Opcion 1 Ingresar valores
nodo *opcion1(nodo *lista){

    lista = crear(lista);
    int numerador,denominador,i,n,menu;
    printf("Presione 1 para ingresar elementos (Orden de llegada)\n");
    printf("Presione 2 para ingresar elementos (Posicion espesifica)\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        printf("Cuantos elementos desea agregar?: ");
        scanf("%d",&n);
        while(n<0){
            printf("Ingrese un numero valido: ");
            scanf("%d",&n);
        }

        for(i=0; i<n; i++){
            printf("Ingrese el valor %d: \n", i+1);
            printf("\t->Numerador: ");
            scanf("%i", &numerador);
            printf("\t->Denominador: ");
            scanf("%i", &denominador);
            lista = agregar(lista, numerador, denominador);
        }

        printf("\n");
        return lista;
    break;

    case 2:
        
        if(lista == NULL){
            printf("No existe lista");
        }else{
            while (lista != NULL) {
                printf("(%i,%i) ", lista->numerador, lista->denominador);
        
                lista = lista->sig;
        
            }
        }

        

    break;

    
    default:
        printf("Error");
        break;
    }

    return lista;
}
//Opcion 2 eliminar un elemento 
nodo *opcion2()
{
    
}

//Opcion 3 mostrar la suma de todo
nodo *opcion3(){
    
}
//Opcion 4 producto de todo
nodo *opcion4(){

}
//opcion 5 buscar un elemento
nodo *opcion5(){
    int menu1;
    printf("Presione 1\n");
    printf("Presione 2\n");
    printf("Presione 3\n");
    switch (menu1){
    case 1:
        
        break;
    
    default:
        break;
    }

}
//opcion 6 division de mayor y menor 
nodo *opcion6(){

}
//opcion 7 ordenar lista 
nodo *opcion7(){
    int menu;
    printf("Presione 1\n");
    printf("Presione 2\n");
    switch (menu){
    case 1:
        
        break;
    
    default:
        break;
    }
}
//Crear lista vacia 
nodo *crear(nodo *lista){

    lista = NULL;
    return lista;

}
//Agregar lista 
nodo *agregar(nodo *lista, int numerador, int denominador){

    nodo *nuevovalor, *aux;
    nuevovalor = (nodo*)malloc(sizeof(nodo));
    nuevovalor->numerador = numerador;
    nuevovalor->denominador = denominador;
    nuevovalor->sig = NULL;

    if(lista == NULL){
        lista = nuevovalor;
    }else{
        aux = lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevovalor;
    }

    return lista;
}


