#include <iostream>

int parent(int n);
int greatestPowerOf2(int n);

int main() {
    int tests;

    std::cin >> tests;

    for (int i=0; i<tests; i++) {
        long long int sum = 0;
        long long int n;
        std::cin >> n;
        sum += n;
        // std::cout << sum;
        while (n != 1) {
            n /= 2;
            sum += n;
            // std::cout << sum;
        }

        std::cout << sum << '\n';
    }
    return 0;
}