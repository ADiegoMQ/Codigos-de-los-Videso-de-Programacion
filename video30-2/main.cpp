#include <iostream>  // Para std::cout, std::endl
#include <vector>    // Para usar std::vector
#include <utility>   // Para usar std::pair

// Funcion para imprimir un vector de pares de enteros.
// Se pasa por referencia (&v) para evitar una copia costosa O(N).
void printVec(std::vector<std::pair<int, int>> &v) {
    std::cout << "size: " << v.size() << std::endl; // Muestra el tamaño actual del vector.
    // Itera sobre cada elemento del vector.
    for (int i = 0; i < v.size(); ++i) {
        // Accede al par en la posicion 'i'.
        // '.first' accede al primer elemento del par.
        // '.second' accede al segundo elemento del par.
        std::cout << v[i].first << " " << v[i].second << std::endl;
    }
    // El 'endl' que estaba comentado en tu codigo original se omite aqui.
    // Esto asegura que cada par se imprima en una linea separada,
    // y el ultimo par tambien tendra su propio salto de linea.
}

int main() {
    // Estas lineas aceleran la entrada/salida en C++.
    // Desactivan la sincronizacion de C++ streams con C stdio.
    std::ios_base::sync_with_stdio(false);
    // Desvinculan cin de cout, lo que puede acelerar 'cin'.
    std::cin.tie(NULL);

    // Declaracion e inicializacion de un vector de pares de enteros.
    // Se inicializa directamente con tres pares usando una lista de inicializacion (C++11 y posterior).
    std::vector<std::pair<int, int>> v = {{1, 2}, {2, 3}, {4, 5}};

    // Llama a la funcion para imprimir el contenido del vector de pares.
    printVec(v);

    return 0; // Indica que el programa finalizo correctamente.
}
