#include <iostream>
using namespace std;

void invertir(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int aux = a[i];
        a[i] = a[n - i-1];
        a[n - i-1] = aux;
    }
}


int main(){
	
	int a[] = {5, 1, 4, 2};
	invertir(a,4);
	for(int i=0; i<4; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}