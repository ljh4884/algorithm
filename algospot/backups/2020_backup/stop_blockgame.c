#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char check(int **array)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(array[i][j]==0)
			{
				if(i>0)
					if(array[i-1][j]==0)
						return 0; //can win
				if(i<4)
					if(array[i+1][j]==0)
						return 0;
				if(j>0)
					if(array[i][j-1]==0)
						return 0;
				if(j<4)
					if(array[i][j+1]==0)
						return 0;
			}
		}
	}
	return 1;  //lose
}

char func(int **array)
{
	if(check(array)==1)
		return 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(array[i][j]==0)
			{
				if(i>0)
				{
					if(i<4)
					{
						if(j>0)
						{
							if(j<4) //free
							{

							}
							else //j=4
							{

							}
						}
						else //j=0
						{

						}
					}
					else //i=4
					{
						if(j>0)
						{
							if(j<4) //i=4
							{

							}
							else //i=4,j=4
							{

							}
						}
						else //i=4,j=0
						{

						}
					}
				}
				else // i=0
				{
					if(j>0) 
					{
						if(j<4) //i=0
						{

						}
						else //i=0,j=4
						{

						}
					}
					else //i=0,j=0
					{

					}
				}
			}
		}
	}
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int array[5][5];
		for(int i=0;i<5;i++)
		{
			char temp[6];
			scanf("%s",temp);
			for(int j=0;j<5;j++)
			{
				if(temp[j]=='.')
					array[i][j]=0;
				else
					array[i][j]=1;
			}
		}
	}
}

