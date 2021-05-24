#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int array[100][100];
int save[100][100];
int save2[100][100];


int func(int x,int y)
{
	if(y == n)
		return 0;
	
	if(save[y][x] != -1)
		return save[y][x];

	save[y][x] = array[y][x] + max(func(x,y+1),func(x+1,y+1));
	return save[y][x];

}

int func_2(int x,int y)
{
	if(save2[y][x]!= -1)
		return save2[y][x];
	if(y == n-1)
		return 1;
	
	if(save[y+1][x] == save[y+1][x+1])
		save2[y][x] = func_2(x,y+1) + func_2(x+1,y+1);
	else if(save[y+1][x] < save[y+1][x+1])
		save2[y][x] = func_2(x+1,y+1);
	else
		save2[y][x] = func_2(x,y+1);
	return save2[y][x];
}




int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i+1;j++)
			{	
				save[i][j] = -1;
				save2[i][j] = -1;
				scanf("%d",&array[i][j]);
			}
		}
		func(0,0);
		printf("%d\n",func_2(0,0));
		
	}


	for(int i=0;i<10000;i++)
	{
		a+=1;
		b+=1;
	}

	for(int i=0;i<10000;i++)
		a+=1;

	for(int i=0;i<10000;i++)
		b+=1;
}
