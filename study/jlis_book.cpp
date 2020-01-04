#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long *a;
long long *b;
int **save;
int n;
int m;
const long long NEGINF = -5000000000;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int jlis(int ia,int ib)
{
	int& ret = save[ia+1][ib+1];
	if(ret != -1)
		return ret;
	ret = 2;
	long long aa = (ia == -1 ? NEGINF : a[ia]);
	long long bb = (ib == -1 ? NEGINF : b[ib]);
	long long maxE = max(aa,bb);

	for(int na = ia+1;na<n;++na)
		if(maxE < a[na])
			ret = max(ret,jlis(na,ib) + 1);
	for(int nb = ib+1;nb<m;++nb)
		if(maxE < b[nb])
			ret = max(ret,jlis(ia,nb) + 1);
	return ret;
}

int main()
{
	int c;
	
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		int result = 0;
		long long comp=0;
		scanf("%d %d",&n,&m);
		a = (long long*)malloc(sizeof(long long)*n);
		b = (long long*)malloc(sizeof(long long)*m);
		save = (int**)malloc(sizeof(int*)*n+1);
		for(int i=0;i<n+1;i++)
		{
			save[i]=(int*)malloc(sizeof(int)*m+1);
			for(int j=0;j<m+1;j++)
				save[i][j]=-1;
			if(i!=n)
				scanf("%lld",&a[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				result = max(result,jlis(i,j));
			}
		}
		*/
		result = jlis(-1,-1);
		printf("%d\n",result-2);


	}
}
