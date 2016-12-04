#include <iostream>
#include <string>
#include <cstring>
#include <sstream> 
#include<cstdlib>
using namespace std;

bool isbiggerThan(string a,string b);
string ConvertToString(int num);
int ConvertToInt(string s);
void eraseZero(string & str);
int main()
{
	string max="2147483647";
	int max_n=2147483647;
	string a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<a<<' '<<b<<' '<<c<<endl;
		eraseZero(a);
		eraseZero(c);

		if(isbiggerThan(a,max) || isbiggerThan(c,max))
		{
			if(isbiggerThan(a,max)) cout<<"first number too big"<<endl;
			if(isbiggerThan(c,max)) cout<<"second number too big"<<endl;
			if(a!="0" && c!="0") cout<<"result too big"<<endl;
		}
		else
		{
			int aa=ConvertToInt(a),cc=ConvertToInt(c);
			if(b=="+")
			{
				int lasta=max_n-aa;
				if(cc>lasta) 
					cout<<"result too big"<<endl;
			}
			else
			{
				if(a=="0" || c=="0") continue;
				int lasta=max_n/aa;
				if(cc>lasta)
					cout<<"result too big"<<endl;
			}
		}
	}

	int program_end;
	cin>>program_end;
	return 0;
}

bool isbiggerThan(string a,string b)
{
	if(a.size()>b.size()) return true;
	if(a.size()==b.size()) return a>b;
	return false;
}
string ConvertToString(int num)
{
	string s;
	stringstream ss;
    ss<<num;
    ss>>s;
	return s;
}
int ConvertToInt(string s)
{
	int num;
	stringstream ss(s);
	ss>>num;
	return num;
}
void eraseZero(string & str)
{
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0') 			
		{
			if(str.size()==1) return;
			str.erase(i,1);
			i--;
		}
		else break;
	}
}