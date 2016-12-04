#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void toLowerCase(string &str);
string toUpperCase(string str);
int main()
{
	set<string> ignores;
	for(string ignore;cin>>ignore;)
	{
		if(ignore=="::") break;
		ignores.insert(ignore);
	}

	multimap <string ,string> m;
	for(string title;getline(cin,title) ;)
	{
		toLowerCase(title);
		istringstream iss(title);

		vector<string> words;
		for(string word;iss>>word;) words.push_back(word);

		for(int i=0;i<words.size();i++)
		{
			if(ignores.find(words[i])!=ignores.end()) continue;
			string s;
			string upper;
			for(int j=0;j<words.size();j++)
			{
				if(j!=0) s+=' ';
				if(i==j)
				{
					upper=toUpperCase(words[j]);
					s+=upper;
				}
				else s+=words[j];
			}
			m.insert(pair<string,string>(upper,s));
		}
	}

	for(multimap<string,string>::iterator itr=m.begin();itr!=m.end();itr++)
	{
		cout<<itr->second<<endl;
	}


	system("pause");
	return 0;
}
	
void toLowerCase(string &str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
             str[i] += ('a' - 'A');
}

string toUpperCase(string str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
        if (str[i] >= 'a' && str[i] <= 'z')
             str[i] -= ('a' - 'A');
	return str;
}