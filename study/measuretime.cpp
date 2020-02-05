#include <stdio.h>

int n;
int array[50000];
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
			for(int j=0;j<i;j++)
			{
				if(array[j]>array[i])
					sum++;
			}
		}
		printf("%d\n",sum);
	}
}
