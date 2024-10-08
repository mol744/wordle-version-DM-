#include "wordle.h"
#include <stdio.h>

void inicio_juego(char *palabraSecreta){
  printf("WORDLE -- EL JUEGO DE ADIVINAR PALABRAS DE 5 LETRAS\n\n");
  printf("La palabra secreta es _____. Deberás descubrirla\ncolocando otras palabras de 5 letras (del castellano)\ny notando la respuesta del programa a esa palabra\ningresada.\n-- Color predeterminado: No se encuentra la letra en la palabra.\n-- Color Amarillo: La letra se encuentra en la palabra.\n-- Color verde: La letra se encuentra en la palabra y en la posición elegida.");

}

int letra_presente(char c, int posicion, char *palabraSecreta){
  if(c==palabraSecreta[posicion])return 1;
  for(int i = 0; i < MAX_TAMANO; i++)
    if(c==palabraSecreta[i])return 2;
  return 0;
}

Interfaz verificar_repeticiones(Interfaz jugada, char *palabraSecreta){
  char aux,contRep;
  /*for(int k = 0; k < MAX_TAMANO; k++){
    if(jugada.intento[k] == aux && jugada.resultado[k] == 2){
      jugada.resultado[k] = 0;
    }
    if(jugada.resultado[k] == 2){
      aux = jugada.intento[k];
    }
  }
  */
  for(int k = 0; k < MAX_TAMANO; k++){
    aux = jugada.intento[k];
    contRep = 0;
    for(int l = k + 1; l < MAX_TAMANO; l++){
      if(palabraSecreta[l] == aux)contRep++;
    }
    for(int m = 0; m < MAX_TAMANO; m++){
      if(jugada.intento[m] == aux && jugada.resultado[m] == 2 && contRep == 0 && m != k){
        jugada.resultado[m] = 0;
        contRep --;
      }
    }
  }
  return jugada;
}

Interfaz cambio_estado(Interfaz jugada, int posicion, char *palabraSecreta){
  for(int i = 0; i < MAX_TAMANO; i++){
    jugada.resultado[i]=letra_presente(jugada.intento[i],i,palabraSecreta);
  }
  jugada = verificar_repeticiones(jugada,palabraSecreta);
  return jugada;
}