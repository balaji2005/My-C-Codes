#include <iostream>
#include <cmath>

int main() {

    double a, b, c;

    std::cout << "Enter the side a: ";
    std::cin >> a;

    std::cout << "Enter the side b: ";
    std::cin >> b;

    a = pow(a, 2);
    b = pow(b, 2);

    c = sqrt(a + b);

    std::cout << "The hypotenuse = " << c;

    return 0;
}