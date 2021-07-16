#include <stdio.h>
int game[5][5];

char save[1<<25];


int make()
{
	int ret = 0;
	int mul = 1;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(game[i][j] == 1)
				ret+=mul;
			mul*=2;
		}
	}
	return ret;
}

int check()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<4;j++)
			if(game[i][j] == 0 && game[i][j+1] == 0)
				return 0;

	for(int i=0;i<4;i++)
		for(int j=0;j<5;j++)
			if(game[i][j] == 0 && game[i+1][j] == 0)
				return 0;
	return 1; // fail

}

void display()
{
	printf("\n");
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(game[i][j] == 0)
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
}

char func(int pos)
{
	int cur_bit = make();
	if(save[cur_bit] != -1)
		return save[cur_bit];

	int cur_ret = check();
	if(cur_ret == 1)
	{
		save[cur_bit] = 1;
		return 1;
	}
	
	int temp;

	

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(game[i][j] == 0 && game[i+1][j+1] == 0)
			{
				game[i][j] = 1;
				game[i+1][j+1] = 1;

				if(game[i+1][j] == 0)
				{
					game[i+1][j] = 1;
					temp = func(pos+1);
					if(temp == 1)
					{
						save[cur_bit] = 0;
						game[i][j] = 0;
						game[i+1][j+1] = 0;
						game[i+1][j] = 0;
						return 0;
					}
					game[i+1][j] = 0;
				}
				if(game[i][j+1] == 0)
				{
					game[i][j+1] = 1;
					temp = func(pos+1);
					if(temp == 1)
					{
						save[cur_bit] = 0;
						game[i][j] = 0;
						game[i+1][j+1] = 0;
						game[i][j+1] = 0;
						return 0;
					}
					game[i][j+1] = 0;
				}

				game[i][j] = 0;
				game[i+1][j+1] = 0;

			}
		}
	}

	for(int i=1;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(game[i][j] == 0 && game[i-1][j+1] == 0)
			{
				game[i][j] = 1;
				game[i-1][j+1] = 1;

				if(game[i-1][j] == 0)
				{
					game[i-1][j] = 1;
					temp = func(pos+1);
					if(temp == 1)
					{
						save[cur_bit] = 0;
						game[i][j] = 0;
						game[i-1][j+1] = 0;
						game[i-1][j] = 0;
						return 0;
					}
					game[i-1][j] = 0;
				}

				if(game[i][j+1] ==0)
				{
					game[i][j+1] =1;
					temp = func(pos+1);
					if(temp == 1)
					{
						save[cur_bit] = 0;
						game[i][j] = 0;
						game[i-1][j+1] = 0;
						game[i][j+1] = 0;
						return 0;
					}
					game[i][j+1] = 0;
				}

				game[i][j] = 0;
				game[i-1][j+1] = 0;
			}
		}
	}


	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(game[i][j] == 0 && game[i][j+1] == 0)
			{
				game[i][j] = 1;
				game[i][j+1] = 1;
				temp = func(pos+1);
				if(temp == 1)
				{
					save[cur_bit] = 0;
					game[i][j] = 0;
					game[i][j+1] = 0;
					return 0;
				}
				game[i][j] = 0;
				game[i][j+1] = 0;
			}
		}
	}

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(game[i][j] == 0 && game[i+1][j] == 0)
			{
				game[i][j] = 1;
				game[i+1][j] = 1;
				temp = func(pos+1);
				if(temp == 1)
				{
					save[cur_bit] = 0;
					game[i][j] = 0;
					game[i+1][j] = 0;
					return 0;
				}
				game[i][j] = 0;
				game[i+1][j] = 0;
			}
		}
	}

	save[cur_bit] = 1;
	return 1;
}

int main()
{
	int c;
	scanf("%d", &c);


	for(int i=0;i<33554432;i++)
		save[i] = -1;

	while(c--)
	{
		char temp[6];

		for(int i=0;i<5;i++)
		{
			scanf("%s",temp);
			for(int j=0;j<5;j++)
			{
				if(temp[j] == '.')
					game[i][j] = 0;
				else
					game[i][j] = 1;
			}
		}

		if(func(1) == 0)
			printf("WINNING\n");
		else
			printf("LOSING\n");



	
	}
}
