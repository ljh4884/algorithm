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
/*
void printa(int **array)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(array[i][j]==0)
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
}*/
int func(int **array)
{
	printf("hihi\n");
	int temp = 0;
	if(check(array)==1)
	{
	//	printa(array);
		return 1; //lose
	}
	printf("hello\n");
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
						/*if(func(array)==1)
							return 0;*/
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
						array[i-1][j]=0;
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
				/*
				if(i>0&&j>0)
				{
					if(array[i-1][j]==0&&array[i][j-1]==0)
					{
						array[i-1][j]=1;
						array[i][j-1]=1;
						if(func(array)==1)
							return 0;
						array[i-1][j]=0;
						array[i][j-1]=0;
					}
					if(array[i-1][j-1]==0)
					{
						array[i-1][j-1]=1;
						if(array[i-1][j]==0)
						{
							array[i-1][j]=1;
							if(func(array)==1)
								return 0;
							array[i-1][j]=0;
						}
						if(array[i][j-1]==0)
						{
							array[i][j-1]=1;
							if(func(array)==1)
								return 0;
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
						if(func(array)==1)
							return 0;
						array[i-1][j]=0;
						array[i][j+1]=0;
					}
					if(array[i-1][j+1]==0)
					{
						array[i-1][j+1]=1;
						if(array[i-1][j]==0)
						{
							array[i-1][j]=1;
							if(func(array)==1)
								return 0;
							array[i-1][j]=0;
						}
						if(array[i][j+1]==0)
						{
							array[i][j+1]=1;
							if(func(array)==1)
								return 0;
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
						if(func(array)==1)
							return 0;
						array[i+1][j]=0;
						array[i][j-1]=0;
					}
					if(array[i+1][j-1]==0)
					{
						array[i+1][j-1]=1;
						if(array[i+1][j]==0)
						{
							array[i+1][j]=1;
							if(func(array)==1)
								return 0;
							array[i+1][j]=0;
						}
						if(array[i][j-1]==0)
						{
							array[i][j-1]=1;
							if(func(array)==1)
								return 0;
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
						if(func(array)==1)
							return 0;
						array[i+1][j]=0;
						array[i][j+1]=0;
					}
					if(array[i+1][j+1]==0)
					{
						array[i+1][j+1]=1;
						if(array[i+1][j]==0)
						{
							array[i+1][j]=1;
							if(func(array)==1)
								return 0;
							array[i+1][j]=0;
						}
						if(array[i][j+1]==0)
						{
							array[i][j+1]=1;
							if(func(array)==1)
								return 0;
							array[i][j+1]=0;
						}
						array[i+1][j+1]=0;
					}

				}
				*/
				array[i][j]=0;
			}
		}
	}
	return temp;
}

int main()
{
	int c;
	scanf("%d",&c);
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

