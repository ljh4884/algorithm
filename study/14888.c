#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int array[11];
int op[4];
//+-*/

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int func(int pos,int a,int b,int c,int d,int pre)
{
	int result=-1000000000;

	if(pos==n-1)
		return pre;
	if(a>0)
		result = max(result,func(pos+1,a-1,b,c,d,pre+array[pos+1]));
	if(b>0)
		result = max(result,func(pos+1,a,b-1,c,d,pre-array[pos+1]));
	if(c>0)
		result = max(result,func(pos+1,a,b,c-1,d,pre*array[pos+1]));
	if(d>0)
		result = max(result,func(pos+1,a,b,c,d-1,pre/array[pos+1]));
	return result;
}

int func2(int pos,int a,int b,int c,int d,int pre)
{
	int result = 1000000000;
	//printf("pos: %d +: %d -: %d *: %d /: %d result: %d\n",pos,a,b,c,d,pre);
	if(pos==n-1)
		return pre;
	if(a>0)
		result = min(result,func2(pos+1,a-1,b,c,d,pre+array[pos+1]));
	if(b>0)
		result = min(result,func2(pos+1,a,b-1,c,d,pre-array[pos+1]));
	if(c>0)
		result = min(result,func2(pos+1,a,b,c-1,d,pre*array[pos+1]));
	if(d>0)
		result = min(result,func2(pos+1,a,b,c,d-1,pre/array[pos+1]));
	return result;

}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	scanf("%d %d %d %d",&op[0],&op[1],&op[2],&op[3]);
	printf("%d\n%d\n",func(0,op[0],op[1],op[2],op[3],array[0]),func2(0,op[0],op[1],op[2],op[3],array[0]));
}
