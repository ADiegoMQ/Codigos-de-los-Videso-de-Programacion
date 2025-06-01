#include <iostream>  // Para entrada/salida (cin, cout)
#include <vector>    // Para usar std::vector (arrays dinámicos)
#include <algorithm> // Para usar std::swap

int main() {
    // Desactivar la sincronización de C++ streams con C stdio
    // y desacoplar cin/cout para una entrada/salida más rápida.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cout << "Ingrese el numero de elementos: ";
    std::cin >> n;

    // Declarar un std::vector de tamaño 'n'
    std::vector<int> a(n);

    std::cout << "Ingrese " << n << " elementos:" << std::endl;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    // Lógica del Selection Sort
    // El bucle exterior itera a través de cada posición donde se colocará el elemento más pequeño.
    // Solo necesitamos ir hasta n-1 porque el último elemento se colocará automáticamente.
    for(int i = 0; i < n - 1; ++i){
        // minIndex guardará el índice del elemento mínimo en la parte no ordenada del array.
        int minIndex = i;

        // El bucle interior busca el elemento mínimo en la sublista no ordenada (desde i+1 hasta n-1).
        for(int j = i + 1; j < n; ++j){
            if(a[j] < a[minIndex]){
                minIndex = j; // Actualiza minIndex si se encuentra un elemento más pequeño.
            }
        }

        // Intercambia el elemento mínimo encontrado con el elemento en la posición actual 'i'.
        // Esto mueve el elemento más pequeño al principio de la parte no ordenada.
        std::swap(a[i], a[minIndex]);
    }

    // Imprimir el array ordenado
    std::cout << "Array ordenado (Selection Sort):" << std::endl;
    for(int i = 0; i < n; ++i){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
