/*거의 책과 인터넷을 참고한 코드
 * opt() 가 안되는 이유는 내가 실제로 겹치는 다각형의 모든 꼭지점을 찾은게 아니기 때문
 * 정말 어려웠음
 *
 */


#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

#define pos struct table

struct table
{
	double x;
	double y;
};

vector<pair<pos,pos>> aup;
vector<pair<pos,pos>> adown;
vector<pair<pos,pos>> bup;
vector<pair<pos,pos>> bdown;

int n,m;

pos a[100];
pos b[100];

bool that(pair<pos,pos> point, double x)
{
	double a = point.first.x;
	double b = point.second.x;

	return (a<=x&&x<=b)||(b<=x&&x<=a);
}

double cal(pair<pos,pos> point,double x)
{
	pos a = point.first;
	pos b = point.second;
	double linear;
	if(a.x>b.x)
	{
		pos temp=a;
		a=b;
		b=temp;
	}

	linear = (b.y-a.y)/(b.x-a.x);

	return linear*(x-a.x)+a.y;

}

double func(double x)
{
	double up1=-1;
	double up2=-1;
	double down1=-1;
	double down2=-1;

	for(int i=0;i<aup.size();i++)
		if(that(aup[i],x))
			up1=cal(aup[i],x);
	for(int i=0;i<bup.size();i++)
		if(that(bup[i],x))
			up2=cal(bup[i],x);
	for(int i=0;i<adown.size();i++)
		if(that(adown[i],x))
			down1=cal(adown[i],x);
	for(int i=0;i<bdown.size();i++)
		if(that(bdown[i],x))
			down2=cal(bdown[i],x);
	if(up1!=-1&&up2!=-1&&down1!=-1&&down2!=-1)
		return min<double>(up1,up2)-max<double>(down1,down2);
	else
		return -1.0;
}



double opt()
{
	
	double ret=0;
	for(int i=0;i<n;i++)
	{
		ret = max<double>(ret,func(a[i].x));
	}
	for(int i=0;i<m;i++)
	{
		ret = max<double>(ret,func(b[i].x));
	}
	return ret;
}
double start()
{
	double ret1=a[0].x;
	double ret2=b[0].x;
	for(int i=1;i<n;i++)
	{
		ret1=min<double>(ret1,a[i].x);
	}
	for(int i=1;i<m;i++)
	{
		ret2=min<double>(ret2,b[i].x);
	}
	return max<double>(ret1,ret2);
}

double end()
{
	double ret1=a[0].x;
	double ret2=b[0].x;
	for(int i=0;i<n;i++)
	{
		ret1 = max<double>(ret1,a[i].x);
	}
	for(int i=0;i<m;i++)
	{
		ret2=max<double>(ret2,b[i].x);
	}
	return min<double>(ret1,ret2);
}
double opt2()
{
	double low = start();
	double high = end();
	if(low>high)
		return 0.0;

	for(int i=0;i<100;i++)
	{
		double pos1=(low*2+high)/3.0;
		double pos2=(low+high*2)/3.0;
		if(func(pos1)<func(pos2))
			low=pos1;
		else
			high=pos2;
	}
	return max<double>(0.0,func(high));
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&a[i].x,&a[i].y);
			
		}
		for(int i=0;i<m;i++)
		{
			scanf("%lf %lf",&b[i].x,&b[i].y);
		}
		int next;
		adown.clear();
		aup.clear();
		bdown.clear();
		bup.clear();
		for(int i=0;i<n;i++)
		{
			next = (i+1)%n;
			if(a[i].x==b[i].x)
			{
			}
			else if(a[i].x<a[next].x)
				adown.push_back(make_pair(a[i],a[next]));
			else
				aup.push_back(make_pair(a[i],a[next]));
		}
		for(int i=0;i<m;i++)
		{
			next = (i+1)%m;
			if(b[i].x==b[next].x)
			{
			}
			else if(b[i].x<b[next].x)
				bdown.push_back(make_pair(b[i],b[next]));
			else
				bup.push_back(make_pair(b[i],b[next]));
		}
		double ret =opt2();
		
		printf("%.20lf\n",max<double>(0.0,ret));
	}
}
