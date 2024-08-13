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

8. 8. El archivo `dfa.c` estará ahora creado y listo para su uso.

# Guía para la Creación del Archivo `ejemplo1.txt` (archivo de configuracion)

Para crear el archivo de configuración `ejemplo1.txt` en un sistema operativo Linux (como Kali Linux), siga los siguientes pasos:

1. Abra una nueva terminal presionando `Ctrl + Alt + T`.
2. Ingrese el comando `nano nombre_del_archivo` (en este caso, use `nano ejemplo1.txt`) y presione Enter.
3. Se abrirá un editor de texto. Copie el contenido Copie el código del archivo `ejemplo1.txt` (disponible en el repositorio) en el editor.  
4. Dado que en algunas distribuciones de Linux los comandos `Ctrl + C` y `Ctrl + V` pueden no funcionar para copiar y pegar, se recomienda seleccionar el contenido del archivo `ejemplo1.txt` manteniendo presionado el botón izquierdo del mouse. Una vez seleccionado, copie el contenido haciendo clic derecho y eligiendo la opción "Copiar".
5. Con el contenido copiado al portapapeles, vuelva a la terminal abierta y pegue el contenido presionando clic derecho y seleccionando "Pegar".
6. Para guardar el archivo en el editor, presione `Ctrl + O`. Aparecerá una confirmación en la parte inferior con el nombre del archivo a guardar. Presione Enter para confirmar.
7. La terminal mostrará una confirmación de la cantidad de líneas escritas en el archivo. Una vez verificado, presione `Ctrl + X` para salir del editor de texto.
8. El archivo `ejemplo1.txt` estará ahora creado y listo para su uso.

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

# Compilación del Archivo `dfa.c`

Una vez creados los archivos `dfa.c` y `ejemplo1.txt`, se procederá a compilar y ejecutar el programa siguiendo estos pasos:

1. Con la terminal abierta (si se ha cerrado, presione `Ctrl + Alt + T` para abrir una nueva), ejecute el siguiente comando: `gcc dfa.c -o dfa`.  
   Este comando compilará el archivo `dfa.c`, creando un archivo ejecutable. Cabe destacar que `gcc` es una sentencia del *GNU Compiler Collection*, `dfa.c` es el nombre del archivo que contiene el código fuente del programa, y `-o dfa` es una opción de `gcc` que indica que el archivo ejecutable resultante debe llamarse `dfa`.

2. Una vez compilado el archivo, ejecute el siguiente comando en la misma terminal: `./dfa`.  
   Este comando ejecutará el programa recién compilado.

3. Al ejecutar el programa, aparecerá una ventana en la consola solicitando el nombre del archivo de configuración. Escriba `ejemplo1.txt` y presione Enter.

4. Después de seleccionar el archivo de configuración, el programa solicitará la cadena de entrada. Ingrese la cadena `aba` para este ejemplo. El programa analizará la cadena y mostrará un mensaje indicando si la cadena fue aceptada o no.
   
# Ejemplo de Ejecución

1. Ingrese el nombre del archivo de configuración: `ejemplo1.txt`.
2. Ingrese la cadena de entrada: `aba`.

**Resultado:** La cadena fue aceptada.





