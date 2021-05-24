#include <stdio.h>


int n,d,t,p;
int q;
int array[50][50];
double save[101][50];

double func(int rest_day,int pos)
{
	if(rest_day == 0)
	{
		if(pos == q)
			return 1;
		else
			return 0;
	}

	if(save[rest_day][pos] > -0.5)
		return save[rest_day][pos];
	
	double ret = 0;
	double size = 0;

	for(int i=0;i<n;i++)
		size+=array[pos][i];

	for(int i=0;i<n;i++)
	{
		if(array[pos][i] == 1)
			ret += (1.0/size)*func(rest_day-1,i);
	}

	save[rest_day][pos] = ret;
	return ret;

}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{


		scanf("%d %d %d",&n,&d,&p);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&array[i][j]);
		

		scanf("%d",&t);
		for(int i=0;i<t;i++)
		{
			for(int i=0;i<d+1;i++)
				for(int j=0;j<n;j++)
					save[i][j] = -1;
			scanf("%d",&q);
			printf("%.8lf ",func(d,p));
		}
		printf("\n");


	}
}
