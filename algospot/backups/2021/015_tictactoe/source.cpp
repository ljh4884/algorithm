#include <stdio.h>


int game[3][3];
int save[19683];


int check()
{
	int count_x = 0;
	int count_o = 0;
	int count = 0;
	for(int i=0;i<3;i++)
	{
		count_x = 0;
		count_o = 0;
		for(int j=0;j<3;j++)
		{
			if(game[i][j] == 1)
				count_x+=1;
			else if(game[i][j] == 2)
				count_o+=1;
		}
		if(count_x == 3)
			return 1;
		else if(count_o == 3)
			return 2;
		count_x = 0;
		count_o = 0;
		for(int j=0;j<3;j++)
		{
			if(game[j][i] == 1)
				count_x+=1;
			else if(game[j][i] ==2)
				count_o+=1;
		}
		if(count_x == 3)
			return 1;
		else if(count_o == 3)
			return 2;

	}
	
	count_x = 0;
	count_o = 0;
	for(int i=0;i<3;i++)
	{
		if(game[i][i] == 1)
			count_x+=1;
		else if(game[i][i] == 2)
			count_o+=1;
	}
	if(count_x == 3)
		return 1;
	else if(count_o == 3)
		return 2;

	count_x = 0;
	count_o = 0;
	for(int i=0;i<3;i++)
	{
		if(game[i][2-i] == 1)
			count_x+=1;
		else if(game[i][2-i] == 2)
			count_o+=1;
	}
	if(count_x == 3)
		return 1;
	else if(count_o == 3)
		return 2;



	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(game[i][j] == 0)
				count+=1;

	if(count == 0)
		return 0;

	return -1;
}

int bit()
{
	int ret = 0;
	int mul = 1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(game[i][j] == 1)
				ret += mul;
			else if(game[i][j] == 2)
				ret += (mul*2);
			mul*=3;
		}

	}
	return ret;
}

int turn()
{
	int count_x = 0;
	int count_o = 0;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(game[i][j] == 1)
				count_x +=1;
			else if(game[i][j] ==2)
				count_o +=1;
		}
	}

	if(count_x > count_o)
		return 2;
	else 
		return 1;
}


int func()
{
	int cur = bit();
	if(save[cur] != -1)
		return save[cur];

	int result = check();

	if(result != -1)
	{
		save[cur] = result;
		return save[cur];
	}

	int t = turn();
	int temp_ret = -1;
	int temp = -1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(game[i][j] == 0)
			{
				game[i][j] = t;
				
				temp = func();


				if(temp == t)
				{
					game[i][j] = 0;
					save[cur] = t;
					return save[cur];
				}
				else if(temp == 0)
					temp_ret = 0;	

				game[i][j] = 0;
			}
		}
	}

	if(temp_ret == 0)
	{
		save[cur] = 0;
		return 0;
	}
	else if(t == 1)
	{
		save[cur] = 2;
		return 2;
	}
	else
	{
		save[cur] = 1;
		return 1;
	}


}

int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
		for(int i=0;i<3;i++)
		{
			char temp[4];
			scanf("%s",temp);
			for(int j=0;j<3;j++)
			{
				if(temp[j] == '.')
					game[i][j] = 0;
				else if(temp[j] == 'x')
					game[i][j] = 1;
				else
					game[i][j] = 2;
			}
		}


		for(int i=0;i<19683;i++)
			save[i] = -1;

		int ret = func();

		if(ret == 0)
			printf("TIE\n");
		else if(ret == 1)
			printf("x\n");
		else
			printf("o\n");
	}
}
