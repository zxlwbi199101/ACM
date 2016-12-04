#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	for(string line;getline(cin,line);cout<<'0'<<endl)
	{
		cout<<line<<endl;

		istringstream iss(line);
		vector<int> stack;
		int length=-1;
		for(int num;iss>>num;length++) stack.push_back(num);

		int current=length+1;
		while(1)
		{
			if(current!=0) current--;
			else break;

			int max_idx=0;
			for(int i=0;i<=current;i++)
				if(stack[i]>stack[max_idx]) max_idx=i;

			if(max_idx == current) continue;
			
			if(max_idx!=0)
			{
				cout<<length-max_idx+1<<' ';
				for(int i=0;i<(max_idx+1)/2;i++)
				{
					int temp=stack[i];
					stack[i]=stack[max_idx-i];
					stack[max_idx-i]=temp;
				}
			}
			for(int i=0;i<(current+1)/2;i++)
			{
				int temp=stack[i];
				stack[i]=stack[current-i];
				stack[current-i]=temp;
			}
			cout<<length-current+1<<' ';
		}
		

	}

	system("pause");
	return 0;
}