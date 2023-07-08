#include <iostream>

int main() {

    std::cout << "***********Rectangle Generator***********\n";

    int rows, columns;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    for (int i=1; i<=rows; i++) {
        for (int j=1; j<=columns; j++) {
            std::cout << "*";
        }
        std::cout << '\n';
    }

}