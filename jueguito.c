#include "wordle.h"
#include <stdio.h>

int main(){
    printf("HOLA MUUUNDO\n\n");
    char secreto[] = "atell";
    Interfaz prueba[5];
    for (int i = 0; i < 5; i++){
        scanf("%s",&prueba[i].intento);
        prueba[i]=cambio_estado(prueba[i],i,secreto);
        for (int j = 0; j < 5; j++)
            printf("%d",prueba[i].resultado[j]);
        printf("\n\n");
    }
    return 0;
}