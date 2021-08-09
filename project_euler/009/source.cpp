#include <stdio.h>

int main()
{
	for(int a = 1; a < 999; a++)
	{
		int check = 0;
		for(int b = 1; b < 1000 - a; b++)
		{
			int c = 1000 - a - b;
			if((a*a + b*b) == (c*c))
			{
				printf("%d\n",a*b*c);
				check = 1;
				break;
			}

		}
		if(check)
			break;
	}
}
