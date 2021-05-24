#include <stdio.h>

const int num = 10000000;
int save[101][101];
int n;
int func(int rest_block,int prev_put_block)
{
	
	if(rest_block == 0)
		return 1;

	if(save[rest_block][prev_put_block] != -1)
		return save[rest_block][prev_put_block];

	int ret = 0;
	for(int i=1;i<rest_block + 1;i++)
		ret += ((prev_put_block + i - 1) * func(rest_block - i,i))%num;
	ret = ret % num;
	save[rest_block][prev_put_block] = ret;
	return ret;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int ret = 0;
		scanf("%d",&n);
		for(int i = 0;i<n+1;i++)
			for(int j=0;j<n+1;j++)
				save[i][j] = -1;
		for(int i=1;i<n+1;i++)
		{
			ret = (ret + func(n-i,i))%num;
		}
		ret = ret % num;
		printf("%d\n",ret);
	}
}
