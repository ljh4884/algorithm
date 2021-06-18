#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int c=100;
	printf("%d\n",c);
	srand(time(NULL));
	while(c--)
	{
		int n = 50;
		int size = 10000;
		int way = 0;
		char str[10001];
		char temp[10001];
		printf("%d\n",n);
		for(int i=0;i<size;i++)
			str[i] = rand()%26 + 65;
		printf("%s\n",str);
		for(int i=0;i<n;i++)
		{
			int pivot = rand()%(size-2) + 1;
			
			int temp_pos = size - pivot;
			for(int i=0;i<pivot;i++)
			{
				temp[temp_pos+i] = str[i];
			}
				
			for(int i=pivot;i<size;i++)
			{
				temp[i-pivot] = str[i];
			}
			strcpy(str,temp);
			printf("%s\n",str);
		}
	}
}
