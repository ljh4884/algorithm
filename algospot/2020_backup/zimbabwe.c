#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * 메모이제이션의 적용점은 내가 어떤 원소를 지금까지 사용 하였는지 + 지금까지 적용한 나머지가 몇인지 + 총 숫자가 원래 숫자보다 작은지 (check,pre,pl) 이다.
 * 위 과정중 첫번째인 check가 가장 어려웠다.
 * array[3] = {4,2,2} 라고 했을때
 * array[0] array[1] array[2] 와 array[1] array[0] array[2] 같은 경우를 1번만 세주어야 함
 * r[i] == r[i-1] 인 경우에는 일반적으로 카운트 하지 못하지만
 * check[i-1] == 1 인 경우에는 카운트 할 수 있음. << 이건 원소를 앞에서 부터 사용하겠다는 의미임 
 *
 * 문제자체는 책을 보지 않고도 풀수 있었지만 메모이제이션을 적용하는 방법이 어려워 계속 시간초과가 났지만 책을 읽고나니 쉽게 적용할 수 있었음
 */
char e[16];
char r[16];
int m;
int size;
int save[1<<15][20][2];
int find(int check,int pos,int pre,int pl)
{
	int ret=0;
	if(save[check][pre][pl]!=-1)
		return save[check][pre][pl];
	if(pos==size)
	{
		if(pl==1)
			return 0;
		if(pre==0)
			return 1;
		return 0;
	}
	for(int i=0;i<size;i++)
	{
		int npl=pl;
		if((check&(1<<i))!=0)
			continue;
		if(i!=0)
		{
			if(r[i-1]==r[i]&&(check&(1<<(i-1)))==0)
				continue;
		}
		if(pl==1)
		{
			if(r[i]>e[pos])
				break;
			else if(r[i]<e[pos])
				npl=0;
		}
		
		int temp = (pre*10+r[i])%m;
		int ncheck = check | (1<<i);
		ret = (ret + find(ncheck,pos+1,temp,npl))%1000000007;
		
	}
	ret = ret%1000000007;
	save[check][pre][pl]=ret;
	return ret;
}
int compare(const void *a, const void *b)
{
	char num1 = *(char *)a;
	char num2 = *(char *)b;
	if(num1 < num2)
		return -1;
	else if(num1==num2)
		return 0;
	else
		return 1;
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%s %d",e,&m);
		size = strlen(e);
		for(int i=0;i<size;i++)
		{
			e[i]-=48;
			r[i]=e[i];
		}
		for(int i=0;i<(1<<size);i++)
		{
			for(int j=0;j<m;j++)
			{
				save[i][j][0]=-1;
				save[i][j][1]=-1;
			}
		}
		qsort(r,size,sizeof(char),compare);
		printf("%d\n",find(0,0,0,1));
	}
}
