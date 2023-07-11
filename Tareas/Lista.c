#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int num;
    struct nodo *link;
} Nodo;

Nodo *crearLista(int n);
Nodo *insertarNodo(Nodo *cabeza);
Nodo *eliminar(Nodo *cabeza, int X);
int buscar(Nodo *cabeza, int X);
void imprimirLista(Nodo *aux);
Nodo *invertir(Nodo *lista);
void menu();



Nodo *crearLista(int n)
{
    Nodo *lista = NULL, *aux = NULL, *nuevo = NULL;
    if (n > 0)
    {
        lista = (Nodo *)malloc(sizeof(Nodo));
        lista->num = rand() % 100;
        lista->link = NULL;
        aux = lista;
        for (int i = 1; i < n; i++)
        {
            nuevo = (Nodo *)malloc(sizeof(Nodo));
            nuevo->num = rand() % 100;
            nuevo->link = NULL;
            aux->link = nuevo;
            aux = aux->link;
        }
    }
    return lista;
}

Nodo *insertarNodo(Nodo *cabeza)
{
    Nodo *aux = cabeza, *nuevo = NULL;
    if (cabeza != NULL)
    {
        while (aux->link != NULL)
            aux = aux->link;
    }
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->num = rand() % 100;
    nuevo->link = NULL;
    if (cabeza == NULL)
        cabeza = nuevo;
    else
        aux->link = nuevo;
    return cabeza;
}

Nodo *eliminar(Nodo *cabeza, int X)
{
    Nodo *anterior = NULL, *actual = cabeza;
    while (actual != NULL)
    {
        if (actual->num == X)
        {
            if (anterior == NULL)
                cabeza = actual->link;
            else
                anterior->link = actual->link;
            free(actual);
            break;
        }
        anterior = actual;
        actual = actual->link;
    }
    return cabeza;
}

int buscar(Nodo *cabeza, int X)
{
    while (cabeza != NULL)
    {
        if (cabeza->num == X)
            return 1;
        cabeza = cabeza->link;
    }
    return 0;
}

void imprimirLista(Nodo *aux)
{
    if (aux == NULL)
    {
        printf("Lista vacia\n");
        return;
    }
    while (aux != NULL)
    {
        printf("[%d] ", aux->num);
        aux = aux->link;
    }
    printf("\n");
}

Nodo *invertir(Nodo *lista)
{
    Nodo *anterior = NULL, *actual = lista, *siguiente = NULL;
    while (actual != NULL)
    {
        siguiente = actual->link;
        actual->link = anterior;
        anterior = actual;
        actual = siguiente;
    }
    return anterior;
}

void menu()
{
    Nodo *lista = NULL;
    int opcion = 0, n = 0, X = 0;
    do
    {
        printf("1. Crear lista\n");
        printf("2. Insertar nodo\n");
        printf("3. Eliminar nodo\n");
        printf("4. Buscar elemento\n");
        printf("5. Imprimir lista\n");
        printf("6. Invertir lista\n");
        printf("7. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Crear lista de n nodos: ");
            scanf("%d", &n);
            lista = crearLista(n);
            break;
        case 2:
            lista = insertarNodo(lista);
            break;
        case 3:
            printf("Eliminar elemento: ");
            scanf("%d", &X);
            lista = eliminar(lista, X);
            break;
        case 4:
            printf("Buscar elemento: ");
            scanf("%d", &X);
            if (buscar(lista, X))
                printf("Elemento encontrado\n");
            else
                printf("Elemento no encontrado\n");
            break;
        case 5:
            imprimirLista(lista);
            break;
        case 6:
            lista = invertir(lista);
            break;
        case 7:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 7);
}

int main()
{
    menu();
    return 0;
}