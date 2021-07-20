#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int c=1;

	printf("%d\n",c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int n=200000;
		printf("%d\n",n);
		for(int i=0;i<n;i++)
		{
			printf("%d ",rand()%1000000000);
		}
		printf("\n");
		for(int i=0;i<n;i++)
		{
			printf("%d ",rand()%1000000000);
		}
		printf("\n");
	}
}
