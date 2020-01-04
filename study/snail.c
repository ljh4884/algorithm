#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
double save[1001][1001];
double func(int a,int b)
{
	if(a<=0)
		return 1;
	if(b==0)
	{
		if(a>0)
			return 0;
		else
			return 1;
	}

	if(save[a][b]!=-1)
		return save[a][b];
	
	
	save[a][b] = 0.75*func(a-2,b-1)+0.25*func(a-1,b-1);
	return save[a][b];
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d %d",&n,&m);
		
		for(int i=0;i<1001;i++)
		{
			for(int j=0;j<1001;j++)
			{
				save[i][j]=-1;
			}
		}
		if(n<=m)
			printf("1.000000000\n");
		else
		{
			printf("%.20lf\n",func(n,m));

		}


		
	}
}
