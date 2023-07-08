#include <iostream>

int main() {

    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age >= 18) {
        std::cout << "You are a major";
    } else if (age < 0) {
        std::cout << "Are you cheating?";
    } else {
        std::cout << "You are a minor";
    }

    return 0;
}