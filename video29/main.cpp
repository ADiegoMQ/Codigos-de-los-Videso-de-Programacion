#include <iostream> // Necesario para std::cout, std::endl, std::cin
#include <string>   // Necesario para std::string
#include <utility>  // Necesario para std::pair y std::make_pair
#include <algorithm> // Necesario para std::swap

int main() {
    // Estas lineas aceleran la entrada/salida en C++.
    // Desactivan la sincronizacion de C++ streams con C stdio.
    std::ios_base::sync_with_stdio(false);
    // Desvinculan cin de cout, lo que puede acelerar 'cin'.
    std::cin.tie(NULL);

    // --- PAIRS (Parejas) ---
    std::cout << "--- PAIRS ---" << std::endl;

    // Declaracion e Inicializacion de un par
    std::pair<int, std::string> p;

    // Metodo 1: make_pair (Explicito pero a menudo implicito en la asignacion)
    // p = std::make_pair(2, "abc");

    // Metodo 2: Inicializacion con llaves (mas comun y conciso en C++11 y posteriores)
    p = {2, "abcd"};
    std::cout << "Par p: " << p.first << " " << p.second << std::endl;

    // Copia de un par (por valor)
    // p1 es una copia independiente de p.
    std::pair<int, std::string> p1 = p;
    p1.first = 3; // Cambia p1, no afecta a p
    std::cout << "Par p despues de que p1 fue modificado (p1 era una copia): "
              << p.first << " " << p.second << std::endl;
    std::cout << "Par p1: " << p1.first << " " << p1.second << std::endl;

    // Copia de un par (por referencia)
    // p2 es una referencia a p. Cualquier cambio en p2 afectara a p.
    std::pair<int, std::string> &p2 = p;
    p2.first = 100; // Cambia p2, y tambien cambia p
    std::cout << "Par p despues de que p2 (referencia) fue modificado: "
              << p.first << " " << p.second << std::endl;
    std::cout << "Par p2: " << p2.first << " " << p2.second << std::endl;

    // --- Array de Pares (para relacionar dos arrays o datos) ---
    std::cout << "\n--- Array de Pares ---" << std::endl;

    // Ejemplos de arrays que podrian ser relacionados
    // int a_arr[] = {1, 2, 3};
    // int b_arr[] = {2, 3, 4};

    // Declaracion de un array de 3 pares de enteros
    std::pair<int, int> p_array[3];

    // Inicializacion de los elementos del array de pares
    p_array[0] = {1, 2}; // Relacion 1 con 2
    p_array[1] = {2, 3}; // Relacion 2 con 3
    p_array[2] = {3, 4}; // Relacion 3 con 4

    std::cout << "p_array original:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << p_array[i].first << " " << p_array[i].second << std::endl;
    }

    // Intercambio de dos elementos del array de pares usando std::swap
    std::swap(p_array[0], p_array[2]);
    std::cout << "p_array despues de intercambiar el 0-esimo y 2-o elemento:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << p_array[i].first << " " << p_array[i].second << std::endl;
    }
    std::cout << std::endl;

    return 0; // Indica que el programa finalizo correctamente
}
