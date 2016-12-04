#include <iostream>
#include <string>
using namespace std;

int main()
{
	int groups;
	cin>>groups;

	cin.get(); 
	for(int g=0;g<groups;g++)
	{
		string first,second;
		getline(cin,first);
		getline(cin,second);

		string s2,s3,s4,s5;
		bool b2=false,b3=false,b4=false,b5=false;
		for(int i=0;i<first.size();i++)
		{
			if(first[i]!='<' && first[i]!='>') cout<<first[i];
			else
			{
				if(first[i]=='<')
				{
					if(b2) b4=true;
					else b2=true;
				}
				else
				{
					if(b3) b5=true;
					else b3=true;
				}
				continue;
			}
			if(b5) {s5+=first[i];continue;}
			if(b4) {s4+=first[i];continue;}
			if(b3) {s3+=first[i];continue;}
			if(b2) {s2+=first[i];continue;}
		}
		cout<<endl;

		cout<<second.substr(0,second.find('.'))<<s4<<s3<<s2<<s5<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}

