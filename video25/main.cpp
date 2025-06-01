#include <iostream>
using namespace std;

// Factorial of N (comment from video)
int fact(int n) {
    if (n == 0) { // Base case
        return 1;
    }
    return fact(n - 1) * n; // Recursive step
}

int main() {
    int n;
    cin >> n; // Input 5, then 6
    cout << fact(n);
}
