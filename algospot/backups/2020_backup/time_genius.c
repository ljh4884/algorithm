#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,k,m;
int minute[50];
double T[50][50];
int Q[50];
double save[5][50];
double result[50];
double func(int num,int time,int last)
{
	double ret=0;
	if(time<0)
	{
		if(last==num)
			return 1;
		else
			return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(T[last][i]!=0)
		{
			ret = ret + T[last][i]*func(num,time-minute[i],i);
		}
	}
	return ret;
	

}
void find()
{
	memset(save,0,sizeof(save));
	save[0][0]=1.0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			save[i%5][j]=0;
			for(int l=0;l<n;l++)
			{
				save[i%5][j]+=save[(i-minute[l]+5)%5][l]*T[l][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		result[i]=0;
		for(int j=k-minute[i]+1;j<=k;j++)
		{
			result[i]+= save[j%5][i];
		}
	}
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d %d",&n,&k,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&minute[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%lf",&T[i][j]);
			}
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&Q[i]);
		}
		find();
		for(int i=0;i<m;i++)
		{
			printf("%.20lf ",result[Q[i]]);
		}
		printf("\n");

	}
}
