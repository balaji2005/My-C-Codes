#include <iostream>

using str = std::string;

int main() {
    using std::cout;
    using std::cin;
    using std::string;

    string name;

    cout << "What is your name?: ";
    cin >> name;
    cout << "Hello " << name << '\n';
    cout << "I like food";
    return 0;
}