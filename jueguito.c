#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    system(limpiar);
    printf("WORDLE -- EL JUEGO DE ADIVINAR PALABRAS DE 5 LETRAS\n\n");
    printf("La palabra secreta es _____. Deberás descubrirla\ncolocando otras palabras de 5 letras (del castellano)\ny notando la respuesta del programa a esa palabra\ningresada.\n-- Color predeterminado: No se encuentra la letra en la palabra.\n-- Color Amarillo: La letra se encuentra en la palabra.\n-- Color verde: La letra se encuentra en la palabra y en la posición elegida.");
    Interfaz prueba [MAX_INTENTOS];
    for (int i = 0; i < MAX_INTENTOS; i++){
        prueba[i] = inicio_juego(prueba[i]);
    }
    char secreto[] = "lleno";
    for (int i = 0; i < MAX_INTENTOS; i++){
        printf("\n\nIngrese una palabra de 5 letras: ");
        scanf("%s",&prueba[i].intento);
        while(strlen(prueba[i].intento)!=5){
            printf("\n\nIngrese una palabra de 5 letras: ");
            scanf("%s",&prueba[i].intento);
        }
        prueba[i]=cambio_estado(prueba[i],secreto);
        system(limpiar);
        mostrar(prueba);
    }
    return 0;
}