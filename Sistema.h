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

#ifndef SISTEMA_H
#define SISTEMA_H

#include <deque>
#include <string_view>
#include "Objeto.h"

using namespace std;

/**
 * @class Sistema
 * @brief Clase que representa un sistema de objetos 3D.
 */
class Sistema
{
private:
    deque<Objeto> objetos; ///< Lista de objetos 3D en el sistema.

public:
    /**
     * @brief Constructor por defecto.
     */
    Sistema();

    /**
     * @brief Obtiene la lista de objetos 3D en el sistema.
     * @return Lista de objetos 3D.
     */
    deque<Objeto> &getObjetos();

    /**
     * @brief Establece la lista de objetos 3D en el sistema.
     * @param o Lista de objetos 3D.
     */
    void setObjetos(deque<Objeto> o);

    /**
     * @brief Busca un objeto 3D en el sistema por su nombre.
     * @param nombre Nombre del objeto 3D.
     * @return Índice del objeto 3D en la lista si se encuentra, -1 en caso contrario.
     */
    int buscarObjeto(string nombre);

    /**
     * @brief Verifica si un nombre es válido.
     * @param nombre Nombre a verificar.
     * @return true si el nombre es válido, false en caso contrario.
     */
    bool nombreValido(string_view nombre);

    /**
     * @brief Verifica si un número es un número natural válido.
     * @param numero Número a verificar.
     * @return true si el número es un número natural válido, false en caso contrario.
     */
    bool numeroNaturalValido(string_view numero);

    /**
     * @brief Verifica si un número es un número entero válido.
     * @param numero Número a verificar.
     * @return true si el número es un número entero válido, false en caso contrario.
     */
    bool numeroEnteroValido(string_view numero);

    /**
     * @brief Verifica si un archivo existe y es válido.
     * @param ruta Ruta del archivo a verificar.
     * @return true si el archivo existe y es válido, false en caso contrario.
     */
    bool validarArchivo(string ruta);

    /**
     * @brief Crea aristas para una cara.
     * @param cara Cara para la que se crean aristas.
     */
    void crearAristas(Objeto &Objeto);

    /**
     * @brief Carga un objeto 3D desde un archivo.
     * @param ruta Ruta del archivo que contiene el objeto 3D.
     */
    void cargarObjeto(string ruta);

    /**
     * @brief Muestra un listado de los objetos 3D en el sistema.
     */
    void listado();

    /**
     * @brief Agrega vértices a una cara.
     * @param cara Cara a la que se agregan vértices.
     * @param i1 Índice del primer vértice.
     * @param i2 Índice del segundo vértice.
     * @param i3 Índice del tercer vértice.
     * @param i4 Índice del cuarto vértice.
     */
    void agregarAristasCara(Objeto &objeto, Cara &cara, int i1, int i2, int i3, int i4);

    /**
     * @brief Calcula la envolvente de un objeto 3D.
     * @param nombre Nombre del objeto 3D.
     */
    void envolvente(string nombre);

    /**
     * @brief Obtiene el punto mayor general de un objeto 3D.
     * @return Punto mayor general del objeto 3D.
     */
    Vertice puntoMayorGeneral();

    /**
     * @brief Obtiene el punto menor general de un objeto 3D.
     * @return Punto menor general del objeto 3D.
     */
    Vertice puntoMenorGeneral();

    void actualizarEnvolvente(Objeto &envolvente);

    /**
     * @brief Calcula la envolvente global de todos los objetos 3D en el sistema.
     */
    void envolventeGlobal();

    /**
     * @brief Descarga un objeto 3D del sistema.
     * @param nombre Nombre del objeto 3D a descargar.
     */
    void descargar(string nombre);

    /**
     * @brief Guarda un objeto 3D en un archivo.
     * @param nombre Nombre del objeto 3D a guardar.
     * @param ruta Ruta del archivo en el que se guardará el objeto 3D.
     */
    void guardar(string nombre, string ruta);

    /**
     * @brief Encuentra el vértice más cercano a un objeto dado por su nombre.
     *
     * Esta función calcula el vértice más cercano a un objeto en el espacio 3D
     * utilizando las coordenadas proporcionadas (px, py, pz) y el nombre del objeto.
     *
     * @param px Coordenada X del punto de referencia.
     * @param py Coordenada Y del punto de referencia.
     * @param pz Coordenada Z del punto de referencia.
     * @param nombre Nombre del objeto del cual se desea encontrar el vértice más cercano.
     *
     * @example
     * verticeCercanoObjeto(1.0, 2.0, 3.0, "Objeto1");
     * // Busca el vértice más cercano al objeto "Objeto1" desde el punto (1.0, 2.0, 3.0).
     */
    void verticeCercanoObjeto(float px, float py, float pz, string nombre);

    /**
     * @brief Encuentra el vértice más cercano en general a un punto dado.
     *
     * Esta función calcula el vértice más cercano en el espacio 3D a un punto
     * específico definido por sus coordenadas (px, py, pz).
     *
     * @param px Coordenada X del punto de referencia.
     * @param py Coordenada Y del punto de referencia.
     * @param pz Coordenada Z del punto de referencia.
     *
     * @example
     * verticeCercanoGeneral(1.0, 2.0, 3.0);
     * // Busca el vértice más cercano al punto (1.0, 2.0, 3.0).
     */
    void verticeCercanoGeneral(float px, float py, float pz);

    /**
     * @brief Encuentra todos los vértices cercanos a un objeto dado por su nombre.
     *
     * Esta función busca y devuelve todos los vértices que están cerca de un objeto
     * específico identificado por su nombre.
     *
     * @param nombre Nombre del objeto del cual se desean encontrar los vértices cercanos.
     *
     * @example
     * verticeCercanosCaja("Caja1");
     * // Busca todos los vértices cercanos al objeto "Caja1".
     */
    void verticeCercanosCaja(string nombre);

    /**
     * @brief Calcula y muestra la ruta más corta entre dos vértices en un objeto específico.
     * 
     * Este método busca un objeto en el sistema utilizando su nombre. Si el objeto no está
     * cargado en memoria, se informa al usuario. Si el objeto está disponible, se llama al
     * método `rutaCorta` del objeto correspondiente para calcular y mostrar la ruta más corta
     * entre los vértices especificados.
     * 
     * @param i1 Índice del primer vértice.
     * @param i2 Índice del segundo vértice.
     * @param nombre Nombre del objeto en el que se desea calcular la ruta.
     */
    void rutaCorta(int i1, int i2, string nombre);

    /**
     * @brief Calcula y muestra la ruta más corta desde un vértice hasta el centroide de un objeto específico.
     * 
     * Este método busca un objeto en el sistema utilizando su nombre. Si el objeto no está
     * cargado en memoria, se informa al usuario. Si el objeto está disponible, se llama al
     * método `rutaCortaCentro` del objeto correspondiente para calcular y mostrar la ruta más
     * corta desde el vértice dado hasta el centroide del objeto.
     * 
     * @param i1 Índice del vértice desde el cual se calcula la ruta más corta al centroide.
     * @param nombre Nombre del objeto en el que se desea calcular la ruta.
     */
    void rutaCortaCentro(int i1, string nombre);
};

#endif // SISTEMA_H