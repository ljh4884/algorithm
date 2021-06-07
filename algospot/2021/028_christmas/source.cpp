#include <stdio.h>
#include <iostream>

using namespace std;

int n,k;
int arr[100001];
int sum_arr[100002];
int save[100002];

int func(int pos)
{
	if(pos == n)
		return 0;

	if(save[pos] != -1)
		return save[pos];

	int ret = func(pos + 1);
	
	for(int i = pos+1;i<n+1;i++)
		if( (sum_arr[i] - sum_arr[pos]) % k == 0)
			ret = max(ret, 1 + func(i));

	save[pos] = ret;
	return ret;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&k);
		sum_arr[0] = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum_arr[i+1] = (arr[i] + sum_arr[i]);
		}
		
		int count = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n+1;j++)
			{
				int temp = sum_arr[j] - sum_arr[i];
				if(temp % k == 0)
					count+=1;
			}
		}

		for(int i=0;i<n+1;i++)
			save[i] = -1;



		printf("%d %d\n",count%20091101,func(0));


	}
}
