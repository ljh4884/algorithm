#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

typedef struct position
{
	double x;
	double y;
}pos;

typedef struct line
{
	pos pos1;
	pos pos2;
}line;

int n;
pos posrec[4];
pos array[100];
vector<line> poly;
int check[4];
int size;
int start;
void make_poly()
{
	for(int i=0;i<n;i++)
	{
		int cur = (start+i)%n;
		int next = (cur+1)%n;
		line temp;
		temp.pos1 = array[cur];
		temp.pos2 = array[next];
		poly.push_back(temp);
	}
}
pos make_vec(pos a,pos b)
{
	pos ret;
	ret.x = b.x-a.x;
	ret.y = b.y-a.y;
	return ret;
}
int meet(pos a,line b)
{
	if(a.y<min(b.pos1.y,b.pos2.y) || a.y>max(b.pos1.y,b.pos2.y))
		return 0;
	if(a.x>max(b.pos1.x,b.pos2.x))
		return 0;
	pos vec = make_vec(b.pos1,b.pos2);
	double comp = a.y+0.000001;
	if(vec.x==0)
	{
		if(a.x<b.pos1.x&&comp<max(b.pos1.y,b.pos2.y)&&comp>min(b.pos1.y,b.pos2.y))
			return 1;
		else
			return 0;
	}
	if(vec.y==0)
	{
		return 0;
	}
	else
	{
		//(b.pos1.x,b.pos1.y)+ (vec.x,vec.y)*t = ( x, comp)
		double t = (comp - b.pos1.y)/vec.y;
		double x = b.pos1.x+vec.x*t;
		if(x<max(b.pos1.x,b.pos2.x)&&x>min(b.pos1.x,b.pos2.x))
		{
			if(x<a.x)
				return 0;
			return 1;
		}
		return 0;
	}

}

void make_check()
{
	for(int i=0;i<4;i++)
	{
		int cnt=0;
		for(int j=0;j<size;j++)
		{
			if(meet(posrec[i],poly[j]))
				cnt++;
		}
		if(cnt%2==1)
			check[i]=1;
		else
			check[i]=0;
	}
}

double make_sum(pos a, pos b,pos c)
{
	pos vec1 = make_vec(a,b);
	pos vec2 = make_vec(a,c);

	return ((vec1.x*vec2.y)-(vec1.y*vec2.x))/2;
}

double f_linear(line a)
{
	return fabs(a.pos2.y-a.pos1.y)/(a.pos2.x-a.pos1.x);
}

void func()
{
	double sum=0;
	int i;
	if(check[0]==0)
	{

		if(check[3]==0)
		{
			if(check[1]==0)
			{
				i=start;
				while(1)
				{
					sum+=make_sum(posrec[0],poly[i].pos1,poly[i].pos2);
					if(f_linear(poly[i])<f_linear(poly[i]))
						break;
					i=i+1;
				}
				sum+=make_sum(poly[i].pos2,posrec[0],posrec[1]);
			}
			else
			{
			}
		
		}
		else
		{
		}
		
	}
	
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%lf %lf %lf %lf %d",&posrec[0].x,&posrec[0].y,&posrec[2].x,&posrec[2].y,&n);
		posrec[1].x = posrec[2].x;
		posrec[1].y = posrec[0].y;
		posrec[3].x = posrec[0].x;
		posrec[3].y = posrec[2].y;
		start=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&array[i].x,&array[i].y);
			if(array[i].x==array[start].x)
			{
				if(array[i].y>array[start].y)
					start=i;
			}
			if(array[i].x<array[start].x)
			{
				start=i;
			}

		}
		poly.clear();
		make_poly();
		size = poly.size();
		make_check();
		for(int i=0;i<4;i++)
		{
			printf("%d\n",check[i]);
		}
	}
}
