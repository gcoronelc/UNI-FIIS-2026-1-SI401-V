#include <iostream>
using namespace std;
int main()
{
	int n,suma;
	cout<<"Ingrese un numero cualquiera: "<<endl;
	cin>>n;
	for(int i=0; i<n;i++)
	{
		suma = suma + i;
	}
	cout<<"La suma de los: "<<n-1<<" numeros es: "<<suma<<endl;
	return 0;
}
