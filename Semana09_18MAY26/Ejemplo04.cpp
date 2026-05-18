#include <iostream>
using namespace std;

void incremento(int &n, int inc = 1){
    n = n + inc;
}

int main(){

    int a = 10;
    
    incremento(a, 5);
    
    cout << "a = " << a << endl;

    return 0;
}