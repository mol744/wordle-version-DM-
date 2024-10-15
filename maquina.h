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

//cambia los valores verded, amarillo y gris de la estructura colores según el intento.
Colores cambio_letras(Colores palabra, char *palabraSecreta);

//sugiere una palabra 
Colores sugerirpalabra(Colores aux);

//filtra el Heap en base a las palabras amarillas, verdes y grises
void juego_maquina(Colores juego[]);



#endif