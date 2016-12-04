#include <iostream>
#include <string>

using namespace std;
int main()
{
	int count=0;
	cin>>count;
	for(int i=0;i<count;i++)
	{
		string result;
		cin>>result;

		int length=result.size();
		if(length<=2)
		{
			cout<<"+"<<endl;
		}
		else
		{
			if(result.substr(length-2,2)=="35")
			{
				cout<<"-"<<endl;
				continue;
			}
			if(result[0]=='9' && result[length-1]=='4')
			{
				cout<<"*"<<endl;
				continue;
			}
			if(result.substr(0,3)=="190")
			{
				cout<<"?"<<endl;
			}
		}
	}

	system("pause");
	return 0;

}