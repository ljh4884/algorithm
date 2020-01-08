#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	srand(time(NULL));
	int c = 2;
	int n = 100;
	int w = 1000;
	printf("%d\n",c);
	for(int cnt=0;cnt<c;cnt++)
	{
		printf("1\n%d %d\n",n,w);
		for(int i=0;i<n;i++)
		{
			printf("%d %d %d\n",i,rand()%1000+1,rand()%1000+1);
		}
	}
}
