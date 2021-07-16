//__builtin_popcount()
/*
 *  위 gcc, g++ 전용 내장함수를 사용 하여 1인 bit의 수를 카운트 하여 알고리즘을 설계하였음
 *  책을 참고하지 않았지만 풀고보니 굉장히 비슷함
 *
 */
#include <stdio.h>
#include <iostream>
using namespace std;
int n,k,m,l;
int pre[12];
int col[10];
int func(int cur,int time);
int save[1<<13][10];
int find(int cur,int bit,int time,int pos)
{
	if(pos > n)
	{
		return 9999;
	}
	if(__builtin_popcount(bit)<=l)
		return 1+func(cur|bit,time+1);

	else
	{
		if(bit&(1<<pos))
		{
			return min(find(cur,bit,time,pos+1),find(cur,(bit^(1<<pos)),time,pos+1));
		}
		else
		{
			return find(cur,bit,time,pos+1);
		}
	}

}
int func(int cur,int time)
{
	if(__builtin_popcount(cur)>=k)
	{
		return 0;
	}
	if(time>=m)
	{
		return 999;
	}
	if(save[cur][time]!=-1)
	{
		return save[cur][time];
	}
	int bit=0;
	for(int i=0;i<n;i++)
	{
		if((col[time]&(1<<i))&&!(cur&(1<<i)))
		{
			if((cur&pre[i])==pre[i])
			{
				bit = bit|(1<<i);
			}
		}
	}
	int ret;
	if(__builtin_popcount(bit)<=l)
	{

		
		save[cur][time] = min(1+func(cur|bit,time+1),func(cur,time+1));
		return save[cur][time];
	}
	else
	{
		
		ret = find(cur,bit,time,0);
	}

	ret = min(ret,func(cur,time+1));
	save[cur][time]=ret;
	return ret;
		
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		
		scanf("%d %d %d %d",&n,&k,&m,&l);
		for(int i=0;i<(1<<(n+1));i++)
		{
			for(int j=0;j<m;j++)
			{
				
				save[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++)
		{
			int cnt;
			scanf("%d",&cnt);
			pre[i]=0;

			for(int j=0;j<cnt;j++)
			{
				int temp;
				scanf("%d",&temp);
				pre[i] |=(1<<temp);
			}
		}
		for(int i=0;i<m;i++)
		{
			int cnt;
			scanf("%d",&cnt);
			col[i]=0;
			for(int j=0;j<cnt;j++)
			{
				int temp;
				scanf("%d",&temp);
				col[i] |= (1<<temp);
			}
		}
		int ret = func(0,0);
		if(ret<11)
			printf("%d\n",ret);
		else
			printf("IMPOSSIBLE\n");
	}
}
