#include <stdio.h>

int main()
{
	int value[55];
	char str[100][51];

	for(int i=0;i<100;i++)
		scanf("%s",str[i]);
	for(int i=0;i<55;i++)
		value[i] = 0;

	for(int i=0;i<50;i++)
	{
		int index = 49-i;
		int sum = 0;
		for(int j=0;j<100;j++)
		{
			sum += ((int)str[j][index] - 48);
		}

		sum += value[i];
		sum += (value[i+1]*10);

		value[i] = sum % 10;
		value[i+1] = (sum%100) / 10;
		value[i+2] = sum/100;
	}	

	for(int i=55;i>=40;i--)
		printf("%d",value[i]);
	printf("\n");
}
