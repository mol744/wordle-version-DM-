#ifndef WORDLE_H
#define WORDLE_H
#define VERDE_T "\x1b[32m"
#define AMARILLO_T "\x1b[33m"  
#define MAX_TAMANO 5

typedef struct juego{
    char intento[MAX_TAMANO];
    int resultado[MAX_TAMANO];
}Interfaz;

 //interfaz de juego
void inicio_juego(char *palabraSecreta);

//esta funcion devuelve: (0) si la letra no está en la palabra, (1) si está en su lugar y (2) si está, pero no en la posición correcta
int letra_presente(char c, int posicion, char *palabraSecreta);

//en los casos en los que haya letras en color amarillo, esta función acomoda el resultado de modo que no hayan letras repetidas.
Interfaz verificar_repeticiones(Interfaz jugada, char *palabraSecreta);

//según el resultado de letra_presente aplicada a cada letra, actualiza el estado de la estructura ingresada como argumento.
Interfaz cambio_estado(Interfaz jugada, int posicion, char *palabraSecreta);

#endif