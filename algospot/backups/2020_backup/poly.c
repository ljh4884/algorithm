#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int save[101][101];

int func(int n,int m)
{
	if(n==1)
		return m;
	if(n==0)
		return 1;
	if(save[n][m]==-1)
	{	save[n][m]=0;
		for(int i=1;i<=n;i++)
		{
			save[n][m] = (save[n][m] + (i+m-1)*func(n-i,i))%10000000;
		}
	}
	
	return save[n][m];
}

int main()
{
	int c;
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		{
			save[i][j]=-1;
		}
	}
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int n;
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			sum = (sum+func(n-i,i))%10000000;
		}
		printf("%d\n",sum);
			
	}
}
