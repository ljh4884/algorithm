#include <stdio.h>


double save[1001][1001];
int n,m;



double func(int rest_height,int rest_day)
{

	if(rest_height <= 0)
		return 1;
	if(rest_day == 0)
		return 0;
	if(save[rest_height][rest_day] != -1)
		return save[rest_height][rest_day];
	save[rest_height][rest_day] = 0.75 * func(rest_height-2,rest_day-1) + 0.25 * func(rest_height - 1, rest_day - 1);
	return save[rest_height][rest_day];
}

int main()
{

	int c;
	scanf("%d",&c);

	while(c--)
	{

		scanf("%d %d",&n,&m);
		for(int i=0;i<n+1;i++)
			for(int j=0;j<m+1;j++)
				save[i][j]=-1;
		printf("%.8lf\n",func(n,m));

	}
}
