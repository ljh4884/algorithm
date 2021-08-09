#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char str[1001];
	scanf("%s",str);

	long long temp;
	long long ans = 0;
	for(int i=0;i<1000-12;i++)
	{
		temp = 1;
		for(int j=0;j<13;j++)
		{
			temp *= (str[i+j] - '0');
		}
		ans = max(ans,temp);
	}
	printf("%lld\n",ans);
}
