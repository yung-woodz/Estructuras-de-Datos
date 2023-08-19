#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 7

typedef struct{
    int key;
    int value;
    struct NODO* next;
}NODO;

typedef struct tabla {
    NODO* table[TAMANO];
}tabla;

int hash(int key) {
    return (2 * key + 1) % TAMANO;
}

tabla* creartabla() {
    tabla* ht = (tabla*)malloc(sizeof(tabla));
    for (int i = 0; i < TAMANO; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(tabla* ht, int key, int value) {
    int index = hash(key);
    NODO* nuevovalor = (NODO*)malloc(sizeof(NODO));
    nuevovalor->key = key;
    nuevovalor->value = value;
    nuevovalor->next = ht->table[index];
    ht->table[index] = nuevovalor;
}

int search(tabla* ht, int key) {
    int index = hash(key);
    NODO* aux = ht->table[index];
    while (aux != NULL) {
        if (aux->key == key) {
            return aux->value;
        }
        aux = aux->next;
    }
    return -1; // Valor no encontrado
}

void imprimirtabla(tabla* ht) {
    for (int i = 0; i < TAMANO; i++) {
        printf("Posición %d:", i);
        NODO* aux = ht->table[i];
        while (aux != NULL) {
            printf(" (%d, %d) ->", aux->key, aux->value);
            aux = aux->next;
        }
        printf("No hay\n");
    }
}

int main() {
    tabla* ht = creartabla();
    
    srand(time(NULL));
    for (int i = 0; i < TAMANO * 2; i++) {
        int key = rand() % 100; // Generar claves aleatorias entre 0 y 99
        int value = i + 1;
        insert(ht, key, value);
    }

    imprimirtabla(ht);

    // Realizar búsqueda con medición de tiempo
    int searchKey = rand() % 100;
    clock_t startTime = clock();
    int result = search(ht, searchKey);
    clock_t endTime = clock();

    if (result != -1) {
        printf("Valor asociado a la clave %d: %d\n", searchKey, result);
    } else {
        printf("Clave %d no encontrada.\n", searchKey);
    }

    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Tiempo de búsqueda: %f segundos\n", elapsedTime);

    // Liberar memoria
    for (int i = 0; i < TAMANO; i++) {
        NODO* aux = ht->table[i];
        while (aux != NULL) {
            NODO* temp = aux;
            aux = aux->next;
            free(temp);
        }
    }
    free(ht);

}
