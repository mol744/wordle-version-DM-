#define MAX_TAMANO 5
#define MAX_INTENTOS 6
#define VERDE_T "\x1b[32m"
#define AMARILLO_T "\x1b[33m"  
#define RESET_COLOR "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef ED1_H
#define ED1_H

#ifdef _WIN32_ 
  #define limpiar "cls"
#else // Linux o MacOS
  #define limpiar "clear"
#endif

typedef struct{
    char intento[MAX_TAMANO];
    int resultado[MAX_TAMANO];
}Interfaz;

//cuenta las lineas del archivo que contiene las palabras de 5 letras.
int contar_lineas(char* nombre_archivo);

//lee una palabra aleatoria del archivo que contiene las palabras de 5 letras.
void leer_palabra_aleatoria(char* nombre_archivo, char* resultado);

//muestra las letras amarillas (aparecen pero no estan en pos correcta), grises (no estan) y verdes (estan en la pos correcta).
void mostrar(Interfaz jugada[]);

#endif