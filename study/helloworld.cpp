#include <stdio.h>
#include <string.h>

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		char temp[51];
		scanf("%s",temp);
		printf("Hello, %s!\n",temp);
	}
}
