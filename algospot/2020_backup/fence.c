#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c,n;
	int *array;
	int sum;
	int max;
	scanf("%d",&c);
	for(int cnt =0;cnt<c;cnt++)
	{
		max = 0;
		scanf("%d",&n);
		array = (int*)malloc(sizeof(int)*n);
		for(int cnt2=0;cnt2<n;cnt2++)
		{
			scanf("%d", &array[cnt2]);
		}
		for(int i=0;i<n;i++)
		{

			int start=0;
			int end=n-1;
			int j;

			for(j=i;j>=0;j--)
			{
				if(array[j]<array[i])
				{
					start=j+1;
					break;
				}
			}
			for(j=i;j<n;j++)
			{
				if(array[j]<array[i])
				{
					end=j-1;
					break;
				}
			}
			sum = array[i]*(end-start+1);
			if(sum>max)
				max=sum;
		}
		printf("%d\n",max);
	}
}
