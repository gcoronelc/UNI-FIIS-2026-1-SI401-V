#include <iostream>
using namespace std;

int f(int a[], int n) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)
            s += a[i];
        else
            s -= a[i];
    }
    return s;
}

int main() {
    int v[] = {3, 5, 2, 8, 1};
    cout << f(v, 5);
    return 0;
}