#include <stdio.h>
#include <assert.h>
#include "wordle.h"

int main(int argc, char *argv[]){
  assert(argc!=2);
  char *palabraSecreta = malloc(strlen(argv[1]) * sizeof(char) + 1);
  strcpy(palabraSecreta,argv[1]);
  if (strlen(palabraSecreta) != MAX_TAMANO){
    printf("PALABRA NO VALIDA, DEBE SER DE %d LETRAS",MAX_TAMANO);
    return 0;
  }
  if(!strcmp(argv[2],"persona")){
    system(limpiar);
    printf("WORDLE -- EL JUEGO DE ADIVINAR PALABRAS DE 5 LETRAS\n\n");
    printf("La palabra secreta es _____. Debes descubrirla\ncolocando otras palabras de 5 letras (del castellano)\ny notando la respuesta del programa a esa palabra\ningresada.\n-- Color predeterminado: No se encuentra la letra en la palabra.\n-- Color Amarillo: La letra se encuentra en la palabra.\n-- Color verde: La letra se encuentra en la palabra y en la posición elegida.");
    printf("\n\nPresiona cualquier tecla para comenzar...\n");
    getch();
    printf("¡Comenzando el programa!\n");
    Interfaz prueba [MAX_INTENTOS];
    for (int i = 0; i < MAX_INTENTOS; i++){
      prueba[i] = inicio_juego(prueba[i]);
    }
    char secreto[] = "lleno";
    int gana = 0;
    for (int i = 0; i < MAX_INTENTOS; i++){
      printf("\n\nIngrese una palabra de 5 letras: ");
      scanf("%s",&prueba[i].intento);
      while(strlen(prueba[i].intento)!=5){
        printf("\n\nIngrese una palabra de 5 letras: ");
        scanf("%s",&prueba[i].intento);
      }
      prueba[i]=cambio_estado(prueba[i],secreto);
      if(ganador(prueba[i]))
        gana = 1;
      system(limpiar);
      mostrar(prueba);
    }
    if (gana){
      printf("FIN DE PARTIDA, ACERTASTE LA PALABRA!");
      return 1;
    }else{
      printf("FIN DE PARTIDA, INTENTOS AGOTADOS.");
      return 2;
    }
  }

  if(strcmp(argv[2],"maquina")){
    
  }
}