/*
 * 재귀함수를 사용하지 않고 dp를 적용
 * 적용하지는 않았지만 배열의 크기가 너무 클경우
 * %연산자를 사용해서 나머지로만 배열을 사용하여도 같은 시간 복잡도를 같는 프로그램 생성가능
 * (슬라이딩 원도 기법)
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n,m;
int price[20];
int score[20];
int save[21474837];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int func()
{
	int ret=0;
	for(int i=0;i<=m;i++)
	{
		save[i]=0;
		for(int j=0;j<n;j++)
		{
			if(price[j]<=i)
			{
				save[i]=max(save[i-price[j]]+score[j],save[i]);
			}
		}
		
		ret = max(ret,save[i]);
	}
	return ret;
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		m=m/100;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&price[i],&score[i]);
			price[i]=price[i]/100;
		}
		printf("%d\n",func());
	}
}
