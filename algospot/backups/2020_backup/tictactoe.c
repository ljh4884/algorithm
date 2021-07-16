/*
 * 어려운 문제는 아니였다.
 * state를 변경해준뒤
 * 계산하고
 * 다시 state를 원래 상태로 돌린다.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rp();

char array[3][3];
char save[19683];

int cat()
{
	int ret=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ret=ret*3;
			if(array[i][j]=='x')
				ret+=1;
			if(array[i][j]=='o')
				ret+=2;
		}
	}
	return ret;
}

char who()
{
	int o1=0;
	int o2=0;
	int x1=0;
	int x2=0;

	for(int i=0;i<3;i++)
	{
		o1=0;
		o2=0;
		x1=0;
		x2=0;
		for(int j=0;j<3;j++)
		{
			if(array[i][j]=='o')
				o1++;
			if(array[i][j]=='x')
				x1++;
			if(array[j][i]=='o')
				o2++;
			if(array[j][i]=='x')
				x2++;
		}
		if(o1==3)
			return 'o';
		if(o2==3)
			return 'o';
		if(x1==3)
			return 'x';
		if(x2==3)
			return 'x';
	}
	o1=0;
	o2=0;
	x1=0;
	x2=0;
	for(int i=0;i<3;i++)
	{
		if(array[i][i]=='o')
			o1++;
		else if(array[i][i]=='x')
			x1++;
		if(array[i][2-i]=='o')
			o2++;
		else if(array[i][2-i]=='x')
			x2++;
	}
	if(o1==3)
		return 'o';
	if(o2==3)
		return 'o';
	if(x1==3)
		return 'x';
	if(x2==3)
		return 'x';
	return 0;
}
void rp()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%c",array[i][j]);
		}
		printf("\n");
	}
}
char func(char turn)
{
	char that;
	char temp;
	int cnt1=0;
	int cnt2=0;
	int cnt3=0;
	int pos = cat();
	if(save[pos]!=-1)

		return save[pos];
	if(turn=='x')
		that='o';
	else
		that='x';
	if((temp=who())!=0)
	{
		return temp;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(array[i][j]=='.')
			{
				cnt1++;
				array[i][j]=turn;
				temp=func(that);
				if(temp==turn)
				{
					array[i][j]='.';
					return turn;
				}
				else if(temp==that)
				{
					cnt2++;
				}
				else
				{
					cnt3++;
				}
				array[i][j]='.';
			}
		}
	}
	if(cnt1==0)
		return 0;
	else if(cnt1==cnt2)
		return that;
	if(cnt3!=0)
		return 0;
	return 1;

}

int main()
{
	int c;
	char ret;
	scanf("%d",&c);
	for(int i=0;i<19683;i++)
	{
		save[i]=-1;
	}
	while(c--)
	{
		int o=0;
		int x=0;
		for(int i=0;i<3;i++)
		{
			scanf("%s",array[i]);
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(array[i][j]=='o')
					o++;
				else if(array[i][j]=='x')
					x++;
			}
		}
		if(o<x)
			ret = func('o');
		else
			ret = func('x');
		if(ret=='o')
			printf("o\n");
		else if(ret=='x')
			printf("x\n");
		else
			printf("TIE\n");

	}
}
