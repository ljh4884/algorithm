#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

typedef struct position
{
	double x;
	double y;
}pos;

pos rec[4];
int check[4];
int n;

pos array[100];
vector<pair<pos,pos>> line;

int insidey(pair<pos,pos> a,double y)
{
	if(a.first.y==y||a.second.y==y)
		return 1;
	else if((a.first.y<y&&y<a.second.y)||(a.second.y<y&&y<a.first.y))
		return 0;
	else
		return -1;
}	

int insidex(pair<pos,pos> a,double x)
{
	if(a.first.x==x||a.second.x==x)
		return 1;
	else if((a.first.x<x&&x<a.second.x)||(a.second.x<x&&x<a.first.x))
		return 0;
	else
		return -1;
}	

bool inside(double y)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int temp = insidey(line[i],y);
		if(temp==1)
		{
			cnt++;
			i++;
		}
		else if(temp==0)
		{
			cnt++;
		}
	}
	return (cnt%2==1);
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%lf %lf %lf %lf %d",&rec[0].x,&rec[0].y,&rec[2].x,&rec[2].y,&n);
		rec[1].x=rec[2].x;
		rec[1].y=rec[0].y;
		rec[3].x=rec[0].x;
		rec[3].y=rec[2].y;
		for(int i=0;i<4;i++)
		{
			check[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&array[i].x,&array[i].y);
		}
		line.clear();
		for(int i=0;i<n;i++)
		{
			int next = (i+1)%n;
			line.push_back(make_pair(array[i],array[next]));
		}
	}
}
