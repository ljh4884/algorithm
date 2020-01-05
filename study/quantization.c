#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[100];
int save[100][10];
int n,s;

int compare(const void* a,const void *b)
{
	int num1 = *(int *) a;
	int num2 = *(int *) b;

	if(num1 > num2)
		return 1;
	else if(num1 < num2)
		return -1;
	else
		return 0;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int func(int i,int count)
{
	int temp=1000000000;
	if(save[i][count-1]!=-1)
		return save[i][count-1];
	if(count==1)
	{
		int sum=0;
		int temp=0;
		for(int cnt=i;cnt<n;cnt++)
		{
			sum=sum+array[cnt];
		}
		if(2*(sum%(n-i))>(n-i))
			sum = sum/(n-i)+1;
		else
			sum = sum/(n-i);
		for(int cnt=i;cnt<n;cnt++)
		{
			temp += (array[cnt]-sum)*(array[cnt]-sum);
		}
		save[i][count-1]=temp;
		return temp;
	}
	if(i == n-1)
	{
		return 0;
	}

	for(int cnt=i+1;cnt<n;cnt++)
	{
		int sum=0;
		int V=0;
		for(int j=i;j<cnt;j++)
		{
			sum=sum+array[j];
		}
		if(2*(sum%(cnt-i))>(cnt-i))
			sum = sum/(cnt-i)+1;
		else
			sum = sum/(cnt-i);
		for(int j=i;j<cnt;j++)
		{
			V += (array[j]-sum)*(array[j]-sum);
		}

		temp = min(temp,V+func(cnt,count-1));
	}
	save[i][count-1] = temp;
	return temp;
}

int main()
{
	int c;

	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d %d",&n,&s);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
			for(int j=0;j<s;j++)
			{
				save[i][j]=-1;
			}
		}
		qsort(array,n,4,compare);
		printf("%d\n",func(0,s));
	}

}
