
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string source;
	while(cin>>source)
	{
		for(int i=0;i<source.size();i++)
		{
			cout<<(char)(source[i]-7);
		}
		cout<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}