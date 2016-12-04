#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int num=8;
	while(cin>>num && num!=0)
	{
		int row=(int)sqrt((double)(num-1))+1;
		int idx=num-(row-1)*(row-1);

		if(row & 0x01) //ÆæÊý
		{
			if(idx>row)
			{
				cout<<row-(idx-row)<<' '<<row<<endl;
			}
			else
			{
				cout<<row<<' '<<idx<<endl;
			}
		}
		else //Å¼Êý
		{
			if(idx>row)
			{
				cout<<row<<' '<<row-(idx-row)<<endl;
			}
			else
			{
				cout<<idx<<' '<<row<<endl;
			}
		}
	}

	return 0;
}