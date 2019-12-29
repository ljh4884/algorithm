#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int c;
	int sum;
	int checksum;

	char hyper[20][200000];
	char fan[20][200000];
	
	char check[200000];

	char hypersize[20];
	int fansize[20];

	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		char temp;
		int i=0;
		int count;
		sum = 0;
		
		scanf("%s",hyper[cnt]);
		hypersize[cnt]=strlen(hyper[cnt]);

		for(int j=0;j<hypersize[cnt];j++)
		{
			temp = hyper[cnt][j];
			
			if(temp=='M')
			{
				check[i]=j;
				i++;
			}
		}
		
		scanf("%s",fan[cnt]);
		fansize[cnt]=strlen(fan[cnt]);
		
		count = fansize[cnt]-hypersize[cnt]+1;
		if(i==0)
		{
			printf("%d\n",count);
		}
		else
		{
			for(int k=0;k<count;k++)
			{
				checksum=0;
				for(int a=0;a<i;a++)
				{
					if(fan[cnt][k+check[a]]=='M')
					{
						checksum=1;
						break;
					}
				}
				if(checksum==0)
					sum++;
			}
			printf("%d\n",sum);
		}
	}
}
