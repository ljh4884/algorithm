#include <stdio.h>

int main()
{
	unsigned long long array[68];
	int t,n;
	array[0]=1;
	array[1]=1;
	array[2]=2;
	array[3]=4;
	for(int i=4;i<68;i++)
	{
		array[i]=array[i-1]+array[i-2]+array[i-3]+array[i-4];
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("%lld\n",array[n]);
	}
}
