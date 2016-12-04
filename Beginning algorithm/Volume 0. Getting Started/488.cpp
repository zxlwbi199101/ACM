
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display(int num,char target);
int main()
{
	int groups;
	cin>>groups;

	for(int i=0;i<groups;i++)
	{
		int amplitude,frequency;
		cin>>amplitude>>frequency;
		for(int j=0;j<frequency;j++)
		{
			for(int k=1;k<=amplitude;k++)
			{
				display(k,k+'0');
				cout<<endl;
			}
			for(int k=amplitude-1;k>=1;k--)
			{
				display(k,k+'0');
				cout<<endl;
			}
			if(j!=frequency-1) cout<<endl;
		}
		if(i!=groups-1) cout<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}

void display(int num,char target)
{
	for(int i=0;i<num;i++)
	{
		cout<<target;
	}
}