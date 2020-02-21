#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct book
{
	double order;
	int size;
	int value;
	int many;
}book;

int compare(const void *a,const void *b)
{
	book *ptra = (book*)a;
	book *ptrb = (book*)b;

	if(ptra->order < ptrb->order)
		return 1;
	else if(ptra->order > ptrb->order)
		return -1;
	else
	{
		if(ptra->size > ptrb->size)
			return 1;
		else if(ptra->size < ptrb->size)
			return -1;
		else
			return 0;
	}

}

int n,v;
int save[100][10001];
book bag[100];
int minsize;
int func(int rest,int pos)
{
	if(rest<0)
		return -9999999;
	if(save[pos][rest]!=-1)
		return save[pos][rest];
	if(pos==n-1)
	{
		
		save[pos][rest]=min((rest/bag[pos].size)*bag[pos].value,bag[pos].many*bag[pos].value);
		return save[pos][rest];
	}
	
	if(rest<minsize)
	{
		save[pos][rest]=0;
			return 0;
	}
	int ret = 0;
	for(int i=0;i<bag[pos].many+1;i++)
	{
		int t = bag[pos].many-i;
		ret = max(ret,t*bag[pos].value+func(rest-t*bag[pos].size,pos+1));
	}
	ret = save[pos][rest];
	return ret;

	
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&v);
		minsize=9999999;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<v+1;j++)
			{
				save[i][j]=-1;
			}
			scanf("%d %d %d",&bag[i].size,&bag[i].value,&bag[i].many);
			bag[i].order = (double)bag[i].value/(double)bag[i].size;
			if(minsize>bag[i].size)
				minsize=bag[i].size;
		}
		qsort(bag,n,sizeof(book),compare);
		printf("%d\n",func(v,0));
	}
}
