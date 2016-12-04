/*
 BCAD CBAD
 DBACEGF ABCDEFG
 
 RESULT:
 CDAB
 ACBFGED
*/
#include <stdio.h>
#define STRING_END "\0";

void post_order(char *pre,char *in,int pre_length);

int main()
{
	char pre_order[3000],in_order[3000];
	while(scanf("%s %s",pre_order,in_order)==2)
	{
		post_order(pre_order,in_order,3000);
		printf("\n");
	}
	
	int program_end;
	scanf("%d",&program_end);
	return 0;
}

void post_order(char *pre,char *in,int pre_length)
{
	int root_idx=-1;
	int in_length=0;
	
	for(int i=0;i<pre_length;i++)
	{
		if(in[i]=='\0') break;
		if(in[i]==pre[0]) root_idx=i;
		in_length++;
	}
	if(root_idx<0) return;
	post_order(&pre[1],in,root_idx);
	post_order(pre+1+root_idx,in+1+root_idx,in_length-root_idx-1);

	printf("%c ",pre[0]);
}

