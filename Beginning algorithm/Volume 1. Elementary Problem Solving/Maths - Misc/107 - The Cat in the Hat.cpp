#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void display(int N,int x,int initHeight,int workers)
{
	int sum_notworking=1,
		sum_height=initHeight;
	int current_notworking=1,
		current_height=initHeight;
	for(int i=1;i<x;i++)
	{
		current_notworking*=N;
		current_height/=(N+1);

		sum_notworking+=current_notworking;
		sum_height+=(current_height*current_notworking);
	}
	cout<<sum_notworking<<' '<<sum_height+workers<<endl;
}
int main()
{
	int height,worker;

	while(1)
	{
		cin>>height>>worker;
		if(height==0) break;
		
		if(height==1 && worker==1) 
		{
			cout<<"0 1"<<endl;
			continue;
		}

		int child=1,level=1;
		for(;;level++)
		{
			child=(int)(pow(worker,1.0/level)+0.5);
			if(pow((child+1.0),(double)level)==height)
			{
				break;
			}
		}

		display(child,level,height,worker);

	}

	system("pause");
	return 0;
}
