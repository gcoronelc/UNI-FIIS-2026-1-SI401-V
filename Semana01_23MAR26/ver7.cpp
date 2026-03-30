#include <iostream>
using namespace std;
int main()
{
	int n,d,M;
	do
	{
	cout<<"Ingrese un numero mayor a 1000: "<<endl;
	cin>>n;
	d=n;
	}while(n<1000);
	M=-1;
	while(d>0)
	{
		cout<<d%10<<endl;
		if(d%10>M)
		{
			M=d;
			d=d/10;
			cout<<M<<endl;
		}
		else
		{
			d=d/10;
		}
	}
	cout<<d<<endl;
	return 0;
}	
