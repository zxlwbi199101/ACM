 

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int calculate_sequence(string & target);
int main()
{
    int groups,char_count;
    cin>>char_count>>groups;

    map<int,vector<string>> contents;
    for(int i=0;i<groups;i++)
    {
		string str;
		cin>>str;
		int sequece=calculate_sequence(str);
		if(contents.find(sequece)!=contents.end())
		{
			contents[sequece].push_back(str);
		}
		else
		{
			vector<string> str_vector;
			str_vector.push_back(str);
			contents[sequece]=str_vector;
		}
    }
	map<int,vector<string>>::iterator it;
    for(it=contents.begin();it!=contents.end();++it)
	{
		vector<string> v=it->second;
		vector<string>::iterator itr;
		for(itr=v.begin();itr!=v.end();itr++)
		{
			cout<<*itr<<endl;
		}
	}

    int program_end;
    cin>>program_end;
    return 0;
}

int calculate_sequence(string & target)
{
    int sequence=0;
    for(int i=0;i<target.length();i++)
    {
		for(int j=0;j<i;j++)
		{
			if(target[i]<target[j]) sequence++;
		}
    }

    return sequence;

}

