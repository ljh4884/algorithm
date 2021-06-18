#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int m,q,n;

char Q[500][11];
double B[500];
double T[500][500];
double M[500][500];
char sen[20][11];
int R[100];

double save[102][502];
int check[102][502];
int change(char *name)
{
	for(int i=0;i<m;i++)
	{
		if(strcmp(name,Q[i])==0)
			return i;
	}
	return m-1;
}

double max(double a,double b)
{
	if(a>b)
		return a;
	else
		return b;
}

double func(int pos,int pre)
{
	double cal;
	double result=-1e200;
	if(save[pos][pre]!=1.0)
		return save[pos][pre];
	if(pos==n)
	{
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		if(pos==0)
			cal = B[i];
		else
			cal = T[pre][i];
		cal = cal + M[i][R[pos]];
		double temp = cal+func(pos+1,i);
		if(result<temp)
		{
			result = temp;
			check[pos][pre]=i;
		}
	
	}
	save[pos][pre] = result;
	return result;
}

void find(int pos,int pre)
{
	if(pos==n)
		return;
	int temp  = check[pos][pre];
	printf("%s ",Q[temp]);
	find(pos+1,temp);
}


int main()
{
	scanf("%d %d",&m,&q);
	double temp;
	for(int i=0;i<m;i++)
	{
		scanf("%s",Q[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%lf",&temp);
		B[i] = log(temp);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%lf",&temp);
			T[i][j] = log(temp);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%lf",&temp);
			M[i][j]=log(temp);
		}
	}
	for(int cnt=0;cnt<q;cnt++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",sen[i]);
			R[i]=change(sen[i]);
		}
		for(int i=0;i<n+2;i++)
		{
			for(int j=0;j<m+2;j++)
			{
				save[i][j]=1.0;
			}
		}
		//printf("%lf\n",func(0,0));
		func(0,0);
		find(0,0);
		printf("\n");
	}
		
}
