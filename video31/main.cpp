#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> v = {2, 3, 5, 6, 7};

    std::vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << (*it) << std::endl;
    }

    return 0;
}
