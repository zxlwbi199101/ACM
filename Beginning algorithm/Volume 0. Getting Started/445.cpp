#include <iostream>
#include <string>
using namespace std;


void display(int num,char target);
void draw(string s);

int main()
{
	string source;
	while(getline(cin,source))
	{
		if(source=="") cout<<endl;
		else
		{
			draw(source);
		}
	}

	int program_end;
	cin>>program_end;
	return 0;
}

void display(int num,char target)
{
	for(int i=0;i<num;i++)
	{
		cout<<target;
	}
}
void draw(string s)
{
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='!')
		{
			cout<<endl;
			continue;
		}
		if(s[i]>=48 && s[i]<=57)
		{
			count+=s[i]-'0';
			continue;
		}

		display(count,s[i]=='b'?' ':s[i]);
		count=0;
	}
	cout<<endl;
}