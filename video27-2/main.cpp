#include <iostream> // Para entrada/salida (cin, cout)
#include <climits>  // Para usar INT_MAX (el valor maximo para un entero)

using namespace std; // Se mantiene 'using namespace std;' como en tu original.

// Definicion del tamaño maximo para el array global.
// 1e5 + 10 es 100,000 + 10 = 100,010, un tamaño comun para problemas de programacion competitiva.
const int N = 1e5 + 10;
int a[N]; // Array global para ser ordenado.

// Funcion 'merge': Fusiona dos sub-arrays ya ordenados en un unico array ordenado.
// Recibe los limites del sub-array principal (l, r) y el punto medio (mid).
void merge(int l, int r, int mid) {
    // Calcula el tamaño del sub-array izquierdo.
    int l_sz = mid - l + 1;
    // Crea un array temporal para la parte izquierda. Se añade +1 para el valor centinela.
    // NOTA: Esto es un VLA (Variable Length Array), una extension de C/C++, no estandar C++.
    int L[l_sz + 1];

    // Calcula el tamaño del sub-array derecho.
    int r_sz = r - mid;
    // Crea un array temporal para la parte derecha. Se añade +1 para el valor centinela.
    // NOTA: Esto es un VLA (Variable Length Array), una extension de C/C++, no estandar C++.
    int R[r_sz + 1];

    // Valores centinela para marcar el final de los arrays temporales L y R.
    // Esto simplifica el bucle de fusion, ya que no necesitamos comprobar si hemos llegado al final
    // de L o R en cada iteracion; INT_MAX actuara como un valor "infinito".
    L[l_sz] = R[r_sz] = INT_MAX;

    // Copia los elementos del array 'a' al array temporal 'L'.
    for (int i = 0; i < l_sz; ++i) {
        L[i] = a[i + l]; // Los elementos de 'a' de l a mid van a 'L'.
    }
    // Copia los elementos del array 'a' al array temporal 'R'.
    for (int i = 0; i < r_sz; ++i) {
        R[i] = a[i + mid + 1]; // Los elementos de 'a' de mid+1 a r van a 'R'.
    }

    int l_i = 0; // Indice para el array temporal izquierdo (L).
    int r_i = 0; // Indice para el array temporal derecho (R).

    // Fusiona los arrays temporales L y R de nuevo en el array global 'a'
    // en el rango desde 'l' hasta 'r'.
    for (int i = l; i <= r; ++i) {
        // Compara el elemento actual de L con el de R.
        // El elemento mas pequeño se copia al array 'a'.
        if (L[l_i] <= R[r_i]) {
            a[i] = L[l_i];
            l_i++; // Avanza el indice de L.
        } else {
            a[i] = R[r_i];
            r_i++; // Avanza el indice de R.
        }
    }
}

// Funcion recursiva 'mergeSort': Implementa el algoritmo Merge Sort.
// Divide el array en dos mitades, las ordena recursivamente y luego las fusiona.
// l: Indice inicial del sub-array a ordenar.
// r: Indice final del sub-array a ordenar.
void mergeSort(int l, int r) {
    // Caso base de la recursion: si el sub-array tiene un solo elemento (o esta vacio),
    // ya esta ordenado, asi que no se hace nada y se regresa.
    if (l >= r) return; // 'l == r' para un elemento, 'l > r' para un rango invalido (seguridad).

    // Encuentra el punto medio para dividir el array en dos mitades.
    // 'l + (r - l) / 2' es preferible a '(l + r) / 2' para evitar desbordamientos de enteros
    // si 'l' y 'r' son valores muy grandes.
    int mid = l + (r - l) / 2;

    // Llama recursivamente a mergeSort para ordenar la primera mitad.
    mergeSort(l, mid);
    // Llama recursivamente a mergeSort para ordenar la segunda mitad.
    mergeSort(mid + 1, r);

    // Una vez que ambas mitades estan ordenadas, se fusionan usando la funcion 'merge'.
    merge(l, r, mid);
}

int main() {
    // Estas lineas aceleran la entrada/salida en C++.
    // Desactivan la sincronizacion de C++ streams con C stdio.
    ios_base::sync_with_stdio(false);
    // Desvinculan cin de cout, lo que puede acelerar 'cin'.
    cin.tie(NULL);

    int n;
    cout << "Ingrese el numero de elementos a ordenar: ";
    cin >> n; // Lee el numero de elementos.

    cout << "Ingrese " << n << " elementos:" << endl;
    // Lee los 'n' elementos y los almacena en el array global 'a'.
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Llama a mergeSort para ordenar todo el array, desde el indice 0 hasta n-1.
    mergeSort(0, n - 1);

    // Imprime el array ya ordenado.
    cout << "Array ordenado (Merge Sort):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl; // Imprime un salto de linea al final para una mejor presentacion.

    return 0; // Indica que el programa finalizo correctamente.
}
