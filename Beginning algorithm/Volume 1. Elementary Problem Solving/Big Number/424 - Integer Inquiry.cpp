#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string nums[100];
	int count=0;
	while(1)
	{
		getline(cin,nums[count]);
		if(nums[count]=="0") break;
		count++;
	}

	char result[150];
	memset(result,0,150*sizeof(char));
	for(int i=0;i<count;i++)
	{
		int last=0;
		for(int j=nums[i].size()-1;j>=0;j--)
		{
			int idx=nums[i].size()-1-j;
			int temp=nums[i][j]-'0'+result[idx]+last;
			result[idx]=temp%10;
			last=temp/10;
		}
		for(int j=nums[i].size();last!=0;j++)
		{
			int temp=result[j]+last;
			result[j]=temp%10;
			last=temp/10;
		}
	}
	bool begin=false;
	for(int i=149;i>=0;i--)
	{
		if(!begin)
		{
			if(result[i]!=0)
			{
				begin=true;
				cout<<(int)result[i];
			}
		}
		else
		{
			cout<<(int)result[i];
		}
	}
	cout<<endl;

	int program_end;
	cin>>program_end;
	return 0;
}
