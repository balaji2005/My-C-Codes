#include <iostream>

int main() {

    int array[] = {1, 3, 5, 6, 7};

    for (int element : array) {
        std::cout << element << '\n';
    }

    return 0;
}