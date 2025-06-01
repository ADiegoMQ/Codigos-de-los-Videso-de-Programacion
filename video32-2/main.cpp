#include <iostream> // Para std::cout, std::endl
#include <vector>   // Para std::vector
#include <utility>  // Para std::pair

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::pair<int, int>> v_p = {{1, 2}, {2, 3}};

    for (std::pair<int, int> &value : v_p) {
        std::cout << value.first << " " << value.second << std::endl;
    }

    return 0;
}
