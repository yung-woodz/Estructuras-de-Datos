/* 1. Dado una cadena de caracteres, encontrar la cantidad de letras de la ultima palabra
	teniendo en cuenta existir espacios en la ultima palabra que no pueden contar

    Dilan Toro Moraga
    20.956.529-3
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    char vector[20];

}vector;

int main (){

    vector v;

    int i, contador = 0;

    gets(v.vector);
    fflush(stdin);

    printf("\n%s", v.vector);

    int longitud = strlen(v.vector);

    for(i = longitud - 1 ; i >= 0 ; i--){

        if(v.vector[i] != ' '){

            contador++;

        }else{

            break;

        }

    }

    printf("\nLa longitud es: %d", longitud);
    printf("\nContador: %d", contador);

}