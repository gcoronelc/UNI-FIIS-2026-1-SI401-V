#include <iostream>
using namespace std;
int main()
{
	int n,c,r,sumaM,sumam,d,r1;
	do
	{
	cout<<"Ingrese un numero de 5 cifras: "<<endl;
	cin>>n;
	d=n;
	}while(n>99999||n<10000);
	sumaM=0;
	for(int i=0;i<3;i++)
	{
		r=d%10;
		cout<<r<<endl;
		sumaM=sumaM+r;
		d=d/10;
	}
	r1=r;
	for(int i=0;i<2;i++)
	{
		r=d%10;
		sumam=sumam+r;
		d=d/10;
	}
	cout<<"la suma de los 3 ultimos es: "<<sumaM<<endl;
	cout<<"la suma de los 3 primeros es: "<<sumam + r1<<endl;
	cout<<"la suma pedida es: "<<sumaM + sumam + r1<<endl;
	return 0;
}
