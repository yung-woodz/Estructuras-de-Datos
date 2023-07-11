/* 2. Dado un vector de enteros, encontrar un elemento objetivo. Buscar dentro de ese vector
    los dos indices que sumen ese objetivo
    
    Dilan Toro Moraga
    20.956.529-3

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int obj, n, i, j, posicI, posicJ, valor1 = 0, valor2 = 0;
    
    printf("Eliga el tamano de su arreglo: \n");
    do{
        scanf("%d", &n);
    }while(n<1);

    int vector[n];

    srand(time(NULL));

    for(i = 0 ; i < n ; i++){
        vector[i] = rand()%100;
    }

    for(i = 0 ; i < n ; i++){
        printf("[%d]", vector[i]);
    }

    printf("\nIngrese el elemento objetivo: ");
    do{
        scanf("%d", &obj);
    }while(obj < 0);

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if((vector[i] + vector[j]) == obj){
                posicI = i;
                posicJ = j;
                valor1 = vector[i];
                valor2 = vector[j];
            }
        }

    }

    if((valor1 == 0)&&(valor2 == 0)){
        printf("No hay :(");
    } else{
        printf("Los valores que suman el objetivo %d son: [%d] + [%d]", obj, valor2, valor1);
        printf("\nCon posicion %d y %d del arreglo generado", posicJ, posicI);
    }

}