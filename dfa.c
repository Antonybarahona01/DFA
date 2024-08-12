#include <stdio.h> // Incluye la biblioteca estándar de entrada/salida
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de utilidades (e.g., exit)
#include <string.h> // Incluye la biblioteca estándar para funciones de manipulación de cadenas

#define MAX_ESTADOS 100 // Define el máximo número de estados
#define MAX_ALFABETO 100 // Define el máximo tamaño del alfabeto
#define MAX_TRANSICIONES 100 // Define el máximo número de transiciones
#define MAX_LONGITUD_LINEA 1000 // Tamaño máximo para las líneas del archivo de configuración

// Definiciones globales
char estados[MAX_ESTADOS][10]; // Arreglo para almacenar los estados
char alfabeto[MAX_ALFABETO]; // Arreglo para almacenar el alfabeto
char estadoInicial[10]; // Arreglo para almacenar el estado inicial
char estadosDeAceptacion[MAX_ESTADOS][10]; // Arreglo para almacenar los estados de aceptación
char tablaDeTransiciones[MAX_ESTADOS][MAX_ALFABETO][10]; // Tabla de transiciones: [estado][símbolo] -> estado siguiente

int numEstados = 0; // Contador de estados
int numAlfabeto = 0; // Contador de símbolos en el alfabeto
int numEstadosDeAceptacion = 0; // Contador de estados de aceptación

// Función para encontrar el índice de un estado en el arreglo estados
int encontrarIndiceEstado(const char *estado) {
    for (int i = 0; i < numEstados; i++) { // Recorre todos los estados
        if (strcmp(estados[i], estado) == 0) // Compara el estado dado con el estado actual
            return i; // Retorna el índice si hay coincidencia
    }
    return -1; // Retorna -1 si el estado no se encuentra
}

// Función para encontrar el índice de un símbolo en el alfabeto
int encontrarIndiceSimbolo(char simbolo) {
    for (int i = 0; i < numAlfabeto; i++) { // Recorre todos los símbolos en el alfabeto
        if (alfabeto[i] == simbolo) // Compara el símbolo dado con el símbolo actual
            return i; // Retorna el índice si hay coincidencia
    }
    return -1; // Retorna -1 si el símbolo no se encuentra
}

// Función para verificar si un estado es uno de los estados de aceptación
int esEstadoDeAceptacion(const char *estado) {
    for (int i = 0; i < numEstadosDeAceptacion; i++) { // Recorre todos los estados de aceptación
        if (strcmp(estadosDeAceptacion[i], estado) == 0) // Compara el estado dado con el estado de aceptación actual
            return 1; // Retorna 1 si es un estado de aceptación
    }
    return 0; // Retorna 0 si el estado no es de aceptación
}

// Función para leer el archivo de configuración
void leerArchivoConfiguracion(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r"); // Abre el archivo para lectura
    if (archivo == NULL) { // Verifica si el archivo se abrió correctamente
        perror("Error al abrir el archivo"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }

    char linea[MAX_LONGITUD_LINEA]; // Buffer para leer líneas del archivo

    // Leer estados
    if (fgets(linea, sizeof(linea), archivo) == NULL) { // Lee la primera línea del archivo (estados)
        perror("Error al leer estados"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }
    char *token = strtok(linea, ",\n"); // Divide la línea en tokens por comas y saltos de línea
    while (token != NULL) { // Mientras haya tokens disponibles
        if (numEstados >= MAX_ESTADOS) { // Verifica si se excede el número máximo de estados
            fprintf(stderr, "Error: demasiados estados\n"); // Imprime un mensaje de error
            exit(EXIT_FAILURE); // Termina el programa con un código de error
        }
        strncpy(estados[numEstados++], token, sizeof(estados[0]) - 1); // Copia el estado al arreglo y aumenta el contador
        estados[numEstados-1][sizeof(estados[0]) - 1] = '\0'; // Asegura terminación de la cadena
        token = strtok(NULL, ",\n"); // Obtiene el siguiente token
    }

    // Leer alfabeto
    if (fgets(linea, sizeof(linea), archivo) == NULL) { // Lee la segunda línea del archivo (alfabeto)
        perror("Error al leer alfabeto"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }
    numAlfabeto = strlen(linea) - 1; // Calcula la longitud del alfabeto, eliminando el carácter de nueva línea
    if (numAlfabeto >= MAX_ALFABETO) { // Verifica si se excede el tamaño máximo del alfabeto
        fprintf(stderr, "Error: alfabeto demasiado grande\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }
    strncpy(alfabeto, linea, numAlfabeto); // Copia el alfabeto al arreglo
    alfabeto[numAlfabeto] = '\0'; // Asegura terminación de la cadena

    // Leer estado inicial
    if (fgets(estadoInicial, sizeof(estadoInicial), archivo) == NULL) { // Lee la tercera línea del archivo (estado inicial)
        perror("Error al leer estado inicial"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }
    estadoInicial[strcspn(estadoInicial, "\n")] = '\0'; // Elimina el carácter de nueva línea del estado inicial

    // Leer estados de aceptación
    if (fgets(linea, sizeof(linea), archivo) == NULL) { // Lee la cuarta línea del archivo (estados de aceptación)
        perror("Error al leer estados de aceptación"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }
    numEstadosDeAceptacion = 0; // Inicializa el contador de estados de aceptación
    token = strtok(linea, ",\n"); // Divide la línea en tokens por comas y saltos de línea
    while (token != NULL) { // Mientras haya tokens disponibles
        if (numEstadosDeAceptacion >= MAX_ESTADOS) { // Verifica si se excede el número máximo de estados de aceptación
            fprintf(stderr, "Error: demasiados estados de aceptación\n"); // Imprime un mensaje de error
            exit(EXIT_FAILURE); // Termina el programa con un código de error
        }
        strncpy(estadosDeAceptacion[numEstadosDeAceptacion++], token, sizeof(estadosDeAceptacion[0]) - 1); // Copia el estado de aceptación al arreglo y aumenta el contador
        estadosDeAceptacion[numEstadosDeAceptacion-1][sizeof(estadosDeAceptacion[0]) - 1] = '\0'; // Asegura terminación de la cadena
        token = strtok(NULL, ",\n"); // Obtiene el siguiente token
    }

    // Leer transiciones
    char estadoDeOrigen[10], estadoDeDestino[10];
    char simbolo;
    while (fscanf(archivo, "%[^,],%c,%[^\n]\n", estadoDeOrigen, &simbolo, estadoDeDestino) == 3) { // Lee las líneas restantes (transiciones)
        int indiceEstadoDeOrigen = encontrarIndiceEstado(estadoDeOrigen); // Encuentra el índice del estado actual
        int indiceSimbolo = encontrarIndiceSimbolo(simbolo); // Encuentra el índice del símbolo
        if (indiceEstadoDeOrigen == -1 || indiceSimbolo == -1) { // Verifica si el estado o símbolo no son válidos
            fprintf(stderr, "Error en la configuración de transiciones: estado o símbolo no reconocido\n"); // Imprime un mensaje de error
            exit(EXIT_FAILURE); // Termina el programa con un código de error
        }
        strncpy(tablaDeTransiciones[indiceEstadoDeOrigen][indiceSimbolo], estadoDeDestino, sizeof(tablaDeTransiciones[0][0]) - 1); // Almacena la transición en la tabla de transiciones
        tablaDeTransiciones[indiceEstadoDeOrigen][indiceSimbolo][sizeof(tablaDeTransiciones[0][0]) - 1] = '\0'; // Asegura terminación de la cadena
    }

    if (ferror(archivo)) { // Verifica si hubo un error durante la lectura del archivo
        perror("Error al leer las transiciones"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un código de error
    }

    fclose(archivo); // Cierra el archivo
}

// Función para procesar una cadena de entrada y determinar si es aceptada o rechazada
void procesarCadena(const char *cadenaEntrada) {
    char estadoActual[10]; // Arreglo para almacenar el estado actual
    strcpy(estadoActual, estadoInicial); // Inicializa el estado actual con el estado inicial

    for (int i = 0; i < strlen(cadenaEntrada); i++) { // Recorre cada carácter de la cadena de entrada
        int indiceEstado = encontrarIndiceEstado(estadoActual); // Encuentra el índice del estado actual
        int indiceSimbolo = encontrarIndiceSimbolo(cadenaEntrada[i]); // Encuentra el índice del símbolo actual

        if (indiceEstado == -1 || indiceSimbolo == -1) { // Verifica si el estado o símbolo no son válidos
            printf("Cadena rechazada\n"); // Imprime que la cadena es rechazada
            return; // Sale de la función
        }

        strcpy(estadoActual, tablaDeTransiciones[indiceEstado][indiceSimbolo]); // Actualiza el estado actual según la transición
    }

    if (esEstadoDeAceptacion(estadoActual)) { // Verifica si el estado final es de aceptación
        printf("Cadena aceptada\n"); // Imprime que la cadena es aceptada
    } else {
        printf("Cadena rechazada\n"); // Imprime que la cadena es rechazada
    }
}

// Función principal
int main() {
    char nombreArchivo[100]; // Buffer para almacenar el nombre del archivo
    printf("Ingrese el nombre del archivo de configuración: "); // Solicita el nombre del archivo
    scanf("%99s", nombreArchivo); // Lee el nombre del archivo (con límite para evitar desbordamiento de búfer)

    leerArchivoConfiguracion(nombreArchivo); // Lee el archivo de configuración

    char cadenaEntrada[100]; // Buffer para almacenar la cadena de entrada
    printf("Ingrese la cadena de entrada: "); // Solicita la cadena de entrada
    scanf("%99s", cadenaEntrada); // Lee la cadena de entrada (con límite para evitar desbordamiento de búfer)

    procesarCadena(cadenaEntrada); // Procesa la cadena de entrada

    return 0; // Termina el programa
}
