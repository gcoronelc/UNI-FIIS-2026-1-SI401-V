#include <iostream>
using namespace std;
int main()
{
	int n,p;
	p=1;
	while(p==1)
	{
	cout<<"Ingrese un numero cualquiera: "<<endl;
	cin>>n;
	if(n>=10)
	{
		cout<<"El numero ingresado es mayor que 10"<<endl;
		//return 1;
	}
	else
	{
		cout<<"El numero ingresado es menor que 10"<<endl;
		//return 2;
	}
	//cout<<"El numero ingresado es: "<<n<<endl;
	cout<<"Si desea ingresar otro numero escriba 1, en otro caso contrario escriba cualquier numero: "<<endl;
	cin>>p;
	}
	return 0;
}
