/*
** 题目:Distance on Chessboard
** 输入:组数--位置
** 作者:赵鑫磊
** poj:1657
** 版本:1.0
*/
#include <stdio.h>
#include <math.h>
#define CANNOT "Inf"

int main()
{
	int TestCount;
	int i;

	scanf("%d",&TestCount);
	for(i=0;i<TestCount;i++)
	{
		char begin[3],end[3];
		scanf("%s %s",begin,end);

		int x=abs(begin[0]-end[0]),
			y=abs(begin[1]-end[1]);

		if(x==0 && y==0) 
		{
			printf("0 0 0 0\n");
			continue;
		}

		printf("%d %d %d ",x>=y?x:y,
			(x==y || x==0 || y==0)?1:2,
			(x==0||y==0)?1:2);

		if((x-y)%2==0)
		{
			if(x == y) printf("%d\n",1);
			else printf("%d\n",2);
			continue;
		}
		printf("%s\n",CANNOT);
	}
	return 0;
}

