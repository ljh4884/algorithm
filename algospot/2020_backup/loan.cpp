/* 지금까지의 최적화문제와 같거나 더 쉬운 문제였다.
 * 댓글에 오차 문제가 있을수 있다는 것 같아서 long double로 사용해 보았다.
 * 수행시간은 0ms여서 큰 차이가 없던것 같다.
 */

#include <stdio.h>
#include <math.h>


int m;
long double n,p;

bool func(long double value)
{
	long double op = 1200.0/(1200.0+p);
	long double sum=0;
	long double po=1;
	for(int i=0;i<m;i++)
	{
		po=po*op;
		sum =sum + (value*po);
	}
	return sum>=n;
}

long double opt()
{
	long double start =n/m;
	long double end = 135*start;
	for(int i=0;i<100;i++)
	{
		//printf ("%Lf %Lf\n",start,end);
		double min = (start+end)/2.0;

		if(func(min))
			end=min;
		else
			start=min;
	}
	return end;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%Lf %d %Lf",&n,&m,&p);
		printf("%.20LF\n",opt());
	}
}
