#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define p struct pair

struct pair
{
	int val;
	p *next;
};

void insert(p *pa,int val)
{
	while(pa->next!=NULL)
		pa=pa->next;

	pa->next = (p*)malloc(sizeof(p));
	pa->next->val = val;
}
int check(int *state,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(state[i]==0)
		{
			break;
		}
	}
	return i;
}
int find(int *state,p **pa,int n)
{
	int i=0;
	int sum=0;
	p* start;
	if((i=check(state,n))==n)
		return 1;
	else
	{
		
		start = pa[i];
		if(start==NULL)
			return 0;
		while(start!=NULL)
		{
			
			if(state[start->val]==0)
			{
				int *temp = (int*)malloc(sizeof(int)*n);
				for(int i=0;i<n;i++)
				{
					temp[i]=state[i];
				}
				temp[i]=1;
				temp[start->val]=1;
				//printf("%d %d\n",i,start->val);
				sum = sum+find(temp,pa,n);
			}
			start = start->next;
		}


	}
	
	
	return sum;
	
}

int main()
{
	int c,n,m;

	int a,b;
	int *state;

	p** pa;

	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d %d",&n,&m);
		state = (int*)malloc(sizeof(int)*n);
		pa = (p**)malloc(sizeof(p*)*n);
		for(int i=0;i<n;i++)
		{
			pa[i] = (p*)malloc(sizeof(p));
			state[i] = 0;
		}
		for(int cnt2=0;cnt2<m;cnt2++)
		{
			scanf("%d %d",&a,&b);
			insert(pa[a],b);
			insert(pa[b],a);
		}
		printf("%d\n",find(state,pa,n));



	}
}
