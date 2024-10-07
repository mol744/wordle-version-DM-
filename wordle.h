#ifndef WORDLE_H
#define WORDLE_H


typedef struct {
    char arreglo[5];
    char estado[5];
}Interfaz;

void inicio_juego(); //interfaz de juego

int letra_presente(char c, int posicion, );

Interfaz cambio_estado(Interfaz)

#endif