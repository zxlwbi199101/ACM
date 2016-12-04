#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> strs;
	int groups=1;
	while(1)
	{
		string s;
		if(!(cin>>s)) break;
		if(s!="9") strs.push_back(s);
		else
		{
			cout<<"Set "<<groups++<<" is ";			
			for(int i=0;i<strs.size()-1;i++)
			{
				bool canBreak = false;
				for(int j=i+1;j<strs.size();j++)
				{
					if(strs[i].find(strs[j])==0 || strs[j].find(strs[i])==0)
					{
						cout<<"not ";
						canBreak=true;
						break;
					}
				}
				if(canBreak) break;
			}
			cout<<"immediately decodable"<<endl;
			strs.clear();
		}
	}

	int program_end;
	cin>>program_end;
	return 0;
}