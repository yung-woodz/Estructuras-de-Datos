#include<stdio.h>

void imprimeDatos(int b, int a);

int main (void){

    int a, b;
    a = 5;
    b = 10;
    imprimeDatos(5,10);
    return 0;

}

void imprimeDatos(int b, int a){

    printf("VALORES: %d y %d", a, b);

    return;

}
