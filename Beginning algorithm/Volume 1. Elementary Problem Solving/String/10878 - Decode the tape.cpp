#include <iostream>
#include <string>
using namespace std;


int main()
{
	string line;
	for(int count=0;true;count++)
	{
		getline(cin,line);
		if(line[0]=='_' && count!=0) break;
		if(line[0]=='_') continue;

		line.erase(6,1);
		int num=0;
		for(int i=8;i>=2;i--)
		{
			if(line[i]=='o' && i==8)
			{
				num++;
				continue;
			}
			if(line[i]=='o') num+=(2<<(7-i));
		}
		cout<<(char)num;
	}
	int program_end;
	cin>>program_end;
	return 0;
}
