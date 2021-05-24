#include <stdio.h>
#include <stdlib.h>
int main()
{
	int c,n,l;
	double *array;
	double min=10000000;
	double sum;
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		min = 10000000;

		scanf("%d %d",&n,&l);

		array=(double*)malloc(sizeof(double)*n);

		for(int cnt2=0;cnt2<n;cnt2++)
		{
			scanf("%lf",&array[cnt2]);
		}

		for(int i=0;i<=n-l;i++)
		{
			for(int j=i+l;j<=n;j++)
			{
				sum=0;
				for(int k=i;k<j;k++)
				{
					sum = sum + array[k];
					if(k==j-1)
					{
						sum=sum/(k-i+1);
						if(sum<min)
						{
							min = sum;
						}
					}
				}
		
				
			}
		}
		printf("%.8lf\n",min);


	}
	

}
