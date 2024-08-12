# DFA
**Autómata Finito Determinista Desarrollado en Lenguaje C, Configurable Mediante Archivo de Texto**

Este DFA se configura a través de un archivo de texto que define:
1. Los estados.
2. El alfabeto.
3. Las transiciones.
4. El estado inicial.
5. Los estados de aceptación.

# Guía para la Creación del Archivo `dfa.c`

Para crear el archivo `dfa.c` en un sistema operativo Linux (como Kali Linux), siga los siguientes pasos:

1. Abra una nueva terminal presionando `Ctrl + Alt + T`.
2. Ingrese el comando `nano nombre_del_archivo` (en este caso, use `nano dfa.c`) y presione Enter.
3. Se abrirá un editor de texto. Copie el código del archivo `dfa.c` (disponible en el repositorio) en el editor. 
4. Dado que en algunas distribuciones de Linux los comandos `Ctrl + C` y `Ctrl + V` pueden no funcionar para copiar y pegar, se recomienda seleccionar el código del archivo `dfa.c` manteniendo presionado el botón izquierdo del mouse. Una vez seleccionado el código, copie el contenido haciendo clic derecho y eligiendo la opción "Copiar".
5. Con el código copiado al portapapeles, vuelva a la terminal abierta y pegue el código presionando clic derecho y seleccionando "Pegar".
6. Para guardar el archivo en el editor, presione `Ctrl + O`. Aparecerá una confirmación en la parte inferior con el nombre del archivo a guardar. Presione Enter para confirmar.
7. La terminal mostrará una confirmación de la cantidad de líneas escritas en el archivo. Una vez verificado, presione `Ctrl + X` para salir del editor de texto.
8. El archivo `dfa.c` estará ahora creado y listo para su uso.

# Archivo de Configuración

El archivo de configuración debe seguir el siguiente formato:

- Primera línea: conjunto de estados (Q), separados por comas.
- Segunda línea: alfabeto (Σ), separado por comas.
- Tercera línea: estado inicial (q0).
- Cuarta línea: estados de aceptación (F), separados por comas.
- Las líneas siguientes: transiciones en el formato `estado_actual,símbolo,estado_siguiente`.

# Ejemplo de Archivo de Configuración

q0,q1,q2,q3
a,b
q0
q3
q0,a,q1
q1,b,q2
q2,a,q3
q3,b,q0


# Ejemplo de Ejecución

1. Ingrese el nombre del archivo de configuración: `ejemplo1.txt`.
2. Ingrese la cadena de entrada: `aba`.

**Resultado:** La cadena fue aceptada.





