#include <iostream>
using namespace std;

int f(int x) {
    if(x <= 1) return 1;
    return x * f(x - 2);
}

int main() {
    cout << f(5);
    return 0;
}