#include <stdio.h>
#include <stdlib.h>

void check(int *a,int n,int k,int p,int current,int *cnt)
{
	if(p==n)
	{
		if(current==k)
		{
			*cnt=*cnt+1;
		}
		return;
	}

	a[p]=0;
	check(a,n,k,p+1,current,cnt);
	a[p]=1;
	if(a[p-1]==1)
	{
		current++;
	}
	check(a,n,k,p+1,current,cnt);

}

int main()
{
	int t,n,k,cnt;
	int *a;
	int *ptr;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		cnt = 0;
		ptr = &cnt;
		scanf("%d %d",&n,&k);
		a=(int*)malloc(sizeof(int)*n);
		a[0]=0;
		check(a,n,k,1,0,ptr);
		a[0]=1;
		check(a,n,k,1,0,ptr);
		printf("%d\n",cnt);

	}
	
}
