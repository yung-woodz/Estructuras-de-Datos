#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){

 	int fila,columna,i,j;
	char matriz [4][4];
    char mina = 'M';
	int cont = 0, contador=0;
    int posicionI, posicionJ;
	
    fila = 4;
    columna = 4;

    srand (time(NULL));
    
    printf("   (1)(2)(3)(4)\n");
    
   for(i = 0 ; i < fila ; i++){ // Matriz vacía imprimida

        printf("(%d)", i+1);

        for(j = 0 ; j < columna ; j++){

            matriz[i][j] = '*';

            printf("[%c]", matriz[i][j]);
        }
        printf("\n");
    }
    

    for(i = 0 ; i < fila ; i++){ // matriz con minas sin imprimir

        for(j = 0 ; j < columna ; j++){

            matriz[i][j] = '*';
            
            contador = rand()%2; // 0 1

            if(cont < 4){

                if(contador == 1){
                    matriz[i][j] = 'M';
                    cont = cont + 1;
                } 

            }

        }

    }
    
    printf("\n");

    scanf("%d%d", &posicionI, &posicionJ);

    if(matriz[posicionI-1][posicionJ-1] == mina){
        printf("perdiste");
    }
    
    return 0;

}
