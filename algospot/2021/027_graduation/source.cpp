#include <stdio.h>
#include <iostream>

using namespace std;

int n,k,m,l;

int pre_class[12][12];
int semester[10][12];
int sem_size[10];
int save[10][1<<12];


int func(int pos, int bit, int count)
{
	if(count >= k)
		return 0;
	if(pos == m)
		return 11;
	if(save[pos][bit] != -1)
		return save[pos][bit];

	int ret = func(pos+1,bit,count);
	for(int cur_bit=1;cur_bit<(1<<n);cur_bit++)
	{
		int break_cond = 0;
		int cur_count = 0;
		for(int i=0;i<n;i++)
		{
			if(cur_bit & (1<<i))
			{
				if(bit & (1<<i))
					continue;
				
				if(semester[pos][i] == 0)
				{
					break_cond = 1;
					break;
				}
				
				for(int j=0;j<n;j++)
				{
					if(pre_class[i][j] == 1)
					{
						if((bit & (1<<j)) == 0)
						{
							break_cond = 1;
							break;
						}
					}
				}
				if(break_cond)
					break;

				cur_count+=1;

				if(cur_count > l)
				{
					break_cond = 1;
					break;
				}
			}
		}
		if(break_cond)
			continue;


		ret = min(ret,1+func(pos+1,bit | cur_bit, count+cur_count));
	}

	save[pos][bit] = ret;

	return ret;


	
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d %d %d",&n,&k,&m,&l);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				pre_class[i][j] = 0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				semester[i][j] = 0;

		for(int i=0;i<n;i++)
		{
			int size;
			scanf("%d",&size);
			for(int j=0;j<size;j++)
			{
				int cur_class;
				scanf("%d",&cur_class);
				pre_class[i][cur_class] = 1;
			}
		}

		for(int i=0;i<m;i++)
		{
			int size;
			scanf("%d",&size);
			sem_size[i] = size;
			for(int j=0;j<size;j++)
			{
				int cur_class;
				scanf("%d",&cur_class);
				semester[i][cur_class] = 1;
			}
		}

		for(int i=0;i<m;i++)
			for(int j=0;j<(1<<n);j++)
				save[i][j] = -1;
		int ret = func(0,0,0);
		if(ret != 11)
			printf("%d\n",ret);
		else
			printf("IMPOSSIBLE\n");

	}
}
