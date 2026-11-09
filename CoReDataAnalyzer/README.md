
# CoRe Data Analyzer

## 1. Descripción del proyecto

CoRe Data Analyzer es una aplicación desarrollada en C++ para el laboratorio de investigación informática (CoRe Lab).

El propósito de esta aplicación es administrar observaciones relacionadas con los resultados de las elecciones presidenciales de Estados Unidos de 2008 en tres estados: Pennsylvania (PA), Ohio (OH) y Florida (FL).

El programa simula un Data Frame, donde cada fila representa una observación (condado) y cada columna representa un campo específico de información.

Para desarrollar la aplicación se utilizan estructuras, arreglos, funciones y un menú interactivo.

## 2. Campos de información

Cada observación almacena los siguientes datos:

- **ID:** Identificador único de cada observación.
- **State:** Abreviatura del estado al que pertenece el condado.
- **County:** Nombre del condado.
- **Total Votes:** Cantidad total de votos registrados.
- **Democratic Votes:** Cantidad de votos recibidos por el Partido Demócrata.
- **Republican Votes:** Cantidad de votos recibidos por el Partido Republicano.
- **Democratic Share:** Porcentaje de votos correspondiente al Partido Demócrata.

El porcentaje de votos demócratas se calcula automáticamente mediante la siguiente fórmula:

Democratic Share = (Votos Demócratas / Total de Votos) * 100

## 3. Organización de los archivos

El proyecto está dividido en diferentes archivos de código fuente y encabezado. Cada archivo tiene una responsabilidad específica para mantener el programa organizado y facilitar su mantenimiento.

### 3.1 main.cpp

Este archivo contiene la función principal main(), que representa el punto de entrada de la aplicación.

**Funcionalidades implementadas:**

- Crea el objeto DataFrame.
- Inicializa el Data Frame.
- Presenta el menú principal.
- Permite seleccionar las operaciones disponibles.
- Utiliza una estructura switch para ejecutar la opción seleccionada.
- Mantiene el menú activo hasta que el usuario decide salir.
- Maneja las entradas incorrectas del menú.

### 3.2 Observation.h

Este archivo de encabezado define la estructura Observation.

**Elementos implementados:**

- Declara los siete campos necesarios para almacenar cada observación.
- Utiliza int para identificadores y cantidades de votos.
- Utiliza string para almacenar los nombres de los estados y condados.
- Utiliza double para almacenar el porcentaje de votos demócratas.
- Declara las funciones encargadas de recopilar y mostrar la información de una observación.

### 3.3 Observation.cpp

Este archivo contiene la implementación de las funciones declaradas en Observation.h.

**Funciones implementadas:**

- readObservation(): Recopila la información de una nueva observación mediante la entrada del usuario.
- displayObservation(): Muestra los datos correspondientes a una observación.

**Validaciones realizadas:**

- Comprueba que el identificador sea un número positivo.
- Verifica que el estado sea PA, OH o FL.
- Evita que el nombre del condado esté vacío.
- Comprueba que las cantidades de votos no sean negativas.
- Evita que los votos demócratas superen el total de votos.
- Evita que la suma de votos demócratas y republicanos supere el total.
- Calcula automáticamente el porcentaje de votos demócratas.
- Presenta el porcentaje con dos posiciones decimales.

### 3.4 DataFrame.h

Este archivo de encabezado define la estructura DataFrame y declara las funciones utilizadas para administrar las observaciones.

**Elementos implementados:**

- Define un arreglo capaz de almacenar hasta 100 observaciones.
- Declara un contador para mantener el número de observaciones almacenadas.
- Declara las funciones necesarias para inicializar, añadir, eliminar y mostrar observaciones.

### 3.5 DataFrame.cpp

Este archivo contiene la implementación de las operaciones utilizadas para administrar el Data Frame.

**Funciones implementadas:**

- initializeDataFrame(): Inicializa el Data Frame con cero observaciones.
- addObservation(): Añade una nueva observación al arreglo.
- Comprueba que no existan identificadores duplicados.
- Evita añadir observaciones cuando el arreglo alcanza su capacidad máxima.
- deleteObservation(): Busca una observación utilizando su identificador único.
- Elimina la observación seleccionada desplazando los elementos restantes del arreglo.
- displayDataFrame(): Muestra todas las observaciones almacenadas en una tabla organizada.
- Presenta la cantidad total de observaciones registradas.

### 3.6 README.md

Este archivo contiene la documentación general del proyecto.

Describe el propósito de la aplicación, los campos de información, la organización de los archivos, las funcionalidades implementadas y las instrucciones necesarias para compilar y ejecutar el programa.

## 4. Funcionalidades principales

La aplicación presenta un menú interactivo con las siguientes opciones:

1. **Añadir observación:** Permite introducir un nuevo registro de un condado.
2. **Eliminar observación:** Permite eliminar un registro utilizando su identificador único.
3. **Mostrar Data Frame:** Presenta todas las observaciones almacenadas.
0. **Salir:** Finaliza la ejecución del programa.

## 5. Validación de datos

La aplicación incorpora diferentes validaciones para evitar que se almacene información incorrecta.

Entre las validaciones implementadas se encuentran:

- Los identificadores deben ser números positivos.
- Los estados deben corresponder a PA, OH o FL.
- Los nombres de los condados no pueden estar vacíos.
- Las cantidades de votos no pueden ser negativas.
- Los votos demócratas no pueden superar el total de votos.
- La suma de los votos demócratas y republicanos no puede superar el total.
- No se permiten identificadores duplicados.
- El Data Frame no puede superar su capacidad máxima de 100 observaciones.

## 6. Instrucciones de compilación

La aplicación puede compilarse utilizando el compilador GNU C++ (g++) con soporte para C++17.

### Windows

Abrir la carpeta del proyecto en VS Code y ejecutar el siguiente comando en la terminal:

g++ -std=c++17 main.cpp Observation.cpp DataFrame.cpp -o CoReDataAnalyzer.exe

### Mac / Linux

g++ -std=c++17 main.cpp Observation.cpp DataFrame.cpp -o CoReDataAnalyzer

## 7. Instrucciones de ejecución

### Windows

.\CoReDataAnalyzer.exe

### Mac / Linux

./CoReDataAnalyzer

## 8. Conceptos de C++ utilizados

Durante el desarrollo de la aplicación se implementan los siguientes conceptos fundamentales de C++:

- Estructuras (struct).
- Arreglos (arrays).
- Funciones.
- Archivos de encabezado (.h).
- Archivos de código fuente (.cpp).
- Ciclos repetitivos (for y do-while).
- Estructuras condicionales (if, else y switch).
- Referencias.
- Operaciones de entrada y salida.
- Validación de datos.
- Administración de información.

## 9. Objetivo del proyecto

El objetivo principal de CoRe Data Analyzer es demostrar la aplicación de los conceptos fundamentales de programación en C++ mediante el desarrollo de una herramienta funcional capaz de administrar información electoral organizada.

La aplicación establece una base para futuras mejoras y la incorporación de nuevas funcionalidades relacionadas con el análisis y la administración de datos.
