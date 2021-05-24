#include <stdio.h>
#include <string.h>


int n,m;
int can_eat[50][50];
char name[50][11];
int g_select;

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int find(char *input)
{
	for(int i=0;i<n;i++)
		if(strcmp(input,name[i]) == 0)
			return i;
	return -1;
}

int func(int pos,int select, int *check)
{
	if(pos == n)
	{
		g_select = min(g_select,select);
		return select;
	}
	if(select > g_select)
		return g_select;


	int ret = 50;


	for(int i=0;i<m;i++)
		if(check[i] == 1)
			if(can_eat[i][pos] == 1)
				return func(pos+1,select,check);
	for(int i=0;i<m;i++)
	{
		if(check[i] == 0)
		{
			if(can_eat[i][pos] == 1)
			{
				check[i] = 1;
				ret = min(ret,func(pos+1,select+1,check));
				check[i] = 0;
			}
		}
	}
	return ret;
}

int main()
{
	int c;
	int check[50];
	scanf("%d", &c);

	while(c--)
	{

		g_select = 50;

		scanf("%d %d",&n,&m);
		
		for(int i=0;i<n;i++)
			scanf("%s",name[i]);

		char temp[11];
		int temp_2;

		for(int i=0;i<m;i++)
		{
			scanf("%d",&temp_2);
			for(int j=0;j<n;j++)
				can_eat[i][j] = 0;

			for(int j=0;j<temp_2;j++)
			{
				scanf("%s",temp);
				can_eat[i][find(temp)] = 1;
			}
		}

		for(int i=0;i<m;i++)
			check[i] = 0;

		printf("%d\n",func(0,0,check));
		
		

	}
}
