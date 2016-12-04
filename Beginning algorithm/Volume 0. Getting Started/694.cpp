
#include <iostream>
#include <string>
using namespace std;
int main()
{
	for(int i=1;1;i++)
	{
		int initial,limit;
		cin>>initial>>limit;

		if(initial<=0 || limit<=0) break;
		int step=0;
		int ori_initial=initial;

		for(;;)
		{
			step++;
			if(initial==1 || initial>limit) break;
			if(initial&1)
			{
				initial=3*initial+1;
				if(initial<0||initial>limit) break;
			}
			else
			{
				initial/=2;				
			}
		}
		cout<<"Case "<<i<<": A = "<<ori_initial<<", limit = "<<limit<<", number of terms = "<<step<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}