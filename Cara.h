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

#ifndef CARA_H
#define CARA_H

#include <deque>

using namespace std;

/**
 * Clase que representa una cara en un grafo.
 */
class Cara
{
private:
    /**
     * Conjunto de índices de vértices que forman parte de esta cara.
     */
    deque<int> indicesVertice;

    /**
     * Conjunto de índices de Aristas que forman parte de esta cara.
     */
    deque<int> indicesAristas;

public:
    /**
     * Constructor por defecto de la clase Cara.
     */
    Cara();

     /**
     * Obtiene el conjunto de índices de vértices que forman parte de esta cara.
     * 
     * @return Conjunto de índices de vértices.
     * 
     * Ejemplo:
     * Cara cara;
     * deque<int> indices = cara.getIndicesVertice();
     */
    deque<int>& getIndicesVertice();

    /**
     * Obtiene el conjunto de índices de Aristas que forman parte de esta cara.
     *
     * @return Conjunto de índices de vértices.
     *
     * Ejemplo:
     * Cara cara;
     * deque<int> indices = cara.getIndicesAristas();
     */
    deque<int> &getIndicesAristas();

    /**
     * Establece el conjunto de índices de vértices que forman parte de esta cara.
     * 
     * @param vertices Conjunto de índices de vértices.
     * 
     * Ejemplo:
     * deque<int> vertices = {1, 2, 3};
     * Cara cara;
     * cara.setIndicesVertice(vertices);
     */
    void setIndicesVertice(deque<int> &vertices);


    /**
     * Establece el conjunto de índices de Aristas que forman parte de esta cara.
     *
     * @param vertices Conjunto de índices de Aristas.
     *
     * Ejemplo:
     * deque<int> Aristas = {1, 2, 3};
     * Cara cara;
     * cara.setIndicesAristas(aristas);
     */
    void setIndicesAristas(deque<int> &aristas);
};

#endif // CARA_H