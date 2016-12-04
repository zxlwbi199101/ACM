#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	int count,group=1;
	for(;cin>>count;group++)
	{
		if(count==0) break;

		vector<int> nums;
		int sum=0,result=0;;
		for(int i=0;i<count;i++)
		{
			int temp;
			cin>>temp;

			sum+=temp;
			nums.push_back(temp);
		}

		int standard=sum/count;
		for(int i=0;i<count;i++)
		{
			if(nums[i]>standard)
				result+=(nums[i]-standard);
		}
		cout<<"Set #"<<group<<endl;
		cout<<"The minimum number of moves is "<<result<<"."<<endl<<endl;
	}

	system("pause");
	return 0;
}