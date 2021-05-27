#include <stdio.h>


int n,k;
int r[1000];
int c[1000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d %d",&r[i],&c[i]);
	}
}
