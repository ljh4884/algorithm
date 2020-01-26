#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define one struct table

struct table
{
	double begin;
	double end;
};

one cal[100];

int n;
int compare(const void *a,const void *b)
{
	one *A = (one *)a;
	one *B= (one*)b;

	if(A->begin < B->begin)
		return -1;
	else if(A->begin == B->begin)
		return 0;
	else
		return 1;
}

int main()
{
	int c;
	double x,y,r;
	double loc,range;

	double my_pi = 2.0*acos(0);
	scanf("%d",&c);
	while(c--)
	{
		double cur=0;
		double nextcur=0;
		int start=0;
		int sum=0;
		int check=0;
		double first;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf %lf",&y,&x,&r);
			loc = fmod(2*my_pi+atan2(y,x),2*my_pi);
			range = 2.0*asin(r/16.0);
			cal[i].begin = loc-range;
			cal[i].end = loc+range;
			//printf("%lf %lf\n",loc,range);
		}
		qsort(cal,n,sizeof(one),compare);
		nextcur = cal[0].end;
		first = cal[0].begin;
		int i=1;
		while(1)
		{
			if(i==n)
			{
				if(nextcur-first>=2*my_pi)
				{
					sum++;
					printf("%d\n",sum);
				}
				else
				{
					printf("IMPOSSIBLE\n");
				}
				break;
			}
			if(cal[i].begin<cur)
			{
				if(cal[i].end>nextcur)
				{
					
					nextcur = cal[i].end;
					start = i;
				}
				i++;
			}
			else
			{
				if(check==0)
				{
					check=1;
					first = cal[start].begin;
				}
				if(cur==nextcur)
				{
					printf("IMPOSSIBLE\n");
				}
				cur = nextcur;
				sum++;

			}
		}
		
	}
}
