#include <bits/stdc++.h>

int main() {
    int u = 0, sum = 120;
    int count = 0;
    for (int i = 256, k=0; i>0 && sum > 0; k++, i = i/2, sum = sum/(k+1)) {
        u = u+ i + sum;
        count += 1;
    }
    std::cout << count; 
}