#include "ed1.h"

int contar_lineas(char* nombre_archivo) {
  FILE* archivo = fopen(nombre_archivo, "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo");
    return 0;
  }
  int conteo = 0;
  char *linea = malloc(sizeof(char) * 100);
  while (fgets(linea, sizeof(linea), archivo) != NULL) {
    conteo++;
  }
  fclose(archivo);
  free(linea);
  return conteo;
}

// Función para leer una palabra aleatoria de un archivo
void leer_palabra_aleatoria(char* nombre_archivo, char* resultado) {
  FILE* archivo = fopen(nombre_archivo, "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo");
    return;
  }

  int lineas = contar_lineas(nombre_archivo);
  if (lineas == 0) {
    strcpy(resultado, ""); // Archivo vacío o error al contar líneas
    fclose(archivo);
    return;
  }

  srand(time(NULL));
  int linea_aleatoria = rand() % lineas;

  char linea[100];
  int contador = 0;
  while (fgets(linea, sizeof(linea), archivo) != NULL) {
    if (contador == linea_aleatoria) {
      sscanf(linea, "%[^,],%*d", resultado);
      break;
    }
    contador++;
  }

  fclose(archivo);
}

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