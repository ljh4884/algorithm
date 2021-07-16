/*
 * 처음에는 linked list를 사용하여 풀고싶어서 노력하였으나
 * optimal한 solution이 아니였다.
 * 결국 오랜시간에 걸쳐 시도하다 실패하여 
 * 인터넷의 도움을 받았다 
 * 알고리즘을 새로운 방식으로 접근한것 같다.
 * 값의 범위로 시작하여 값을 좁혀나가 답을 출력하는
 * 마치 수치해석 같은 느낌이였다.
 * 문제에서 정확도를 10^-2 까지만 출력하면 되기에 가능했던것 같다.
 * 물론 opt()에서 i의 반복수를 더늘려주면 더 정확한 값도 문제없이 작동할것 같다.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>

int n,m;
double array[200];

int func(double gap)
{
	double cnt=0;
	double last=array[0];
	for(int i=1;i<m;i++)
	{
		if(array[i]-last>gap)
		{
			last = array[i];
			cnt++;
		}
	}
	if(cnt>=n-1)
		return 1;
	else
		return 0;
}

double opt()
{
	double left=0;
	double right = array[m-1]-array[0]+1.0;
	for(int i=0;i<100;i++)
	{
		double mid = (left+right)/2.0;
		
		if(func(mid))
			left=mid;
		else
			right = mid;
	}
	return left;

}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		double ret;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%lf",&array[i]);
		}
		ret = opt()*100.0;
		ret = round(ret)/100.0;
		printf("%.2lf\n",ret);
	}
}
