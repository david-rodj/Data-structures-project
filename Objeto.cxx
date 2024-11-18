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

#include "Objeto.h"

using namespace std;

#include <string>
#include <set>
#include <iostream>

/**
 * @brief Constructor por defecto de la clase Objeto.
 *
 * Inicializa el objeto con un nombre vacío.
 */
Objeto::Objeto() : nombre(""), grafo(0) {}

Objeto::Objeto(string nombre) : nombre(nombre) {}

/**
 * @brief Constructor de la clase Objeto con un nombre específico.
 *
 * @param nombre El nombre del objeto.
 *
 * @example
 * Objeto obj("Cubo");
 */
Objeto::Objeto(string nombre, int vertices) : nombre(nombre), grafo(vertices) {}

/**
 * @brief Obtiene el nombre del objeto.
 *
 * @return El nombre del objeto.
 *
 * @example
 * string nombre = obj.getNombre(); // nombre será "Cubo"
 */
string Objeto::getNombre() { return nombre; }

/**
 * @brief Obtiene la lista de vértices del objeto.
 *
 * @return La lista de vértices del objeto.
 *
 * @example
 * deque<Vertice>& vertices = obj.getVertices();
 */
deque<Vertice> &Objeto::getVertices() { return vertices; }

/**
 * @brief Obtiene la lista de caras del objeto.
 *
 * @return La lista de caras del objeto.
 *
 * @example
 * deque<Cara>& caras = obj.getCaras();
 */
deque<Cara> &Objeto::getCaras() { return caras; }

/**
 * @brief Obtiene la lista de aristas del objeto.
 * @return Lista de aristas del objeto.
 */
deque<Arista> &Objeto::getAristas()
{
    // Retornamos una referencia a la lista de aristas
    return aristas;
}

Grafo& Objeto::getGrafo()
{
    return grafo;
}

/**
 * @brief Establece el nombre del objeto.
 *
 * @param n El nuevo nombre del objeto.
 *
 * @example
 * obj.setNombre("Esfera");
 */
void Objeto::setNombre(string n) { this->nombre = n; }

/**
 * @brief Establece la lista de vértices del objeto.
 *
 * @param vertices La nueva lista de vértices del objeto.
 *
 * @example
 * deque<Vertice> nuevosVertices = {Vertice(1, 2, 3), Vertice(4, 5, 6)};
 * obj.setVertices(nuevosVertices);
 */
void Objeto::setVertices(deque<Vertice> &vertices) { this->vertices = vertices; }

/**
 * @brief Establece la lista de caras del objeto.
 *
 * @param caras La nueva lista de caras del objeto.
 *
 * @example
 * deque<Cara> nuevasCaras = {Cara(0, 1, 2), Cara(1, 2, 3)};
 * obj.setCaras(nuevasCaras);
 */
void Objeto::setCaras(std::deque<Cara> &caras) { this->caras = caras; }

/**
 * @brief Establece la lista de aristas del objeto.
 * @param aristas Nueva lista de aristas del objeto.
 */
void Objeto::setAristas(deque<Arista> &aristas)
{
    // Asignamos la nueva lista de aristas al objeto
    this->aristas = aristas;
}

void Objeto::setGrafo(const Grafo& nuevoGrafo)
{
    grafo = nuevoGrafo;
}

/**
 * @brief Obtiene el vértice con mayor valor en cada coordenada (x, y, z).
 *
 * @return El vértice con mayor valor en cada coordenada.
 *
 * @example
 * Vertice mayor = obj.puntoMayor(); // mayor contendrá el vértice con las coordenadas máximas
 */
Vertice Objeto::puntoMayor()
{
    float mayorx = vertices.front().getX();
    float mayory = vertices.front().getY();
    float mayorz = vertices.front().getZ();

    for (auto it = vertices.begin() + 1; it != vertices.end(); it++)
    {
        if (it->getX() > mayorx)
        {
            mayorx = it->getX();
        }
        if (it->getY() > mayory)
        {
            mayory = it->getY();
        }
        if (it->getZ() > mayorz)
        {
            mayorz = it->getZ();
        }
    }

    return Vertice(mayorx, mayory, mayorz);
}

/**
 * @brief Obtiene el vértice con menor valor en cada coordenada (x, y, z).
 *
 * @return El vértice con menor valor en cada coordenada.
 *
 * @example
 * Vertice menor = obj.puntoMenor(); // menor contendrá el vértice con las coordenadas mínimas
 */
Vertice Objeto::puntoMenor()
{
    float menorx = vertices.front().getX();
    float menory = vertices.front().getY();
    float menorz = vertices.front().getZ();

    for (auto it = vertices.begin() + 1; it != vertices.end(); it++)
    {
        if (it->getX() < menorx)
        {
            menorx = it->getX();
        }
        if (it->getY() < menory)
        {
            menory = it->getY();
        }
        if (it->getZ() < menorz)
        {
            menorz = it->getZ();
        }
    }

    return Vertice(menorx, menory, menorz);
}

/**
 * @brief Agrega aristas únicas a la deque del objeto.
 *
 * Esta función recibe dos índices que representan una arista y la agrega a la deque de aristas del objeto
 * solo si la arista no existe ya en la deque. La función asegura que la arista se almacene de manera
 * ordenada (menor, mayor) para evitar duplicados.
 *
 * @param i1 Primer índice de la arista.
 * @param i2 Segundo índice de la arista.
 *
 * La función realiza las siguientes operaciones:
 * 1. Determina el menor y mayor de los dos índices proporcionados.
 * 2. Si la deque de aristas está vacía, agrega la nueva arista directamente.
 * 3. Itera sobre las aristas existentes para verificar si la arista (menor, mayor) ya existe.
 * 4. Si la arista ya existe, la función termina sin agregarla.
 * 5. Si la arista no existe, se agrega a la deque utilizando `push_back`.
 */
void Objeto::agregarAristasUnicas(int i1, int i2)
{
    int menor = min(i1, i2);
    int mayor = max(i1, i2);

    int i = 0;
    for (auto arista : aristas)
    {
        if (arista.getIndice1() == menor && arista.getIndice2() == mayor)
        {
            return; // Arista ya existe
        }
         i++;   
    }

    aristas.push_back(Arista(menor, mayor));
}

/**
 * @brief Inicializa el grafo agregando las aristas definidas en el objeto.
 * 
 * Este método recorre todas las aristas almacenadas en el objeto y, para cada arista,
 * obtiene sus índices y calcula su peso utilizando la distancia entre los vértices.
 * Luego, agrega cada arista al grafo correspondiente.
 */
void Objeto::inicializarGrafo()
{
    for (auto arista : aristas)
    {
        int i = arista.getIndice1();
        int j = arista.getIndice2();

        double peso = arista.distancia(vertices);

        grafo.agregarArista(i, j, peso);
    }
}

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
int Objeto::buscarIndiceArista(int i1, int i2)
{
    int menor = min(i1, i2);
    int mayor = max(i1, i2);

    int i = 0;

    for (auto it = aristas.begin(); it != aristas.end(); ++it, i++)
    {
        if ((it->getIndice1() == menor) && (it->getIndice2() == mayor))
        {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Encuentra el índice del vértice más cercano a un vértice dado.
 *
 * @param v El vértice de referencia para calcular la distancia.
 * @return El índice del vértice más cercano, o -1 si no hay vértices.
 *
 * @example
 * Vertice vReferencia(1, 1, 1);
 * int indiceCercano = obj.verticeCercano(vReferencia); // indiceCercano contendrá el índice del vértice más cercano
 */
int Objeto::verticeCercano(Vertice &v)
{
    if (vertices.empty())
    {
        return -1; // Indicar que no hay vértices en el objeto
    }

    int indice = 0;
    int i = 1;
    float distanciaActual;

    float menorDistancia = vertices.front().distancia(v);

    for (auto it = vertices.begin() + 1; it != vertices.end(); it++, i++)
    {
        distanciaActual = it->distancia(v);
        if (distanciaActual < menorDistancia)
        {
            menorDistancia = distanciaActual;
            indice = i;
        }
    }

    return indice;
}

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
void Objeto::rutaCorta(int i1, int i2)
{
    if (i1 == i2)
    {
        cout << "\nLos índices de los vértices dados son iguales.\n\n";
        return;
    }

    if (i1 >= vertices.size() || i2 >= vertices.size())
    {
        cout << "\nAlgunos de los índices de vértices están fuera de rango para el objeto " << nombre << ".\n"
             << endl;
        return;
    }

    vector<int> camino;
    double distancia = grafo.floydWarshall(i1, i2, camino);

    if (distancia == Grafo::INF)
    {
        cout << "\nNo hay ruta entre los vértices " << i1 << " y " << i2 << ".\n"
             << endl;
    }
    else
    {
        cout << "\nLa ruta más corta que conecta los vértices " << i1 << " y " << i2
             << " pasa por: ";
        for (int idx : camino)
        {
            cout << idx << ",";
        }
        cout << " con una longitud de " << distancia << ".\n"
             << endl;
    }
}

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
void Objeto::rutaCortaCentro(int i1)
{
    if (i1 >= vertices.size() || i1 < 0)
    {
        cout << "\nEl índice de vértice está fuera de rango para el objeto " << nombre << ".\n"
             << endl;
        return;
    }

    // Calcular el centroide
    float cx = 0, cy = 0, cz = 0;
    for (Vertice v : vertices)
    {
        cx += v.getX();
        cy += v.getY();
        cz += v.getZ();
    }
    cx /= vertices.size();
    cy /= vertices.size();
    cz /= vertices.size();

    Vertice centroide(cx, cy, cz);

    // Encontrar el vértice más cercano al centroide
    int indiceCercano = 0;
    float distanciaMin = vertices[0].distancia(centroide);

    for (int i = 1; i < vertices.size(); ++i)
    {
        float distancia = vertices[i].distancia(centroide);
        if (distancia < distanciaMin)
        {
            indiceCercano = i;
            distanciaMin = distancia;
        }
    }

    float x =vertices[indiceCercano].getX();
    float y =vertices[indiceCercano].getY();
    float z =vertices[indiceCercano].getZ();

    // Conectar el centroide al vértice más cercano
    grafo.agregarArista(indiceCercano, vertices.size(), distanciaMin);

    // Calcular la ruta más corta
    vector<int> camino;
    float distancia = grafo.floydWarshall(i1, vertices.size(), camino);

    if (distancia == Grafo::INF)
    {
        cout << "\nNo hay ruta entre el vértice " << i1 << " y el centroide.\n"
             << endl;
    }
    else
    {
        cout << "\nLa ruta más corta que conecta el vértice " << i1 << " con el centro del objeto, ubicado en ("
             << cx << ", " << cy << ", " << cz << "), pasa por: ";
        for (int idx : camino)
        {
            cout << idx << ",";
        }
        cout << " con una longitud de " << distancia << ".\n"
             << endl;
    }
}
