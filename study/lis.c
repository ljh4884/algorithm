#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int run(int *array,int start, int end,int sum,int d)
{
	
	if(start > end - 1)
		return 0;

	if(start == end - 1)
		return 1;

	int i = start + 1;
		
	if(array[i]>d)
	{	
			sum = max(run(array,i,end,sum,array[i])+1,run(array,i+1,end,sum,d));
	}
	else
	{
		if(array[start]==d)
			sum = max(run(array,i,end,0,array[i]),run(array,i+1,end,sum,d));
		else
			sum = max(run(array,start,end,0,array[start]),run(array,i,end,sum,d));
	}
	printf("%d %d\n",start,sum);	

	return sum;
}

int main()
{
	int c,n;

	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int array[500];
		int sum=0;
		int m=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
		}
		m = run(array,0,n,0,array[0]);
		
		
		printf("%d\n",m);

	}
}
