#include <iostream> // Para std::cout, std::endl
#include <vector>   // Para std::vector

int main() {
    // Estas lineas aceleran la entrada/salida en C++.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> v = {2, 3, 5, 6, 7};

    // Metodo 1: Usando bucle for basado en indices
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // Metodo 2: Usando iteradores
    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;

    return 0; // Indica que el programa finalizo correctamente
}
