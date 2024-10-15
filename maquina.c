#include "maquina.h"

int cantelem(Colores aux) {
    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux.verdes[i].verde == '\0') {
            break;
        }
        cont++;
    }
    return cont;
}

Heap *filtrarHeap(Heap *bd, Colores aux) {
    if (bd == NULL) {
        return bd;
    }

    int lgris = strlen(aux.gris);
    int lver = cantelem(aux);
    int lamar = strlen(aux.amarillo);
    int cont = 0;

    for (int i = 0; i < lver; i++) {
        if (bd->palabra[aux.verdes[i].pos] == aux.verdes[i].verde) {
            cont++;
        }
    }

    
    for (int i = 0; i < lamar; i++) {
        for (int j = 0; j < 5; j++) {
            for(int a=0;a<lver;a++){
                if(j==(aux.verdes[a].pos)){
                    j++;
                }
            }
            if (bd->palabra[j] == aux.amarillo[i]) {
                cont++;
                break; 
            }
        }
    }

    for (int i = 0; i < lgris; i++) {
            int aux1=0;
            for (int j = 0; j < 5; j++) {
                if (bd->palabra[j] != aux.gris[i]) {
                    aux1++;
                }
            }
            if(aux1==5){
                cont++;
            }
        }

    if (cont == (lgris + lver + lamar)) {
        bd->izq = filtrarHeap(bd->izq, aux);
        bd->der = filtrarHeap(bd->der, aux);
    } else {
        bd = eliminarMax(bd);
        bd = filtrarHeap(bd, aux);
    }

    return bd;
}

Colores cambio_letras(Colores aux, char *palabraSecreta){
    int contadorVerde = cantelem(aux);
    int contadorAmarillo = strlen(aux.amarillo);
    int contadorGris = strlen(aux.gris);
    for (int i = 0; i < MAX_PALABRA; i++){
        if (aux.palabra[i] == palabraSecreta[i]){
            aux.verdes[contadorVerde].verde = aux.palabra[i];
            aux.verdes[contadorVerde].pos = i;
            contadorVerde ++; 
        }
        for (int j = 0; j < MAX_PALABRA; j++){
            for (int v = 0; v < MAX_PALABRA; v++){
                if (aux.palabra[i] == palabraSecreta[j] && i != j && aux.verdes[v].pos != i){
                    aux.amarillo[contadorAmarillo] = aux.palabra[i];
                    contadorAmarillo ++;
                }else{
                    aux.gris[contadorGris] = aux.palabra[i];
                    contadorGris ++;
                }
            }
        }
    }
    return aux;
}

Colores sugerirpalabra(Colores aux) {
    Heap *bd = armarbd();
    if (bd == NULL) {
        printf("Error al armar la base de datos.\n");
        return aux;
    }

    bd = filtrarHeap(bd, aux);

    if (bd == NULL) {
        printf("No hay palabras disponibles después de filtrar.\n");
        aux.palabra[0] = '\0';
    } else {
        strcpy(aux.palabra, bd->palabra);
    }

    liberarmem(bd);
    return aux;
}

// int main() {
//     Colores parametros;
//     parametros = sugerirpalabra(parametros);
//     strcpy(parametros.palabra,"jaula");
//     if (parametros.palabra != NULL) {
//         printf("\nPalabra obtenida: %s\n", parametros.palabra);
//     } else {
//         printf("\nNo se pudo obtener una palabra.\n");
//     }
//     return 0;
// }