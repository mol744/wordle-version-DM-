# TRABAJO PRACTICO 2 - WORDLE

### García Tomás, Morales Joaquín,  5to INFO IPS 2024

## Descripción del proyecto
La idea de este proyecto es recrear el conocido juego de página web en lenguaje C que ,además de la funcionalidad normalizada en que el usuario intenta adivinar la palabra por medio de intentos, se agrega una aplicación de sugerencia de palabras manejada por una maquina también codificada.

Esta máquina toma palabras ,del mismo largo cada una (5), de una base de datos donde también están acompañadas de un número que representa la frecuencia con la que se usan en el habla de nuestro idioma. Es un criterio que usa la máquina para determinar cuál elegir para el intento de adivinar. En el caso de nuestro código, no actúa como una sugerencia para quien está jugando, sino que intentará la misma máquina adivinar la palabra secretra con sus palabras disponibles. Si no puede sugerir más palabras, dará un mensaje al respecto y mostrará en pantalla los intentos que hizo.

Criterio de desempate: peso alfabético letra por letra.

También se evalúa intento por intento la similitud de la palabra intentada con la palabra secreta en:
-- letras presentes, pero posición incorrecta (representadas con el color amarillo)
-- letras presentes, en su correcta posición (color verde)
-- y letras ausentes, (color gris)

## Archivos del proyecto

- `main.c`: Controla la ejecución principal del juego, tiene dos modos: persona y maquina.
- `wordle.c` y `wordle.h`: Contienen la lógica del juego y la interacción con el jugador humano.
- `maquina.c` y `maquina.h`: Implementan la lógica del jugador virtual.
- `ed2.c` y `ed2.h`: Estructura de datos utilizada para optimizar la selección de palabras más frecuentes.
- `ed1.c` y `ed1.h`: Estructuras que se encargan de mostrar en pantalla los resultados.
- `Makefile`: Script para compilar el proyecto.

## Compilación y ejecución

1. Para compilar el proyecto, usa el siguiente comando:
    ```bash
    make
    ```

2. Para ejecutar el juego:
    ```bash
    ./wordle <palabra_secreta> <modo_de_juego>
    ```
--nota-- los modos de juego disponibles son "persona", para que juegue el usuario y "maquina" para que la utilización de las funciones automatizadas. 

3. Para limpiar los archivos compilados:
    ```bash
    make clean
    ```