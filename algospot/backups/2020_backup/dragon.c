/*
 * 동적 계획법을 사용하지 않고 품
 * p번째 글자를 찾는 알고리즘을 구현한뒤
 * 그알고리즘을 l번 만큼 반복 하였다.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,p,l;
int aow[30];

void func(int n,int start,char op,char ans)
{
	if(n==0)
	{
		if(start==1)
			printf("F");
		else
			printf("X");
		return;
	}
	if(n==1)
	{
		switch(start)
		{
			case 1:
				printf("F");
				break;
			case 2:
				printf("X");
				break;
			case 3:
				if(ans=='x')
					printf("+");
				else
					printf("-");
				break;
			case 4:
				printf("Y");
				break;
			case 5:
				printf("F");
				break;
			default:
				printf("WRONG\n");
				break;
			}
		return;	
	}
	if(1+aow[n]/2>start)
	{
		func(n-1,start,'+','x');
	}
	else if(1+aow[n]/2==start)
	{
		printf("%c",op);
	}
	else
	{
		start = start - 1 - aow[n]/2;
		func(n-1,start,'-','y');
	}
}

int main()
{
	int temp=1;
	for(int i=0;i<30;i++)
	{
		aow[i]=temp*3-1;
		temp=temp*2;
	}
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d %d",&n,&p,&l);
		if(n>29)
			n=29;
		for(int i=p;i<p+l;i++)
		{
			func(n,i,'+','x');
		}
		printf("\n");
	}

}

