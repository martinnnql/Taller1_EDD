# Taller 1: Sistema de Gestión - Hospital Marmaja

<p align="center">
  <img src="https://media.tenor.com/tUKrO23mU_UAAAAC/pokemon-center.gif" alt="Centro Pokemon Marmaja" width="400">
</p>

Este proyecto es una simulación de un sistema de gestión hospitalaria desarrollado en C++ para el curso de Estructuras de Datos. Implementa conceptos de Programación Orientada a Objetos (POO), manejo de memoria dinámica, y estructuras de datos manuales (Pila, Cola y Listas Enlazadas).

##  Integrantes

* **Nombre:** Martin Arancibia
* **RUT:** 22.273.853-9
* **Nombre en GitHub:** @martinnnql
* **Carrera:** ICCI

##  Estructura del Proyecto

El proyecto sigue una arquitectura separada para mantener las responsabilidades claras:
* `dominio/`: Contiene las entidades puras del negocio (`Persona`, `Paciente`).
* `logica/`: Contiene el motor y las estructuras de datos (`Nodo`, `Cola`, `PilaHistorial`, `HospitalListaPrincipal`).
* `main/`: Contiene el punto de entrada y la interfaz de usuario (`main.cpp`).

##  Instrucciones de Compilación y Ejecución

Para evaluar este proyecto, asegúrese de tener instalado el compilador **MinGW-w64 (g++)** y de abrir su terminal en la carpeta raíz del proyecto (donde se ubica este archivo README y el archivo `pacientes.txt`).

### 1. Compilación
Ejecute el siguiente comando para ensamblar todos los archivos en un único ejecutable:

`g++ main/main.cpp dominio/Persona.cpp dominio/Paciente.cpp logica/Nodo.cpp logica/Cola.cpp logica/NodoHistorial.cpp logica/PilaHistorial.cpp logica/NodoPacienteServicio.cpp logica/NodoServicio.cpp logica/HospitalListaPrincipal.cpp -o TallerHospital`

### 2. Ejecución
Una vez compilado sin errores, inicie el programa con el siguiente comando:

* **En Windows (PowerShell/CMD):**
`.\TallerHospital.exe`

* **En Linux/Mac:**
`./TallerHospital`

### 3. Consideraciones de Uso
* El archivo `pacientes.txt` debe estar obligatoriamente en la misma carpeta raíz que el archivo ejecutable antes de iniciar el programa.
