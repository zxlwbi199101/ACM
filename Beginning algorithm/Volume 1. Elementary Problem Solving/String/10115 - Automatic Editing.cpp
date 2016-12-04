#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int count;
	while(true)
	{
		string a[10],b[10];
		cin>>count;
		cin.get();
		if(count==0) break;

		for(int i=0;i<count;i++)
		{
			getline(cin,a[i]);
			getline(cin,b[i]);
		}
		string words;
		getline(cin,words);

		for(int i=0;i<count;i++)
		{
			int idx=0;
			while((idx=words.find(a[i]))!=string::npos)
			{
				if(a[i]=="") break;
				words.replace(idx,a[i].size(),b[i]);
			}
		}
		cout<<words<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}

