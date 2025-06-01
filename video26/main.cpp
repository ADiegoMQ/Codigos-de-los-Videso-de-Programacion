#include <iostream>

int digit_sum(int n){
    if (n == 0) return 0;
    return digit_sum(n / 10) + (n % 10);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << digit_sum(n);
    return 0; // Added return 0 for good practice
}
