#include <iostream>  // Para std::cout, std::endl, std::cin
#include <vector>    // Para usar std::vector
#include <string>    // Para usar std::string
#include <utility>   // Para usar std::pair y std::make_pair (aunque no se use directamente en el ejemplo visible)
#include <algorithm> // Para std::swap si fuera necesario, aunque no se usa directamente en este ejemplo.

// Funcion para imprimir un vector de enteros.
// Se pasa por referencia (&v) para evitar una copia costosa O(N).
void printIntVec(std::vector<int> &v) {
    std::cout << "size: " << v.size() << std::endl; // v.size() es una operacion O(1)
    // v.push_back(2); // Ejemplo de modificacion si se pasa por referencia (comentado)
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " "; // Accediendo a elementos como en arrays v[i]
    }
    std::cout << std::endl;
}

// Funcion para imprimir un vector de strings.
// Se pasa por referencia (&v) para evitar una copia costosa O(N).
void printStringVec(std::vector<std::string> &v) {
    std::cout << "size: " << v.size() << std::endl;
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    // Estas lineas aceleran la entrada/salida en C++.
    // Desactivan la sincronizacion de C++ streams con C stdio.
    std::ios_base::sync_with_stdio(false);
    // Desvinculan cin de cout, lo que puede acelerar 'cin'.
    std::cin.tie(NULL);

    std::cout << "--- VECTORES ---" << std::endl;

    // --- Vectores de Enteros ---
    std::cout << "\n--- Vectores de Enteros ---" << std::endl;
    std::vector<int> v_int; // Declaracion, el tamaño actual es 0

    // Codigo para tomar entrada de usuario y usar push_back (descomentar para usar)
    /*
    int n_int;
    std::cout << "Ingrese el numero de enteros para el vector: ";
    std::cin >> n_int;
    for (int i = 0; i < n_int; ++i) {
        int x;
        std::cin >> x;
        // printIntVec(v_int); // Para mostrar el cambio de tamaño en cada paso
        v_int.push_back(x); // Añade 'x' al final del vector, operacion O(1) amortizado
    }
    std::cout << "Contenido final del vector de enteros despues de la entrada:" << std::endl;
    printIntVec(v_int);
    */

    // Ejemplo de uso de push_back para demostrar la naturaleza dinamica del vector
    v_int.push_back(7);
    v_int.push_back(6);
    std::cout << "Despues de añadir 7 y 6:" << std::endl;
    printIntVec(v_int);

    v_int.pop_back(); // Elimina el ultimo elemento (6 en este caso), operacion O(1)
    std::cout << "Despues de pop_back():" << std::endl;
    printIntVec(v_int); // Deberia imprimir tamaño: 1, contenido: 7

    // Inicializacion de un vector con un tamaño especifico (elementos se inicializan a 0 por defecto para int)
    std::vector<int> v_int_sized(5);
    std::cout << "Vector inicializado con tamaño 5 (v_int_sized):" << std::endl;
    printIntVec(v_int_sized); // Mostrara 5 ceros

    // Inicializacion de un vector con un tamaño especifico y un valor inicial para todos los elementos
    std::vector<int> v_int_filled(10, 3);
    std::cout << "Vector inicializado con tamaño 10, todos los elementos con valor 3 (v_int_filled):" << std::endl;
    printIntVec(v_int_filled);
    v_int_filled.push_back(7); // El tamaño se vuelve 11
    std::cout << "Despues de añadir 7 a v_int_filled:" << std::endl;
    printIntVec(v_int_filled);


    // Copia de un vector (operacion O(N))
    // v_int_copy es una copia separada de v_int_filled.
    // Modificar v_int_copy no afecta a v_int_filled.
    std::vector<int> v_int_copy = v_int_filled;
    v_int_copy.push_back(5);
    std::cout << "v_int_filled original despues de modificar la copia:" << std::endl;
    printIntVec(v_int_filled);
    std::cout << "Vector copiado v_int_copy despues de añadir 5:" << std::endl;
    printIntVec(v_int_copy);


    // --- Vectores de Strings ---
    std::cout << "\n--- Vectores de Strings ---" << std::endl;
    std::vector<std::string> v_str;
    int n_str;
    std::cout << "Ingrese el numero de strings para el vector: ";
    std::cin >> n_str;
    std::cout << "Ingrese " << n_str << " strings:" << std::endl;
    for (int i = 0; i < n_str; ++i) {
        std::string s;
        std::cin >> s;
        v_str.push_back(s);
    }
    std::cout << "Contenido del vector de strings:" << std::endl;
    printStringVec(v_str);


    // --- Vector de Pares (Ejemplo, descomentar para usar) ---
    // Este bloque muestra como declarar y usar un vector de pares.
    /*
    std::cout << "\n--- Vector de Pares ---" << std::endl;
    std::vector<std::pair<int, int>> v_pair_of_int;
    v_pair_of_int.push_back({1,2}); // Inicializacion con llaves (C++11+)
    v_pair_of_int.push_back(std::make_pair(3,4)); // Usando std::make_pair explicito
    std::cout << "Contenido del vector de pares:" << std::endl;
    for(int i=0; i<v_pair_of_int.size(); ++i){
        std::cout << v_pair_of_int[i].first << " " << v_pair_of_int[i].second << std::endl;
    }
    */

    return 0; // Indica que el programa finalizo correctamente
}
