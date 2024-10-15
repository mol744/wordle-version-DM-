#include <stdio.h>
#include <assert.h>
#include "wordle.h"

int main(int argc, char *argv[]){
  assert(argc != 2);
  char *palabraSecreta = malloc(strlen(argv[1]) * sizeof(char) + 1);
  strcpy(palabraSecreta,argv[1]);
  
  if (strlen(palabraSecreta) != MAX_TAMANO){
    printf("%s NO ES UNA PALABRA VALIDA, DEBE SER DE %d LETRAS",palabraSecreta,MAX_TAMANO);
    return 0;
  }

  Interfaz juego [MAX_INTENTOS];
  for (int i = 0; i < MAX_INTENTOS; i++){
    juego[i] = inicio_juego(juego[i]);
  }

  if(!strcmp(argv[2],"persona")){
    system(limpiar);
    printf("WORDLE -- EL JUEGO DE ADIVINAR PALABRAS DE %d LETRAS\n\n",MAX_TAMANO);
    printf("La palabra secreta tiene %d letras. Debes descubrirla\ncolocando otras palabras de 5 letras (del castellano)\ny notando la respuesta del programa a esa palabra\ningresada.\n-- Color predeterminado: No se encuentra la letra en la palabra.\n-- Color Amarillo: La letra se encuentra en la palabra.\n-- Color verde: La letra se encuentra en la palabra y en la posición elegida.",MAX_TAMANO);
    printf("\n\nPresiona ENTER para comenzar...\n");
    getchar();
    printf("Comenzando el programa!\n");
    int gana = 0;
    for (int i = 0; i < MAX_INTENTOS && !gana; i++){
      printf("\n\nIngrese una palabra de 5 letras: ");
      scanf("%s",&juego[i].intento);
      while(strlen(juego[i].intento)!=5){
        printf("\033[A");
        printf("\033[2K");
        printf("\033[A");
        printf("\nIngrese una palabra de 5 (CINCO) letras: ");
        scanf("%s",&juego[i].intento);
      }
      juego[i]=cambio_estado(juego[i],palabraSecreta);
      if(ganador(juego[i]))
        gana = 1;
      system(limpiar);
      mostrar(juego);
    }
    if (gana){
      printf("FIN DE PARTIDA, ACERTASTE LA PALABRA!");
      return 1;
    }else{
      printf("FIN DE PARTIDA, INTENTOS AGOTADOS.");
      return 2;
    }
  }else{}

  if(!strcmp(argv[2],"maquina")){
    printf("HOLA, MODO MAQUINA\n");
    Colores color;
    int gana = 0;
    for (int i = 0; i < MAX_INTENTOS && !gana; i++){
      color = sugerirpalabra(color);
      color = cambio_letras(color,palabraSecreta);
      strcpy(juego[i].intento, color.palabra);
      cambio_estado(juego[i],palabraSecreta);
      gana = ganador(juego[i]);
    }
    mostrar(juego);
  }
}