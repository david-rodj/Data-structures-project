# Data Structures Project

This repository contains a project developed for a Data Structures course, implementing various data structures and algorithms in C++.

## Overview

The project represents 3D objects using implementations of several fundamental data structures and algorithms, such as graphs and trees. These implementations serve as a practical demonstration of concepts learned during the course.

## Implemented Structures / Estructuras Implementadas

- **Graph / Grafo:** Represents a graph and provides methods for performing graph-related operations. / Representa un grafo y proporciona métodos para realizar operaciones sobre el grafo.
- **Vertex / Vértice:** Represents a vertex in the graph. / Representa un vértice dentro del grafo.
- **Edge / Arista:** Represents an edge connecting two vertices. / Representa una arista que conecta dos vértices.
- **Face / Cara:** Represents a face in the graph. / Representa una cara dentro del grafo.
- **Object / Objeto:** Represents an object associated with the graph. / Representa un objeto asociado al grafo.
- **System / Sistema:** Manages overall system operations. / Gestiona las operaciones generales del sistema.


## Project Structure / Estructura del Proyecto

The repository is organized as follows: / El repositorio está organizado de la siguiente manera:

- `principal.cpp`: The main entry point of the application. / El punto de entrada principal de la aplicación.
- `Grafo.h` and `Grafo.cxx`: Header and source files for the Graph class. / Archivos de encabezado y fuente para la clase Grafo.
- `Vertice.h` and `Vertice.cxx`: Header and source files for the Vertex class. / Archivos de encabezado y fuente para la clase Vértice.
- `Arista.h` and `Arista.cxx`: Header and source files for the Edge class. / Archivos de encabezado y fuente para la clase Arista.
- `Cara.h` and `Cara.cxx`: Header and source files for the Face class. / Archivos de encabezado y fuente para la clase Cara.
- `Objeto.h` and `Objeto.cxx`: Header and source files for the Object class. / Archivos de encabezado y fuente para la clase Objeto.
- `Sistema.h` and `Sistema.cxx`: Header and source files for the System class. / Archivos de encabezado y fuente para la clase Sistema.
- `ejemplo1.txt`, `ejemplo2.txt`, `ejemplo3.txt`, `ejemplo4.txt`: Text files containing sample data used for testing and demonstration purposes. / Archivos de texto que contienen datos de ejemplo utilizados para pruebas y demostraciones.


## Compilation and execution guide of the project
In this file you will find the step by step guide to compile and run the whole project, I hope it will be of great hel

To compile and run the project, follow these steps:

1. **Clone the Repository**: Use the following command to clone the repository to your local machine:

   ```bash
   git clone https://github.com/david-rodj/Data-structures-project.git
   ```

   Navigate to the project directory:

   ```bash
   cd Data-structures-project
   ```

2. **Install g++ Compiler with MinGW for Windows (You can skip this step if you already have it or you use a Unix based system)**: 
To compile this project I recommend `g++`, so we will have to install it following the guide of [MSYS2](https://www.msys2.org/), it will install `g++` as well as `gcc` and `gdb`.


3. **Compiling**
To compile the project, you will open the console of your choice, type the following command replacing the parameters according to your need:

```bash
g++ [name of the file(s) to compile (.cpp and .cxx)] -o [name of the executable]
```

## Execution
To run the project, you will type the following command in the console:

```bash
./[executable name] 
```
