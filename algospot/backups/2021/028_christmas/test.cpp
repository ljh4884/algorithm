#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	printf("60\n");

	for(int i=0;i<60;i++)
	{
		int n = rand()%100000 + 1;
		printf("%d %d\n",n,rand()%n + 1);
		for(int i=0;i<n;i++)
		{
			printf("%d\n",rand()%100000 + 1);
		}
	}
}
