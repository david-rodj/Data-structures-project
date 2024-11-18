/********************************************************
Pontificia Universidad Javeriana

Grupo: David Rodriguez Jurado.
Juan Sebastian Rodriguez Pabon.
Julian Perez Gomes.
Jan Marco Muñoz Pineda.
Daniel Galvis Betancourth.

Fecha: 17/11/2024

Materia: Estructuras de datos
********************************************************/

/********************************************************
Proyecto Mallas poligonales
********************************************************/

#include "Cara.h"

/**
 * Obtiene los índices de los vértices de la cara.
 * 
 * @return Un deque con los índices de los vértices de la cara.
 * 
 * Ejemplo:
 * Cara cara;
 * deque<int> indices = cara.getIndicesVertice();
 */
deque<int>& Cara::getIndicesVertice() { return indicesVertice; }

/**
 * Constructor por defecto de la clase Cara.
 * Inicializa un objeto de la clase Cara sin aristas.
 */
Cara::Cara() : indicesAristas() {}

/**
 * Obtiene el conjunto de índices de Aristas que forman parte de esta cara.
 *
 * @return Referencia al deque que contiene los índices de las aristas.
 */
deque<int> &Cara::getIndicesAristas()
{
    return indicesAristas;
}

/**
 * Establece los índices de los vértices de la cara.
 * 
 * @param vertices Un deque con los índices de los vértices de la cara.
 * 
 * Ejemplo:
 * deque<int> vertices = {0, 1, 2};
 * Cara cara;
 * cara.setIndicesVertice(vertices);
 */
void Cara::setIndicesVertice(deque<int> &vertices)
{
    this->indicesVertice = vertices;
}

/**
 * Establece el conjunto de índices de Aristas que forman parte de esta cara.
 *
 * @param aristas Conjunto de índices de las aristas.
 */
void Cara::setIndicesAristas(deque<int> &aristas)
{
    indicesAristas = aristas;
}
