#ifndef WORDLE_H
#define WORDLE_H
#define MAX_TAMANO 5
#define MAX_INTENTOS 6

#include "ed1.h"

#define limpiar "cls"

//inicializa los valores de los intentos a caracteres invisibles reemplazando la basura en memoria.
Interfaz inicio_juego(Interfaz juego);

//esta función cuenta las veces que una letra aparece en el intento cumpliendo la condición de estar en la secreta pero no en la posición correcta.
int contar_letra_en_palabra_sin_posicion(char letra, char* palabraSecreta, char* intento);

//esta funcion devuelve: (0) si la letra no está en la palabra, (1) si está en su lugar y (2) si está, pero no en la posición correcta
int letra_presente(char c, int posicion, char *palabraSecreta);

//en los casos en los que haya letras en color amarillo, esta función acomoda el resultado de modo que no hayan letras repetidas.
Interfaz verificar_repeticiones(Interfaz jugada, char *palabraSecreta);

//devuelve la estructura con los valores que representan letras ubicadas correctamente
Interfaz letras_correctas (Interfaz jugada, char *palabraSecreta);

//devuelve la estructura con los valores completos al analizar también las letras presentes pero mal posicionadas.
Interfaz letras_parciales (Interfaz jugada, char *palabraSecreta);

//según el resultado de letra_presente aplicada a cada letra, actualiza el estado de la estructura ingresada como argumento.
Interfaz cambio_estado(Interfaz jugada, char *palabraSecreta);

//devuelve 1 si el intento es acertado.
int ganador (Interfaz jugada);

#endif