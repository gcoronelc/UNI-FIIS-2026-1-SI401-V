
#include <iostream>
using namespace std;

int suma(int a, int b){
    return a + b;
}

double suma(double a, double b){
    return a + b;
}

int suma(int a, int b, int c){
    return a + b + c;
}

int main(){

    cout << suma(2,3) << endl;
    cout << suma(2.5,4.1) << endl;
    cout << suma(1,2,3) << endl;

    return 0;
}

