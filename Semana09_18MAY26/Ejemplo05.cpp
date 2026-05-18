#include <iostream>
using namespace std;

int suma(int arreglo[], int n){

    int total = 0;

    for(int i = 0; i < n; i++){
        total += arreglo[i];
    }

    return total;
}

int main(){

    int datos[5] = {2,4,6,8,10};

    cout << "Suma = " << suma(datos,5);

    return 0;
}
