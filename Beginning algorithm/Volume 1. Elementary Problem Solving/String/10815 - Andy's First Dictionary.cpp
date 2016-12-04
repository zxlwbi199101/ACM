#include <iostream>
#include <string>
#include <set>
using namespace std;

void toLowerCase(string& str);
int main()
{
	string str;
	set<string> dictionary;
	while(getline(cin,str))
	{
		toLowerCase(str);
		bool Inword=false;
			 string word;
		for(int i=0;i<str.size();i++)
		{
			if((str[i]>='a' && str[i]<='z'))
			{
				if(Inword) word+=str[i];
				else
				{
					Inword=true;
					word=str[i];
				}
			}
			else
			{
				if(Inword)
				{
					Inword=false;
					dictionary.insert(word);
					word="";
				}
			}
		}//for every string end
		if(word.size()>0) dictionary.insert(word);
	}//input end

	set<string>::iterator iter;
	int idx=0;
	for (iter = dictionary.begin(); iter != dictionary.end(); iter++)
		cout<<*iter<<endl;

	cin.clear();
	int program_end;
	cin>>program_end;
	return 0;
}

void toLowerCase(string& str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
             str[i] += ('a' - 'A');
}