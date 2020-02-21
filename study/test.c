#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL));

	printf("50\n");
	for(int i=0;i<50;i++)
	{
		int check[100001];
		for(int j=0;j<100001;j++)
		{
			check[j]=0;
		}
		printf("10\n");
		for(int j=0;j<10;j++)
		{
			int p = rand()%100001;
			while(check[p]==1)
			{
				p=rand()%100001;
			}
			check[p]=1;
			printf("%d ",p);
			while(check[p]==1)
			{
				p=rand()%100001;
			}
			printf("%d\n",p);
			check[p]=1;
		}
	}
}
