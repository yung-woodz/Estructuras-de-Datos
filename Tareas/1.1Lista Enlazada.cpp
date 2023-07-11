#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
     int num;
     struct nodo *link;
}*NODO;

NODO Invertir(NODO lista){
     NODO p,aux,aux2;
     aux=p=lista;
     while(p != NULL){
          aux2=aux;
          aux=p;
          p=p->link;
          if(aux==lista){
               lista->link=NULL;
          }
          else{
             aux->link=aux2;
          }
     }
     return aux;
}

NODO Crear_lista(int n){//funcion que crea una lista 
     NODO aux, lista=NULL, nuevo;
     int cont=0;
     if(n>0){
        lista = new nodo;
        lista->num=rand()%100;
        lista->link = NULL;
        aux = lista;
        cont = 1;
        while (cont != n){
              nuevo = new nodo;
              nuevo->num=rand()%100;
              nuevo->link = NULL;
              aux->link = nuevo;
              aux = aux->link;
              cont++;
          }
     }
     return lista;

} 
NODO insertaNodo(NODO h){
     NODO aux, nuevo;
     if (h!=NULL){
          aux=h;
          while(aux->link != NULL) aux=aux->link;
          nuevo = new nodo;
          nuevo->num=rand()%100;
          nuevo->link = NULL;
          aux->link = nuevo;
     }else {
          nuevo = new nodo;
          nuevo->num=rand()%100;
          nuevo->link = NULL;
          h=nuevo;
     }
     return h;
} 
void Imprimir_lista (NODO aux){//Funcion que mprime la lista
     if(aux != NULL){
        while (aux != NULL){
          printf ("[%d] ", aux->num);
          aux = aux->link;
          }
          printf ("\n\n");
     }
     else printf ("Lista vacía\n\n");
}

int buscar(NODO h, int X){
     int flag=0;
    while(h!= NULL){
	     if(h->num== X)flag=1;
          h=h->link;
     }
    return(flag); //si sale del while con 0 es que no está X o la lista es vacía
}

NODO eliminar(NODO h, int X){
     NODO p,q;
     p=h;
    if (h!=NULL){
          if(p->num == X){
               h=h->link;
               delete(p);
          }else {
               q=p->link;
               while(q->num != X) {
                    p=q;
                    q=q->link;
               }
               p->link=q->link;
               delete(q);
          }
     }
    else printf ("Lista vacía\n\n");
    return(h);
}    
    
void instrucciones( void ){
   printf( "Introduzca su eleccion:\n"
      "   1 para crear una lista randómica de N elementos\n"
      "   2 para imprimir la lista \n"
      "   3 para insertar un nuevo elemento en la lista\n"
      "   4 para eliminar un elemento de la lista.\n"
      "   5 para invertir la lista\n"
      "   6 para terminar la ejecución\n" );
} 

main(){
     NODO h=NULL;
     int n,s;
     char eleccion;
     instrucciones();
     scanf("%c",&eleccion);
     /* repite mientras el usuario no elija 6 */
     do {

          switch ( eleccion ) {
          case '1':  { 
               printf("Ingrese total de nodos de la lista\n"); 
               scanf("%d",&n);
               h=Crear_lista(n); 
               Imprimir_lista(h);
          break;}

          case '2':  {
               Imprimir_lista(h); 
          break;}

          case '3': { 
               h=insertaNodo(h);
               Imprimir_lista(h); 
          break;}

          case '4': {
               printf("Ingrese el valor que desea eliminar:\n"); 
               scanf("%d",&n);
               s=buscar(h,n); 
               if(s)h=eliminar(h,n);
               else printf("El valor no se encuentra en la lista\n");
               Imprimir_lista(h);
          break;} 

          case '5':{
               h=Invertir(h);
               printf("Lista invertida\n");
               Imprimir_lista (h); 
          break;}

          default:{
          break;}

          case '6': printf( "Fin de la ejecucion.\n" );
     } /* fin de switch */

    scanf("%c",&eleccion);

} while (eleccion != '6' ); /* fin de do-while */

   system("pause");
}
                     
     /*do{
          printf("en que posicion desea ingresar su nuevo valor?");
          scanf("%d", &op);
     }while(op < n || op > n)*/
      
      
