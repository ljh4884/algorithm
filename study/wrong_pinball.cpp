#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define one struct cir
#define pos struct table
struct cir
{
	double x,y,r;
};

struct table
{
	double x,y;
};

one circle[50];

double x,y,dx,dy;
int n;

void normald()
{
	double tempx=dx;
	double tempy=dy;
	dx = dx/(sqrt(tempx*tempx+tempy*tempy));
	dy = dy/(sqrt(tempx*tempx+tempy*tempy));
}

pos normal(double x,double y)
{
	pos temp;
	double tempx=x;
	double tempy=y;
	temp.x = x/(sqrt(tempx*tempx+tempy*tempy));
	temp.y = y/(sqrt(tempx*tempx+tempy*tempy));
	return temp;

}

pos dis(int i)
{
	pos temp;
	double cross;
	double garo;
	double sero;
	double deo;
	double a = circle[i].x-x;
	double b = circle[i].y-y;
	temp.x=0;
	temp.y=0;
	cross = a*a+b*b;
	garo = a*dx+b*dy;
	if(garo<0)
		return temp;
	garo = garo*garo;
	sero = cross-garo;
	deo = (circle[i].r+1)*(circle[i].r+1);
	if(sero<deo)
	{
		double bbe = deo-sero;
		garo = sqrt(garo);
		bbe = sqrt(bbe);
		temp.x= x+dx*(garo-bbe);
		temp.y=y+dy*(garo-bbe);
		return temp;
	}
	else
	{
		return temp;
	}

}

double ris(pos input)
{
	double tempx=input.x;
	double tempy=input.y;

	return ((tempx-x)*(tempx-x)+(tempy-y)*(tempy-y));

}

int select(int pre)
{
	int check=0;
	pos temp;
	pos ret;
	int reti;
	double min=999999;
	for(int i=0;i<n;i++)
	{
		if(i==pre)
			continue;
		temp = dis(i);
		if(temp.x!=0)
		{
			//printf("hihi %d\n",i);
			//check=1;
			
			if(ris(temp)<min)
			{
					
					//printf("%lf %lf %d\n",temp.x,temp.y,i);
					check=1;
					min = ris(temp);
					ret=temp;
					reti=i;
				
			}
		}
	}
	if(check==1)
	{
		pos nv;
		nv.x = ret.x-circle[reti].x;
		nv.y = ret.y-circle[reti].y;
		nv=normal(nv.x,nv.y);
		double disx= ret.x-x;
		double disy= ret.y-y;
		double disr = sqrt(disx*disx+disy*disy);

		double pl = -(dx*disr*nv.x)-(dy*disr*nv.y);

		//printf("%lf %lf %lf\n",pl,nv.x,nv.y);
		nv.x = nv.x*pl;
		nv.y = nv.y*pl;
		dx = disr*dx+2*nv.x;
		dy = disr*dy+2*nv.y;
		//printf("%d %lf %lf\n",reti,nv.x,nv.y);
		x=ret.x;
		y=ret.y;
		normald();
		//printf("%lf %lf %lf %lf\n",x,y,dx,dy);
		return reti;
	}
	return -1;
}

void solve()
{
	int temp=-1;
	for(int i=0;i<10;i++)
	{
		temp=select(temp);
		if(temp==-1)
			break;
		else
		{
		
			printf("%d ",temp);
		}
	}
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%lf %lf %lf %lf %d",&x,&y,&dx,&dy,&n);
		normald();
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf %lf",&circle[i].x,&circle[i].y,&circle[i].r);
		}
		solve();
		printf("\n");
	}
}
