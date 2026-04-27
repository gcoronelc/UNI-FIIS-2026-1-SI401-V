#include <iostream>
using namespace std;

int h(int a[], int n) {
    int m = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] < m)
            m = a[i];
    return m;
}

int main() {
    int v[] = {7, 3, 9, 2, 6};
    cout << h(v, 5) * 2;
    return 0;
}