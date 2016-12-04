
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> strs;
	string str;
	while(getline(cin,str) && str.size()>0)
	{
		strs.push_back(str);
	}

	int pos=0;
	while(1)
	{
		bool not_end=true;
		string buffer="";
		for(int i=strs.size()-1;i>=0;i--)
		{
			string s=strs[i];
			if(pos<s.size())
			{
				not_end=false;
				buffer+=s[pos];
			}
			else
			{
				buffer+=" ";
			}
		}
		if(not_end) break;
		else
		{
			pos++;
			not_end=true;
			cout<<buffer<<endl;
			buffer="";
		}
	}

	int program_end;
	cin>>program_end;
	return 0;
}