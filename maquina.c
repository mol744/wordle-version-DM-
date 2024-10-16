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

    // Array para marcar las posiciones de las letras verdes
    int posicionesVerdes[MAX_PALABRA] = {0};
    for (int i = 0; i < lver; i++) {
        posicionesVerdes[aux.verdes[i].pos] = 1;
    }

    // Verificar si la palabra cumple con los requisitos de los colores verdes
    for (int i = 0; i < lver; i++) {
        if (bd->palabra[aux.verdes[i].pos] == aux.verdes[i].verde) {
            cont++;
        }
    }

    // Verificar si la palabra cumple con los requisitos de los colores amarillos
    for (int i = 0; i < lamar; i++) {
        int encontrado = 0;
        for (int j = 0; j < MAX_PALABRA && !encontrado; j++) {
            // Solo verificar si la posición no es de una letra verde
            if (!posicionesVerdes[j] && bd->palabra[j] == aux.amarillo[i]) {
                cont++;
                encontrado = 1;
            }
        }
    }

    // Verificar si la palabra cumple con los requisitos de los colores grises
    for (int i = 0; i < lgris; i++) {
        int esGris = 1;
        for (int j = 0; j < MAX_PALABRA; j++) {
            for (int k = 0; k < MAX_PALABRA; k++){
                if (bd->palabra[j] == aux.gris[i] && aux.gris[i] != aux.amarillo[k] && aux.gris[i] != aux.verdes[k].verde) {
                    esGris = 0;
                    break;
                }
            }
        }
        if (esGris) {
            cont++;
        }
    }
    // Si la palabra cumple con todos los criterios, filtrar los subárboles
    if (cont == (lgris + lver + lamar)) {
        bd->izq = filtrarHeap(bd->izq, aux);
        bd->der = filtrarHeap(bd->der, aux);
    } else {
        // Si no cumple, eliminar el nodo y continuar con el filtrado
        bd = eliminarMax(bd);
        bd = filtrarHeap(bd, aux);
    }

    return bd;
}

Colores cambio_letras(Colores aux, char *palabraSecreta) {
    int contadorVerde = 0;
    int contadorAmarillo = 0;
    int contadorGris = 0;
    int letrasUsadas[MAX_PALABRA] = {0}; // Arreglo para marcar las posiciones ya usadas en la palabra secreta para letras amarillas

    // Primero: Identificar las letras verdes
    for (int i = 0; i < MAX_PALABRA; i++) {
        if (aux.palabra[i] == palabraSecreta[i]) {
            aux.verdes[contadorVerde].verde = aux.palabra[i];
            aux.verdes[contadorVerde].pos = i;
            contadorVerde++;
            letrasUsadas[i] = 1; // Marca esta posición como usada
        }
    }
    // Segundo: Identificar las letras amarillas
    for (int i = 0; i < MAX_PALABRA; i++) {
        if (aux.palabra[i] != palabraSecreta[i]) {
            for (int j = 0; j < MAX_PALABRA; j++) {
                if (aux.palabra[i] == palabraSecreta[j] && letrasUsadas[j] == 0) {
                    aux.amarillo[contadorAmarillo] = aux.palabra[i];
                    contadorAmarillo++;
                    letrasUsadas[j] = 1; 
                    break;
                }
            }
        }
    }
    // Paso 3: Identificar las letras grises
    for (int i = 0; i < MAX_PALABRA; i++) {
        int esGris = 1;
        // Verifica si la letra ya está en verde o amarillo
        for (int j = 0; j < contadorVerde; j++) {
            if (aux.palabra[i] == aux.verdes[j].verde) {
                esGris = 0;
                break;
            }
        }
        for (int j = 0; j < contadorAmarillo; j++) {
            if (aux.palabra[i] == aux.amarillo[j]) {
                esGris = 0;
                break;
            }
        }

        // Si no es verde ni amarillo, es gris
        if (esGris) {
            aux.gris[contadorGris] = aux.palabra[i];
            contadorGris++;
        }
    }

    // Aseguramos que las cadenas estén terminadas con '\0' para evitar problemas de impresión
    aux.verdes[contadorVerde].verde = '\0';
    aux.amarillo[contadorAmarillo] = '\0';
    aux.gris[contadorGris] = '\0';

    return aux;
}

Colores sugerirpalabra(Heap *bd,Colores aux) {
    bd = filtrarHeap(bd, aux);

    if (bd == NULL) {
        aux.palabra[0] = '\0';
    } else {
        strcpy(aux.palabra, bd->palabra);
    }

    return aux;
}