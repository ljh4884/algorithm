#include <stdio.h>

int n;

int save[101];

const int num = 1000000007;

int func(int rest)
{
	if(save[rest] != -1)
		return save[rest];

	save[rest] = (func(rest-1) + func(rest-2))%num;
	return save[rest];
}


int main()
{
	int c;
	scanf("%d",&c);

	for(int i=3;i<101;i++)
		save[i] = -1;
	save[1] =1;
	save[2] =2;

	while(c--)
	{
		scanf("%d",&n);
		printf("%d\n",func(n));
	}
}
