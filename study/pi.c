#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *array;
int n;

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int func(int i)
{
	if(i>=n)
	{
		return 0;
	}
	if(n-i<3)
	{
		return 999999999;
	}
	//3
	if(array[i]==array[i+1]==array[i+2])
	{

	}

}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d",&n);
		array =(char*)malloc(sizeof(char)*n);
		scanf("%s",array);
	}

}
