#include <stdio.h>
#include <iostream>
using namespace std;

int D[100000];
int par[100000];
int n;
int main()
{
	int c;
	scanf("%d",&c);
	int cnt=1;
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&D[i]);
			par[i] = -1;
		}

		for(int i=0;i<n;i++)
		{
			if(par[i] == -1)
			{
				int pos = i;
				while(1)
				{

					pos += D[pos];
					if(pos > n-1)
						break;
					if(par[pos] == -1)
					{
						par[pos] = i;
					}
					else
					{
						par[i] = par[pos];
					}
				}
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			if(par[i] == -1)
			{
				ans++;
			}
		}
		printf("Case #%d\n",cnt++);
		printf("%d\n",ans);
	}
}
