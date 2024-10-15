#include "ed2.h"

// Función para crear un nuevo nodo
Heap *crearNodo(char palabra[], int frecuencia) {
    Heap *nuevoNodo = (Heap *)malloc(sizeof(Heap));
    assert(nuevoNodo != NULL);  // Verifica que la memoria fue asignada correctamente
    strcpy(nuevoNodo->palabra, palabra);
    nuevoNodo->frecuencia = frecuencia;
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
}

// Función para intercambiar dos nodos
void intercambiarNodos(Heap *a, Heap *b) {
    char tempPalabra[5];
    int tempFrecuencia;

    // Intercambiar las palabras
    strcpy(tempPalabra, a->palabra);
    strcpy(a->palabra, b->palabra);
    strcpy(b->palabra, tempPalabra);

    // Intercambiar las frecuencias
    tempFrecuencia = a->frecuencia;
    a->frecuencia = b->frecuencia;
    b->frecuencia = tempFrecuencia;
}

Heap *insertar(Heap *bd, char palabra[], int frecuencia) {
    // Si el árbol es vacío, se crea un nuevo nodo
    if (bd == NULL) {
        return crearNodo(palabra, frecuencia);
    }

    // Si la frecuencia es menor, se inserta en el subárbol izquierdo
    if (frecuencia < bd->frecuencia) {
        bd->izq = insertar(bd->izq, palabra, frecuencia);
    }
    // Si la frecuencia es mayor, se inserta en el subárbol derecho
    else if (frecuencia > bd->frecuencia) {
        Heap *aux = crearNodo(palabra, frecuencia);
        intercambiarNodos(aux, bd);
        bd->der = insertar(bd->der, aux->palabra, aux->frecuencia);
        free(aux); // Liberar el nodo auxiliar
    }
    // Si las frecuencias son iguales, se comparan las palabras
    else {
        if (strcmp(palabra, bd->palabra) > 0) {
            Heap *aux = crearNodo(palabra, frecuencia);
            intercambiarNodos(aux, bd);
            bd->izq = insertar(bd->izq, aux->palabra, aux->frecuencia);
            free(aux); // Liberar el nodo auxiliar
        } else {
            bd->der = insertar(bd->der, palabra, frecuencia);
        }
    }
    return bd; // Retornar el árbol actualizado
}

// Función para reorganizar hacia abajo el heap para mantener la propiedad de max-heap
void downHeap(Heap *bd) {
    if (bd == NULL) return;

    Heap *mayor = bd;

    // Comparar con el hijo izquierdo
    if (bd->izq && bd->izq->frecuencia > mayor->frecuencia) {
        mayor = bd->izq;
    }
    // Comparar con el hijo derecho
    if (bd->der && bd->der->frecuencia > mayor->frecuencia) {
        mayor = bd->der;
    }
    if(bd->izq && bd->izq->frecuencia==mayor->frecuencia){
        if(strcmp(bd->izq->palabra, mayor->palabra) > 0){
           mayor = bd->izq;
        }
    }
    if(bd->der && bd->der->frecuencia==mayor->frecuencia){
        if(strcmp(bd->der->palabra, mayor->palabra) > 0){
           mayor = bd->der;
        }
    }

    // Si el nodo actual no es el mayor, intercambiar y continuar hacia abajo
    if (mayor != bd) {
        intercambiarNodos(bd, mayor);
        downHeap(mayor);
    }
}

// Función para eliminar el nodo raíz del max-heap y mantener la prioridad

Heap *eliminarMax(Heap *bd) {
    if (bd == NULL) return NULL; // Si el heap está vacío, no hay nada que eliminar.

    Heap *temp = NULL;

    // Si no hay hijos, simplemente se elimina.
    if (bd->izq == NULL && bd->der == NULL) {
        free(bd);
        return NULL;
    }

    // Si solo hay un hijo, se reemplaza la raíz con ese hijo.
    if (bd->izq != NULL && bd->der == NULL) {
        temp = bd->izq;
        free(bd);
        return temp;
    }
    if (bd->izq == NULL && bd->der != NULL) {
        temp = bd->der;
        free(bd);
        return temp;
    }

    // Si hay ambos hijos, encontrar el hijo con mayor frecuencia.
    if (bd->izq->frecuencia > bd->der->frecuencia ||
        (bd->izq->frecuencia == bd->der->frecuencia && strcmp(bd->izq->palabra, bd->der->palabra) <= 0)) {
        // Reemplazar la raíz por el hijo izquierdo.
        strcpy(bd->palabra, bd->izq->palabra);
        bd->frecuencia = bd->izq->frecuencia;
        bd->izq = eliminarMax(bd->izq); // Llamar a eliminar sobre el hijo izquierdo.
    } else {
        // Reemplazar la raíz por el hijo derecho.
        strcpy(bd->palabra, bd->der->palabra);
        bd->frecuencia = bd->der->frecuencia;
        bd->der = eliminarMax(bd->der); // Llamar a eliminar sobre el hijo derecho.
    }

    return bd; // Retornar el nuevo árbol.
}

void imprimirHeap(Heap *bd) {
    if (bd == NULL) {
        return;
    }
    printf("Palabra1: %s, Frecuencia1: %d\n", bd->palabra, bd->frecuencia);
    // Recorrer el hijo izquierdo
    imprimirHeap(bd->izq);
    // Recorrer el hijo derecho
    imprimirHeap(bd->der);
}

void liberarmem(Heap *arbol){
    while (arbol != NULL) {
        arbol = eliminarMax(arbol);
    }
}

Heap *armarbd(){
    FILE *archivo = fopen("3.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }
    char palabra[MAX_PALABRA + 1] ;// +1 para el carácter nulo '\0'
    int frecuencia;
    Heap *arbol = NULL;
    // Leer línea por línea del archivo
    while (fscanf(archivo, "%5[^,],%d\n", palabra, &frecuencia) == 2) {
        // %5[^,] significa que se lee hasta 5 caracteres antes de la coma y se guarda en 'palabra'
        // Luego lee el número después de la coma y lo guarda en 'frecuencia'
        arbol = insertar(arbol, palabra, frecuencia);
        //printf("Palabra: %s, Frecuencia: %d\n", palabra, frecuencia);
        //printf("\n");
        // Aquí puedes hacer lo que necesites con la palabra y frecuencia, como insertar en un heap
    }

    fclose(archivo);
    printf("\n");
    return arbol;
}
// int main(){
//     Heap *bd=NULL;
//     bd=armarbd();
//     imprimirHeap(bd);
// }