#include <iostream>
#include <cmath>

int main() {

    char op;

    double num1, num2, result;

    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    switch (op) {
        case '+':
            std::cout << "The result is " << num1 + num2 << '\n';
            break;
        case '-':
            std::cout << "The result is " << num1 - num2 << '\n';
            break;
        case '*':
            std::cout << "The result is " << num1 * num2 << '\n';
            break;
        case '/':
            std::cout << "The result is " << num1 / num2 << '\n';
            break;
        default:
            std::cout << "Please enter only the operation (+, -, *, /)!!!\n";       
    }
    
    main();
}