#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long *a;
long long *b;
int **save;
int n;
int m;

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

int lis(int posa,int posb,long long comp)
{
	int result=1;
	
	int i = posa;
	int j = posb;
	if(save[i][j]!=-1)
	{
		return save[i][j];
	}
	while(1)
	{
		if(i==n&&j==m)
			break;
		if(i==n)
		{
			if(b[j]>comp)
			{
				result = max(result,1+lis(i,j,b[j]));
			}
			j++;
		}
		else if(j==m)
		{
			if(a[i]>comp)
				result = max(result,1+lis(i,j,a[i]));
			i++;
		}
		else if(a[i]==b[j])
		{
			
			if(a[i]>comp)
			{
				result = max(result,1+lis(i,j,a[i]));
			}
			i++;
			j++;
		}
		else if(a[i]<b[j])
		{
			if(a[i]>comp)
			{
				result = max(result,1+lis(i,j,a[i]));
			}
			i++;
		}
		else
		{
			
			if(b[j]>comp)
			{
				result = max(result,1+lis(i,j,b[j]));
			}
			j++;
		}
	}
	save[posa][posb] = result;
	return result;
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

		
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i]<b[j])
					comp = a[i];
				else
					comp = b[j];
				result = max(result,lis(i,j,comp));
			}
		}
		printf("%d\n",result);


	}
}
