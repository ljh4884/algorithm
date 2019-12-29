#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//int a[30][30];
	int a[1000][1000];
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
			a[i][j]=-1;
	}
	//memset(a,-1,sizeof(a));

	printf("%d\n",a[10][10]);
}
