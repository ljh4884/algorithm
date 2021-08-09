#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	long long num = 600851475143;
	long long div = 775146;
	long long ans = 0;

	while(1)
	{
		int check = 0;
		for(long long start = 2;start<num;start++)
		{
			if((num % start) == 0)
			{
				check = 1;
				ans = max(ans,start);
				num /= start;
				break;
			}
		}
		if(check == 0)
			break;
	}
	
	printf("%lld\n",max(ans,num));
}
