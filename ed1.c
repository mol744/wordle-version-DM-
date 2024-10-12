#include "ed1.h"
#include <stdio.h>
#include <string.h>

void mostrar(Interfaz jugada){
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      printf("+---");
    }
    printf("+\n");
    for (int j = 0; j < 5; j++) {
      if(jugada.resultado[j]==0){
      printf("| %c ",jugada.intento[j]);
    }
    if(jugada.resultado[i]==1){
      printf(VERDE_T"| %c ",jugada.intento[j]);
    }
    if(jugada.resultado[i]==2){
      printf(AMARILLO_T"| %c ",jugada.intento[j]);
    }
    }
      printf("|\n");
  }
  for (int j = 0; j < 5; j++) {
    printf("+---");
  }
  printf("+\n");
  printf("\n\n");
}

