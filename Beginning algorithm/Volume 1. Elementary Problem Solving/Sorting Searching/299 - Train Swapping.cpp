#include <iostream>
#include <string>
using namespace std;

int main()
{
	int groups;
	cin>>groups;

	short train[51];
	for(int g=0;g<groups;g++)
	{
		int count;
		cin>>count;
		for(int c=0;c<count;c++)
			cin>>train[c];

		int wraps=0;
		short current=1;
		for(int c=0;c<count;c++)
		{
			if(train[c] == current && current==c+1)
			{
				current++;
				continue;
			}
			if(train[c] == current && current!=c+1)
			{
				for(int i=c;i>=current;i--)
				{
					wraps++;
					short temp = train[i];
					train[i] = train[i-1];
					train[i-1] = temp;
				}
				current++;
				c=current-2;
				continue;
			}
		}
		cout<<"Optimal train swapping takes "<<wraps<<" swaps."<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}