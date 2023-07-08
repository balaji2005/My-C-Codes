#include <iostream>

int main() {
    int tests;

    std::cin >> tests;

    for (int i=0; i<tests; i++) {
        int n;

        std::cin >> n;

        switch (n) {
            case 2:
                std::cout << "Bob\n";
                break;
            case 3:
                std::cout << "Bob\n";
                break;
            case 4:
                std::cout << "Bob\n";
                break;
            default:
                std::cout << "Alice\n";
        }
    }
}