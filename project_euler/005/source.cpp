#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int count[20];

	for(int i=0;i<20;i++)
		count[i] = 0;

	for(int i=2;i<20;i++)
	{
		int temp_count[20];
		for(int j=0;j<20;j++)
			temp_count[j] = 0;
		int num = i;
		int j = 2;
		while(1)
		{
			if(num == 1)
				break;
			if(num%j == 0)
			{
				num/=j;
				temp_count[j]++;
				continue;
			}
			j++;
		}
		for(int j=0;j<20;j++)
			count[j] = max(count[j], temp_count[j]);
	}
	int ans = 1;
	for(int i=2;i<20;i++)
	{
		for(int j=0;j<count[i];j++)
			ans *= i;
	}

	printf("%d\n",ans);
}
