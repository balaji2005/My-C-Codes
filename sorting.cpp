#include <iostream>

bool sorted(int array[], int size);

int main() {

    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = 10;

    int temp = 0;

    for (int i=0; i<size; i++) {
            std::cout << array[i] << ' ';
        }
    std::cout << '\n';

    while (!sorted(array, size)) {
        for (int i=0; i<size-1; i++) {
            if (array[i] > array[i+1]) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
            for (int i=0; i<size; i++) {
                std::cout << array[i] << ' ';
            }
            std::cout << '\n';
        }
        for (int i=0; i<size; i++) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

bool sorted(int array[], int size) {

    for (int i = 0; i<size-1; i++) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }

    return true;
}