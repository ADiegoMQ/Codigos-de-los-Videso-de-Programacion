#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

void printIntVec(std::vector<int> &v) {
    std::cout << "size: " << v.size() << std::endl;
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void printStringVec(std::vector<std::string> &v) {
    std::cout << "size: " << v.size() << std::endl;
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "--- VECTORES ---" << std::endl;

    std::cout << "\n--- Vectores de Enteros ---" << std::endl;
    std::vector<int> v_int;

    v_int.push_back(7);
    v_int.push_back(6);
    std::cout << "Despues de añadir 7 y 6:" << std::endl;
    printIntVec(v_int);

    v_int.pop_back();
    std::cout << "Despues de pop_back():" << std::endl;
    printIntVec(v_int);

    std::vector<int> v_int_sized(5);
    std::cout << "Vector inicializado con tamaño 5 (v_int_sized):" << std::endl;
    printIntVec(v_int_sized);

    std::vector<int> v_int_filled(10, 3);
    std::cout << "Vector inicializado con tamaño 10, todos los elementos con valor 3 (v_int_filled):" << std::endl;
    printIntVec(v_int_filled);
    v_int_filled.push_back(7);
    std::cout << "Despues de añadir 7 a v_int_filled:" << std::endl;
    printIntVec(v_int_filled);

    std::vector<int> v_int_copy = v_int_filled;
    v_int_copy.push_back(5);
    std::cout << "v_int_filled original despues de modificar la copia:" << std::endl;
    printIntVec(v_int_filled);
    std::cout << "Vector copiado v_int_copy despues de añadir 5:" << std::endl;
    printIntVec(v_int_copy);

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

    return 0;
}
