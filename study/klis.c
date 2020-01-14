#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define vec struct vector

struct vector
{
	int value;
	int pos;
};

int n;
int k;
int array[501];
int save[502];
int save2[502];
int size;
int sum;
int result[500];
const int MAX = 2000000000+1;
int compare(const void *a, const void *b)
{
	vec *i = (vec*)a;
	vec *j = (vec*)b;

	if(i->value < j->value)
		return -1;
	else if(i->value == j->value)
		return 0;
	else
		return 1;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
long long min(long long a,long long b)
{
	if(a<b)
		return a;
	else
		return b;
}
int func(int pos)
{
	int result=1;
	if(save[pos+1]!=-1) 
	{
		return save[pos+1];
	}
	for(int i=pos+1;i<n;i++)
		if(array[i]>array[pos]||pos==-1)
			result = max(result,1+func(i));
	save[pos+1] = result;
	return result;
}

int count(int pos)
{
	int result =0;
	if(func(pos)==1)
		return 1;
	if(save2[pos+1]!=-1&&pos !=-1) return save2[pos+1];
	for(int i=pos+1;i<n;i++)
	{
		if((pos==-1||array[pos]<array[i])&&func(pos)==func(i)+1)
			result=min((long long)result+count(i),MAX);	
	}
	save2[pos+1]=result;
	return result;
	
}

void make(int pos,int skip)
{
	vec my[501];
	int temp=0;
	if(sum==size)
		return;
	
	for(int i=pos+1;i<n;i++)
	{
		if((pos==-1||array[pos]<array[i])&&func(pos)==func(i)+1)
		{
			my[temp].pos = i;
			my[temp].value = array[i];
			temp++;
		}
	}
	qsort(my,temp,sizeof(vec),compare);
	for(int i=0;i<temp;i++)
	{
		if(skip<count(my[i].pos))
		{
			result[sum]=my[i].value;
			sum++;
			make(my[i].pos,skip);
			break;
		}
		skip-=count(my[i].pos);
			
	}
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		sum=0;
		scanf("%d %d",&n,&k);
		save[n+1]=-1;
		save[n]=-1;
		save2[n+1]=-1;
		save2[n]=-1;
		for(int i=0;i<n;i++)
		{
			save[i]=-1;
			save2[i]=-1;
			scanf("%d",&array[i]);
		}
		size = func(-1)-1;
		printf("%d\n",size);
		make(-1,k-1);
		for(int i=0;i<size;i++)
		{
			printf("%d ",result[i]);
		}
		printf("\n");
		
	}
}
