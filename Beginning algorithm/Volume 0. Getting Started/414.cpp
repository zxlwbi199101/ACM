
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	while(1)
	{
		int count;
		cin >> count;
		cin.ignore();
		if(count == 0) break;

		vector<int> nums;
		int max = 0;
		for(int j = 0; j < count; j++)
		{
			string str;
			getline(cin, str);

			int n = 0;
			for(int i=0; i<str.size();i++)
			{
				if(str[i]=='X' || str[i]=='x') n++;
			}
			if(max<n) max=n;
			nums.push_back(n);
		}
		int sum=0;
		for(int i=0;i<nums.size();i++)
		{
			sum+=max-nums[i];
		}
		cout<<sum<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}