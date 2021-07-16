/*
 * 수업때 배운 newton-rapson method를 적용해보고 싶었지만
 * 왜 틀린지는 모르겠지만 결과가 올바르게 나오지 않았다.
 * 그래서 그냥 bisection 메소드를 사용해 보았지만 마찬가지 였다.
 * 내 처음 해법은 -10 ~ 10 범위를 0.01 단위로 체크해서 극값을 찾는것이였지만
 * 그렇게 찾으면 오답이 나올 가능성이 생기는것 같다.
 * 인터넷을 참고하여 극값을 구할때도 미분한것의 극값을 재귀적으로 찾는 방식으로 극값을
 * 찾았더니 답이 통과되었다.
 */

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

double fx(double x,int n, double *poly)
{
	double sum=0;
	double po=1;

	for(int i=0;i<n+1;i++)
	{
		sum = sum + (poly[n-i]*po);
		po=po*x;
	}
	return sum;
}
double *dpoly(double *poly,int n)
{
	double *newpoly;
	newpoly = (double*)malloc(sizeof(double)*n);
	for(int i=0;i<n;i++)
	{
		newpoly[i]=poly[i]*(n-i);
	}
	return newpoly;
}

double *solve(double *poly,int n)
{
	double *newpoly;
	newpoly = (double*)malloc(sizeof(double)*n);
	if(n==1)
	{
		newpoly[0]=-poly[1]/poly[0];
		return newpoly;
	}
	else if(n==2)
	{
		double a=poly[0];
		double b=poly[1];
		double c=poly[2];
		newpoly[0]=(-b-sqrt(b*b-4*a*c))/(2*a);
		newpoly[1]=(-b+sqrt(b*b-4*a*c))/(2*a);
		return newpoly;
	}
	else
	{
		
		double *pos=solve(dpoly(poly,n),n-1);
		double *rpos = (double*)malloc(sizeof(double)*n+1);
		rpos[0]=-10.1;
		rpos[n]=10.1;
		for(int i=1;i<n;i++)
		{
			rpos[i]=pos[i-1];
		}
		for(int i=0;i<n;i++)
		{
			double start=rpos[i];
			double end=rpos[i+1];
			for(int j=0;j<100;j++)
			{
				double mid = (start+end)/2.0;
				if(fx(start,n,poly)*fx(mid,n,poly)>0)
				{
					start=mid;
				}
				else
				{
					end=mid;
				}
			}
			newpoly[i]=(start+end)/2.0;
		}
		return newpoly;
	}

}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		double poly[6];
		double *ans;
		scanf("%d",&n);
		for(int i=0;i<n+1;i++)
		{
			scanf("%lf",&poly[i]);
		}
		ans = solve(poly,n);
		for(int i=0;i<n;i++)
		{
			printf("%.15lf ",ans[i]);
		}
		printf("\n");
	}
}
