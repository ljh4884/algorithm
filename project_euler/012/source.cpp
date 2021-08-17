#include <stdio.h>
#include <map>

using namespace std;

int cache[100000];


int func(int k)
{
	if(cache[k] != -1)
		return cache[k];

	int num = k;
	map<int, int> prime;
	prime.clear();
	while(1)
	{
		if(num == 1)
			break;
		for(int i=2;i<=k;i++)
		{
			if(num%i == 0)
			{
				if(prime.find(i) == prime.end())
				{
					prime[i] = 1;
				}
				else
				{
					prime[i] = prime[i] + 1;
				}
				num /= i;
				break;
			}
		}
	}

	map<int, int>::iterator iter;
	int temp = 1;
	for(iter=prime.begin();iter!=prime.end();iter++)
	{
		temp *= (iter->second + 1);
	}
	cache[k] = temp;

	return temp;
}

int main()
{

	for(int i=0;i<100000;i++)
		cache[i] = -1;
	cache[1] = 1;
	cache[2] = 2;
	
	int sum = 0;
	for(int n=1;n<50000;n++)
	{
		int k = 0;
		int count = 0;
		sum += n;
		if(n%2 == 0)
		{
			k = n/2;
			count = func(k) * func(2*k + 1);
			//k*(2k+1)
		}
		else
		{
			k = (n-1)/2;
			count = func(k+1) * func(2*k + 1);
			//(k+1)(2k+1)
		}

		if(count >= 500)
		{
			printf("%d\n",sum);
			break;
		}
	}

}
