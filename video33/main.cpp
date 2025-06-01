#include <iostream>
#include <string>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> m;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::string s;
        std::cin >> s;
        m[s]++;
    }

    for(auto pr : m){
        std::cout << pr.first << " " << pr.second << std::endl;
    }
    return 0;
}
