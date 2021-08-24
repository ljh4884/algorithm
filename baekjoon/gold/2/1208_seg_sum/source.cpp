#include <stdio.h>


const int value = 500000;

int arr[40];
int cache[40][value*2];
int n;
int s;

int func(int pos, int sum)
{
	if(pos == n)
	{
		if(sum == s)
			return 1;
		else
			return 0;
	}
	if((sum < value) && (sum > -value))
		if(cache[pos][sum+value] != -1)
			return cache[pos][sum+value];
	
	int ret = func(pos+1, sum+arr[pos]) + func(pos+1, sum);
	if((sum<value) && (sum>-value))
		cache[pos][sum+value] = ret;
	return ret;
	
}

int main()
{
	scanf("%d %d",&n,&s);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		for(int j=0;j<value*2;j++)
			cache[i][j] = -1;
	}
	int ret = func(0,0);
	if(s == 0)
		ret -= 1;
	printf("%d\n",ret);
}
