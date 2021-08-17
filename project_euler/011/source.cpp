#include <stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int map[20][20];
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			scanf("%d",&map[i][j]);

	int ans = 0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<17;j++)
		{
			int temp = 1;
			for(int k=0;k<4;k++)
			{
				temp *= map[i][j+k];
			}
			ans = max(ans,temp);
		}
	}

	for(int i=0;i<17;i++)
	{
		for(int j=0;j<20;j++)
		{
			int temp = 1;
			for(int k=0;k<4;k++)
			{
				temp *= map[i+k][j];
			}
			ans = max(ans,temp);
		}
	}

	for(int i=0;i<17;i++)
	{
		for(int j=0;j<17;j++)
		{
			int temp = 1;
			for(int k=0;k<4;k++)
			{
				temp *= map[i+k][j+k];
			}
			ans = max(ans, temp);
		}
	}

	for(int i=0;i<17;i++)
	{
		for(int j=3;j<20;j++)
		{
			int temp = 1;
			for(int k=0;k<4;k++)
			{
				temp *= map[i+k][j-k];
			}
			ans = max(ans,temp);
		}
	}
	printf("%d\n",ans);
}
