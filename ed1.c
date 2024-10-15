#include "ed1.h"

void mostrar(Interfaz jugada[]){
  for (int i = 0; i < MAX_INTENTOS; i++){
    for (int j = 0; j < MAX_TAMANO; j++) {
      printf("+---");
    }
    printf("+\n");
    for (int j = 0; j < MAX_TAMANO; j++) {
      if(jugada[i].resultado[j]==0){
        printf("| %c ",jugada[i].intento[j]);
      }
      if(jugada[i].resultado[j]==1){
        printf(VERDE_T "| %c " RESET_COLOR,jugada[i].intento[j]);
      }
      if(jugada[i].resultado[j]==2){
        printf(AMARILLO_T "| %c " RESET_COLOR,jugada[i].intento[j]);
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