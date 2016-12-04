/*
	有N盏灯 第一个人全开 第二个按2的倍数开关 以此类推 k个人
	最后jizhandengkaizhe
	7 3
	1 5 6 7
*/

#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1000;
int main()
{
	int lights,persons;
	int states[1000];
	
	scanf("%d %d",&lights,&persons);
	memset(states,1,sizeof(states));

	for(int i=1;i<persons;i++)
		for(int j=1;j<lights;j++)
			if((j+1)%(i+1)==0)
				states[j]=!states[j];

	for(int i=0;i<lights;i++)
		if(states[i])printf("%d ",i+1);

	scanf("%d",&lights);
	return 0;
}

