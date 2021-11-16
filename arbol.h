#ifndef __ARBOL_H__
#define __ARBOL_H__
#include <stdio.h>
#include <stdlib.h>

struct arbol{
        int dato;
        struct arbol *izquierdo;
        struct arbol *derecho;
};

int insertar(struct arbol ** , int);
int buscar(struct arbol *, int);
int eliminar(struct arbol **, int);
void mostrar(struct arbol *);

int altura_arbolavl(struct arbol *);


int balanceo(struct arbol *);
void balancear_arbolavl(struct arbol **);
int rotar_derecha(struct arbol **);
int rotar_izq(struct arbol **);

int reordenar(struct arbol **, struct arbol **);

#endif
