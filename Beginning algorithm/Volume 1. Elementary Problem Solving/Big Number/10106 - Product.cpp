#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char result[510];
	string a,b;
	while(cin>>a>>b)
	{
		memset(result,0,sizeof(char)*510);
		for(int i=a.size()-1;i>=0;i--)
		{
			int last=0,idx;
			for(int j=b.size()-1;j>=0;j--)
			{
				idx=a.size()-1-i + b.size()-1-j;
				int temp=(a[i]-'0')*(b[j]-'0')+result[idx]+last;
				result[idx]=temp%10;
				last=temp/10;
			}
			for(int j=idx+1;last!=0;j++)
			{
				int temp=result[j]+last;
				result[j]=temp%10;
				last=temp/10;
			}
		}
		bool begin=false;
		for(int i=509;i>=0;i--)
		{
			if(!begin)
			{
				if(i==0) cout<<0;
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
	}

	int program_end;
	cin>>program_end;
	return 0;
}
