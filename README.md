# Polygonal Mesh System

## Project Overview

This project implements a 3D polygonal mesh manipulation system developed as part of the Data Structures course at Pontificia Universidad Javeriana. The system allows loading, manipulating, and analyzing three-dimensional objects represented through vertices, edges, and faces.

## Implemented Structures

- **Graph / Grafo:** Represents a graph and provides methods for performing graph-related operations. 
- **Vertex / Vértice:** Represents a vertex in the graph.
- **Edge / Arista:** Represents an edge connecting two vertices.
- **Face / Cara:** Represents a face in the graph.
- **Object / Objeto:** Represents an object associated with the graph. 
- **System / Sistema:** Manages overall system operations. 


## Project Structure 

The repository is organized as follows: 

- `principal.cpp`: The main entry point of the application. 
- `Grafo.h` and `Grafo.cxx`: Header and source files for the Graph class.
- `Vertice.h` and `Vertice.cxx`: Header and source files for the Vertex class.
- `Arista.h` and `Arista.cxx`: Header and source files for the Edge class. 
- `Cara.h` and `Cara.cxx`: Header and source files for the Face class. 
- `Objeto.h` and `Objeto.cxx`: Header and source files for the Object class. 
- `Sistema.h` and `Sistema.cxx`: Header and source files for the System class. 
- `ejemplo1.txt`, `ejemplo2.txt`, `ejemplo3.txt`, `ejemplo4.txt`: Text files containing sample data used for testing and demonstration purposes. 

## System Requirements

- GNU g++ compiler (version 4.0.0 or higher)
- C++ compatible operating system
- Terminal or command console

## Compilation and Execution Guide

### 1. Clone the Repository

Use the following command to clone the repository to your local machine:

```bash
git clone [repository-url]
```

Navigate to the project directory:

```bash
cd polygonal-mesh-system
```

### 2. Install g++ Compiler (Windows with MinGW)

If you don't already have g++ installed on Windows, follow these steps:

To compile this project we recommend using `g++`. Install it following the [MSYS2](https://www.msys2.org/) guide, which will install `g++` as well as `gcc` and `gdb`.

For Unix-based systems, g++ is typically available through the package manager.

### 3. Compilation

To compile the project, open your console of choice and type the following command:

```bash
g++ main.cpp Sistema.cpp [other source files] -o mesh_system
```

Replace `[other source files]` with any additional .cpp or .cxx files in your implementation.

### 4. Execution

To run the project, type the following command in the console:

```bash
./mesh_system
```

On Windows:
```bash
mesh_system.exe
```

## Input File Format

Mesh files must follow this structure:

```
mesh_name
n
x0 y0 z0
...
xn-1 yn-1 zn-1
c1 i1_1 i1_2 ... i1_c1
...
cm im_1 im_2 ... im_cm
-1
```

Where:
- `mesh_name`: 3D object name (no spaces)
- `n`: Number of vertices
- `xi yi zi`: Coordinates of the i-th vertex
- `cj`: Number of vertices in the j-th face
- `ij_k`: Index of the k-th vertex in the j-th face
- `-1`: End of file indicator

## System Usage

The system operates through an interactive command-line interface. The system prompt is `$`.

### Available Commands

#### Component 1: Information Organization

**cargar nombre_archivo**
- Loads a 3D object from file into memory
- Example: `cargar cube.txt`

**listado**
- Lists all objects loaded in memory with basic information
- Example: `listado`

**envolvente nombre_objeto**
- Calculates the bounding box of a specific object
- Example: `envolvente cube`

**envolvente**
- Calculates the global bounding box of all objects in memory
- Example: `envolvente`

**descargar nombre_objeto**
- Removes an object from memory
- Example: `descargar cube`

**guardar nombre_objeto nombre_archivo**
- Saves an object to a file
- Example: `guardar cube modified_cube.txt`

#### Component 2: Closest Vertices

**v_cercano px py pz nombre_objeto**
- Finds the closest vertex of the object to the specified point
- Example: `v_cercano 1.0 2.0 3.0 cube`

**v_cercano px py pz**
- Finds the closest vertex among all objects to the specified point
- Example: `v_cercano 1.0 2.0 3.0`

**v_cercanos_caja nombre_objeto**
- Identifies vertices closest to the 8 corners of the bounding box
- Example: `v_cercanos_caja cube`

#### Component 3: Shortest Paths

**ruta_corta i1 i2 nombre_objeto**
- Calculates the shortest path between two vertices of the object
- Example: `ruta_corta 0 5 cube`

**ruta_corta_centro i1 nombre_objeto**
- Calculates the shortest path between a vertex and the object's center
- Example: `ruta_corta_centro 3 cube`

#### System Commands

**ayuda** / **help**
- Shows the complete list of available commands
- Example: `ayuda`

**ayuda comando** / **help command**
- Shows specific information about a command
- Example: `ayuda cargar`

**salir** / **exit**
- Terminates program execution
- Example: `salir`

## Implemented Algorithms

### Bounding Box Calculation
The system calculates bounding boxes by identifying extreme points (pmin and pmax) that define a parallelepiped completely containing the object.

### Closest Vertex Search
Uses Euclidean distance to identify vertices closest to specific points in 3D space.

### Shortest Paths
Implements graph algorithms to find shortest paths between vertices, considering edges as connections with weights based on Euclidean distance.

## Project Structure

The repository is organized as follows:

- `main.cpp`: Main file with user interface and command handling
- `Sistema.h/Sistema.cpp`: Main class implementing system functionality
- Additional ADT and data structure files according to implementation
- `ejemplo1.txt`, `ejemplo2.txt`, `ejemplo3.txt`, `ejemplo4.txt`: Sample data files for testing and demonstration

## Error Handling

The system handles various error cases:
- Non-existent or unreadable files
- Objects not loaded in memory
- Out-of-range indices
- Insufficient or incorrect parameters
- Empty memory

## Usage Example

```
$ cargar cube.txt
El objeto Cube ha sido cargado exitosamente desde el archivo cube.txt

$ listado
Hay 1 objetos en memoria:
Cube contiene 8 vertices, 12 aristas y 6 caras.

$ v_cercano 0.5 0.5 0.5 Cube
El vertice 0 (0,0,0) del objeto Cube es el más cercano al punto (0.5,0.5,0.5), a una distancia de 0.866

$ salir
```

## Technical Notes

- The system maintains all objects in memory during execution
- Coordinates are handled as real numbers (float/double)
- Vertex indices start from 0
- Distances are calculated using standard Euclidean metric
