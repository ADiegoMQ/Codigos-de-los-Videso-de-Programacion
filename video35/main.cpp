#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_set<std::string> s;

    int n_strings;
    std::cin >> n_strings;
    for (int i = 0; i < n_strings; ++i) {
        std::string str_input;
        std::cin >> str_input;
        s.insert(str_input);
    }

    int num_queries;
    std::cin >> num_queries;
    while (num_queries--) {
        std::string query_str;
        std::cin >> query_str;
        if (s.find(query_str) == s.end()) {
            std::cout << "no\n";
        } else {
            std::cout << "yes\n";
        }
    }

    return 0;
}
