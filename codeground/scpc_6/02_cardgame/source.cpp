#include <stdio.h>

int n,k;
int X[3001];
int Y[3001];
int cache[3001][3001];
int ret[2];


int func(int x, int y)
{

	if(cache[x][y] != -1)
		return cache[x][y];

	int x_sum = 0;
	for(int i=1;i<=x;i++)
	{
		x_sum += X[x-i];
		if(x_sum > k)
			break;
		if(func(x-i,y) == 0)
		{
			cache[x][y] = 1;
			return 1;
		}
	}

	int y_sum = 0;
	for(int i=1;i<=y;i++)
	{
		y_sum += Y[y-i];
		if(y_sum > k)
			break;
		if(func(x,y-i) == 0)
		{
			cache[x][y] = 1;
			return 1;
		}
	}

	x_sum = 0;
	y_sum = 0;

	for(int i=1;i<=x;i++)
	{
		x_sum += X[x-i];
		y_sum = 0;
		if(x_sum > k)
			break;
		for(int j=1;j<=y;j++)
		{
			y_sum += Y[y-i];
			if((x_sum+y_sum) > k)
				break;
			if(func(x-i,y-j) == 0)
			{
				cache[x][y] = 1;
				return 1;
			}
		}
	}

	cache[x][y] = 0;
	return 0;
}

int main()
{
	int c;
	int cnt=1;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&X[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&Y[i]);

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				cache[i][j] = -1;

		cache[0][0] = 1;
		cache[1][0] = 0;
		cache[0][1] = 0;
		func(n,n);
		ret[0] = 0;
		ret[1] = 0;

		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(cache[i][j] == -1)
				{
					func(i,j);
				}
				
				ret[cache[i][j]]+=1;
			}
		}
		printf("Case #%d\n",cnt++);
		printf("%d %d\n",ret[1],ret[0]);

		
	}
}
