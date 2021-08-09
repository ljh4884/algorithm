#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int temp;
	int size;
	char str[8];
	int ans = 0;
	for(int i=1;i<1000;i++)
	{
		for(int j=1;j<1000;j++)
		{
			int check = 1;
			temp = i*j;
			sprintf(str,"%d",temp);
			size = strlen(str);

			for(int k=0;k<(size/2);k++)
			{
				if(str[k] != str[size-1-k])
				{
					check = 0;
					break;
				}
			}
			if(check)
			{
				if(temp > ans)
					ans = temp;
			}

		}
	}
	printf("%d\n",ans);
}
