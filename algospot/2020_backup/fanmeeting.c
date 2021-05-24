#include <stdio.h>
#include <string.h>
int main()
{
	int c,fansize,hypersize,mansize;
	char hyper[200000];
	int hyperman[200000];
	char fan[200000];
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		mansize=0;
		
		scanf("%s",hyper);
		hypersize = strlen(hyper);
		memset(hyperman,-1,hypersize*4);
		for(int i=0;i<hypersize;i++)
		{
			if(hyper[i]=='M')
			{
				hyperman[mansize]=i;
				mansize++;
			}
		}
		scanf("%s",fan);
		fansize = strlen(fan);
		if(mansize == 0)
		{
			printf("%d\n",fansize-hypersize+1);

		}
		else
		{
			int result=0;
			int check=0;
			for(int i=0;i<fansize-hypersize+1;i++)
			{
				check=0;
				for(int j=0;j<mansize;j++)
				{
					if(fan[i+hyperman[j]]=='M')
					{
						check=1;
						break;
					}
				}
				if(check==1)
				{
					continue;
				}
				result++;
			}
			printf("%d\n",result);
		}
	}
}
