/*
ÉßĞÎ¾ØÕó n*n
7 8 1
6 9 2
5 4 3
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int nums[20][20],max,current=1,row_count;
	
	scanf("%d",&max);
	memset(nums,0,sizeof(nums));
	row_count=max--;

	for(int i=max;i>0;i--)
	{
		int currentx=i,currenty=max-i;

		for(int j=1;j<row_count;j++) nums[currentx][currenty++]=current++;
		for(int j=1;j<row_count;j++) nums[currentx--][currenty]=current++;
		for(int j=1;j<row_count;j++) nums[currentx][currenty--]=current++;
		for(int j=1;j<row_count;j++) nums[currentx++][currenty]=current++;

		if(row_count==1) nums[currentx][currenty]=current++;

		row_count-=2;
		if(row_count<=0) break;
	}

	for(int i=0;i<=max;i++)
	{
		for(int j=0;j<=max;j++)
			printf("%3d ",nums[j][i]);
		printf("\n");
	}
	scanf("%d",&max);
	return 0;
}