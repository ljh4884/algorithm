/*
 * 4가지 단계로 나누었다.
 * 1. 점들을 선물포장 알고리즘을 사용하여 최소의 볼록껍질을 만들어 선분들을 저장해서 2개의 다각형을 만든다.
 * 2. 다각형내의 한점과 다른 다각형의 선분들을 통해 그점이 다른 다각형안에 포함되는지 확인한다.
 * 	  포함되었다면 true를 반환하여 INVALID를 출력한다.
 * 3. 다각형의 한 선분과 다른 다각형의 선분들을 통해 그선분이 다른 다각형의 선분들을 교차한다면
 *    true를 반환하여 INVALID를 출력한다.
 * 4. 위의 과정들이 true가 아닐경우에만 HOLDS를 출력한다.
 */

#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

typedef struct position
{
	int x;
	int y;
}pos;

typedef struct line
{
	pos pos1;
	pos pos2;
}line;

pos array1[5000];
pos array2[5000];
int n;
int n1,n2;
int min1;
int min2;
int p1;
int p2;
vector<line> poly1;
vector<line> poly2;

int dot(pos a,pos b)
{
	return a.x*b.x+a.y*b.y;
}

double sizevec(pos a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

double rad(pos a,pos b)
{
	return (double)dot(a,b)/(sizevec(a)*sizevec(b));
}

pos make_vec(pos a,pos b)
{
	pos ret;
	ret.x = b.x-a.x;
	ret.y = b.y-a.y;
	return ret;
}



void make_poly()
{
	pos startpos = array1[min1];
	pos startvec;
	startvec.x = -1-startpos.x;
	startvec.y = 10001-startpos.y;
	double max;
	int ret=0;
	while(1)
	{
		max = -2;
		for(int i=0;i<n1;i++)
		{
			if(startpos.x==array1[i].x&&startpos.y==array1[i].y)
				continue;
			pos temp = make_vec(startpos,array1[i]);
			double result = rad(temp,startvec);
			if(result == max)
			{
				if(abs(dot(temp,startvec)) > abs(dot(startvec,make_vec(startpos,array1[ret]))))
				{
					ret = i;
				}
			}
			else if(result > max)
			{
				max=result;
				ret = i;
			}
		}
		line temp;
		temp.pos1 = startpos;
		temp.pos2 = array1[ret];
		poly1.push_back(temp);
		startvec = make_vec(startpos,array1[ret]);
		startpos = array1[ret];
		if(ret==min1)
			break;
	}
	p1 = poly1.size();
	startpos = array2[min2];
	startvec.x = -1-startpos.x;
	startvec.y = 10001-startpos.y;
	while(1)
	{
		max = -2;
		for(int i=0;i<n2;i++)
		{
			if(startpos.x==array2[i].x&&startpos.y==array2[i].y)
				continue;
			pos temp = make_vec(startpos,array2[i]);
			double result = rad(temp,startvec);
			if(result == max)
			{
				if(abs(dot(temp,startvec)) > abs(dot(startvec,make_vec(startpos,array2[ret]))))
				{
					ret = i;
				}
			}
			else if(result > max)
			{
				max = result;
				ret= i;
			}
		}
		line temp;
		temp.pos1 = startpos;
		temp.pos2 = array2[ret];
		poly2.push_back(temp);
		startvec = make_vec(startpos,array2[ret]);
		startpos = array2[ret];
		if(ret == min2)
			break;
	}
	p2 = poly2.size();
}

int shadow(pos a, line b)
{
	//can't meet
	if(a.x>max(b.pos1.x,b.pos2.x))
		return 0;
	if(a.y>max(b.pos1.y,b.pos2.y)||a.y<min(b.pos1.y,b.pos2.y))
		return 0;
	//pot
	pos vec = make_vec(b.pos1,b.pos2);
	if(vec.x==0)
	{
		if(vec.y==0)
		{
			if(a.x==b.pos1.x&&a.y==b.pos2.y)
				return 2;
			else
				return 0;
		}
		if(a.x==b.pos1.x)
			return 2;
		else if(a.x>b.pos1.x)
			return 0;
		else
			return 1;

	}
	if(vec.y==0)
	{
		if(a.x>max(b.pos1.x,b.pos2.x))
			return 0;
		else if(a.x<min(b.pos1.x,b.pos2.x))
			return 0;
		else
			return 2;
	}
	//inline
	double x = (double)b.pos1.x + (double)vec.x*((double)(a.y-b.pos1.y))/((double)(vec.y));
	if(x==(double)a.x)
		return 2;

	//outline
	
	x = (double)b.pos1.x + (double)vec.x*((double)a.y + 0.1 - (double)b.pos1.y)/(double)vec.y;
	if(min(b.pos1.x,b.pos2.x)<x&&x<max(b.pos1.x,b.pos2.x))
	{
		if(x<a.x)
			return 0;
		return 1;
	}
	else
		return 0;

	printf("error\n");
	return -1;	
}

bool inside()
{
	int cnt;
	for(int i=0;i<p1;i++)
	{
		cnt=0;
		for(int j=0;j<p2;j++)
		{
			int ret = shadow(poly1[i].pos1,poly2[j]);
			if(ret==2)
			{
				return true;
			}
			else if(ret==1)
			{
				cnt++;
			}
		}
		if(cnt%2==1)
		{
			return true;
		}
	}
	for(int i=0;i<p2;i++)
	{
		cnt=0;
		for(int j=0;j<p1;j++)
		{
			int ret = shadow(poly2[i].pos1,poly1[j]);
			if(ret==2)
			{
				return true;
			}
			else if(ret==1)
			{
				cnt++;
			}
		}
		if(cnt%2==1)
			return true;
	}
	return false;
}
int crossvec(pos a, pos b)
{
	return a.x*b.y-a.y*b.x;
}
bool crossdot(line x,line y,pos vec1,pos vec2)
{
	double a = (double)vec1.y/(double)vec1.x;
	double b = (double)x.pos1.y - a*(double)x.pos1.x;
	double c = (double)vec2.y/(double)vec2.x;
	double d = (double)y.pos1.y - c*(double)y.pos1.x;

	double retx = (d-b)/(a-c);
	double rety = a*retx+b;
	if(min(x.pos1.x,x.pos2.x)<=retx&&retx<=max(x.pos1.x,x.pos2.x)
			&&min(y.pos1.x,y.pos2.x)<=retx&&retx<=max(y.pos1.x,y.pos2.x)
			&&min(x.pos1.y,x.pos2.y)<=rety&&rety<=max(x.pos1.y,x.pos2.y)
			&&min(y.pos1.y,y.pos2.y)<=rety&&rety<=max(y.pos1.y,y.pos2.y))
		return true;
	return false;
}
bool meet(line a,line b)
{
	pos vec1 = make_vec(a.pos1,a.pos2);
	pos vec2 = make_vec(b.pos1,b.pos2);
	if(crossvec(vec1, vec2)==0)
	{
		//same line
		double t = (double)(b.pos1.x-a.pos1.x)/(double)vec1.x;
		double d = (double)a.pos1.y + (double)vec1.y*t;
		if(d==(double)b.pos1.y)
		{
			if(max(a.pos1.x,a.pos2.x)<min(b.pos1.x,b.pos2.x))
				return false;
			if(max(b.pos1.x,b.pos2.x)<min(a.pos1.x,b.pos1.x))
				return false;
			return true;
		}
		//diff line
		else
		{
			return false;
		}

	}
	else
	{
		return crossdot(a,b,vec1,vec2);
	}
}

bool cross()
{
	for(int i=0;i<p1;i++)
	{
		for(int j=0;j<p2;j++)
		{
			if(meet(poly1[i],poly2[j]))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		n1=0;
		n2=0;
		min1=0;
		min2=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp)
			{
				scanf("%d %d",&array1[n1].x,&array1[n1].y);	
				if(array1[n1].x==array1[min1].x)
				{
					if(array1[n1].y<array1[min1].y)
					{
						min1=n1;
					}
				}
				else if(array1[n1].x<array1[min1].x)
				{
					min1=n1;
				}
				n1++;
			}
			else
			{
				scanf("%d %d",&array2[n2].x,&array2[n2].y);
				if(array2[n2].x==array2[min2].x)
				{
					if(array2[n2].y<array2[min2].y)
					{
						min2=n2;
					}
				}
				else if(array2[n2].x<array2[min2].x)
				{
					min2 = n2;
				}
				n2++;
			}
		}

		poly1.clear();
		poly2.clear();
		
		make_poly();
	
		for(int i=0;i<p1;i++)
		{
			//printf("%d :(%d, %d) -> (%d, %d) \n",i+1,poly1[i].pos1.x,poly1[i].pos1.y,
			//		poly1[i].pos2.x,poly1[i].pos2.y);
		}

		for(int i=0;i<p2;i++)
		{
			//printf("%d :(%d, %d) -> (%d, %d) \n",i+1,poly2[i].pos1.x,poly2[i].pos1.y,
			//		poly2[i].pos2.x,poly2[i].pos2.y);
		}

		if(inside())
		{
			printf("THEORY IS INVALID\n");
		}
		else
		{
			//need more check
			if(cross())
				printf("THEORY IS INVALID\n");
			else
				printf("THEORY HOLDS\n");
		}


	}
}
