#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int ARRAY_LENGTH=40;
	char outputs[]={' ','.','x','W'};
	int density[10];

	int cases;
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		for(int p=0;p<10;p++)
		{
			cin>>density[p];
		}
		short dishes[ARRAY_LENGTH]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		short dishes_new[ARRAY_LENGTH];
		for(int k=0;k<50;k++)
		{
			if(k==0)
			{
				for(int j=0;j<ARRAY_LENGTH;j++)
				{
					cout<<outputs[dishes[j]];
				}
				cout<<endl;
				continue;
			}

			for(int j=0;j<ARRAY_LENGTH;j++)
			{
				dishes_new[j]=density[dishes[j]+(j==0?0: dishes[j-1])+(j==ARRAY_LENGTH-1?0:dishes[j+1])];
			}
			for(int j=0;j<ARRAY_LENGTH;j++)
			{
				dishes[j]=dishes_new[j];
				cout<<outputs[dishes[j]];
			}
			cout<<endl;
		}
		if(cases-1!=i) cout<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}