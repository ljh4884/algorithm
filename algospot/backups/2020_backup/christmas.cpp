/*
 * 누적합을 k로 나눈 나머지를 array에 저장한것을 이용
 * 좀더 최적화 할수 있을것 같음
 *
 */


#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int n,k;
int array[100000];
int size[100000];
bool check[100001];
int prob1()
{
	long long sum=0;
	for(int i=0;i<k;i++)
	{
		long long temp = size[i];
		temp = (temp*(temp-1))/2;
		temp = temp%20091101;
		sum = (sum + temp)%20091101;
	}
	return (int)sum;
}

int prob2()
{
	int pos = -1;
	int cnt=0;
	while(1)
	{

		for(int i=0;i<k;i++)
		{
			check[i]=false;
		}
		if(pos==-1)
		{
			check[0]=true;
		}
		else
		{
			check[array[pos]]=true;
		}
		int i;
		for(i=pos+1;i<n;i++)
		{
			if(check[array[i]]==true)
			{
				pos=i;
				cnt++;
				//printf("hihi %d %d\n",pos,cnt);
				break;
			}
			check[array[i]]=true;
		}
		if(i>n-1)
			break;
		
	}
	return cnt;
}

int prob3(int pos)
{
	for(int i=0;i<k;i++)
	{
		check[i]=false;
	}
	if(pos==-1)
		check[0]=true;
	else
		check[array[pos]]=true;
	int i;
	for(i=pos+1;i<n;i++)
	{
		if(check[array[i]]==true)
		{
			return 1+prob3(i);
		}
		check[array[i]]=true;
	}
	return 0;
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int sum=0;
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;i++)
		{
			size[i]=0;
			//check[i]=false;  //for opt
		}
		//check[0]=true;	//for opt
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			sum=(sum+temp)%k;
			array[i]=sum;
			size[array[i]]++;
		}
		size[0]++;
		printf("%d ",prob1());
		printf("%d\n",prob2());
		printf("%d\n",prob3(-1));
	}
}
