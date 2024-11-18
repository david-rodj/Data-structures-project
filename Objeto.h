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

#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <deque>

#include "Vertice.h"
#include "Arista.h"
#include "Cara.h"
#include "Grafo.h"

using namespace std;

/**
 * @class Objeto
 * @brief Representa un objeto 3D con vértices y caras.
 */
class Objeto
{
private:
    string nombre;           ///< Nombre del objeto.
    deque<Vertice> vertices; ///< Lista de vértices del objeto.
    deque<Cara> caras;       ///< Lista de caras del objeto.
    deque<Arista> aristas;  ///< Lista de aristas del objeto.
    Grafo grafo;

public:
    /**
     * @brief Constructor por defecto.
     */
    Objeto();

    Objeto(string nombre);

    /**
     * @brief Constructor con nombre del objeto.
     * @param nombre Nombre del objeto.
     */
    Objeto(string nombre, int vertices);

    /**
     * @brief Obtiene el nombre del objeto.
     * @return Nombre del objeto.
     */
    string getNombre();

    /**
     * @brief Obtiene la lista de vértices del objeto.
     * @return Lista de vértices del objeto.
     */
    deque<Vertice> &getVertices();

    /**
     * @brief Obtiene la lista de caras del objeto.
     * @return Lista de caras del objeto.
     */
    deque<Cara> &getCaras();

    /**
     * @brief Obtiene la lista de aristas del objeto.
     * @return Lista de aristas del objeto.
     */
    deque<Arista> &getAristas();

    Grafo& getGrafo();

    /**
     * @brief Establece el nombre del objeto.
     * @param n Nuevo nombre del objeto.
     */
    void setNombre(string n);

    /**
     * @brief Establece la lista de vértices del objeto.
     * @param vertices Nueva lista de vértices del objeto.
     */
    void setVertices(deque<Vertice> &vertices);

    /**
     * @brief Establece la lista de caras del objeto.
     * @param caras Nueva lista de caras del objeto.
     */
    void setCaras(deque<Cara> &caras);

    /**
     * @brief Establece la lista de aristas del objeto.
     * @param aristas Nueva lista de aristas del objeto.
     */
    void setAristas(deque<Arista> &aristas);

    void setGrafo(const Grafo& nuevoGrafo);

    /**
     * @brief Obtiene el vértice con mayor valor en el objeto.
     * @return Vértice con mayor valor en el objeto.
     */
    Vertice puntoMayor();

    /**
     * @brief Obtiene el vértice con menor valor en el objeto.
     * @return Vértice con menor valor en el objeto.
     */
    Vertice puntoMenor();

    /**
     * @brief Agrega las aristas únicas en el objeto.
     */
    void agregarAristasUnicas(int i1, int i2);

    /**
     * @brief Inicializa el grafo agregando las aristas definidas en el objeto.
     * 
     * Este método recorre todas las aristas almacenadas en el objeto y, para cada arista,
     * obtiene sus índices y calcula su peso utilizando la distancia entre los vértices.
     * Luego, agrega cada arista al grafo correspondiente.
     */
    void inicializarGrafo(); 

    /**
     * @brief Busca el índice de una arista en la lista de aristas.
     * 
     * Este método busca una arista en la lista de aristas del objeto, dado
     * sus índices. Se asegura de comparar los índices de manera ordenada
     * (menor y mayor) para facilitar la búsqueda.
     * 
     * @param i1 El índice del primer vértice de la arista.
     * @param i2 El índice del segundo vértice de la arista.
     * @return int El índice de la arista en la lista, o -1 si no se encuentra.
     */
    int buscarIndiceArista(int i1, int i2);

    /**
     * @brief Encuentra el vértice más cercano a un vértice dado.
     *
     * Esta función toma un objeto de tipo Vertice como referencia y
     * determina cuál es el vértice más cercano a este en un conjunto
     * de vértices. La distancia se calcula utilizando la fórmula
     * de la distancia euclidiana.
     *
     * @param v Referencia al vértice del cual se desea encontrar el más cercano.
     * @return El índice del vértice más cercano en el conjunto de vértices.
     *
     * @example
     * Vertice v1(1.0, 2.0);
     * Vertice v2(3.0, 4.0);
     * Vertice v3(5.0, 6.0);
     * int indiceCercano = verticeCercano(v1);
     * // Suponiendo que v1 es el vértice más cercano a v2,
     * // indiceCercano contendrá el índice de v2.
     */
    int verticeCercano(Vertice &v);

    /**
     * @brief Calcula y muestra la ruta más corta entre dos vértices en el grafo.
     * 
     * Este método verifica si los índices de los vértices son iguales o están fuera de rango.
     * Si son válidos, utiliza el algoritmo de Floyd-Warshall para encontrar la ruta más corta
     * entre los vértices especificados. Imprime la ruta y la distancia si existe, de lo contrario,
     * indica que no hay ruta entre los vértices.
     * 
     * @param i1 Índice del primer vértice.
     * @param i2 Índice del segundo vértice.
     */
    void rutaCorta(int i1, int i2);

    /**
     * @brief Calcula y muestra la ruta más corta entre un vertice y el centro del objeto en el grafo.
     * 
     * Este método verifica si los índices de los vértices son iguales o están fuera de rango.
     * Si son válidos, utiliza el algoritmo de Floyd-Warshall para encontrar la ruta más corta
     * entre los vértices especificados. Imprime la ruta y la distancia si existe, de lo contrario,
     * indica que no hay ruta entre los vértices.
     * 
     * @param i1 Índice del primer vértice.
     */
    void rutaCortaCentro(int i1);
};

#endif // OBJETO_H