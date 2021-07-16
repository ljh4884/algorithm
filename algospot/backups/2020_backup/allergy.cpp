/*
 * 거의 책을 그대로 배낌
 * 내가 처음 구현했던것과 다른점은
 * person[] 이라는 새로운 백터를 사용한것
 * c++을 사용하는 것이 메모리적으로나 시간적으로나 더 편리한것 같다.
 */


#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m;
vector<int> person[50];
vector<int> food[50]; //eater
int minsum;
char name[50][11];
int find(char *input)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(name[i],input)==0)
			return i;
	}
	return -1;
}

void func(vector<int>& eat,int sum)
{
	int ret=99999;
	if(minsum<=sum)
		return;
	int count=0;
	while(count<n&&eat[count]>0)
		count++;
	if(count==n)
	{
		minsum=sum;
	}
	for(int i=0;i<person[count].size();i++)
	{
		int pos = person[count][i];
		for(int j=0;j<food[pos].size();j++)
		{
			eat[food[pos][j]]++;
		}
		func(eat,sum+1);
		for(int j=0;j<food[pos].size();j++)
		{
			eat[food[pos][j]]--;
		}

	}
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		minsum=99999;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%s",name[i]);
			person[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			int cnt;
			food[i].clear();
			scanf("%d",&cnt);
			while(cnt--)
			{
				char temp[11];
				scanf("%s",temp);
				food[i].push_back(find(temp));
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<food[i].size();j++)
			{
				person[food[i][j]].push_back(i);
			}
		}
		vector<int> input;
		for(int i=0;i<50;i++)
		{
			input.push_back(0);
		}
		func(input,0);
		printf("%d\n",minsum);

	}
}
