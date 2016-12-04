
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string source;
	while(getline(cin,source))
	{
		int count=0;
		bool inWord=false;
		for(int i=0;i<source.size();i++)
		{
			char s=source[i];
			if((s>=65 && s<=90) || (s>=97 && s<=122))
			{
				inWord=true;
			}
			else
			{
				if(inWord) count++;
				inWord=false;
			}
		}
		cout<<count<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}