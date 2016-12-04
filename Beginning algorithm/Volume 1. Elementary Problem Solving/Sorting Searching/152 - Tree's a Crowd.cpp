#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int x[5010], y[5010], z[5010];
	int result[10]={0,0,0,0,0,0,0,0,0,0};

	int count;
	for(;;count++)
	{
		cin>>x[count]>>y[count]>>z[count];
		if(x[count]==0 && y[count]==0 && z[count]==0) break;
	}
	for(int i=0;i<count;i++)
	{
		int min=11;
		for(int j=0;j<count;j++)
		{
			if(i==j) continue;
			int dx=x[i]-x[j];
			int dy=y[i]-y[j];
			int dz=z[i]-z[j];
			int d=(int)sqrt((double)dx*dx + dy*dy + dz*dz);
			if(min>d) min=d;
			if(min==0) break;
		}
		if(min>=10) continue;
		result[min]++;
	}
	for(int i=0;i<10;i++)
	{
		cout<<setiosflags(ios::right)<<setw(4)<<result[i];
	}
	cout<<endl;    

	int program_end;
	cin>>program_end;
	return 0;
}