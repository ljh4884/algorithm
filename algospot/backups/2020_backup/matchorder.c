#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int russia[100];
int korea[100];
int n;
int cnt;
int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1 < num2)
		return -1;
	else if(num1==num2)
		return 0;
	else
		return 1;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		cnt=0;
		int j=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&russia[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&korea[i]);
		}
		qsort(&russia,n,sizeof(int),compare);
		qsort(&korea,n,sizeof(int),compare);
		for(int i=0;i<n;i++)
		{
			
			for(;j<n;j++)
			{
			
				if(russia[i]<=korea[j])
				{
					cnt++;
					j++;
					break;
				}
			}
		}
		printf("%d\n",cnt);
	}
}
