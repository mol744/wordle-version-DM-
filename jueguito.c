#include "wordle.h"
#include <stdio.h>

int main(){
    printf("HOLA MUUUNDO\n\n");
    char secreto[] = "lento";
    Interfaz prueba[MAX_INTENTOS];
    for (int i = 0; i < MAX_INTENTOS; i++){
        scanf("%s",&prueba[i].intento);
        prueba[i]=cambio_estado(prueba[i],secreto);
        mostrar(prueba[i]);
    }
    return 0;
}