#include <iostream>
using namespace std;

void intercambio( int &n1, int &n2 ){
	int t = n1;
	n1 = n2;
	n2 = t;
}

int main()
{
	int a = 7;
	int b = 9;
	
	cout << a << ", " << b << endl;
	
	intercambio(a, b);
	
	cout << a << ", " << b << endl;
	
}


	