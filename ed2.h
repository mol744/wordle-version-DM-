#define MAX_PALABRA 5
#define MAX_INTENTOS 6
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#ifndef ED2_H

typedef struct Heap{
char palabra[MAX_PALABRA];
int frecuencia;
struct Heap *der, *izq;
} Heap;

// Función para crear un nuevo nodo
Heap *crearNodo(char palabra[], int frecuencia);

// Función para intercambiar dos nodos
void intercambiarNodos(Heap *a, Heap *b);

//Inserta un Nodo en el heap
Heap *insertar(Heap *bd, char palabra[], int frecuencia);

// Función para reorganizar hacia abajo el heap para mantener la propiedad de max-heap
void downHeap(Heap *bd);

// Función para eliminar el nodo raíz del max-heap
Heap *eliminarMax(Heap *bd);

//Función para imprimir el Heap entero
void imprimirHeap(Heap *bd);

// Liberar memoria del heap antes de salir
void liberarmem(Heap *arbol);

//arma la base de datos con todas las palabras
Heap *armarbd();

#endif