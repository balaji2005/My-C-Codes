#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    char array[n];
    vector<char> v;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i] == '+') {
            v.push_back('+');
            v.push_back('+');
            v.push_back('+');
        } else {
            v.push_back('-');
            v.push_back('-');
        }
    }
    for (char c : v) {
        cout << c;
    }
}