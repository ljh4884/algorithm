#include <stdio.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct position
{
	int x;
	int y;
}pos;

typedef struct vecto
{
	int x;
	int y;
}vec;

typedef struct line
{
	pos pos1;
	pos pos2;
}line;

int n;
int n1;
int n2;
int min1;
int min2;
pos pos1[5000];
pos pos2[5000];
vector<line> poly1;
vector<line> poly2;
int dotp(vec a,vec b)
{
	return a.x*b.x+a.y*b.y;
}
double sizevec(vec a)
{
	return sqrt((double)(a.x*a.x+a.y*a.y));
}
double angle(vec a,vec b)
{
	return dotp(a,b)/(sizevec(a)*sizevec(b));
}
vec pos2vec(pos a, pos b)
{
	vec ret;
	ret.x = b.x-a.x;
	ret.y = b.y-a.y;
	return ret;
}
void make_poly()
{
	pos startpos;

	startpos.x=-1;
	startpos.y=10001;
	double max;
	vec startvec = pos2vec(pos1[min1],startpos);
	int start = min1;
	int next = min1;
	while(1)
	{
		max=-2;
		for(int i=0;i<n1;i++)
		{
			if((pos1[i].x==pos1[start].x)&&(pos1[i].y==pos1[start].y))
				continue;
			vec thisvec = pos2vec(pos1[start],pos1[i]);
			double thisangle = angle(startvec,thisvec);
			if(thisangle==max)
			{
				if(abs(dotp(startvec,thisvec)) > abs(dotp(startvec,pos2vec(pos1[start],pos1[next]))))
				{
					next = i;
				}
			}
			else if(thisangle>max)
			{
				max = thisangle;
				next = i;
			}
		}
		line input;
		input.pos1 = pos1[start];
		input.pos2 = pos1[next];
		poly1.push_back(input);
		startvec = pos2vec(pos1[start],pos1[next]);
		if(next==min1)
			break;
		start=next;
	}
	startvec = pos2vec(pos2[min2],startpos);
	start=min2;
	next=min2;
	while(1)
	{
		max=-2;
		for(int i=0;i<n2;i++)
		{
			if(pos2[i].x==pos2[start].x&&pos2[i].y==pos2[start].y)
				continue;
			vec thisvec = pos2vec(pos2[start],pos2[i]);
			double thisangle = angle(startvec,thisvec);
			if(thisangle==max)
			{
				if(abs(dotp(startvec,thisvec)) > abs(dotp(startvec,pos2vec(pos2[start],pos2[next]))))
				{
					next = i;
				}
			}
			else if(thisangle>max)
			{
				max = thisangle;
				next = i;
			}
		}
		line input;
		input.pos1 = pos2[start];
		input.pos2 = pos2[next];
		poly2.push_back(input);
		startvec = pos2vec(pos2[start],pos2[next]);
		if(next==min2)
			break;
		start=next;
	}
}

int meet(pos a,line b)
{
	//always can't meet 
	if(a.x>b.pos1.x&&a.x>b.pos2.x)
		return 0;
	if(b.pos1.y>a.y&&b.pos2.y>a.y)
		return 0;
	if(b.pos1.y<a.y&&b.pos2.y<a.y)
		return 0;
	//on line?
	if(b.pos1.y==b.pos2.y)
	{
		if(a.y!=b.pos1.y)
			return 0;
		else
		{
			if(a.x>b.pos1.x&&a.x>b.pos2.x)
				return 0;
			else
			{
				if(b.pos1.y!=b.pos2.y)
					return 2;
			}
		}
	}
	else
	{
		vec calvec = pos2vec(b.pos1,b.pos2);
		int left = b.pos1.x*calvec.y+(a.y-b.pos1.y)*calvec.x;
		int right = calvec.y*a.x;
		if(left==right)
		{
			return 2;
		}
		double last = (double)a.y + 0.1;
		if((last >(double)b.pos1.y )&& (last > (double)b.pos2.y))
		{
			return 0;
		}
		double l = (double)(b.pos1.x*calvec.y)+(0.1+(double)a.y-(double)b.pos1.y)*(double)calvec.x;
		double r= (double)right;
		if(calvec.y<0)
		{
			if(l>r)
				return 0;
			else
				return 1;
		}
		else if(calvec.y==0)
		{
			printf("error\n");
		}
		else
		{
			if(l>r)
				return 1;
			else
				return 0;
		}
	}
	return 0;
	
}

bool isinside()
{
	int m1=poly1.size();
	int m2=poly2.size();
	/*if(m1==2)
	{
		n1--;
	}
	if(m2==2)
	{
		m2--;
	}*/
	int cnt;
	for(int i=0;i<m1;i++)
	{
		cnt=0;
		for(int j=0;j<m2;j++)
		{
			int compare = meet(poly1[i].pos1,poly2[j]);
			if(compare==2)
			{
				return true;
			}
			else if(compare==1)
				cnt++;
		}
		if(cnt%2==1)
		{
			return true;
		}
	}
	for(int i=0;i<m2;i++)
	{
		cnt=0;
		for(int j=0;j<m1;j++)
		{
			int compare = meet(poly2[i].pos1,poly1[j]);
			if(compare==2)
			{
				return true;
			}
			else if(compare==1)
				cnt++;
		}
		if(cnt%2==1)
		{
			return true;
		}
	}
	return false;
}
void swap(int *a, int *b)
{
	if(*a>*b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}
bool cal(line a, line b)
{
	vec vec1 = pos2vec(a.pos1,a.pos2);
	vec vec2 = pos2vec(b.pos1,b.pos2);
	//D==0 parr but can't same because it is not meet
	if(vec1.x*vec2.y==vec1.y*vec2.x)
	{
		return false;
	}
	else // can cross 
	{
		int sign1 = (a.pos2.x-a.pos1.x)*(b.pos1.y-a.pos1.y) - (b.pos1.x-a.pos1.x) * (a.pos2.y-a.pos1.y);
		int sign2 = (a.pos2.x-a.pos1.x)*(b.pos2.y-a.pos1.y) - (b.pos2.x-a.pos1.x) * (a.pos2.y-a.pos1.y);
		int sign3 = (b.pos2.x-b.pos1.x)*(a.pos1.y-b.pos1.y) - (a.pos1.x-b.pos1.x) * (b.pos2.y-b.pos1.y);
		int sign4 = (b.pos2.x-b.pos1.x)*(a.pos2.y-b.pos1.y) - (a.pos2.x-b.pos1.x) * (b.pos2.y-b.pos1.y);
	return ((sign1 * sign2 < 0) && (sign3*sign4<0));
	}
}

bool crossp()
{
	int m1=poly1.size();
	int m2=poly2.size();
	//if(m1==2)
		//m1--;
	//if(m2==2)
		//m2--;
	for(int i=0;i<m1;i++)
	{
		for(int j=0;j<m2;j++)
		{
			if(cal(poly1[i],poly2[j]))
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
				scanf("%d %d",&pos1[n1].x,&pos1[n1].y);
				if(pos1[n1].x==pos1[min1].x)
				{
					if(pos1[n1].y<pos1[min1].y)
					{
						min1=n1;
					}
				}
				else if(pos1[n1].x<pos1[min1].x)
				{
					min1=n1;
				}
				n1++;
			}
			else
			{
				scanf("%d %d",&pos2[n2].x,&pos2[n2].y);
				if(pos2[n2].x==pos2[min2].x)
				{
					if(pos2[n2].y<pos2[min2].y)
					{
						min2=n2;
					}
				}
				else if(pos2[n2].x<pos2[min2].x)
					min2=n2;
				n2++;
			}
		}
		poly1.clear();
		poly2.clear();
		make_poly();
		if(isinside())
		
			printf("THEORY IS INVALID\n");
		else
		{
			if(crossp())
			{

				printf("THEORY IS INVALID\n");
			}
			else
			{
				printf("THEORY HOLDS\n");
			}
		}
	}
}

