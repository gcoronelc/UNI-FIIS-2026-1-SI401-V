#include <iostream>
using namespace std;

int traza(int mat[][3], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += mat[i][i];
	}
	return suma;
}

int main() {
	int matriz[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matriz[i][j];
			//if (j < 2) 
				cout << " ";
		}
		cout << endl;
	}
	int d = traza(matriz, 3);
	cout << "Traza: " << d << endl;
	return 0;
}