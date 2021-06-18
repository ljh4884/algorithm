#include <stdio.h>
#include <math.h>
#include <algorithm>


using namespace std;


typedef struct data
{
	int index;
	double x;
	double y;
	double value;
}data;

int check[100];


data map[100];
double dis[100][100];
double list[5000];
int n;
int cnt;



double cal(int pos1,int pos2)
{
	return sqrt((map[pos1].x - map[pos2].x) * (map[pos1].x - map[pos2].x) + (map[pos1].y - map[pos2].y) * (map[pos1].y - map[pos2].y));
}

int func(double r)
{

	for(int i=1;i<n;i++)
		check[i] = 0;
	check[0] = 1;

	while(1)
	{
		int cond = 1;
		for(int i=0;i<n;i++)
		{
			if(check[i] == 1)
			{
				cond = 0;
				check[i] = 2;
				for(int j=0;j<n;j++)
				{
					if(check[j] == 0)
						if(dis[i][j] <= r)
							check[j] = 1;
				}
			}
		}
		if(cond)
			break;
		
	}


	for(int i=0;i<n;i++)
		if(check[i] == 0)
			return 0;
	return 1;
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
			scanf("%lf %lf",&map[i].x,&map[i].y);
		}
		cnt = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dis[i][j] = cal(i,j);
				dis[j][i] = dis[i][j];
				list[cnt] = dis[i][j];
				cnt++;
			}
		}

		sort(list,list+cnt);
		
		for(int i=0;i<cnt;i++)
		{
			if(func(list[i]))
			{
				printf("%.2lf\n",list[i]);
				break;
			}
		}
	}
}
