#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char input[1000000];
	char* result;
	char save[100][100];

	int cnt =1;
	scanf("%s",input);

	result = strtok(input,"&&");
	strcpy(save[0],result);
	while(result!=NULL)
	{
		strcpy(save[cnt],result);
		cnt++;
		result = strtok(NULL,"&&");
	}

}
