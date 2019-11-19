#include <stdio.h>

int main()
{
	int array[41];
	int n,m,vip;
	int start;
	int result=1;
	array[0]=1;
	array[1]=1;
	for(int i=2;i<41;i++)
	{
		array[i]=array[i-1]+array[i-2];
	}

	scanf("%d %d",&n,&m);
	vip=0;
	start=1;
	for(int i=0;i<m;i++)
	{
		start=vip+1;
		scanf("%d",&vip);
		result=result*array[vip-start];
	}
	if(m!=0)
	{
		result=result*array[n-vip];
	}
	else
	{
		result=result*array[n];
	}
	printf("%d\n",result);
}
