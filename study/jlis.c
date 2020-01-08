#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;

int a[100];
int b[100];
int save[102][102];
long long max(long long a,long long b)
{
	if(a>b)
		return a;
	else
		return b;

}


int func(int posa,int posb)
{
	int result = 2;
	long long tempa= (posa == -1 ? -4000000000 : a[posa]);
	long long tempb= (posb == -1 ? -4000000000 : b[posb]);
	long long cmp;
	if(save[posa+1][posb+1]==-1)
	{
	cmp = max(tempa,tempb);
	if(tempa==tempb)
		result = 1;

	for(int i=posa+1;i<n;i++)
	{
		if(cmp<a[i])
			result = max(result,1+func(i,posb));
	}
	for(int j=posb+1;j<m;j++)
	{
		if(cmp<b[j])
			result = max(result,1+func(posa,j));
	}
	save[posa+1][posb+1]=result;
	}
	return save[posa+1][posb+1];
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n+2;i++)
		{
			for(int j=0;j<m+2;j++)
			{
				save[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		printf("%d\n",func(-1,-1)-2);
	}
}
