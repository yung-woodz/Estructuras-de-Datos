/* FilaCircular1: crea y destruye una fila con almacenamiento estático circular*/
#include <stdio.h>
#include <stdlib.h>
#define max 5

void printqueue(int qfront, int qrear, int cont, int cola[])
{int i,j=0;
 if (cont == 0) printf("\n la cola está vacía...");
 else {
      printf("\n La cola contiene los siguientes elementos (en orden de llegada):");
      i=qfront; 
      while (j<cont) {printf("  %d", cola[i]);
                             j++;
                             if(i==max-1)i=0;
                             else i++;
                             }
}
 printf("\n");
     }
     
void inqueue(int &qfront,int &qrear, int &cont, int cola[])
{ 
if (cont < max) {
         if(qrear == max-1) qrear=0;
         else qrear++;
         cont++;
         printf("\nIngrese el siguiente elemento de la fila:");scanf("%d",&cola[qrear]);  
         printf("\n\n Seguimiento: en inqueue, qfront %d, qrear %d, cont %d ", qfront, qrear, cont);
         }
else printf("\n overflow: la fila está llena...");
}

int dequeue(int &qfront,int &qrear, int &cont, int cola[])
{int aux=qfront;
if (cont != 0) { if (qfront == max-1)qfront=0;
                 else qfront++; 
                 cont--;
                 printf("\n en dequeue, qfront %d, qrear %d, cont %d cola:", qfront, qrear, cont, cola[qrear]);
                 return (cola[aux]);
         }
else {printf("\La fila está actualmente vacía, no es posible retirar un elemento...");
     return(0);
     }
}

int newqueue(int &qfront, int &qrear, int &cont)
{   int var;
    qfront=qrear=0; cont++;
    printf("\n Ingrese el primer elemento de la cola: ");scanf("%d",&var);
    return(var);
}


     
main()
{
int cola[max];
int N,c,i,qrear,qfront,cont=0;



do{
printf("\n\n1.- crea una nueva fila)");
printf("\n\n2.- añade un elemento a la fila");
printf("\n\n3.- retira un elemento de la fila");
printf("\n\n4.- despliega los elementos de la fila");
printf("\n\n5.- fin del programa");
printf("\n\n");
scanf("%d",&c);
switch(c) {
  case 1:{ 
       do{
          printf("\n\nIngrese el total de elementos de la fila, N:"); scanf("%d",&N);}
       while(N<=0);
       cola[0] = newqueue(qfront,qrear, cont);
       for(i=1;i<N;i++)inqueue(qfront, qrear, cont, cola);
       system("pause");
  break;}
  case 2: 
	{inqueue(qfront, qrear, cont, cola);
	 printqueue(qfront, qrear, cont, cola);
    system("pause");      
	break;}
  case 3: {
        i= dequeue(qfront, qrear, cont, cola);
	    printqueue(qfront, qrear, cont, cola);
        system("pause");
	 	break;}
  case 4: {
         printqueue(qfront, qrear, cont,cola);
         break;}
  case 5: {
           break;}
      }//fin del switch
 }while(c!=5);
 



}
