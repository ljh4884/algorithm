#include <stdio.h>

int n;

int pre[200];
int ans[200];
int result[200];
int mom;
int son;

void ucl()
{
	int a= mom;
	int b= son;
	
	while(1)
	{
		
		if(a==b)
		{
			mom=mom/a;
			son=son/a;
			return;
		}
		else if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
}

void func()
{
	for(int i=0;i<n;i++)
	{
		if(mom>son)
		{
			son=1;
			mom=1;
			i=-1;
			continue;
		}
		if(son*ans[i]<mom*pre[i])
		{
			mom=ans[i];
			son=pre[i];
			ucl();
			i=-1;
			continue;
		}
		if((ans[i]*son)%mom!=0)
		{
			son = (ans[i]*son)/mom + 1;
			mom = ans[i];
			ucl();
			i=-1;
			continue;
		}
	}
}



int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ans[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pre[i]);
		}
		mom=ans[0];
		son=pre[0];
		ucl();
		func();
		for(int i=0;i<n;i++)
		{
			int temp = (ans[i]*son)/mom;
			printf("%d ",temp-pre[i]);
		}
		printf("\n");
	
	}
}
