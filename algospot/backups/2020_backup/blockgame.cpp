/*
 * inline 함수를 쓴것과 안쓴것과 70ms 정도의 시간차이가 났다.
 * 5*5 판 자체를 2^25 bit로 생각하는 것이 신기하였다.
 * 또한 ㄱ자 블럭이나 2칸짜리 블럭으로 저 판을 채울수 있는 경우의 수가 104가지 밖에 되지 않는다는 것도 어려운 부분이였다.
 */

#include <stdio.h>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
char array[5][5];
char save[1<<25];

//#define sub(x,y) (1<<(x*5+y))
inline int sub(int x,int y)
{
	return (1<<(x*5+y));
}
vector<int> forcal;

void pre()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int sum;
			sum = sub(i,j)+sub(i,j+1)+sub(i+1,j)+sub(i+1,j+1);
			forcal.push_back(sum-sub(i,j));
			forcal.push_back(sum-sub(i,j+1));
			forcal.push_back(sum-sub(i+1,j));
			forcal.push_back(sum-sub(i+1,j+1));
		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			forcal.push_back(sub(i,j)+sub(i,j+1));
			forcal.push_back(sub(j,i)+sub(j+1,i));
		}
	}
}


char func(int pos)
{
	if(save[pos]!=-1)
		return save[pos];
	save[pos]=0;
	for(int i=0;i<forcal.size();i++)
	{
		
		if((forcal[i]&pos)==0)
		{
			if(!func(pos|forcal[i]))
			{
				save[pos]=1;
				break;
			}
		}
	}
	return save[pos];
}

int main()
{
	int c;
	
	scanf("%d",&c);
	for(int i=0;i<(1<<25);i++)
	{
		save[i]=-1;
	}
	pre();
	while(c--)
	{
		int pos=0;
		int temp=1;
		for(int i=0;i<5;i++)
		{
			scanf("%s",array[i]);
			for(int j=0;j<5;j++)
			{
				if(array[i][j]=='#')
				{
					array[i][j]=1;
					pos=pos|temp;
				}
				else
					array[i][j]=0;
				temp=temp<<1;
			}
		}
		if(func(pos)==1)
			printf("WINNING\n");
		else
			printf("LOSING\n");
		
	}
	
}
