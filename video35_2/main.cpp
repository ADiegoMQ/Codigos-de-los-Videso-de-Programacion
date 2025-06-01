#include <iostream>
#include <string>
#include <set> // Necesario para std::multiset

void print_multiset_string(std::multiset<std::string> &s) {
    std::cout << "Multiset elements (sorted, duplicates allowed):" << std::endl;
    for (std::string value : s) {
        std::cout << value << std::endl;
    }
    std::cout << "---" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::multiset<std::string> s;
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");

    print_multiset_string(s);

    auto it_find_multi = s.find("abc");
    if (it_find_multi != s.end()) {
        std::cout << "Found (first occurrence): " << (*it_find_multi) << std::endl;

        s.erase(it_find_multi);
        std::cout << "After erasing one 'abc' using iterator:" << std::endl;
        print_multiset_string(s);
    }

    s.insert("abc");
    s.insert("abc");
    std::cout << "Before erasing 'abc' by value:" << std::endl;
    print_multiset_string(s);

    s.erase("abc");
    std::cout << "After erasing all 'abc's using value:" << std::endl;
    print_multiset_string(s);

    return 0;
}
