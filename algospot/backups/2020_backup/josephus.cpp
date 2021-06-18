/*책을 참고하지 않았음
 * list라는 링크드 리스트를 사용하여 구현하였음
 */

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;
int n,k;
int array[1001];
list<int> lt;
list<int>::iterator pos;
void pop()
{
	//printf("%d\n",*pos);
	pos=lt.erase(pos);
	if(pos==lt.end())
		pos=lt.begin();
	for(int i=0;i<k-1;i++)
	{
		pos++;
		if(pos==lt.end())
			pos=lt.begin();
	}
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&k);
		lt.clear();
		for(int i=1;i<n+1;i++)
		{
			lt.push_back(i);
		}
		pos =lt.begin();
		for(int i=0;i<n-2;i++)
		{
			pop();
		}
		printf("%d %d\n",lt.front(),lt.back());
		
	}
}
