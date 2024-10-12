#include "wordle.h"
#include <stdio.h>
#include <string.h>

Interfaz inicio_juego(Interfaz juego){
  for (int j = 0; j < MAX_TAMANO; j++){
    juego.intento[j] = ' ';
    juego.resultado[j] = 0;
  }
  return juego;
}

int contar_letra_en_palabra_sin_posicion(char letra, char* palabraSecreta, char* intento) {
  int contador = 0;
  for (int i = 0; i < MAX_TAMANO; i++) {
    if (palabraSecreta[i] == letra && intento[i] != letra) {
       contador++;  // Contar solo si la letra coincide y no está en la misma posición que en el intento
    }
  }
  return contador;
}

Interfaz letras_correctas (Interfaz jugada, char *palabraSecreta){
  for (int i = 0; i < MAX_TAMANO; i ++)
    if (jugada.intento[i] == palabraSecreta[i]){
      jugada.resultado[i] = 1;
    }else{
      jugada.resultado[i] = 0;
    }
  return jugada;
}

Interfaz letras_parciales (Interfaz jugada, char *palabraSecreta){
  for (int i = 0; i < MAX_TAMANO; i++) {
    if (jugada.resultado[i] == 0) {  // Solo analizar si la letra no fue marcada como verde
      int repeticionesRestantes = contar_letra_en_palabra_sin_posicion(jugada.intento[i], palabraSecreta, jugada.intento);     
      int repeticionesIntento = 0;
      for (int j = 0; j < i; j++) {
        if (jugada.intento[j] == jugada.intento[i] && jugada.resultado[j] == 2)
          repeticionesIntento++;
      }
      if (repeticionesIntento < repeticionesRestantes) {
        jugada.resultado[i] = 2;
      } else {
        jugada.resultado[i] = 0;
      }
    }
  }
  return jugada;
} 
Interfaz cambio_estado(Interfaz jugada, char *palabraSecreta){
    jugada = letras_correctas(jugada,palabraSecreta);
    if(ganador(jugada))
      return jugada;
    jugada = letras_parciales(jugada,palabraSecreta);
  return jugada;
}

int ganador (Interfaz jugada){
  for (int i = 0; i < MAX_TAMANO; i ++)
    if (jugada.resultado[i] != 1)
      return 0;
  return 1;
}