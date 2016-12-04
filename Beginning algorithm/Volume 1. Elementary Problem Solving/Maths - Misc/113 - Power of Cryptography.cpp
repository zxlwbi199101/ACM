#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double a=0,b=0;
	while(cin>>a>>b)
	{
		int c=(int)(pow(b,1.0/a)+0.5);
		cout<<c<<endl;
	}


	system("pause");
	return 0;
}