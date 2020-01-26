/*
 * 문제를 거꾸로 푸는 방법을 선택하였다. 
 * 시작을 먹는시간이 가장 조금 걸리는 도시락을 기준으로 먹는 시간 + 데피는 시간
 * 그리고 계속 데피는 시간을 더해가지만 먹는 시간이 전까지 시간보다 더 크다면 전까지 시간을 먹는 시간으로 대체
 * sorting을 c언어 qsort를 사용하였다.
 * c++의 sort 알고리즘을 사용하면 더 빠를수도 있을것 같다.
 */

#include <stdio.h>
#include <stdlib.h>

#define lunch struct box

struct box
{
	int cook;
	int eat;
};

int compare(const void *a, const void *b)
{
	lunch *A = (lunch*)a;
	lunch *B = (lunch*)b;

	if(A->eat < B->eat)
		return -1;
	else if(A->eat == B->eat)
		return 0;
	else
		return 1;
}

lunch table[10000];
int n;
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int sum=0;
		//int temp=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&table[i].cook);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d", &table[i].eat);
		}
		qsort(table,n,sizeof(lunch),compare);
		sum+=table[0].eat;
		sum+=table[0].cook;
		for(int i=1;i<n;i++)
		{
			if(table[i].eat>sum)
				sum=table[i].eat;
			sum+=table[i].cook;
		}
		printf("%d\n",sum);
	}
}
