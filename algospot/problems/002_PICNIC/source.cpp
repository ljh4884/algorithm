/*********************************
 * 난이도: 하
 * page: 155p
 * 유형: 완전탐색, bit mask
 *********************************/


#include <stdio.h>

int n,m;

int arr[10][10];

int func(int bit,int count,int last)
{
	if(count == n)
		return 1;
	int ret = 0;
	for(int i=last+1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int bit_i = 1<<i;
			int bit_j = 1<<j;

			if(bit&bit_i)
				continue;
			if(bit&bit_j)
				continue;
			if(arr[i][j] == 0)
				continue;

			ret += func(bit|bit_i|bit_j,count+2,i);
		}
	}
	return ret;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);


		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arr[i][j] = 0;

		for(int i=0;i<m;i++)
		{
			int f1,f2;
			scanf("%d %d",&f1,&f2);
			arr[f1][f2] = 1;
			arr[f2][f1] = 1;
		}

		printf("%d\n",func(0,0,-1));



	}
}
