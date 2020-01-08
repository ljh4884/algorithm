#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

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
	return m;
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
	if(pos == n) return 0;
	double& ret = save[pos][pre];
	if(ret != 1.0) return ret;
	ret = -1e200;
	int &choose = check[pos][pre];
	for(int i=0;i<m;++i)
	{
		double cand = T[pre][i]+M[i][R[pos]]+func(pos+1,i);
		if(ret < cand)
		{
			ret = cand;
			choose = i;
		}
	}
	return ret;
}

string find(int pos,int pre)
{
	int choose = check[pos][pre];
	string ret = Q[choose];
	if(pos < n-1)
		ret = ret + " " + find(pos+1,choose);
	return ret;
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
		cout << find(0,0) +"\n";
	}
		
}
