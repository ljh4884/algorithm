#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int a,b;
		unsigned long long n;
		scanf("%d %d %llu",&a,&b,&n);


		unsigned long long sum;
		unsigned long long temp=1;
		for(int i=0;i<a;i++)
		{
			temp=(temp*n)%1000000007;
		}
		sum = temp;
		for(int i=a;i<b;i++)
		{
			temp = (temp*n)%1000000007;
			sum = (sum+temp)%1000000007;
		}
		printf("%llu\n",sum);
	}
}
