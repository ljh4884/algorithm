#include <stdio.h>
#include <stdlib.h>


int main()
{
	int c,n,l;
	int i;
	double *array;
	double L=0;
	double min;
	double sum;
	
	int start;
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d %d",&n,&l);
		array = (double*)malloc(sizeof(double)*n);
		for(int cnt2=0;cnt2<n;cnt2++)
		{
			scanf("%lf",&array[cnt2]);
		}
		L=0;
		for(i=0;i<l;i++)
		{
			L=L+array[i];
			
		}
		min = L/l;
		sum = L;
		for(;i<n;i++)
		{
			sum += array[i];
			if(sum/(i+1)<min)
				min = sum/(i+1);
		}
		start = l;
		while(1)
		{
			if(start == n)
				break;
			L -= array[start-l];
			L += array[start];
			sum = L;
			if(L/l<min)
				min = L/l;
			for(int j=start+1;j<n;j++)
			{
				sum+=array[j];
				if(sum/(j-start+l)<min)
					min = sum/(j-start+l);
			}
			start++;
		}
		printf("%.9lf\n",min);
		


		
	}

}
