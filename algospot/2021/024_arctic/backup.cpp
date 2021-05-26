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


data map[100];
double dis[100][100];
int n;

bool compare(const data& d1, const data& d2)
{
	return d1.value < d2.value;
}


double cal(int pos1,int pos2)
{
	return sqrt((map[pos1].x - map[pos2].x) * (map[pos1].x - map[pos2].x) + (map[pos1].y - map[pos2].y) * (map[pos1].y - map[pos2].y));
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
			map[i].index = i;
			map[i].value = 2000;
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
			map[i].value = dis[0][i];
		map[0].value = 0;
		for(int i=1;i<n;i++)
		{
			sort(map+i,map+n,compare);


			

			for(int j=i+1;j<n;j++)
			{
				map[j].value = min(map[j].value,dis[map[i].index][map[j].index]);
				map[j].value = max(map[j].value,map[i].value);
			}
		}
		double temp;
		for(int i=1;i<n;i++)
			temp = max(temp,map[i].value);
		printf("%.2lf\n",temp);
		






	}
}
