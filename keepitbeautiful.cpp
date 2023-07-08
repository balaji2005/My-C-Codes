#include <iostream>

bool nonDecreasing(int array[], int size) {
    for (int i; i<size-1; i++) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }
    return true;
}

void rearrange(int array[], int size, int ind) {
    int temp[ind+1];
    for (int i=0; i<=ind; i++) {
        temp[i] = array[i];
    }
    for (int i=0; i<size; i++) {
        array[i] = i<=ind ? array[ind+i+1] : temp[size-ind+i];
    }
}

int main() {

    int tests;

    std::cin >> tests;

    for (int _=0; _<tests; _++) {
        int len;
        std::cin >> len;
        int array[len];
        int result[len];

        for (int i=0; i<len; i++) {
            std::cin >> array[i];
        }

        for (int i=0; i<len-1; i++) {
            rearrange(&result, len, i);
        }
    }

    return 0;
}