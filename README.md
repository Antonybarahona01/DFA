# DFA
Autómata Finito Determinista Desarrollado en lenguaje C, Configurable Mediante Archivo De Texto

Este DFA especifica mediante el archivo de texto:
  1. Los estados
  2. El Alfabeto
  3. Las Transiciones
  4. El Estado Inicial
  5. Los estados De Transicion

# Guia De Implementación  
  Una vez dentro de nuestro Sistema Operativo (Kali Linux) para este caso, haremos lo siguiente  
  1. Presionamos los comandos Ctrl + alt + T (Para abrir una nueva terminal)  
  2. escribimos los comando nano 'nombre del archivo' (en este caso usaremos nano dfa.c
  3. se nos abrira un editor de texto dentro del cual debemos copiar el codigo que se encuentra dentro del archivo dfa.c (este archivo se encuentra dentro de los documentos de este repositorio)
  4. debido a la limitacion de comando de Ctrl + c y Ctrl + v (para copiar y pegar respectivamente) se recomienda seleccionar el codigo del archivo dfa.c de este repositorio manteniendo presionando click izquierdo 

# Archivo De Configuración
El archivo de configuración debe estar dado de la siguiente manera:

Primera línea: conjunto de estados (Q), separados por comas.  
Segunda línea: alfabeto (Σ), separado por comas.  
Tercera línea: estado inicial (q0).  
Cuarta línea: estados de aceptación (F), separados por comas.  
Las siguientes líneas: transiciones en el formato estado_actual,símbolo,estado_siguiente.  

# Ejemplo Archivo de Configuración

q0,q1,q2,q3  
a,b  
q0  
q3  
q0,a,q1  
q1,b,q2  
q2,a,q3  
q3,b,q0  

# Ejemplo de ejecución 

Ingrese el nombre del archivo de configuración: ejemplo1.txt  
Ingrese la cadena de entrada: aba  
  
Resultado: La cadena fue aceptada.




