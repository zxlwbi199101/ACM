#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int marbles,queries;
	int group=1;
	for(;1;group++)
	{
		cin>>marbles>>queries;
		if(marbles==0 && queries==0) break;

		cout<<"CASE# "<<group<<":"<<endl;

		int marble[10000];
		for(int i=0;i<marbles;i++)
			cin>>marble[i];
		for(int i=0;i<queries;i++)
		{
			int toFind,idx=1;
			bool found=false;
			cin>>toFind;
			for(int j=0;j<marbles;j++)
			{
				if(marble[j]==toFind) found=true;
				if(marble[j]<toFind) idx++;
			}
			if(!found) cout<<toFind<<" not found"<<endl;
			else cout<<toFind<<" found at "<<idx<<endl;
		}
	}

	int program_end;
	cin>>program_end;
	return 0;
}

