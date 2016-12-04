
#include <iostream>
using namespace std;
long absl(long x) 
{
	return x>0?x:-x;
    //return (x ^ (x >> 31)) - (x >> 31);
}
int main()
{
	long a,b;
	while(cin>>a>>b)
	{
		cout<<absl(b-a)<<endl;
	}

	int program_end;
	cin>>program_end;
	return 0;
}