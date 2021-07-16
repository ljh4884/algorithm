/*
 * c언어로 짜본뒤 c++로 짠 버전이다.
 * 코드 자체도 간소화 되었고 시간 자체도 빨라졌다.
 */

#include <stdio.h>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;
int n;

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int temp;
		priority_queue<int,vector<int>,greater<int>>pq;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			pq.push(temp);
		}
		temp=0;
		for(int i=0;i<n-1;i++)
		{
			int input=pq.top();
			pq.pop();
			input+=pq.top();
			pq.pop();
			temp+=(input);
			pq.push(input);
		}
		printf("%d\n",temp);
	}
}

