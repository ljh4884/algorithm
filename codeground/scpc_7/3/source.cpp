#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int n,m;
long long seg[100000];
long long check[20000];
int main()
{
	int c;
	int cnt=1;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		
		long long ans = 0;
		for(int i=0;i<n;i++)
		{
			int temp = 0;
			scanf("%d",&temp);
			for(int j=0;j<temp;j++)
				scanf("%lld",&seg[j]);
			sort(seg,seg+temp);

			for(int j=0;j<4;j++)
			{
				ans += seg[j];
			}

			if(temp%2 == 1)
			{
				ans += seg[0];
			}
			check[i] = (seg[2] + seg[3]);

		}

		sort(check,check+n);
		ans -= check[n-1];
		ans -= check[n-2];
		printf("Case #%d\n",cnt++);
		printf("%lld\n",ans);
	}

}
