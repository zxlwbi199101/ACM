#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

string toLowerCase(string str);
void swap(char &c1,char &c2);
int main()
{
	map<string,vector<string> > collection;
	for(string s;cin>>s && s!="#";)
	{
		string low=toLowerCase(s);
		for(int i=0;i<low.size()-1;i++)
		{
			char min=i;
			for(int j=i+1;j<low.size();j++)
			{
				if(low[min]>low[j]) min=j;
			}
			swap(low[i],low[min]);
		}
		(collection[low]).push_back(s);
	}

	set<string> result;
	for(map<string,vector<string> >::iterator itr=collection.begin();itr!=collection.end();itr++)
	{
		if((itr->second).size()!=1) continue;
		result.insert((itr->second)[0]);
	}

	for(set<string>::iterator itr=result.begin();itr!=result.end();itr++)
	{
		cout<<*itr<<endl;
	}

	system("pause");
	return 0;
}

string toLowerCase(string str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
             str[i] += ('a' - 'A');
	return str;
}
void swap(char &c1,char &c2)
{
	char temp=c1;
	c1=c2;
	c2=temp;
}