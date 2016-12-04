#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned char secret[1001];
	unsigned char guess[1001];
	int length;
	int groups=1;
	while(1)
	{
		cin>>length;
		if(length==0) break;
		cout<<"Game "<<groups++<<":"<<endl;
		
		for(int i=0;i<length;i++)
			cin>>secret[i];
		
		while(1)
		{
			for(int i=0;i<length;i++)
				secret[i] &= 0x7F;

			int strongs=0,weaks=0;
			for(int i=0;i<length;i++)
			{
				cin>>guess[i];
				if(guess[i] == secret[i])
				{
					strongs++;
					guess[i] |= 0x80;
					secret[i] |= 0x80;
				}
			}
			if(guess[0]=='0') break;

			for(int i=0;i<length;i++)
			{
				if((secret[i] >> 7) & 0x01) continue;
				for(int j=0;j<length;j++)
				{
					if((guess[j] >> 7) & 0x01) continue;
					if(secret[i]==guess[j])
					{
						weaks++;
						guess[j] |= 0x80;
						break;
					}
				}
			}
			cout<<"    ("<<strongs<<","<<weaks<<")"<<endl;
		}

	}


	int program_end;
	cin>>program_end;
	return 0;
}
