#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int n,q;
int x[250000];
int y[250000];

int a,b;
int c;
int check;
int save[250000];



double dis(int a,int b, int c, int d)
{
	if(a>c)
	{
		int temp = a;
		a = c;
		c = temp;
	}
	if(b>d)
	{
		int temp = b;
		b = d;
		d = temp;
	}

	return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
void func(int start);
void func2(int posa,int posb)
{
	for(int i=0;i<n;i++)
	{
		int temp = posa-x[i];
		int temp2 = posb-y[i];
		if(temp<=c&&temp>=-c)
			func(i);
		else if(temp2<=c&&temp2>=-c)
			func(i);
	}
}

void func(int start)
{
	if(start==b)
	{
		check=1;
		return;
	}
	if(check==1)
		return;
	if(save[start]==1)
		return;

	int posa = x[start];
	int posb = y[start];
	save[start]=1;
	for(int i=0;i<n;i++)
	{
		if(posa == x[i])
			func(i);
		else if(posb == y[i])
			func(i);
	}
	func2(posa,posb);
}

int main()
{
	scanf("%d %d",&n,&q);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	for(int cnt=0;cnt<q;cnt++)
	{
		for(int i=0;i<n;i++)
			save[i]=0;
		scanf("%d %d %d",&a,&b,&c);
		a=a-1;
		b=b-1;
		check=0;
		func(a);
		if(check==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
