#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int valor;
    struct Nodo *siguiente;
}Nodo;

Nodo* insertar(Nodo* cabeza, int nuevo_valor) {
  Nodo* nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
  nuevo_nodo->valor = nuevo_valor;
  nuevo_nodo->siguiente = NULL;
  
  if(cabeza == NULL) {
    cabeza = nuevo_nodo;
  } else {
    Nodo* actual = cabeza;
    while(actual->siguiente != NULL) {
      actual = actual->siguiente;
    }
    actual->siguiente = nuevo_nodo;
  }
  
  return cabeza;
}

void mostrar(Nodo* cabeza) {
  Nodo* actual = cabeza;
  
  while(actual != NULL) {
    printf("%d ", actual->valor);
    actual = actual->siguiente;
  }
  printf("\n");
}

Nodo* eliminar(Nodo* cabeza, int indice) {
  Nodo* eliminar_nodo;
  
  if(cabeza == NULL) {
    return cabeza;
  }
  
  if (indice == 0) {
    eliminar_nodo = cabeza;
    cabeza = cabeza->siguiente;
    free(eliminar_nodo);
    return cabeza;
  }
  
  Nodo* anterior = cabeza;
  Nodo* actual = cabeza->siguiente;
  
  for(int i = 1; actual != NULL && i < indice; i++){
    anterior = actual;
    actual = actual->siguiente;
  }
  
  if(actual != NULL) {
    anterior->siguiente = actual->siguiente;
    free(actual);
  }
  
  return cabeza;
}


int main(){

    Nodo *cabeza = NULL;

    int n, valor;
  
    printf("Ingrese la cantidad de elementos que desea insertar en la fila: ");
    scanf("%d", &n);
  
    for(int i = 0; i < n; i++) {
        printf("Ingrese el valor para el elemento %d: ", i+1);
        scanf("%d", &valor);
        cabeza = insertar(cabeza, valor);
    }
  
    printf("La fila es: ");
    mostrar(cabeza);
  
    int indice;
    printf("Ingrese el indice del elemento que desea eliminar: ");
    scanf("%d", &indice);
    cabeza = eliminar(cabeza, indice);
  
    printf("La fila despues de eliminar el elemento es: ");
    mostrar(cabeza);

}
