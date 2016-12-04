///*
//** 题目:鸡兔同笼问题
//** 输入:组数--脚数
//** 作者:赵鑫磊
//** poj:none
//** 版本:1.0
//*/
//#include <stdio.h>
//int main()
//{
//	int TestCount,Feets;
//	int i;
//
//	scanf("%d",&TestCount);
//	for(i=0;i<TestCount;i++)
//	{
//		scanf("%d",&Feets);
//		if( Feets%2 != 0)
//			printf("0 0\n");
//		else
//		{
//			if(Feets%4!=0 && Feets/4>0)
//				printf("%d %d\n",Feets/4+1,Feets/2);
//			else
//				printf("%d %d\n",Feets/4,Feets/2);
//		}
//	}
//	return 0;
//}



/*
** 题目:鸡兔同笼问题
** 输入:组数--脚数
** 作者:赵鑫磊
** poj:none
** 版本:1.1 优化最少动物的判断
*/
#include <stdio.h>
int main()
{
	int TestCount,Feets;
	int i;

	scanf("%d",&TestCount);
	for(i=0;i<TestCount;i++)
	{
		scanf("%d",&Feets);
		if( Feets%2 != 0)
			printf("0 0\n");
		else
			printf("%d %d\n",Feets/4+Feets%4/2,Feets/2);
	}
	return 0;
}