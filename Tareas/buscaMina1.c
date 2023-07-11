#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int i, j, posicionI, posicionJ;

    char matriz[4][4];

    int contador = 0, cto = 0;

    // 0 1 2 3

    srand(time(NULL));

    printf("  1  2  3  4\n");

    for(i = 0 ; i < 4 ; i++){ // Matriz vacía imprimida

        printf("%d", i+1);

        for(j = 0 ; j < 4 ; j++){

            matriz[i][j] = '*';

            printf("[%c]", matriz[i][j]);
        }
        printf("\n");
    }
    

    for(i = 0 ; i < 4 ; i++){ // matriz con minas sin imprimir

        for(j = 0 ; j < 4 ; j++){

            matriz[i][j] = '*';
            
            contador = rand()%2; // 0 1

            if(cto < 4){

                if(contador == 1){
                    matriz[i][j] = 'M';
                    cto = cto + 1;
                } 

            }

        }

    }
    
    printf("\n");

    scanf("%d%d", &posicionI, &posicionJ);

    for(i = posicionI-1 ; i < 4 ; i++){
        for (j = posicionJ-1 ; i < 4 ; j++){
            
            if((i && j) == 'M'){
                printf("perdiste");
            }else{
                break;
            }

        } 
    }

}