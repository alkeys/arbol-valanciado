#include "arbol.h"

int insertar(struct arbol **un_arbol, int dato){
    if(*un_arbol == NULL){
        *un_arbol = (struct arbol *)malloc(sizeof(struct arbol));
        if(*un_arbol == NULL){
            return 0;
        }

        (*un_arbol)->dato = dato;
        (*un_arbol)->izquierdo = NULL;
        (*un_arbol)->derecho = NULL;
    }
    else{
        if((*un_arbol)->dato < dato){
            insertar(&((*un_arbol)->derecho), dato);
        }
        else{
            insertar(&((*un_arbol)->izquierdo), dato);
        }
    }

    balancear_arbolavl(un_arbol);

    return 1;
}


int buscar(struct arbol *un_arbol, int dato){
    if(un_arbol == NULL){
        return 0;
    }
    if(un_arbol->dato == dato){
        return 1;
    }

    if(un_arbol->dato < dato){
        return buscar(un_arbol->derecho, dato);
    }
    else{
        return buscar(un_arbol->izquierdo, dato);
    }
}


int eliminar(struct arbol **un_arbol, int dato){
    struct  arbol ** aux = NULL;
    if(un_arbol == NULL){
        return 0;
    }
  
    if((*un_arbol)->dato == dato){
        if((*un_arbol)->derecho == NULL){
            (*un_arbol) = (*un_arbol)->izquierdo;
            balancear_arbolavl(un_arbol);
        }
        else if((*un_arbol)->izquierdo == NULL){
            (*un_arbol) = (*un_arbol)->derecho;
            balancear_arbolavl(un_arbol);
        }
        else{
            aux = un_arbol;
            reordenar(&((*un_arbol)->izquierdo), aux);
            balancear_arbolavl(&((*un_arbol)->izquierdo));
        }
    }
    else if((*un_arbol)->dato < dato){
        if((*un_arbol)->derecho == NULL){
            return 0;
        }
        return eliminar(&((*un_arbol)->derecho), dato);
    }
    else{
        if((*un_arbol)->izquierdo == NULL){
            return 0;
        }
        return eliminar(&((*un_arbol)->izquierdo), dato);
    }

    return 1;
}

void mostrar(struct arbol *un_arbol) {
    if(un_arbol == NULL){
        return;
    }
    printf(" \t%d ", un_arbol->dato);
    mostrar(un_arbol->derecho);
    mostrar(un_arbol->izquierdo);
}
int altura_arbolavl(struct arbol *un_arbol){
    int alturaizq = 0;
    int alturader = 0;
    if(un_arbol == NULL){
        return 0;
    }
    alturaizq = altura_arbolavl(un_arbol->izquierdo);
    alturader = altura_arbolavl(un_arbol->derecho);
    if (alturader > alturaizq){
        return alturader + 1;
    }
    else{
        return alturaizq + 1;
    }
}

void balancear_arbolavl(struct arbol ** un_arbol) {
    int aux_balance = 0;
    if(un_arbol == NULL){
        return;
    }
    aux_balance = balanceo(*un_arbol);
    if(aux_balance > 1){
        if(balanceo((*un_arbol)->derecho) >= 1){
            rotar_izq(un_arbol);
        }
        else{
            rotar_derecha(&((*un_arbol)->derecho));
            rotar_izq(un_arbol);
        }
    }
    else if(aux_balance < -1){
        if(balanceo((*un_arbol)->izquierdo) <= -1){
            rotar_derecha(un_arbol);
        }
        else{
            rotar_izq(&((*un_arbol)->izquierdo));
            rotar_derecha(un_arbol);
        }
    }
}

int balanceo(struct arbol * un_arbol){
    int altura = 0;
    if(un_arbol == NULL){
        return 0;
    }
    
    altura = altura_arbolavl(un_arbol->derecho) - altura_arbolavl(un_arbol->izquierdo);
    return altura;
}

int rotar_derecha(struct arbol ** un_arbol){
    struct arbol *auxiliar = NULL;
    struct arbol *raiz = NULL;
    struct arbol *raiz_nueva = NULL;
    

    if(un_arbol == NULL){
        return 0;
    }
    raiz = (*un_arbol);
    raiz_nueva = (*un_arbol) -> izquierdo;
    auxiliar = (*un_arbol) -> izquierdo -> derecho;

    (*un_arbol) = raiz_nueva;
    raiz_nueva -> derecho = raiz;
    raiz -> izquierdo = auxiliar;
    return 1;
}

int rotar_izq(struct arbol ** un_arbol){
    struct arbol *auxiliar = NULL;
    struct arbol *raiz = NULL;
    struct arbol *raiz_nueva = NULL;
    
    if(un_arbol == NULL){
        return 0;
    }
    
    raiz = *un_arbol;
    raiz_nueva = (*un_arbol) -> derecho;
    auxiliar = (*un_arbol) -> derecho -> izquierdo;

    *un_arbol = raiz_nueva;
    (*un_arbol) -> izquierdo = raiz;
    raiz -> derecho = auxiliar;

    return 1;
}
int reordenar(struct arbol **un_arbol, struct arbol **aux_arbol) {
    if ((*un_arbol)->derecho == NULL){
        (*aux_arbol)->dato = (*un_arbol)->dato;
        *un_arbol = (*un_arbol)->izquierdo;
    }else
        reordenar(&(*un_arbol)->derecho, aux_arbol);
    return 1;
}
