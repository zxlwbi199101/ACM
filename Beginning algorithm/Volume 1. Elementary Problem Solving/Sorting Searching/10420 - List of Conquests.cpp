#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int count;
	cin>>count;
	cin.get();

	map<string,int> result;
	for(int i=0;i<count;i++)
	{
		string line;
		getline(cin,line);
		
		string country;
		for(int j=0;j<line.size();j++)
		{
			if(line[j]==' ') break;
			country+=line[j];
		}
		if(result.find(country)==result.end())
			result[country]=1;
		else result[country]++;
	}
	map <string, int>::iterator m1_Iter; 
	for ( m1_Iter = result.begin(); m1_Iter != result.end(); m1_Iter++ )
      cout<<m1_Iter->first<<" "<<m1_Iter->second<<endl;
  
	int program_end;
	cin>>program_end;
	return 0;
}

