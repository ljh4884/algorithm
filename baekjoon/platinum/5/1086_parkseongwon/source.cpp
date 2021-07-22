#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[15][51];
int size[15];
long long cache[1<<15][100];
long long fact[16];
int pos[51];
int pre_mod[15];
int n,k;


long long func(int bit, int mod,int count)
{
	if(count == n)
	{
		if(mod == 0)
			return 1;
		else
			return 0;
	}
	if(cache[bit][mod] != -1)
		return cache[bit][mod];
	long long ret = 0;
	for(int i=0;i<n;i++)
	{
		int cur_bit = 1<<i;
		if((bit & cur_bit) == 0)
		{
			
			ret += func((bit | cur_bit), (mod*pos[size[i]] + pre_mod[i])%k, count+1);
			
		}
	}
	cache[bit][mod] = ret;
	return ret;
}

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	
	scanf("%d",&n);
	char temp[51];
	for(int i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
		size[i] = strlen(arr[i]);
		for(int j=0;j<size[i];j++)
			arr[i][j] = arr[i][j] - '0';
	}
	scanf("%d",&k);
	for(int i=1;i<51;i++)
		pos[i] = (pos[i-1]*10)%k;

	for(int i=0;i<n;i++)
	{
		int mod = 0;
		for(int j=0;j<size[i];j++)
		{
			mod*=10;
			mod+=arr[i][j];
			mod%=k;
		}
		pre_mod[i] = mod;
	}

	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<k;j++)
			cache[i][j] = -1;

	fact[1] = 1;
	for(int i=2;i<=n;i++)
		fact[i] = fact[i-1]*i;


	long long ans = func(0,0,0);

	long long div = gcd(ans, fact[n]);
	printf("%lld/%lld\n",ans/div,fact[n]/div);



}
