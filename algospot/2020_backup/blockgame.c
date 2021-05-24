#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char save[1<<25];
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
int cat(int **array)
{
	int ret=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			ret=ret*2;
			if(array[i][j]==0)
				ret++;
		}
	}
	return ret;
}
char func(int **array)
{
	char temp = 0;
	int pos = cat(array);
	if(save[pos]!=-1)
		return save[pos];
	if(check(array)==1)
	{
		return 1; //lose
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(array[i][j]==0)
			{
				array[i][j]=1;
				if(i>0)
				{
					if(array[i-1][j]==0)
					{
						array[i-1][j]=1;
						temp = temp||func(array);
						array[i-1][j]=0;
					}
				}
				if(j>0)
				{
					if(array[i][j-1]==0)
					{
						array[i][j-1]=1;
						temp = temp||func(array);
						array[i][j-1]=0;
					}
				}
				if(i<4)
				{
					if(array[i+1][j]==0)
					{
						array[i+1][j]=1;
						temp = temp||func(array);
						array[i+1][j]=0;
					}
				}
				if(j<4)
				{
					if(array[i][j+1]==0)
					{
						array[i][j+1]=1;
						temp = temp||func(array);
						array[i][j+1]=0;
					}
				}
				
				if(i>0&&j>0)
				{
					if(array[i-1][j]==0&&array[i][j-1]==0)
					{
						array[i-1][j]=1;
						array[i][j-1]=1;
						
						temp = temp||func(array);
						array[i-1][j]=0;
						array[i][j-1]=0;
					}
					if(array[i-1][j-1]==0)
					{
						array[i-1][j-1]=1;
						if(array[i-1][j]==0)
						{
							array[i-1][j]=1;
							
							temp = temp||func(array);
							array[i-1][j]=0;
						}
						if(array[i][j-1]==0)
						{
							array[i][j-1]=1;
							
							temp = temp||func(array);
							array[i][j-1]=0;
						}
						array[i-1][j-1]=0;
					}
				}
				if(i>0&&j<4)
				{
					if(array[i-1][j]==0&&array[i][j+1]==0)
					{
						array[i-1][j]=1;
						array[i][j+1]=1;
						
						temp = temp||func(array);
						array[i-1][j]=0;
						array[i][j+1]=0;
					}
					if(array[i-1][j+1]==0)
					{
						array[i-1][j+1]=1;
						if(array[i-1][j]==0)
						{
							array[i-1][j]=1;
							temp = temp||func(array);
							
							array[i-1][j]=0;
						}
						if(array[i][j+1]==0)
						{
							array[i][j+1]=1;
							
							temp = temp||func(array);
							array[i][j+1]=0;
						}
						array[i-1][j+1]=0;
					}

				}
				if(i<4&&j>0)
				{
					if(array[i+1][j]==0&&array[i][j-1]==0)
					{
						array[i+1][j]=1;
						array[i][j-1]=1;
						temp = temp||func(array);
						
						array[i+1][j]=0;
						array[i][j-1]=0;
					}
					if(array[i+1][j-1]==0)
					{
						array[i+1][j-1]=1;
						if(array[i+1][j]==0)
						{
							array[i+1][j]=1;
							temp = temp||func(array);
							
							array[i+1][j]=0;
						}
						if(array[i][j-1]==0)
						{
							array[i][j-1]=1;
							temp = temp||func(array);
							
							array[i][j-1]=0;
						}
						array[i+1][j-1]=0;
					}

				}
				if(i<4&&j<4)
				{
					if(array[i+1][j]==0&&array[i][j+1]==0)
					{
						array[i+1][j]=1;
						array[i][j+1]=1;
						temp = temp||func(array);
						
						array[i+1][j]=0;
						array[i][j+1]=0;
					}
					if(array[i+1][j+1]==0)
					{
						array[i+1][j+1]=1;
						if(array[i+1][j]==0)
						{
							array[i+1][j]=1;
							temp = temp||func(array);
							
							array[i+1][j]=0;
						}
						if(array[i][j+1]==0)
						{
							array[i][j+1]=1;
							temp = temp||func(array);
							
							array[i][j+1]=0;
						}
						array[i+1][j+1]=0;
					}

				}
				
				array[i][j]=0;
			}
		}
	}
	save[pos]=!temp;
	return !temp;
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int i=0;i<(1<<25);i++)
	{
		save[i]=-1;
	}
	while(c--)
	{
		int **array;
		array =(int **)malloc(sizeof(int*)*5);
		for(int i=0;i<5;i++)
		{
			char temp[6];
			array[i]=(int*)malloc(sizeof(int)*5);
			scanf("%s",temp);
			for(int j=0;j<5;j++)
			{
				if(temp[j]=='.')
					array[i][j]=0;
				else
					array[i][j]=1;
			}
		}
		if(func(array)==0)
		{
			printf("win\n");
		}
		else
			printf("lose\n");
	}
}