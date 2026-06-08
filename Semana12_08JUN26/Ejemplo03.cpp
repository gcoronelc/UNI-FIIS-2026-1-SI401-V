/*
  * VARIABLES POR REFERENCIA Y PUNTEROS
*/

#include <iostream>

using namespace std;

void variables(int a, int &b, int* c){
	a = a * 2;
	b = b * 2;
	*c = *c * 2;
}

int main(){
	
	int x = 10;
	int y = 10;
	int z = 10;
	
	cout << x << "\t" << y << "\t" << z << endl;
	variables(x, y, &z);
	cout << x << "\t" << y << "\t" << z << endl;
	
	return 0;
	
}
