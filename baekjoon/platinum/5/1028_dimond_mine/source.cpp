#include <stdio.h>
#include <iostream>

using namespace std;
int r,c;
int mine[751][751];





int dec(int y, int x, int size)
{
	if(y==r)
		return -2000;
	if(size == 0)
	{
		if(mine[y][x] == 1)
			return 0;
		else
			return -2000;
	}
	
	if((x-size >= 0) && (x+size < c))
	{
		if((mine[y][x+size] == 1) && (mine[y][x-size] == 1))
			return dec(y+1,x,size-1);
		else
			return -2000;
	}
	else
		return -2000;
}

int inc(int y, int x, int size)
{
	if(y == r)
		return -2000;
	int ret = 0;
	if((x-size >= 0) && (x+size < c))
		if((mine[y][x+size] == 1) && (mine[y][x-size] == 1))
			ret = 1+inc(y+1,x,size+1);
	if(size > 1)
		return max(ret,dec(y+1,x,size-2));
	else
		return max(ret,0);
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
	int check = 0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(mine[i][j] == 1)
			{
				check = 1;
				ans = max(ans, 1 + inc(i+1,j,1));
			}
		}
	}
	printf("%d\n",max(ans, check));
}
