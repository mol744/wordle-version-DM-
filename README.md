# TRABAJO PRACTICO 2 - WORDLE

### García Tomás, Morales Joaquín,  5to INFO IPS 2024

## Descripción del proyecto
La idea de este proyecto es recrear el conocido 'juego de adivinar palabras' en lenguaje C que, además de la funcionalidad estándar en que el usuario intenta adivinar la palabra por medio de intentos, se agrega otro modo de juego donde una máquina codificada se encarga de intentar adivinar la palabra secreta.

Esta máquina toma palabras, del mismo largo cada una (5), de una base de datos donde también están acompañadas de un número que representa la frecuencia con la que se usan en el habla de nuestro idioma. Es un criterio que usa la máquina para determinar cuál elegir para el intento de adivinar. En el caso de nuestro código, no actúa como una sugerencia para quien está jugando, sino que intentará la misma máquina adivinar la palabra secreta con sus palabras disponibles. Si no puede sugerir más palabras, dará un mensaje al respecto. Una vez terminada la acción de la máquina se mostrará en pantalla los intentos que hizo.

El criterio de desempate que se utiliza para la elección de palabras en la base de datos, cuando hay más de una palabra con la mayor frecuencia es el peso alfabético de cada palabra.

También se evalúa intento por intento la similitud de la palabra intentada con la palabra secreta en:
-- letras presentes, pero posición incorrecta (representadas con el color amarillo)
-- letras presentes, en su correcta posición (color verde)
-- y letras ausentes, (color gris)

Esta información que queda guardada sirve como referencia para el siguiente intento que tomará la máquina.

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
    --notas-- 
    | los modos de juego disponibles son "persona", para que juegue el usuario y "maquina" para que la      utilización de las funciones automatizadas.
    | si en el primer argumento pasamos la palabra "random" tomará una palabra del archivo que contiene las palabras de la base de datos de manera aleatoria para jugar en cualquiera de los dos modos mencionados anteriormente.

3. Para limpiar los archivos compilados:
    ```bash
    make clean
    ```