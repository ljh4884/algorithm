#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
int r,c;
int array[50][50];
int way;
int cnt;
// 북동남서
//  0 1 2 3
void rotate(int cnt);
void func()
{
	if(array[r][c]==0)
	{
		array[r][c]=2;
		cnt++;
	}
	rotate(0);

}
void back()
{
	if(way==0)
	{
		if(array[r+1][c]==1)
			return;
		else
			r=r+1;
		rotate(0);
	}
	else if(way==1)
	{
		if(array[r][c-1]==1)
			return;
		else
			c=c-1;
		rotate(0);
	}
	else if(way==2)
	{
		if(array[r-1][c]==1)
			return;
		else
			r=r-1;
		rotate(0);
	}
	else if(way==3)
	{
		if(array[r][c+1]==1)
			return;
		else
			c=c+1;
		rotate(0);
	}
}
void rotate(int cnt)
{
	if(cnt==4)
	{
		back();
	}
	else if(way==0)
	{
		way=3;
		if(c>0)
		{
			if(array[r][c-1]==0)
			{
				c=c-1;
				func();
			}
			else
			{
				rotate(cnt+1);
			}
		}
		else
		{
			rotate(cnt+1);
		}
	}
	else if(way==1)
	{
		way=0;
		if(r>0)
		{
			if(array[r-1][c]==0)
			{
				r=r-1;
				func();
			}
			else
			{
				rotate(cnt+1);
			}
		}
		else
		{
			rotate(cnt+1);
		}
	}
	else if(way==2)
	{
		way=1;
		if(c<m-1)
		{
			if(array[r][c+1]==0)
			{
				c=c+1;
				func();
			}
			else
			{
				rotate(cnt+1);
			}
		}
		else
		{
			rotate(cnt+1);
		}
	}
	else if(way==3)
	{
		way=2;
		if(r<n-1)
		{
			if(array[r+1][c]==0)
			{
				r=r+1;
				func();
			}
			else
			{
				rotate(cnt+1);
			}
		}
		else
		{
			rotate(cnt+1);
		}
	}
}


int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&r,&c,&way);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&array[i][j]);
	func();
	printf("%d\n",cnt);

}
