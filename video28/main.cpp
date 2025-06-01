#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> // Para sort, find, etc.
#include <numeric>   // Para accumulate
#include <string>    // Para std::string

// using namespace std; // Es com�n en programaci�n competitiva para brevedad, pero puede ser riesgoso en proyectos grandes.

// --- INTRODUCCI�N A STL (Standard Template Library) ---
// STL (Standard Template Library) -> Biblioteca de Plantillas Est�ndar de C++.
// Es fundamental para Programaci�n Competitiva (Competitive Programming).
// Proporciona Estructuras de Datos (Data Structures) y Algoritmos (Algorithms)
// predefinidos (Predefined) y optimizados.
// Ayuda a reducir la cantidad de c�digo (ej. 50 l�neas a 10) gracias a sus implementaciones (Implementations) eficientes.
// Las implementaciones suelen estar optimizadas (Optimized) en t�rminos de complejidad (Complexity),
// por ejemplo, N log N para ordenamiento.

// --- COMPONENTES PRINCIPALES DE STL ---
// 1. Containers (Contenedores): Almacenan colecciones de objetos.
// 2. Iterators (Iteradores): Permiten acceder y recorrer elementos en contenedores.
// 3. Algorithms (Algoritmos): Funciones para operar sobre rangos de elementos (usualmente en contenedores).
// 4. Functors (Funtores): Objetos que se comportan como funciones (clases con operator()).

int main() {
    // --- 1. CONTENEDORES (Containers) ---
    // Son estructuras de datos pre-implementadas en STL.

    // A. Contenedores Secuenciales (Sequential Containers): Mantienen el orden de inserci�n.
    //    - std::vector: Array din�mico. Ejemplo: std::vector<int> miVector;
    //    - std::stack: Estructura LIFO (Last-In, First-Out). Ejemplo: std::stack<int> miPila;
    //    - std::queue: Estructura FIFO (First-In, First-Out). Ejemplo: std::queue<int> miCola;
    //    - std::pair: No es un contenedor en s�, sino una clase para agrupar dos valores.
    //                 Ejemplo: std::pair<int, std::string> miPar = {1, "hola"};

    // B. Contenedores Ordenados (Ordered Containers): Mantienen los elementos ordenados autom�ticamente.
    //    - std::map: Almacena pares clave-valor, ordenados por clave. Claves �nicas.
    //                Ejemplo: std::map<std::string, int> miMapa;
    //    - std::multimap: Similar a std::map, pero permite claves duplicadas.
    //    - std::set: Almacena elementos �nicos, ordenados.
    //              Ejemplo: std::set<int> miConjunto;
    //    - std::multiset: Similar a std::set, pero permite elementos duplicados.

    // C. Contenedores Desordenados (Unordered Containers): Usan tablas hash (Hashing) para almacenamiento r�pido,
    //                                                     sin orden espec�fico garantizado.
    //    - std::unordered_map: Similar a std::map pero sin orden (m�s r�pido en promedio).
    //                          Ejemplo: std::unordered_map<char, int> miMapaDesordenado;
    //    - std::unordered_set: Similar a std::set pero sin orden (m�s r�pido en promedio).

    // D. Contenedores Anidados (Nested Containers): Contenedores dentro de otros.
    //    - std::vector<std::vector<int>> vecDeVec; // Vector de vectores (matriz 2D)
    //    - std::map<int, std::vector<int>> mapDeVec; // Mapa donde el valor es un vector
    //    - std::set<std::pair<int, std::string>> setDePares; // Conjunto de pares
    //    - std::vector<std::map<int, std::set<int>>> ejemploComplejo; // Vector de mapas, donde el valor del mapa es un conjunto


    // --- 2. ITERADORES (Iterators) ---
    // Act�an como punteros (Pointers) a elementos dentro de los contenedores.
    // Permiten apuntar a una Direcci�n de Memoria (Memory Address) de un elemento del contenedor.
    // Funciones comunes:
    //    - .begin(): Retorna un iterador al primer elemento del contenedor.
    //    - .end(): Retorna un iterador al elemento *despu�s* del �ltimo (usado como marcador de fin).
    // Declaraci�n:
    //    std::vector<int> v_ej = {1, 2, 3};
    //    std::vector<int>::iterator it_largo = v_ej.begin(); // Forma larga
    //    auto it_corto = v_ej.begin();                     // Forma corta usando 'auto' (C++11 en adelante)
    // Continuidad (Continuity) vs Discontinuidad (Discontinuity) de iteradores:
    //    - std::vector, std::array: Iteradores continuos (se puede hacer `it + n`).
    //    - std::map, std::set: Iteradores no continuos (no se puede hacer `it + n` directamente, se usa `std::advance` o `++`/`--`).


    // --- 3. ALGORITMOS (Algorithms) ---
    // Funciones predefinidas que operan sobre rangos (generalmente definidos por iteradores).
    // La mayor�a se encuentran en la cabecera <algorithm>.

    // B�squeda y L�mites (Binary search related):
    //    - std::upper_bound: En un rango ordenado, encuentra el primer elemento estrictamente mayor que un valor.
    //    - std::lower_bound: En un rango ordenado, encuentra el primer elemento no menor (mayor o igual) que un valor.
    //    - std::find: Busca un elemento en un rango (no necesariamente ordenado).

    // Ordenamiento:
    //    - std::sort: Ordena un rango. Complejidad promedio N log N.
    //                 La implementaci�n interna suele ser IntroSort (h�brido de QuickSort, HeapSort e InsertionSort).
    //    - Comparator (Comparador): Funci�n o funtor para definir un orden personalizado en std::sort.

    // Elementos M�ximos/M�nimos:
    //    - std::max_element: Devuelve un iterador al elemento m�ximo en un rango.
    //    - std::min_element: Devuelve un iterador al elemento m�nimo en un rango.

    // Operaciones Num�ricas (de <numeric>):
    //    - std::accumulate: Calcula la suma (u otra operaci�n binaria acumulativa) de elementos en un rango.

    // Modificaci�n de Secuencia:
    //    - std::reverse: Invierte el orden de los elementos en un rango.
    //    - std::next_permutation: Genera la siguiente permutaci�n lexicogr�fica de un rango.
    //    - std::prev_permutation: Genera la permutaci�n lexicogr�fica anterior de un rango.

    // Conteo:
    //    - std::count: Cuenta las ocurrencias de un valor espec�fico en un rango.


    // --- 4. FUNTORES (Functors) ---
    // Son Clases (Classes) que sobrecargan el operador `operator()` para que sus objetos
    // puedan ser llamados como si fueran funciones (can act as functions).
    // �tiles para pasar comportamiento personalizado a algoritmos (ej. un comparador personalizado para std::sort).
    // El video menciona que no son muy usados en programaci�n competitiva b�sica/intermedia y
    // requieren conocimiento de Clases y Plantillas (Templates), por lo que no se cubrir�n en detalle en este curso.
    // Generalmente, para comparadores, se usan funciones lambda o funciones normales.


    // std::cout << "Fin de los comentarios de STL." << std::endl;
    return 0;
}
