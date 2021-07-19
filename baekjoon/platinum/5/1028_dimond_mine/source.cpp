#include <stdio.h>

int r,c;
int mine[750][750];

int main()
{
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&mine[i][j]);

	int ans = 0;
	int size = 0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(mine[i][j] == 1)
			{
				int temp_ans = 0;
				for(size = 1;size<((2/r)+1);size++)
				{
					
				}

			}
		}
	}
}
