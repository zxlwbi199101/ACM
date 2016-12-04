#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int abs_int(int x)
{
	return (x ^ (x >> 31)) - (x >> 31);
}

int main()
{
	int count,sum;
	cin>>count;
	for(int i=0;i<count;i++)
	{
		cin>>sum;
		sum = abs_int(sum);
		if(sum==0) cout<<3<<endl;
		else
		{
			int r1=(int)(sqrt((double) (sum*2)));
			for(;;r1++)
			{
				int result=r1*(r1+1)/2;
				if(result<sum) continue;			
				if(((result-sum) & 1) ==1) continue;
			
				cout<<r1<<endl;
				break;
			}
		}
		if(i!=count-1) cout<<endl;
	}

	system("pause");
	return 0;
}