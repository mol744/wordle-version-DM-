#include "ed2.h"

#ifndef MAQUINA_H
#define MAQUINA_H

typedef struct{
  char verde;
  int pos;
}Verde;

typedef struct{ 
  char palabra[MAX_PALABRA];
  Verde verdes[MAX_PALABRA];
  char amarillo[MAX_PALABRA];
  char gris[MAX_PALABRA];
}Colores;

//cuenta las letras que están en correcta posición por el momento.
int cantelem(Colores aux);

//cambia los valores verde, amarillo y gris de la estructura colores según el intento.
Colores cambio_letras(Colores palabra, char *palabraSecreta);

//Filtra el heap en base a las verdes, amarillas y grises
Heap *filtrarHeap(Heap *bd, Colores aux);

//elige una palabra para el siguiente intento
Colores sugerirpalabra(Heap *bd,Colores aux);

#endif