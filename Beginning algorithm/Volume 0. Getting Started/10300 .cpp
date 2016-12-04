
#include <iostream>
using namespace std;
int main()
{
	int count;
	cin>>count;
	for(int i=0;i<count;i++)
	{
		int count2;
		cin>>count2;
		
		long sum=0;
		for(int j=0;j<count2;j++)
		{
			int a,b,c;
			cin>>a>>b>>c;

			sum+=a*c;
		}
		cout<<sum<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}