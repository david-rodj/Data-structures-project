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

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <deque>
#include <limits>

using namespace std;

/**
 * Clase que representa un grafo ponderado con una lista de adyacencia.
 */
class Grafo {
private:
    int numVertices;                        ///< Número de vértices en el grafo.
    vector<deque<pair<int, float>>> adyacencia; ///< Lista de adyacencia para representar el grafo.

public:
    /**
     * Constructor por defecto.
     */
    Grafo();

    /**
     * Constructor que inicializa el grafo con un número de vértices dado.
     * 
     * @param n Número de vértices.
     */
    Grafo(int n);

    static const double INF;

    /**
     * Establece el número de vértices del grafo y reinicia su estructura.
     * 
     * @param n Número de vértices.
     */
    void setNumVertices(int n);

    /**
     * Agrega una arista con peso al grafo.
     * 
     * @param origen Índice del vértice de origen.
     * @param destino Índice del vértice de destino.
     * @param peso Peso de la arista.
     */
    void agregarArista(int origen, int destino, float peso);

    /**
     * Devuelve la lista de adyacencia del grafo.
     * 
     * @return Lista de adyacencia.
     */
    vector<deque<pair<int, float>>> getAdyacencia();

    /**
     * Calcula la distancia más corta entre dos vértices específicos utilizando el algoritmo de Floyd-Warshall.
     * 
     * @param i1 Índice del vértice de origen.
     * @param i2 Índice del vértice de destino.
     * @param camino Vector donde se almacena el camino más corto entre i1 e i2.
     * @return La distancia más corta entre i1 e i2. Retorna infinito si no hay conexión.
     */
    double floydWarshall(int i1, int i2, vector<int>& camino);
};

#endif // GRAFO_H
