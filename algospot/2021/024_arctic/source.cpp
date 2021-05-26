#include <stdio.h>
#include <math.h>
int n;

double x[100];
double y[100];
double dis[100][100];
double g_dis[100];

double min(double a,double b)
{
	if(a<b)
		return a;
	else
		return b;
}

double cal(int pos1,int pos2)
{
	return sqrt((x[pos1] - x[pos2]) * (x[pos1] - x[pos2]) + (y[pos1] - y[pos2]) * (y[pos1] - y[pos2]));
}

double func(int pos,int stack)
{
	int ret = dis[0][pos];
	
	
}



int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&x[i],&y[i]);
			check[i] = 0;
		}

		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dis[i][j] = cal(i,j);
				dis[j][i] = dis[i][j];
			}
		}

		for(int i=1;i<n;i++)
			g_dis[i] = dis[0][i];


	}
}
