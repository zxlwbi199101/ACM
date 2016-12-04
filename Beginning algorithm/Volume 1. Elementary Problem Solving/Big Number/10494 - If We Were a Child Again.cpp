#include <iostream>
#include <string>
#include <cstring>
#include <sstream> 
#include<cstdlib>
using namespace std;

void eraseZero(string & str);
int main()
{
	string a,op;
	long b;
	while( cin>>a>>op>>b)
	{
		eraseZero(a);
		if(a=="0") 
		{
			cout<<"0"<<endl;
			continue;
		}

		string result="";
		long remainder=0;
		bool hasBegin=false;
		for(int i=0;i<a.size();i++)
		{
			long temp=a[i]-'0' + 10*remainder;
			char divide= temp/b ;
			remainder=temp%b;
			if(!hasBegin && divide==0) continue;

			hasBegin=true;
			result+=divide+'0';
		}
		if(result=="") result="0";
		if(op=="/") cout<<result<<endl;
		else cout<<remainder<<endl;
	}
	
	int program_end;
	cin>>program_end;
	return 0;
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