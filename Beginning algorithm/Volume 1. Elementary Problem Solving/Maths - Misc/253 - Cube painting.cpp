#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cases[6][9]={{1,6,2,4,5,3  ,2,4,5},{6,1,2,3,5,4  ,2,3,5},{3,4,2,1,5,6  ,2,1,5},{4,3,2,6,5,1  ,2,6,5},{2,5,3,6,4,1  ,3,6,4},{5,2,3,1,4,6  ,3,1,4}};

	string cubes;
	while(cin>>cubes)
	{
		string cube1=cubes.substr(0,6);
		string cube2=cubes.substr(6,6);

		string cube2new="";
		for(int i=0;i<6;i++)
		{
			cube2new+=cube2[cases[0][i]-1];
		}

		bool hasTrue=false;
		for(int i=0;i<6;i++)
		{
			for(int j =0;j<4;j++)
			{
				string result1;
				result1+=cube1[cases[i][0]-1];
				result1+=cube1[cases[i][1]-1];
				result1+=cube1[cases[i][j+2]-1];
				result1+=cube1[cases[i][j+3]-1];
				result1+=cube1[cases[i][j+4]-1];
				result1+=cube1[cases[i][j+5]-1];

				if(result1==cube2new)
				{
					cout<<"TRUE"<<endl;
					hasTrue=true;
					break;
				}
			}
			if(hasTrue) break;
		}
		if(!hasTrue)
		{
			cout<<"FALSE"<<endl;
		}
	}

	system("pause");
	return 0;
}