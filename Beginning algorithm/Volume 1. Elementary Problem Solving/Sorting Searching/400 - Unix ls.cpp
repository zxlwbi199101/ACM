#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	for(int length;cin>>length ;)
	{
		for(int i=0;i<60;i++) cout<<'-';
		cout<<endl;

		map<string,int> collection;
		int max_length=0;
		for(int i=0;i<length;i++)
		{
			string a;
			cin>>a;

			if(a.size()>max_length) max_length=a.size();
			if(collection.find(a)==collection.end()) collection[a]=1;
			else collection[a]++;
		}

		vector<string> result;
		int columns=60/(max_length+2);
		for(map<string,int>::iterator itr=collection.begin();itr!=collection.end();itr++)
		{
			for(int i=0;i<itr->second;i++)
				result.push_back(itr->first);
		}
		int rows=length/columns+(length%columns==0?0:1);

		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				if(length>rows*j+i)
					cout<<setiosflags(ios::left)<<setw(max_length+2)<<result[rows*j+i];
			}
			cout<<endl;
		}
	}


	system("pause");
	return 0;
}
