#include <stdio.h>
#include <vector>

using namespace std;


int main()
{
	vector<int> prime;
	prime.push_back(2);
	int num = 3;
	while(1)
	{
		if(prime.size() == 10001)
			break;
		int check = 1;
		
		for(int i=0;i<prime.size();i++)
		{
			if((num % prime[i] )== 0)
			{
				check = 0;
				break;
			}
		}

		if(check)
			prime.push_back(num);
		num++;
	}
	printf("%d\n",prime[prime.size()-1]);

}
