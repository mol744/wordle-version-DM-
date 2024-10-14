#include "ed2.h"

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
// Función para crear un nuevo nodo
Heap *crearNodo(char palabra[], int frecuencia) {
    Heap *nuevoNodo = (Heap *)malloc(sizeof(Heap));
    assert(nuevoNodo != NULL);  // Verifica que la memoria fue asignada correctamente
    strcpy(nuevoNodo->palabra, palabra);
    nuevoNodo->frecuencia = frecuencia;
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
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

/*Función para encontrar y eliminar el nodo más profundo y derecho
Heap *eliminarNodoProfundo(Heap *bd) {
    if (bd == NULL) return NULL;

    // Si el nodo no tiene hijos, se puede eliminar directamente
    if (bd->izq == NULL && bd->der == NULL) {
        free(bd);
        return NULL;
    }

    // Utilizamos una cola para recorrer el árbol nivel por nivel
    Heap *ultimo, *padreUltimo = NULL;
    Heap *cola[100];  // Cola para almacenar nodos (arreglo con capacidad arbitraria)
    int inicio = 0, fin = 0;

    // Encolar el nodo raíz
    cola[fin++] = bd;

    // Recorrer el árbol hasta encontrar el último nodo
    while (inicio < fin) {
        ultimo = cola[inicio++];

        if (ultimo->izq) {
            padreUltimo = ultimo;
            cola[fin++] = ultimo->izq;
        }

        if (ultimo->der) {
            padreUltimo = ultimo;
            cola[fin++] = ultimo->der;
        }
    }

    // Eliminar el último nodo encontrado y ajustar el puntero del padre
    if (padreUltimo && padreUltimo->izq == ultimo) {
        padreUltimo->izq = NULL;
    } else if (padreUltimo && padreUltimo->der == ultimo) {
        padreUltimo->der = NULL;
    }

    free(ultimo);
    return bd;
}
*/
// Función para eliminar el nodo raíz del max-heap y mantener la prioridad
Heap *eliminarMax(Heap *bd) {
    if (bd == NULL) return NULL; // Si el heap está vacío, no hay nada que eliminar

    // Guardar la raíz para liberarla más tarde
    Heap *raiz = bd;

    // Reemplazar la raíz con el hijo izquierdo o derecho, según cuál exista
    if (bd->izq == NULL && bd->der == NULL) {
        // Si no hay hijos, simplemente se elimina
        free(raiz);
        return NULL;
    } else if (bd->izq != NULL && bd->der == NULL) {
        // Si solo hay hijo izquierdo
        bd = bd->izq;
    } else if (bd->izq == NULL && bd->der != NULL) {
        // Si solo hay hijo derecho
        bd = bd->der;
    } else {
        // Si hay ambos hijos, se debe encontrar el mayor entre ellos para moverlo a la raíz
        if (bd->izq->frecuencia > bd->der->frecuencia) {
            bd->palabra[0] = bd->izq->palabra[0]; // Reemplazar la raíz
            bd->frecuencia = bd->izq->frecuencia; // Reemplazar la frecuencia
            bd->izq = eliminarMax(bd->izq); // Eliminar el antiguo hijo izquierdo
        } else if (bd->izq->frecuencia > bd->der->frecuencia){
            bd->palabra[0] = bd->der->palabra[0]; // Reemplazar la raíz
            bd->frecuencia = bd->der->frecuencia; // Reemplazar la frecuencia
            bd->der = eliminarMax(bd->der); // Eliminar el antiguo hijo derecho
        }else if(strcmp(bd->izq->palabra,bd->der->palabra)>0){
            bd->palabra[0] = bd->der->palabra[0]; // Reemplazar la raíz
            bd->frecuencia = bd->der->frecuencia; // Reemplazar la frecuencia
            bd->der = eliminarMax(bd->der); // Eliminar el antiguo hijo derecho
        }else{
            bd->palabra[0] = bd->izq->palabra[0]; // Reemplazar la raíz
            bd->frecuencia = bd->izq->frecuencia; // Reemplazar la frecuencia
            bd->izq = eliminarMax(bd->izq); // Eliminar el antiguo hijo izquierdo
        }
    }

    // Liberar la memoria del nodo eliminado (la antigua raíz)
    free(raiz);
    return bd; // Retornar el nuevo árbol
}

void imprimirHeap(Heap *bd) {
    if (bd == NULL) {
        return;
    }
    printf("Palabra: %s, Frecuencia: %d\n", bd->palabra, bd->frecuencia);
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
    FILE *archivo = fopen("1.txt", "r");
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
        printf("Palabra: %s, Frecuencia: %d\n", palabra, frecuencia);
        printf("\n");
        // Aquí puedes hacer lo que necesites con la palabra y frecuencia, como insertar en un heap
    }

    fclose(archivo);
    imprimirHeap(arbol);
    printf("\n");
    arbol = eliminarMax(arbol);
    return arbol;
}
