///*
//** ��Ŀ:����ͬ������
//** ����:����--����
//** ����:������
//** poj:none
//** �汾:1.0
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
** ��Ŀ:����ͬ������
** ����:����--����
** ����:������
** poj:none
** �汾:1.1 �Ż����ٶ�����ж�
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