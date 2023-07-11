#include<stdio.h>

int main() {

    float n = 3.9;
    float *ptr = &n;
    n = 3.8;

    printf("El valor de n es %f", *ptr);

}