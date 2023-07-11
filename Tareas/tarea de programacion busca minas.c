#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, j;
	int contador=0, cto=0;
	int fila, columna;
	int ganaste;
	int matjuego[4][4];
	int matriz[4][4];
	
	srand (time(NULL));
	
	for(i=0; i<4; i++){ //crear matriz vacio
		
		for(j=0; j<4; j++){
			
			matriz [i][j] = 9;
			contador = rand()%2;
			
			if (cto<4){
				
				if (contador==1){
					
					matriz[i][j] = 1; //agregar las 4 minas de forma aletoria
					cto = cto + 1;	
				}
			}	
		}
	}
	
	printf("\n"); 
	
	
	for(i=0; i<4; i++){ // matriz con minas vicibles
		
		for(j=0; j<4; j++){
		
			if (matriz[i][j]=='M'){	
			
			}
		}
	} //validar posicione de las minas

	for (i=0;i<4;i++){ //validacion lado de arriba
		for (j=0;j<4;j++){
		
			if (matriz[i][j]!= 'M'){
				matriz[i][j] = 0;
				
				if (matriz[i-1][j-1] == 'M' && i > 0 && j > 0){
					matriz [i][j] = matriz[i][j] + 1;
					
					if (matriz[i-1][j] == 'M' && i>0){
						matriz[i][j] = matriz[i][j] + 1;
						
						if (matriz[i-1][j+1] == 'M' && i > 0 && j > 3){
							matriz[i][j] = matriz[i][j] + 1;
						}
					}
				}
			}
		}
	}
	
	for (i=0; i<4; i++){ //validacion lado izquierdon y derecho
		for (j=0; j<4; j++){
			
			if (matriz[i][j]!= 'M'){
				matriz[i][j] = 0;
				
				if (matriz[i][j-1] == 'M' && j > 0){
					matriz[i][j] = matriz[i][j] + 1;
					
					if (matriz[i][j+1] == 'M' && j < 3){
						matriz[i][j] = matriz[i][j] + 1;
					}
				}
			}
		}
	}
	
	for  (i=0; i<4; i++){ //validar lado de abajo
		for (j=0; j<4; j++){
			
			if (matriz[i][j]!= 'M'){
				matriz[i][j] = 0;
				
				if (matriz[i+1][j-1] == 'M' && i < 3 && j > 0){
					matriz[i][j] = matriz[i][j] + 1;
					
					if (matriz[i+1][j] == 'M' && i < 3){
						matriz[i][j] = matriz[i][j] + 1;
						
						if (matriz[i+1][j+1] == 'M' && i < 3 && j < 3){
							matriz[i][j] = matriz[i][j] + 1;
						}
					}
				}
			}
		}
	}

	//iniciar juego
	
	
	for (i=0; i<4; i++){
		
		for (j=0; j<4; j++){
			
			matjuego[i][j] = 32; 
		}
	}
	
	printf("  1  2  3  4\n");
	
	for (i=0;i<4;i++){ //matriz juego
		printf("%d", i+1);
		
		for (j=0;j<4;j++){
			
			if (matjuego[i][j] == 32 || matjuego [i][j] == 'M'){
				printf("[%c]", matjuego[i][j]);
				
			} else {
				printf("[%d]", matjuego[i][j]);
				
			}
		}
		printf("\n");
	}
	
	do {
		printf("Seleccionar fila \n");
		do{
			scanf("%d", &fila);
			
			if (fila>4 || 1>fila){
				printf("La linea tiene que ser entre 1 y 4 \n");
				
			}
	} while (fila>4 || 1>fila);
	
	fila = fila - 1;
	
	printf("Seleccione una columna \n");
	
	do{
		scanf("%d", &columna);
		if (columna>4 || 1>columna){
			printf("La columna tiene que ser entre 1 y 4 \n");
			
		}
	} while (columna>4 || 1>columna);
	
	columna = columna - 1;
	
	if (matjuego[fila][columna] == matriz[fila-1][columna-1]){
		system("cls");
		
	printf("  1  2  3  4\n");
	
	for (i=0;i<4;i++){
		printf("%d", i+1);
		
		for (j=0;j<4;j++){
			
			if(matjuego[i][j]=='M'||matjuego[i][j]==32){
				printf("[%c]", matjuego[i][j]);
								
			} else {
				printf("[%d]", matjuego[i][j]);
				
			}
		}
		printf("\n");
	}
	
	printf("Seleccionas la misma fila \n");
	} 
	else {
		matjuego[fila][columna] = matriz[fila-1][columna-1];
		
		if(matjuego[fila][columna] != 'M'){
			
			system("cls");
			ganaste = ganaste + 1 ;
			
			printf("  1  2  3  4\n");
			for (i=0;i<4;i++){
				printf("%d", i+1);
				
				for (j=0;j<4;j++){
					if (matjuego[i][j] == 32 || matjuego [i][j]== 'M'){
						printf("[%c]", matjuego[i][j]);
					} else {
						printf("[%d]", matjuego[i][j]);
				}
			}
		printf("\n");
		}
		printf("Te faltan [%d] casillas \n ", 12 - ganaste);
	}
	}
	
	} while (ganaste != 12 && matjuego[fila][columna] != 'M');
	
	//perder
	if (matjuego[fila][columna] == 'M'){
	system("cls");	
	
	for(i=0;i<4;i++){
		
		for(j=0;j<4;j++){
			matjuego[i+1][j+1] = matriz[i][j];
		}
	}
	
	for(i=0;i<4;i++){
		
		for (j=0;j<4;j++){
			
			if(j==0){
				matjuego[i][j] = i;
				
			}
		}
	}
	
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			
			if(matjuego[i][j] == 'M'){
				printf("[%c]", matjuego[i][j]);
								
			} else {
				printf("[%d]", matjuego[i][j]);
				
			}
		}
		printf("\n");
	}     
	}
	
	//ganar
	if (ganaste == 12){
		system ("cls");
		
		for (i=0; i<4; i++){
			
			for (j=0; j<4; j++){
				matjuego[i+1][j+1]=matriz[i][j];
			}	
		}
	}
	
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			
			if (j == 0)
			matjuego[i][j] = i;
		}
	}
	
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			
			if(matjuego[i][j]=='M'){
				printf("[%c]", matjuego[i][j]);
								
			} else {
				printf("[%d]", matjuego[i][j]);
			}
		}
		printf("\n");	
	}
 
}
