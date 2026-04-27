#include <iostream>
using namespace std;

void g(int a[], int n) {
    for(int i = 0; i < n; i++)
        a[i] = a[i] + i;
}

int main() {
    int x[] = {1, 2, 3, 4};
    g(x, 4);
    
    for(int i = 3; i >= 0; i--)
        cout << x[i] << " ";
        
    return 0;
}