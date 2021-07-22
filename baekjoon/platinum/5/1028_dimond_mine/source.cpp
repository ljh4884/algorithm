#include <stdio.h>
#include <iostream>

using namespace std;
int r,c;
int mine[750][750];


int dec(int y, int x, int size)
{
	if(y == r)
		return 0;
	if(size == 0)
	{
		if(mine[y][x] == 1)
			return 1;
		else
			return 0;
	}
	if((x-size >= 0) && (x+size < c))
	{
		if((mine[y][x+size] == 1) && (mine[y][x-size] == 1))
			return dec(y+1, x, size-1);
		else
			return 0;
	}
	return 0;
}


int inc(int y, int x, int size)
{
	int ret = 0;
	if(y == r)
		return -2000;
	if((x-size >= 0) && (x+size < c))
	{
		if((mine[y][x+size] == 1) && (mine[y][x-size] == 1))
		{
			ret = inc(y+1, x, size+1);
		}
	}
	if(size > 1)
	{
		if(dec(y, x, size-2) == 1)
			return max(ret,size);
		else
			return -2000;
	}
	else
	{
		return ret;
	}
	
}


int main()
{
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
	{
		char temp[751];
		scanf("%s",temp);
		for(int j=0;j<c;j++)
		{
			mine[i][j] = temp[j]-48;
		}
	}
		int ans = 0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(mine[i][j] == 1)
				{
					ans = max(ans,1);
					ans = max(ans,inc(i,j,0));
				}
			}
		}
		printf("%d\n",ans);

}
