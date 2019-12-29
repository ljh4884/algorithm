#include <stdio.h>
#include <stdlib.h>


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

int func(int l,int r,int *array)
{
	if(l==r)
		return array[l];
	else
	{
		int mid = (l+r)/2;
		int a = func(l,mid,array);
		int b = func(1+mid,r,array);
		int ret = max(a,b);
		int lo=mid;
		int hi=mid+1;
		int temp  = min(array[lo],array[hi]);
		int temp2;
		ret = max(temp*2,ret);
		while(1)
		{
			if(hi==r&&lo==l)
				break;
			while(hi<r)
			{
				if(array[hi+1]>=temp)
				{
					hi++;
				}
				else
				{
					
					break;
				}
			}
			while(lo>l)
			{
				if(array[lo-1]>=temp)
				{
					lo--;
				}
				else
				{
					break;
				}
			}
			
			ret = max(temp*(hi-lo+1),ret);
			if(hi+1<=r&&lo-1>=l)
				temp = max(array[lo-1],array[hi+1]);
			else if(hi+1<=r)
				temp = array[hi+1];
			else
				temp = array[lo-1];
			
		}

		return ret;
	}
}

int main()
{
	int c,n;
	int *array;
	int data;
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d",&n);
		array = (int*)malloc(sizeof(int)*n);
		for(int cnt2=0;cnt2<n;cnt2++)
		{
			scanf("%d",&array[cnt2]);
		}
		data = func(0,n-1,array);
		printf("%d\n",data);
		
	}
}
