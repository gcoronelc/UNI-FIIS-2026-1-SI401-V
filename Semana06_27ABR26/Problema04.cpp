#include <iostream>
using namespace std;

void f(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) {
            int t = a[i];
            a[i] = a[i+1];
            a[i+1] = t;
        }
    }
}

int main() {
    int v[] = {5, 1, 4, 2};
    f(v, 4);
    
    for(int i = 0; i < 4; i++)
        cout << v[i] << " ";
        
    return 0;
}