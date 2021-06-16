#include <stdio.h>


long long next_val(long long prev_val)
{
	long long div = 4294967296;
	return (prev_val * 214013 + 2531011) % div;
}

int l2i(long long prev_val)
{
	return (int)(prev_val % 10000 + 1);
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int k,n;
		int f = 0;
		int r = 0;
		long long f_value = 1983;
		long long r_value = 1983;
		int sum = 1984;
		int count = 0;
		

		scanf("%d %d",&k,&n);

		while(1)
		{
			if(sum == k)
			{
				count+=1;
				sum -= l2i(f_value);
				r+=1;
				f+=1;
				f_value = next_val(f_value);
				r_value = next_val(r_value);
				sum += l2i(r_value);
				if(r == n)
				{
					if(sum == k)
						count+=1;
					break;
				}
			}

			else if(sum < k)
			{
				r+=1;
				r_value = next_val(r_value);
				sum += l2i(r_value);
				if(r == n)
				{
					if(sum == k)
						count+=1;
					break;
				}
			}

			else
			{
				f+=1;
				sum -= l2i(f_value);
				f_value = next_val(f_value);
			}
		}

		printf("%d\n",count);

		
	}
}
