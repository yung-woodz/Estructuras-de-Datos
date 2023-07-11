/* FiboPila: el N-ésimo término de la serie de Fibonacci usando diferentes formas: 
   recursividad, estructuramiento y una pila*/
#include <stdio.h>
#include <stdlib.h>

struct pila
{
  int dato;
  struct pila *sig;
};

typedef struct pila NODO;

NODO *push(NODO *L, int N)
{ 
  NODO *p;
  p = new(NODO);
  p->dato=N;
  p->sig = L; 
  return(p);
}

NODO *pop(NODO *L)
{ NODO *p;
  if (L!=NULL){   p = L;
                  L=L->sig; 
                  delete(p);
                  return(L);}
  else printf("Pila vacía");
}

int tos(NODO *L)
{  if (L!=NULL)return(L->dato);
   else {return(0);
         printf("Pila vacía");
    }
}

int FiboR(int n)
{   if (n < 3) return 1;
   else return (FiboR(n - 1) + FiboR(n - 2));
}
 
int Fibo(int n)
{    if (n < 3) return 1;
    else 
    {   int eneMenosUno = 1;
        int eneMenosDos = 1;
        int contador = 2;
        int fib;
        do
        {
            contador++; 
            fib = eneMenosDos + eneMenosUno; 
            eneMenosDos = eneMenosUno;
            eneMenosUno = fib;
        } while (n != contador);
        return fib;
     } 
}

int FiboP(NODO *tope)
{    int aux,fibo =0;
     while (tope != NULL)
     { aux= tope->dato; tope=pop(tope); 
       if ( aux >= 2){
                    tope=push(tope, aux-1);
                    tope= push(tope, aux-2);
                    }
       else fibo = fibo + aux;
      }
     return(fibo);
}
 
int FiboPE(int N)
{    int aux,fibo =0,tope=-1,pila[20];
     tope++; pila[tope]=N;
     while (tope>=0)
     { aux= pila[tope]; tope--; 
       if ( aux >= 2){
                    tope++; pila[tope]=aux-1;
                    tope++; pila[tope]=aux-2;
                    }
       else fibo = fibo + aux;
      }
     return(fibo);
}    
 
int FiboPE2(int N)
{    int f=0,f1=1,f2=0,tope=0,pila[20];
     while (N>=2){
                    pila[tope]=N;
                    tope++;
                    N--;
                    while(tope>0){tope--;
                                   f=f1+f2;
                                   f2=f1;
                                   f1=f;
                                   }
                    }
                                   
    return(f);
}  
    
main()
{
int N,f1,f2,f3,f4,f5;
NODO  *tope=0;

do{
printf("\n\n El programa calcula el N-ésimo término de la sucesión de Fibonacci,\n ingrese el valor de N:");
scanf("%d",&N);}
while(N<=0);

tope=push(tope, N); 
f1=FiboR(N);
f2=Fibo(N);
f3=FiboP(tope);
f4=FiboPE(N);
f5=FiboPE2(N);
printf("\n\n El %d-ésimo término de la serie de Fibonacci es\nrecursiva:%d \nestructurada:%d \ncon Pila:%d\ncon Pila Estatica: %d\n",N,f1,f2,f3,f4);
printf("\n con otro método con pila: %d\n",f5);
system("pause");

}
