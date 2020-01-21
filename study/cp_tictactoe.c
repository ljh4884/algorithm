#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int save[19683];

int cat(char **array)
{
	int ret=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ret=ret*3;
			if(array[i][j]=='o')
				ret+=1;
			else if(array[i][j]=='x')
				ret+=2;
		}
	}
	return ret;
}
char **make()
{
	char **array;
	array = (char**)malloc(sizeof(char*)*3);
	for(int i=0;i<3;i++)
	{
		array[i] = (char*)malloc(sizeof(char)*4);
	}
	return array;
}
char **copy(char **array)
{
	char **temp;
	temp = (char**)malloc(sizeof(char*)*3);
	for(int i=0;i<3;i++)
	{
		temp[i]=(char*)malloc(sizeof(char)*3);
		for(int j=0;j<3;j++)
		{
			temp[i][j]=array[i][j];
		}
	}
	return temp;
}
int check(char **array)
{
	int o;
	int x;
	for(int i=0;i<3;i++)
	{
		o=0;
		x=0;
		for(int j=0;j<3;j++)
		{
			if(array[i][j]=='o')
				o++;
			if(array[i][j]=='x')
				x++;
		}
		if(o==3)
			return 0;
		if(x==3)
			return 1;
		o=0;
		x=0;
		for(int j=0;j<3;j++)
		{
			if(array[j][i]=='o')
				o++;
			if(array[j][i]=='x')
				x++;
		}
		if(o==3)
			return 0;
		if(x==3)
			return 1;
	}
	o=0;
	x=0;
	for(int i=0;i<3;i++)
	{
		if(array[i][i]=='o')
			o++;
		if(array[i][i]=='x')
			x++;
	}
	if(o==3)
		return 0;
	if(x==3)
		return 1;
	x=0;
	o=0;
	for(int i=0;i<3;i++)
	{
		if(array[i][2-i]=='o')
			o++;
		if(array[i][2-i]=='x')
			x++;
	}
	if(o==3)
		return 0;
	if(x==3)
		return 1;
	return 2;
}


int func(char **array,char turn)
{
	char that;
	int count =0;
	int count2=0;
	int pos = cat(array);
	if(save[pos]!=-1)
		return save[pos];
	if(turn=='x')
		that='o';
	else
		that='x';
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(array[i][j]=='.')
			{
				count++;
				count2++;
				char **temp = copy(array);
				temp[i][j]=turn;
				if(turn=='o')
				{
					if(check(temp)==0)
					{
						save[pos]=0;
						return 0;
					}
					if(func(temp,that)==1)
						count--;
				}
				else if(turn=='x')
				{
					if(check(temp)==1)
					{
						save[pos]=1;
						return 1;
					}
					if(func(temp,that)==0)
						count--;
				}
				
			}
		}
	}
	if(count2==0)
	{
		return check(array);
		save[pos]=2;
		return 2;
	}
	if(count==0)
	{
		if(turn=='x')
		{
			save[pos]=0;
			return 0;
		}
		if(turn=='o')
		{
			save[pos]=1;
			return 1;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(array[i][j]=='.')
			{
				char **temp = copy(array);
				temp[i][j]=turn;
				if(turn=='x')
				{
					if(func(temp,that)!=0)
					{
						save[pos]=func(temp,that);
						return save[pos];
					}
				}
				else if(turn=='o')
				{
					if(func(temp,that)!=1)
					{
						save[pos]=func(temp,that);
						return save[pos];
					}
				}
			}
		}
	}
	save[pos]=2;
	return 2;

}

int main()
{
	int c;
	scanf("%d",&c);
	for(int i=0;i<19683;i++)
	{
		save[i]=-1;
	}
	while(c--)
	{
		char **array=make();
		int x=0;
		int o=0;
		int result;
		for(int i=0;i<3;i++)
		{
			scanf("%s",array[i]);
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(array[i][j]=='x')
					x++;
				if(array[i][j]=='o')
					o++;
			}
		}
		if(o<x)
			result=func(array,'o');
		else
			result=func(array,'x');
		if(result==0)
			printf("o\n");
		else if(result==1)
			printf("x\n");
		else
			printf("TIE\n");

	}
}
