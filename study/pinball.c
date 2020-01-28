/*
 * 지금까지 책에 있던 문제중 가장 어려웠다고 생각한다.
 * 먼저 한글 주석을 포함하고 제출해서 컴파일 에러가 많이 발생하였다.
 * 1<x<99 1<y<99 인 범위라고 생각하고 제출 하였더니 오답이 나왔다.
 * 최대 100개의 답을 출력한다는 것을 몰라 시간초과가 나왔다.
 * 고등학교 수준의 도형의 이해가 필요하다.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct position
{
	double x;
	double y;
}pos;

typedef struct vecto
{
	double x;
	double y;
}myvec;

typedef struct circle
{
	pos loc;
	double radius;
}one;

int n;
one circle[50];
pos start;
myvec way;

double dotp(myvec a,myvec b);

myvec pos2vec(pos a,pos b)
{
	myvec ret;
	ret.x = b.x-a.x;
	ret.y = b.y-a.y;
	return ret;
}
myvec pos1vec(pos a)
{
	myvec ret;
	ret.x =a.x;
	ret.y =a.y;
	return ret;
}
double sizevec(myvec a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}
pos vec2pos(myvec a,pos b)
{
	pos ret;
	ret.x = b.x+a.x;
	ret.y = b.y+a.y;
	return ret;
}
myvec nomalvec(myvec a)
{
	myvec ret;
	double mom = sizevec(a);
	ret.x = a.x/mom;
	ret.y = a.y/mom;
	return ret;
}

double dotp(myvec a,myvec b)
{
	return a.x*b.x+a.y*b.y;
}

myvec provec(myvec a,myvec b) 
{
	myvec ret;
	double multi;
	multi=dotp(a,b);
	ret.x = b.x*multi;
	ret.y = b.y*multi;
	return ret;
}

pos findloc(int num)
{
	myvec stand = pos2vec(start,circle[num].loc);
	myvec project = provec(stand,way); 

	double project_s = sizevec(project); 
	double compare = circle[num].radius+1;
	myvec vertical;
	vertical.x = project.x-stand.x;
	vertical.y = project.y-stand.y;
	double vertical_s = sizevec(vertical);
	pos ret;
	ret.x=-1000;
	ret.y=-1000;
	if(dotp(way,project)<=0) 
	{
		return ret;
	}

	if(vertical_s < compare)
	{
		double rest = compare*compare - vertical_s*vertical_s;
		rest = sqrt(rest);
		double result = project_s - rest;
		project=nomalvec(project);
		project.x=project.x*result;
		project.y=project.y*result;
		return vec2pos(project,start);
	}
	return ret;
}

int findobs()
{
	double minpos = 99999;
	pos result;
	int resulti;
	int end=0;
	for(int i=0;i<n;i++)
	{
		pos prob = findloc(i);
		if(prob.x!=-1000&&prob.y!=-1000)
		{
			myvec probvec=pos2vec(start,prob);
			double probsize = sizevec(probvec);
			if(probsize<minpos)
			{
				end=1;
				minpos=probsize;
				result.x=prob.x;
				result.y=prob.y;
				resulti=i;
			}

		}

	}
	if(end==0)
	{
		return -1;
	}
	myvec nor = pos2vec(circle[resulti].loc,result);
	myvec opp = pos2vec(result,start);
	myvec ori = pos2vec(start,result);
	nor = nomalvec(nor);
	
	nor=provec(opp,nor);
	ori.x = ori.x + nor.x + nor.x;
	ori.y = ori.y + nor.y + nor.y;
	
	ori = nomalvec(ori);
	way.x=ori.x;
	way.y=ori.y;
	start.x=result.x;
	start.y=result.y;
	return resulti;

}

void solve()
{
	int ret;
	int cnt=0;
	while((ret = findobs())!=-1&&cnt<100)
	{
		printf("%d ",ret);
		cnt++;
	
	}
	printf("\n");
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%lf %lf %lf %lf %d",&start.x,&start.y,&way.x,&way.y,&n);
		way=nomalvec(way);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf %lf",&circle[i].loc.x,&circle[i].loc.y,&circle[i].radius);
		}
		solve();
	}
}
