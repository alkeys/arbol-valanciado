#include "arbol.h"

int main(){
    struct arbol *un_arbol = NULL;
    int encontrado=0;
    int buscar1=0;
    int eliminado=0;
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;
    int num5=0;
    int eliminar2;

    printf("\nInsertar numero: ");
    scanf("%d",&num1);
    insertar(&un_arbol ,num1);
    printf("\nInsertar numero: ");
    scanf("%d",&num2);
    insertar(&un_arbol ,num2);
    printf("\nInsertar numero: ");
    scanf("%d",&num3);
    insertar(&un_arbol ,num3);
    printf("\nInsertar numero: ");
    scanf("%d",&num4);
    insertar(&un_arbol ,num4);
    printf("\nInsertar numero: ");
    scanf("%d",&num5);
    insertar(&un_arbol ,num5);
    mostrar(un_arbol);
    printf("\n\n");

    
printf("\nbuscar el numero: ");
scanf("%d",&buscar1);
printf("\n %d",buscar(un_arbol,buscar1)); 
printf("\nEliminar el número: ");
scanf("%d",&eliminar2);
printf("\n%d",eliminar(&un_arbol, eliminar2));


printf("\nArbol final:");
mostrar(un_arbol);
printf("\n");

    return 0;
}
