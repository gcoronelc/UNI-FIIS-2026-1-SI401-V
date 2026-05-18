#include <iostream>
using namespace std;

int sumar( int n1, int n2 ){
	int suma = n1 + n2;
	return suma;
}

int main()
{
	int a = 7;
	int b = 9;
	
	int c = sumar(a, b);
	
	cout << a << " + " << b << " = " << c << endl;
	
}


	