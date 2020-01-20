#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 항상 자신의 점수를 최대로 하는것을 선택하지만
 * 다음 재귀는 상대의 turn 이므로 음수 부호를 붙혀줌
 * */
int n;
int array[50];
int save[50][50];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int funca(int start,int end)
{
	if(save[start][end-1]!=-1)
		return save[start][end-1];
	if(start==end)
	{
		save[start][end-1]=0;
		return 0;
	}
	else if(start+1==end)
	{
		save[start][end-1]=array[start];
		return array[start];
	
	}
	else
	{
		save[start][end-1]= max(-funca(start+2,end),max(-funca(start,end-2),max(array[start]-funca(start+1,end),array[end-1]-funca(start,end-1))));
	return save[start][end-1];
	}
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
			scanf("%d",&array[i]);
			for(int j=0;j<n;j++)
			{
				save[i][j]=-1;
			}
		}
		
		printf("%d\n",funca(0,n));
	}
}
