#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

int main()
{
	int n,k;
	long double *array;
	long double mean;
	long double min = LDBL_MAX;
	long double sum;

	scanf("%d %d",&n,&k);
	array = (long double*)malloc(sizeof(long double)*n);
	for(int cnt=0;cnt<n;cnt++)
	{
		scanf("%Lf",&array[cnt]);
	}
	
	for(int i=0;i<n-k+1;i++)
	{
		for(int temp=0;temp+k+i<n+1;temp++)
		{
		mean = 0;
		sum = 0;
		for(int j=0;j<k+temp;j++)
		{
			mean += array[i+j];
		}
		mean = mean/(k+temp);
		for(int j=0;j<k+temp;j++)
		{
			sum = sum + array[i+j]*array[i+j];
			sum = sum - 2 * array[i+j] * mean;
			sum = sum + mean * mean;
		}
		sum = sum/(k+temp);
		
		if(sum<min)
			min = sum;
		}
	}

	printf("%.20Lf\n",sqrtl(min));
	
}
