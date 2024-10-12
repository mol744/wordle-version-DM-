#define MAX_TAMANO 5
#define MAX_INTENTOS 6
#define VERDE_T "\x1b[32m"
#define AMARILLO_T "\x1b[33m"  

#ifndef ED1_H
#define ED1_H
typedef struct{
    char intento[MAX_TAMANO];
    int resultado[MAX_TAMANO];
}Interfaz;

//muestra las letras amarillas (aparecen pero no estan en pos correcta), grises(no estan) y verdes (estan en la pos correcta).
void mostrar(Interfaz jugada);

#endif