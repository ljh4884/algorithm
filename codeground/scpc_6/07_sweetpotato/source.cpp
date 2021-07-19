#include <stdio.h>

long long arr[300001];
int n,m;
int main()
{
	int c;
	int cnt = 1;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		if(n > 50000)
		{
			printf("0\n"
		}
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(int i=1;i<=n;i++)
			arr[i] = arr[i] + arr[i-1];

		long long money = m;
		long long ans = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				long long temp = arr[j] - arr[i];
				if(temp <= money)
					if(temp > ans)
						ans = temp;
			}
		}
		printf("Case #%d\n",cnt++);
		printf("%lld\n",ans);
	}
}
