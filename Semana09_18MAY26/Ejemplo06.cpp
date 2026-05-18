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

    int datos[] = {2, 4, 6, 8, 10, 16, 11};
    
	int n = sizeof(datos) / sizeof(datos[0]);
	
    cout << "Suma = " << suma(datos, n);

    return 0;
}
