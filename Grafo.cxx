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

#include "Grafo.h"
#include <limits>
#include <algorithm>

// Definición de la constante estática INFINITO
const double Grafo::INF = numeric_limits<double>::infinity();

// Constructor por defecto
Grafo::Grafo() : numVertices(0), adyacencia() {}

// Constructor con número de vértices
Grafo::Grafo(int n) : numVertices(n), adyacencia(n) {}

// Establece el número de vértices y reinicia la estructura
void Grafo::setNumVertices(int n)
{
    numVertices = n;
    adyacencia.resize(numVertices);
}

// Agrega una arista con peso
void Grafo::agregarArista(int origen, int destino, float peso)
{
    pair<int,float> par1(destino, peso); 
    pair<int,float> par2(origen, peso); 
    adyacencia[origen].push_back(par1);
    adyacencia[destino].push_back(par2);
}

// Obtiene la lista de adyacencia
vector<deque<pair<int, float>>> Grafo::getAdyacencia()
{
    return adyacencia;
}

// Algoritmo de Floyd-Warshall con reconstrucción de camino
double Grafo::floydWarshall(int i1, int i2, vector<int> &camino)
{
    vector<vector<double>> dist(numVertices, vector<double>(numVertices, INF));
    vector<vector<int>> next(numVertices, vector<int>(numVertices, -1));

    // Inicializa distancias y el vector 'next' para reconstrucción de caminos
    for (size_t i = 0; i < numVertices; ++i)
    {
        dist[i][i] = 0;
        for (const auto &adyacente : adyacencia[i])
        {
            int destino = adyacente.first;
            double peso = adyacente.second;
            dist[i][destino] = peso;
            next[i][destino] = destino;
        }
    }

    // Relajación de caminos
    for (size_t k = 0; k < numVertices; ++k)
    {
        for (size_t i = 0; i < numVertices; ++i)
        {
            for (size_t j = 0; j < numVertices; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Si no hay conexión entre i1 e i2, retorna infinito
    if (dist[i1][i2] == INF)
    {
        camino.clear();
        return INF;
    }

    // Reconstrucción del camino
    camino.clear();
    int actual = i1;
    while (actual != -1 && actual != i2)
    {
        camino.push_back(actual);
        actual = next[actual][i2];
    }
    camino.push_back(i2);

    return dist[i1][i2];
}
