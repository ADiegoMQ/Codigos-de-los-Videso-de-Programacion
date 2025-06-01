#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<std::string, int> m;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        m[s]++;
    }

    int q;
    std::cin >> q;
    while (q--) {
        std::string s;
        std::cin >> s;
        std::cout << m[s] << std::endl;
    }

    return 0;
}
